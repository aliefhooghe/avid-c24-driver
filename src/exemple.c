#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include <unistd.h>

#include <c24_surface.h>


static void button_event_callback(
	void *user_data,
	const uint16_t button,
	const uint8_t state)
{
	printf("Received button event : button : 0x%x ~ '%s', state = %u\n", 
		button, c24_surface_get_button_name(button), state);

	const unsigned int track = 
		c24_button_track(button);

	if (track < C24_TRACK_COUNT) {
		printf("This button is on track %u\n", track);

		if ( button == c24_button_select(track))
		printf("Button is select\n");

		if ( button == c24_button_solo(track))
			printf("Button is solo\n");

		if ( button == c24_button_mute(track))
			printf("Button is mute\n");
	}
	else
		printf("This button is not on a track\n");

	if (c24_button_is_slider(button)) {
		
		if (track >=  C24_TRACK_COUNT)
		{
			printf("################## ERROR :  slider not on a track !!\n");
			return;
		}

		if ( button != c24_button_slider(track))
		{
			printf("################## ERROR :  button != slider_track(track) == %x\n", 
				c24_button_slider(track));
			return;
		}

		printf("Button is a slider\n");
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
	printf("Received knob rotate event : knob = %x ~ '%s', state = %02x\n", 
		knob, c24_surface_get_knob_name(knob), state);
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

	while(1) {
		continue;
		for (unsigned int i = 0; i < 24; i++) {
			c24_surface_set_slider_pos(surface, i, 512 * (1.0 + sin(2.0 * 3.14 * (t + (float)i/24.0))));
		}

		t += 0.01;
		usleep(10000);
	}

	c24_surface_close(surface);

	return 0;
}
