#ifndef QUEUE_H_
#define QUEUE_H_

#include <stdlib.h>

struct queue;

struct queue *queue_new(const size_t capacity, const size_t element_size);
int queue_delete(struct queue *queue);

int queue_dequeue(struct queue *queue, void *dest);
int queue_enqueue(struct queue *queue, const void *src);

size_t queue_get_element_count(const struct queue *queue);
size_t queue_get_capacity(const struct queue *queue);

#endif
