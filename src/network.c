
#include <stdlib.h>

#include "network.h"
#include "log.h"

int recvfrom_with_timeout(
	int sock,
	void * const buffer,
	const size_t len,
	struct sockaddr_ll *addr,
	struct timeval *timeout)
{
	socklen_t recv_addr_len = sizeof(struct sockaddr_ll);
	fd_set sock_set;

	FD_ZERO(&sock_set);
	FD_SET(sock, &sock_set);

	const int ret = select(sock + 1, &sock_set, NULL, NULL, timeout);

	if (ret <= 0)
	{     //  error or timeout
		return ret;
	}
	else
	{
		return recvfrom(sock, buffer, len, 0, (struct sockaddr*) addr,
				&recv_addr_len);
	}
}
