#ifndef C24_HANDSHAKE_H_
#define C24_HANDSHAKE_H_

struct c24_surface_t;

int c24_surface_find(
	struct c24_surface_t *surface,
	c24_reconnection_callback_t callback);
int c24_surface_connect(struct c24_surface_t *surface);
int c24_surface_disconnect(
	struct c24_surface_t *surface,
	const unsigned int usec_timeout);

#endif
