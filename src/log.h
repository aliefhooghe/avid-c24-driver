#ifndef LOG_H_
#define LOG_H_

#include <stdio.h>

#define LOG_PRINT(...) printf("[C24 driver log]\t" __VA_ARGS__)

//#define DEBUG

#ifdef DEBUG
#define DEBUG_PRINT(...) printf("[C24 driver debug-info]\t" __VA_ARGS__)
#else
#define DEBUG_PRINT(...)
#endif

#endif
