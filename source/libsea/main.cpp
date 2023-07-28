#include "main.h"
#include "mueller.h"
#include "sea.h"

#include <string>

static struct {
    std::string mueller;
    std::string processed;
    std::string result;
    bool hex;
} _main;

int sea_init(const char* mueller, int hex)
{
    _main.mueller = std::string(mueller);
    _main.processed = _main.mueller + ".o";
    _main.result = _main.mueller + ".x";
    _main.hex = (bool)hex;
    return 0;
}

int sea_order(void* q, void* p, void* a, void* b, int len)
{
    miracl *mip;
    mip=mirsys(10000,0);
    mip->IOBASE=16;
    Big P = le2big(p, len);
    process_main(P, _main.mueller.c_str(), _main.processed.c_str(), _main.hex);
    mirexit();

    mip=mirsys(18,0);
    mip->IOBASE=16;
    Big A = le2big(a, len);
    Big B = le2big(b, len);
    sea_main(A, B, _main.processed.c_str(), _main.result.c_str());
    mirexit();
    return 0;
}

int sea_clear() 
{
    return 0;
}