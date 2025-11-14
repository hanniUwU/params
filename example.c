#include <stdio.h>

// begin: define parameters
typedef char* char_ptr;
#define XPARAMS(X)               \
    X(HAPPINESS, uint32_t, 4)   \
    X(SADNESS  , double  , 2) \
    X(CUTENESS , char_ptr, UWU)  \

#include "params.h"
// end: define parameters

int main(int argc, char** argv) {

	Parameters* par = parameters_read();

	printf("The number of parameters is %zu\n", par->count);
	printf("HAPPINESS = %u\n", par->HAPPINESS);
	printf("SADNESS   = %f\n", par->SADNESS);
	printf("CUTENESS  = %s\n", par->CUTENESS);

	for (uint32_t i = 0; i < par->HAPPINESS; i++) {
		printf(":> ");
		if (par->SADNESS > 0.1) {
			printf(":( ");
		}
		if (!strcmp(par->CUTENESS, "UWU")) {
			printf(":3\n");
		}
	}

	parameters_free(par);

	return 0;
}

