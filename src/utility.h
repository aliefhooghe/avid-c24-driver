#ifndef UTILITY_H_
#define UTILITY_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "network.h"

void print_hw_address(const uint8_t addr[]);
int hw_adress_cmp(const uint8_t addr1[], const uint8_t addr2[]);

#endif
