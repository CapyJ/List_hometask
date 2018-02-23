#pragma once

template <typename T>
class Node {

public:

	Node(T item) :
		item(item)
	{
	}

	Node* GetNext() const {
		return next;
	}

	T GetItem() const {
		return item;
	}

	void SetNext(Node* const next) {
		this->next = next;
	}

private:

	Node* next = nullptr;
	T item;

};