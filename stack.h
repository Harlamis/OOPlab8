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