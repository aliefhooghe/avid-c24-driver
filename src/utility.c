#include "utility.h"


int hw_adress_cmp(const uint8_t addr1[], const uint8_t addr2[])
{
	return memcmp(addr1, addr2, 6);
}
