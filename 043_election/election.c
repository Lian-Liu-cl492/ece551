#include "election.h"
#include <stdio.h>
#include <string.h>
//include any other headers you need here...

state_t parseLine(const char * line) {
	state_t state;
	const char *save, *p;
	size_t namelen;

	save = p = line;

	/* name = [^:]+ */
	/* I don't see an accurate spec,
	 * but I would argue that this field
	 * should be non-empty */
	while (*p != ':') {
		if (*p == '\0') goto error;
		p++;
	}
	namelen = (size_t) (p - save);
	if (namelen == 0) goto error;
	if (namelen > MAX_STATE_NAME_LENGTH - 1) {
		fprintf(stderr, "name too long: %zu > %zu\n",
			namelen, (size_t) (MAX_STATE_NAME_LENGTH-1));
		exit(EXIT_FAILURE);
	}
	memcpy(state.name, save, namelen);
	state.name[namelen] = '\0';

	save = ++p; /* skip : */

	/* population = [0-9]+ */
	/* I'm also not sure if there're any constraints
	 * on the range of the input, e.g. must be positive? */
	state.population = 0ULL;
	while ('0' <= *p && *p <= '9') {
		state.population = state.population * 10ULL + (uint64_t) (*p - '0');
		p++;
	}
	if (p == save || *p != ':') goto error;

	save = ++p; /* skip : */

	/* electoralVotes = [0-9]+ */
	state.electoralVotes = 0U;
	while ('0' <= *p && *p <= '9') {
		state.electoralVotes = state.electoralVotes * 10U + (unsigned) (*p - '0');
		p++;
	}
	if (p == save || *p != '\0') goto error;

	/* success */
	return state;

error:
	fprintf(stderr, "unexpected character \\x%02x at position %td.\n",
		*p, p - line);
	fprintf(stderr, "%s\n%*s\n", line, (int) (p - line + 1), "^");
	exit(EXIT_FAILURE);
}
unsigned int countElectoralVotes(state_t * stateData, 
		uint64_t * voteCounts, 
		size_t nStates) {
	//STEP 2: write me
	return 0;
}

void printRecounts(state_t * stateData, 
		uint64_t * voteCounts, 
		size_t nStates) {
	//STEP 3: write me
}
void printLargestWin(state_t * stateData, 
		uint64_t * voteCounts, 
		size_t nStates) {
	//STEP 4: write me
}