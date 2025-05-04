#pragma once
#include <memory>
namespace sNode {
	template <typename T>
	struct Snode {
		T data;
		std::unique_ptr<Snode<T>> nextNode;
		Snode(const T& value) : data{ value }, nextNode{ nullptr } {};
	};
}
