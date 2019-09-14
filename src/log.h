#ifndef LOG_H_
#define LOG_H_

#include <stdio.h>

#define LOG_PRINT(...) printf("[log            ]\t" __VA_ARGS__);

#ifdef VERBOSE
#define VERBOSE_PRINT(...) printf("[log  :  verbose]\t" __VA_ARGS__)
#else
#define VERBOSE_PRINT(...)
#endif

#endif
