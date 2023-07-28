
#ifndef __SEA_MAIN_H
#define __SEA_MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

int sea_init(const char* mueller, int hex);

int sea_order(void* q, void* p, void* a, void* b, int len);

int sea_clear();

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* __SEA_MAIN_H */
