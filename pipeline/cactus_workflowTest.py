"""Tests the core pipeline.
"""

import unittest
import os
import sys

from cactus.shared.test import parseCactusSuiteTestOptions
from sonLib.bioio import TestStatus

from cactus.shared.test import getCactusInputs_random
from cactus.shared.test import getCactusInputs_blanchette
from cactus.shared.test import getCactusInputs_encode
from cactus.shared.test import getCactusInputs_chromosomeX

from cactus.shared.test import getCactusInputs_evolver_primate_small

from cactus.shared.test import runWorkflow_multipleExamples

class TestCase(unittest.TestCase):
    
    def setUp(self):
        if os.system("parasol status") == 0:
            self.batchSystem = "parasol"
        else:
            self.batchSystem = "single_machine"
        unittest.TestCase.setUp(self)
        
    def testCactus_Random(self):
        return
        runWorkflow_multipleExamples(getCactusInputs_random, 
                                     testNumber=TestStatus.getTestSetup(),
                                     buildReference=False,
                                     batchSystem=self.batchSystem, buildJobTreeStats=True)
        
    def testCactus_Blanchette(self):
        outputDir = os.path.join(TestStatus.getPathToDataSets(), "cactus", 
                                 "blanchettesRegionsTest")
        runWorkflow_multipleExamples(getCactusInputs_blanchette, 
                                     outputDir=outputDir,
                                     testNumber=1,
                                     testRestrictions=(TestStatus.TEST_MEDIUM,),
                                     batchSystem=self.batchSystem,
                                     buildCactusPDF=True,
                                     makeCactusTreeStats=True, makeMAFs=True, buildReferencePDF=True, buildJobTreeStats=True)
                
    def testCactus_Encode(self): 
        outputDir = os.path.join(TestStatus.getPathToDataSets(), "cactus", "encodeRegionsTest")
        runWorkflow_multipleExamples(getCactusInputs_encode, 
                                     outputDir=outputDir,
                                     testNumber=1,
                                     testRestrictions=(TestStatus.TEST_LONG,),
                                     batchSystem=self.batchSystem,
                                     makeCactusTreeStats=True, makeMAFs=True, buildJobTreeStats=True)
    
    def testCactus_Chromosomes(self):
        return
        outputDir = os.path.join(TestStatus.getPathToDataSets(), "cactus", "chrX")
        runWorkflow_multipleExamples(getCactusInputs_chromosomeX, 
                                     outputDir=outputDir,
                                     testRestrictions=(TestStatus.TEST_VERY_LONG,),
                                     batchSystem=self.batchSystem,
                                     makeCactusTreeStats=True, makeMAFs=True)
    
    def testCactus_EvolverPrimatesSmall(self):
        outputDir = os.path.join(TestStatus.getPathToDataSets(), "cactus", "evolver", "primates", "small")
        runWorkflow_multipleExamples(getCactusInputs_evolver_primate_small,
                                     outputDir=outputDir,
                                     testRestrictions=(TestStatus.TEST_VERY_LONG,),
                                     batchSystem=self.batchSystem,
                                     makeCactusTreeStats=True, makeMAFs=True)
    
def main():
    parseCactusSuiteTestOptions()
    sys.argv = sys.argv[:1]
    unittest.main()
        
if __name__ == '__main__':
    main()
