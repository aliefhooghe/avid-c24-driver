#include "utility.h"

void print_hw_address(const uint8_t addr[])
{
	for (unsigned int i = 0; i < 5; i++)
		printf("%02x:", addr[i]);
	printf("%02x", addr[5]);
}

int hw_adress_cmp(const uint8_t addr1[], const uint8_t addr2[])
{
	return memcmp(addr1, addr2, 6);
}
