/*
 * Copyright (C) 2009-2011 by Benedict Paten (benedictpaten@gmail.com)
 *
 * Released under the MIT license, see LICENSE.txt
 */

#ifndef CACTUS_META_SEQUENCE_PRIVATE_H_
#define CACTUS_META_SEQUENCE_PRIVATE_H_

#include "cactusGlobals.h"

struct _sequence {
	Name name;
	Name stringName;
	int64_t start;
	int64_t length;
	Event *event;
	CactusDisk *cactusDisk;
	char *header;
	bool isTrivialSequence; //This flag is used to indicate if a sequence is trivial.
};

////////////////////////////////////////////////
////////////////////////////////////////////////
////////////////////////////////////////////////
//Private meta sequence functions.
////////////////////////////////////////////////
////////////////////////////////////////////////
////////////////////////////////////////////////

/*
 * Constructs a meta sequence using an existing reference to a sequence in the sequence file.
 */
Sequence *sequence_construct2(Name name, int64_t start, int64_t length, Name stringName, const char *header,
		Event *event, bool isTrivialSequence, CactusDisk *cactusDisk);

/*
 * Destructs a meta sequence.
 */
void sequence_destruct(Sequence *sequence);

#endif
