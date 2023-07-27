#include "bee2/core/hex.h"
#include "bee2/core/err.h"
#include "bee2/core/mem.h"
#include "bee2/crypto/bign.h"
#include <time.h>
#include "libsea/main.h"
#include <stdio.h>


void bignParamsPrint(const bign_params* params)
{
	char hex[1000];
	printf("params:\n");
	// печатать l
	printf("  l: %d\n", params->l);
	// печатать p
	hexFrom(hex, params->p, params->l / 4);
	printf("  p: 0x%s\n", hex);
	// печатать a
	hexFrom(hex, params->a, params->l / 4);
	printf("  a: 0x%s\n", hex);
	// печатать b
	hexFrom(hex, params->b, params->l / 4);
	printf("  b: 0x%s\n", hex);
	// печатать seed
	hexFrom(hex, params->seed, 8);
	printf("  seed: 0x%s\n", hex);
	// печатать yG
	hexFrom(hex, params->yG, params->l / 4);
	printf("  yG: 0x%s\n", hex);
	// печатать q
	hexFrom(hex, params->q, params->l / 4);
	printf("  q: 0x%s\n", hex);
}


// Call PARI ellcard function to calculate group order
err_t seaCard(bign_params* params) 
{
    err_t code = ERR_OK;
    int n = params->l / 4;
    int error;
    error = sea_order(params->q, params->p, params->a, params->b, n);
    switch(error) {
    case 0:  
        return ERR_OK;
        break;
    default:
        return ERR_BAD_PARAMS;
        break;
    }
}

int main() 
{
    err_t code;
    double sec; /* 10ms */
    clock_t before;
    bign_params params[1];
    size_t n;
	code = bignStdParams(params, "1.2.112.0.2.0.34.101.45.3.1");
    n = params->l / 4;
    sea_init("mueller.txt");
    before = clock();
    code = seaCard(params);
    clock_t difference = clock() - before;
    sec = (double)difference / CLOCKS_PER_SEC;
    printf("%lf sec\n", sec);
    bignParamsPrint(params);
    sea_clear();
    return 0;
}

//q = 07663D26_99BF5A7E_FC4DFB0D_D68E5CD9_FFFFFFFF_FFFFFFFF_FFFFFFFF_FFFFFFFF