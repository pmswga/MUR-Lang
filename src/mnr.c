#include "mnr.h"

struct mnr* init(uint n)
{
	struct mnr *m = malloc(sizeof(struct mnr));

	m->registers = malloc(sizeof(uint) * n);
	m->n = n;

	return m;
}

void terminate(struct mnr *m)
{
	if (m) {
		if (m->registers) {
			free(m->registers);
		}

		free(m);
	}
}


void Z(struct mnr *m, uint i)
{
	if (m) {
		if (i >= 1 && i <= m->n) {
			m->registers[i-1] = 0;
		}
	}
}

void S(struct mnr *m, uint i)
{
	if (m) {
		if (i >= 1 && i <= m->n) {
			m->registers[i-1] += 1;
		}
	}
}

void T(struct mnr *m, uint j, uint i)
{
	if (m) {
		if ((i >= 1 && i <= m->n) && (j >= 1 && j <= m->n)) {
			m->registers[i-1] = m->registers[j-1];
		}
	}
}

int J(struct mnr *m, uint j, uint i)
{
	if (m) {
		if ((i >= 1 && i <= m->n) && (j >= 1 && j <= m->n)) {
			return m->registers[i-1] == m->registers[j-1];
		}
	}
	
	return 0;
}

