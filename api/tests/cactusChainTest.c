/*
 * Copyright (C) 2009-2011 by Benedict Paten (benedictpaten@gmail.com)
 *
 * Released under the MIT license, see LICENSE.txt
 */

#include "cactusChainsTestShared.h"

static bool nestedTest = 0;

static void cactusChainTestTeardown(CuTest* testCase) {
    if (!nestedTest) {
        cactusChainsSharedTestTeardown(testCase->name);
    }
}

static void cactusChainTestSetup(CuTest* testCase) {
    if (!nestedTest) {
        cactusChainsSharedTestSetup(testCase->name);
    }
}

void testChain_construct(CuTest* testCase) {
    nestedTest = 0;
    cactusChainTestSetup(testCase);
    CuAssertTrue(testCase, chain != NULL);
    CuAssertTrue(testCase, link1 != NULL);
    CuAssertTrue(testCase, link2 != NULL);
    CuAssertTrue(testCase, link5 != NULL);
    cactusChainTestTeardown(testCase);
}

void testChain_getFirst(CuTest* testCase) {
    cactusChainTestSetup(testCase);
    CuAssertTrue(testCase, chain_getFirst(chain) == link1);
    CuAssertTrue(testCase, chain_getFirst(chain3) == link5);
    Chain *chain6 = chain_construct(flower);
    CuAssertTrue(testCase, chain_getFirst(chain6) == NULL);
    cactusChainTestTeardown(testCase);
}

void testChain_getLast(CuTest* testCase) {
    cactusChainTestSetup(testCase);
    CuAssertTrue(testCase, chain_getLast(chain) == link2);
    CuAssertTrue(testCase, chain_getLast(chain2) == link4);
    CuAssertTrue(testCase, chain_getLast(chain3) == link5);
    Chain *chain6 = chain_construct(flower);
    CuAssertTrue(testCase, chain_getLast(chain6) == NULL);
    cactusChainTestTeardown(testCase);
}

void testChain_getName(CuTest* testCase) {
    cactusChainTestSetup(testCase);
    CuAssertTrue(testCase, chain_getName(chain) != NULL_NAME);
    CuAssertTrue(testCase, flower_getChain(flower, chain_getName(chain)) == chain);
    cactusChainTestTeardown(testCase);
}

void testChain_getFlower(CuTest* testCase) {
    cactusChainTestSetup(testCase);
    CuAssertTrue(testCase, chain_getFlower(chain) == flower);
    cactusChainTestTeardown(testCase);
}

void testChain_isCircular(CuTest* testCase) {
    cactusChainTestSetup(testCase);
    CuAssertTrue(testCase, !chain_isCircular(chain));
    CuAssertTrue(testCase, !chain_isCircular(chain2));
    CuAssertTrue(testCase, chain_isCircular(chain3));
    cactusChainTestTeardown(testCase);
}

CuSuite* cactusChainTestSuite(void) {
    CuSuite* suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, testChain_getFirst);
    SUITE_ADD_TEST(suite, testChain_getLast);
    SUITE_ADD_TEST(suite, testChain_getName);
    SUITE_ADD_TEST(suite, testChain_getFlower);
    SUITE_ADD_TEST(suite, testChain_isCircular);
    SUITE_ADD_TEST(suite, testChain_construct);
    return suite;
}
