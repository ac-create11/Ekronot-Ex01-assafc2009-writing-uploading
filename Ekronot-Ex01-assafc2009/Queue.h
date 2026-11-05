#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* a queue contains positive integer values. */
typedef struct Queue
{
	int* queue;
	int first;
	int last;//אני מתייחס לזה כאיבר הבא בתור הפנוי במערך 
	int capacity;
	int count;//counts how many filled spaces in queue there are
} Queue;

void initQueue(Queue* q, unsigned int size);
void cleanQueue(Queue* q);

void enqueue(Queue* q, unsigned int newValue);
int dequeue(Queue* q); // return element in top of queue, or -1 if empty

bool isEmpty(Queue* s);
bool isFull(Queue* s);

#endif /* QUEUE_H */