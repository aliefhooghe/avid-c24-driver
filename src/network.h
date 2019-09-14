#ifndef NETWORK_H_
#define NETWORK_H_

#include <sys/socket.h>

#include <netpacket/packet.h>
#include <net/if.h>
#include <arpa/inet.h>
#include <net/ethernet.h>
#include <netinet/if_ether.h>

#include <sys/select.h>

int recvfrom_with_timeout(
	int sock,
	void * const buffer,
	const size_t len,
	struct sockaddr_ll *addr,
	struct timeval *timeout,
	size_t *size);

#endif
