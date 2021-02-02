#ifndef MNR_H
#define MNR_H

#include <stdlib.h>
#include <stdio.h>

typedef unsigned int uint;

struct mnr {
	uint *registers;
	uint n;
};

struct mnr* init(uint n);
void terminate(struct mnr *m);

void Z(struct mnr *m, uint i);
void S(struct mnr *m, uint i);
void T(struct mnr *m, uint j, uint i);
int J(struct mnr *m, uint j, uint i);

#endif

