#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include <unistd.h>

#include <c24_surface.h>

int running = 1;

static void button_event_callback(
	void *user_data,
	const uint16_t button,
	const uint8_t state)
{
	printf("Received button event : button = %02x, state = %u\n", button, state);

	if (button == C24_STOP_BUTTON) {
		printf("Stop animation\n");
		running = 0;
	}
}

static void slider_move_callback(
	void *user_data,
	const uint8_t track_id,
	const uint16_t value)
{
	printf("Received slider move event : track_id = %u, value = %u\n", track_id, value);
}

static void knob_rotate_callback(
	void *user_data,
	const uint16_t knob,
	const uint8_t state)
{
	printf("Received knob rotate event : knob = %02x, state = %02x\n", knob, state);
}


int main(int argc, char **argv)
{
	struct c24_surface_t *surface = c24_surface_open(64);

	if (surface == NULL) {
		perror("surface open ");
		exit(1);
	}

	c24_surface_set_button_callback(surface, button_event_callback);
	c24_surface_set_slider_callback(surface, slider_move_callback);
	c24_surface_set_knob_callback(surface, knob_rotate_callback);

	c24_surface_print(surface, "Hello world !!!!!!!!!", 1, 0);

	float t = 0.0;

	while(running) {
		for (unsigned int i = 0; i < 24; i++) {
			c24_surface_set_slider_pos(surface, i, 512 * (1.0 + sin(2.0 * 3.14 * (t + (float)i/24.0))));
		}

		t += 0.001;
		usleep(1000);
	}

	c24_surface_close(surface);

	return 0;
}
