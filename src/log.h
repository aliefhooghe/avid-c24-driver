#ifndef LOG_H_
#define LOG_H_

#include <stdio.h>

#define LOG_PRINT(...) printf("[C24 driver log]\t" __VA_ARGS__)

//#define DEBUG
#ifdef VERBOSE
#define VERBOSE_PRINT(...) printf("debug-info : " __VA_ARGS__)
#else
#define VERBOSE_PRINT(...)
#endif

#endif
