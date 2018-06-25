#ifndef LOG_H_
#define LOG_H_

#include <stdio.h>

#define LOG_PRINT(...) printf(__VA_ARGS__)

//#define DEBUG

#ifdef DEBUG
#define DEBUG_PRINT(...) printf("debug-info : " __VA_ARGS__)
#else
#define DEBUG_PRINT(...)
#endif

#endif