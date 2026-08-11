// Trees.h : Include file for standard system include files,
// or project specific include files.

#pragma once
#include <iostream>
using namespace std;


struct TreeNode {
	int data;
	TreeNode* left;
	TreeNode* right;
};

struct Queue {
	int size;
	int front;
	int rear;
	TreeNode** Q;
};

void create(Queue* q, int size)
{
	q->size = size;
	q->front = q->rear = 0;
	q->Q  = new TreeNode*[q->size];
}

void enqueue(Queue* q, TreeNode* x)
{
	if ((q->rear + 1) % q->size == q->front)
		cout << "Queue is full" << endl;
	else
	{
		q->rear = (q->rear + 1) % q->size;
		q->Q[q->rear] = x;
	}
}

TreeNode* dequeue(Queue* q)
{
	TreeNode* x = nullptr;
	if (q->front == q->rear)
		cout << "Queue is empty" << endl;
	else
	{
		q->front = (q->front + 1) % q->size;
		x = q->Q[q->front];
	}
	return x;
}

int isEmpty(Queue* q)
{
	return q->front == q->rear;
}


// TODO: Reference additional headers your program requires here.
