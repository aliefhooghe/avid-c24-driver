#include <string.h>
#include "queue.h"

// Lock free queue implementation

struct queue
{
	unsigned char *data;
	size_t capacity;
	size_t element_size;
	unsigned int enqueue_cursor;
	unsigned int dequeue_cursor;
};

struct queue *queue_new(const size_t capacity, const size_t element_size)
{
	struct queue *queue = NULL;

	if (capacity < 2 || element_size == 0)
		return NULL;

	if ((queue = malloc(sizeof(struct queue))) == NULL)
		return NULL;

	if ((queue->data = malloc(capacity * element_size)) == NULL)
	{
		free(queue);
		return NULL;
	}

	queue->capacity = capacity;
	queue->element_size = element_size;
	queue->enqueue_cursor = 1;
	queue->dequeue_cursor = 0;

	return queue;
}

int queue_delete(struct queue *queue)
{
	free(queue->data);
	free(queue);
	return 0;
}

int queue_dequeue(struct queue *queue, void *dest)
{
	const unsigned int next_dequeue_cursor = (queue->dequeue_cursor + 1)
			% queue->capacity;

	if (next_dequeue_cursor == queue->enqueue_cursor) // queue is empty
		return -1;

	queue->dequeue_cursor = next_dequeue_cursor;
	memcpy(dest, queue->data + queue->element_size * next_dequeue_cursor,
			queue->element_size);

	return 0;
}

int queue_enqueue(struct queue *queue, const void *src)
{
	if (queue->dequeue_cursor == queue->enqueue_cursor) // queue is full
		return -1;

	const unsigned int next_enqueue_cursor = (queue->enqueue_cursor + 1)
			% queue->capacity;

	memcpy(queue->data + queue->element_size * queue->enqueue_cursor, src,
			queue->element_size);
	queue->enqueue_cursor = next_enqueue_cursor;
	return 0;
}

size_t queue_get_element_count(const struct queue *queue)
{
	if (queue->enqueue_cursor > queue->dequeue_cursor)
		return (queue->enqueue_cursor - queue->dequeue_cursor) - 1;
	else
		return (queue->capacity - queue->dequeue_cursor) + queue->enqueue_cursor;
}

size_t queue_get_capacity(const struct queue *queue)
{
	return queue->capacity;
}
