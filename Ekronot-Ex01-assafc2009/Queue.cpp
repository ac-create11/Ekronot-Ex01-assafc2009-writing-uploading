#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

void initQueue(Queue* q, unsigned int size)//אתחול התור
{//טוב

	//q->queue = (int*)malloc(size * sizeof(int));
	q->queue = new int[size];
	if (q->queue == nullptr)
	{
		return;
	}

	q->first = 0;
	q->last = 0;
	q->count = 0;
	q->capacity = size;

}

void cleanQueue(Queue* q)//cleans the queue (deletes it)
{
	while (q->queue != nullptr) //checks if queue is NULL or not - means that deleting it is needed
	{
		//free(q->queue);//שחרור/מחיקת התור

		delete[] q->queue;//שחרור/מחיקת התור
		q->queue = nullptr; // איפוס מיד לאחר השחרור
	}
}

bool isEmpty(Queue* s)//good
{
	//if (s->last == s->first)
	if (s->count==0)
	{
		return true;
	}

	return false;
}

bool isFull(Queue* s)//טוב
{
	//if ((s->last - 1) % (s->capacity) == s->first)
	//if (s->last == s->capacity)//
	if(s->count==s->capacity)
	{
		return true;
	}

	return false;
}

void enqueue(Queue* q, unsigned int newValue)
{
	if (not(isFull(q)))
	{
		q->queue[q->last] = newValue;//
		//q->last = q->last + 1;//
		q->last=(q->last+1)%q->capacity;
		q->count = q->count+1;//
	}
}


int dequeue(Queue* q) // return element in top of queue, or -1 if empty
{
	int save = 0;
	if (not(isEmpty(q)))
	{
		save = q->queue[q->first];//"deleting"
		//need to delete first!
		q->first=(q->first+1)%q->capacity;
		q->count = q->count-1;//
		//return q->queue[q->first];//
		return save;
	}

	return -1;//empty queue
}


