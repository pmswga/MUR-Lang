#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "mnr.h"
#define DEBUG_MODE 1


void main(int argc, char **argv)
{
	struct mnr *m = init(10);

	S(m, 1);
	S(m, 1);
	S(m, 1);
	T(m, 1, 2);
	S(m, 2);
	printf("%d", J(m, 1, 2));

	#if DEBUG_MODE
		for (int i = 0; i < m->n; i++) {
			printf("Register[%d] = %d\n", i, m->registers[i]);
		}
	#endif

	terminate(m);
}
