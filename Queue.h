#pragma once
#include <memory>
#include <stdexcept>
#include <iostream>
template<typename T>

class QueueR
{
private:
	T* arr;
	int rear;
	int front;
	int capacity;
public:
	QueueR(int cap) : capacity{ cap }, front{ -1 }, rear{ -1 } {
		arr = new T[capacity];
	};
	~QueueR() { delete[] arr; };
	void enqueue(const T& value) {
		if (isFull()) {
			throw std::overflow_error("Queue is Full!!!");
		}
		if (front == -1) front = 0;
		rear++;
		arr[rear] = value;
		std::cout << "Enqueued: " << value << "\n";
	}
	void dequeue() {
		if (isEmpty()) {
			throw std::underflow_error("Queue is empty!!!");
		}
		front++;
		if (front > rear) {
			front = -1;
			rear = -1;
		}
	}
	bool isEmpty() {
		return front > rear;
	};
	bool isFull() {
		return rear == capacity - 1;
	};
	T& peek() {
		if (isEmpty()) {
			throw std::underflow_error("Queue is Empty!!!");
		}
		std::cout << "Peek called, front index: " << front << "\n"; // DEBUG
		return arr[front];
	}
};

template<typename T>
class QueueC
{
private:
	T* arr;
	int rear;
	int front;
	int size;
	int capacity;
public:
	QueueC(int cap) : capacity{ cap }, front{ 0 }, rear{ capacity - 1 } {
		arr = new T[capacity];
	};
	~QueueC() { delete[] arr; };
	void enqueue(const T& value) {
		if (isFull()) {
			throw std::overflow_error("Queue is Full!!!");
	}
		rear = (rear + 1) % capacity;
		arr[rear] = value;
		++size;
	};
	void dequeue() {
		if (isEmpty()) {
			throw std::underflow_error("Queue is empty!!!");
		}
		front = (front + 1) % capacity;
		--size;
	};
	bool isEmpty() {
		if (size == 0) {
			return true;
	}
		return false;
	};
	bool isFull() {
		if (size == capacity) {
			return true;
		}
		return false;
	};
	T& peek() {
		if (isEmpty()) {
			throw std::underflow_error("Queue is Empty!!!");
		}
		return arr[front];
	};
	int getSize() { return size; };
};

