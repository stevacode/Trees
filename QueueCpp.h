#pragma once
#include <iostream>
using namespace std;

class Node {
public:
	Node* lchild;
	int data;
	Node* rchild;
};

class Queue{
private:
	int size;
	int front;
	int rear;
	Node** Q ;
public: 
	Queue() { front = rear = -1; size = 10; Q = new Node*[size]; }
	Queue(int size);
	~Queue();
	void enqueue(Node* x);
	Node* dequeue();
	void Display();
	bool isEmpty();

};

Queue::Queue(int size) {
	this->size = size;
	front = rear = 0;
	Q = new Node * [this->size];
}
Queue ::~Queue() {
	delete[] Q;
}



bool Queue::isEmpty() {
	return front == rear;
}

void Queue::enqueue(Node* x) {
	if ((rear + 1) % size == front)
		cout << "Queue is full" << endl;
	else
	{
		rear = (rear + 1) % size;
		Q[rear] = x;
	}
}

void Queue::Display() {
	int i = front + 1;
	do {
		cout << Q[i]->data << " ";
		i = (i + 1) % size;
	} while (i != (rear + 1) % size);
	cout << endl;
}

Node* Queue::dequeue() {
	Node* x = nullptr;
	if (front == rear)
		cout << "Queue is empty" << endl;
	else
	{
		front = (front + 1) % size;
		x = Q[front];
	}
	return x;
}
