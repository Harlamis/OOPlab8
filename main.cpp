#include "Queue.h"
#include "stack.h"
#include <iostream>



//void test() {
//	try {
//		
//	catch (const std::exception& e) {
//		std::cerr << "Exception: " << e.what() << "\n";
//	}
//};


int main() {
	Stack<std::string> st;
	st.push("I");
	st.push("Hate");
	st.push("C++");
	st.pop();
	std::cout << "Stack top: " << st.peek() << "\n";

	QueueR<std::string> qr(4);
	qr.enqueue("I");
	qr.enqueue("Hate");
	qr.enqueue("C++");
	qr.dequeue();
	std::cout << "QueueR front: " << qr.peek() << "\n";

	QueueC<std::string> qc(4);
	qc.enqueue("I");
	qc.enqueue("Hate");
	qc.enqueue("C++");
	qc.dequeue();
	std::cout << "QueueC front: " << qc.peek() << "\n";


	return 0;
};