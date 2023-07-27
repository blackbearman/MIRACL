#ifndef __SEA_MUELLER_H
#define __SEA_MUELLER_H

#include "big.h"

int mueller_main(int skip, const char* filename, int start, int end);

Big le2big(void* src, size_t len);

int process_main(Big p, const char* in, const char* out);

#endif /* __SEA_MUELLER_H */