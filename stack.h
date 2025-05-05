#pragma once
#include "node.h"
#include <stdexcept>
#include <memory>

template <typename T>
class Stack {
	std::unique_ptr<sNode::Snode<T>> head;
public:
	Stack() : head{ nullptr } {};
	bool isEmpty() {
		return head == nullptr;
	};
	void push(const T& value) {
		auto newNode = std::make_unique<sNode::Snode<T>>(value);
			if (!newNode) {
				throw std::overflow_error("Worng value entered!!!");
			}
			newNode->nextNode = std::move(head);
			head = std::move(newNode);
	}
	void pop() {
		if (isEmpty()) {
			throw std::underflow_error("Stack is empty!!!");
			return;
		}
		head = std::move(head->nextNode);
	}
	T peek() {
		if (isEmpty()) {
			throw std::underflow_error("Stack is empty");
		}
		return head->data;
	}

};
template <typename T>
class StackR {
private:
    T* arr;
    int top;
    int capacity;

public:
    StackR(int cap = 100) : capacity(cap), top(-1) {
        arr = new T[capacity];
    }

    ~StackR() {
        delete[] arr;
    }

    void push(const T& value) {
        if (isFull()) {
            throw std::overflow_error("stack is full");
        }
        arr[++top] = value;
    }

    void pop() {
        if (isEmpty()) {
            throw std::underflow_error("stack is empty");
        }
        --top;
    }

    T& peek() {
        if (isEmpty()) {
            throw std::underflow_error("Stack is empty");
        }
        return arr[top];
    }

    bool isEmpty() const {
        return top == -1;
    }

    bool isFull() const {
        return top == capacity - 1;
    }

    int getSize() const {
        return top + 1;
    }
};