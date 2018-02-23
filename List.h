#pragma once

#include "Node.h"

#include <iostream>

using namespace std;

template <typename T>
class List {

public:

	List();
	List(const List& source);
	List(List&& source);
	//~List();

	//List& operator=(const List& source);
	//List& operator=(List&& source);

	void AddFirst(const T item);
	void AddLast(const T item);
	//void Clear();
	unsigned int GetSize() const;
	void Print() const;
	bool RemoveFirst(const T item);
	bool RemoveLast(const T item);


private:

	unsigned int size;
	Node<T>* head;

};

template<typename T>
inline List<T>::List()
{
	size = 0;
	head = nullptr;
}

template<typename T>
inline List<T>::List(const List & source) :
	List(source.head, source.size)
{
}

template<typename T>
inline List<T>::List(List && source) :
	head(move(source.head)),
	size(move(source.size))
{
	head = nullptr;
	size = 0;
}

template<typename T>
inline void List<T>::AddFirst(const T item)
{

	Node<T>* node = new Node<T>(item);
	Node<T>* current = head;
	Node<T>* tmp = head;

	while (current->GetNext() != nullptr) {

		current = current->GetNext();

	}

	head = node;
	head->SetNext(tmp);

	size++;

}

template<typename T>
inline void List<T>::AddLast(const T item)
{
	Node<T>* node = new Node<T>(item);
	
	if (head == nullptr) {

		head = node;
	
	} else {

		Node<T>* last = head;
		while (last->GetNext() != nullptr) {

			last = last->GetNext();

		}
		last->SetNext(node);
	}

	size++;

}

template<typename T>
inline unsigned int List<T>::GetSize() const
{
	return size;
}

template<typename T>
inline void List<T>::Print() const
{

	Node<T>* node = head;
	while (node != nullptr) {

		cout << node->GetItem() << " | ";

		node = node->GetNext();
	}
	cout << endl;

}

template<typename T>
inline bool List<T>::RemoveFirst(const T item)
{

	Node<T>* previous = nullptr;
	Node<T>* current = head;

	while (current != nullptr && current->GetItem() != item) {

		previous = current;
		current = current->GetNext();
	}

	bool removed = current != nullptr;
	if (removed) {

		if (previous == nullptr) {
			head = current->GetNext();
		} else {
			previous->SetNext(current->GetNext());
		}
		delete current;
	}

	return removed;
}

template<typename T>
inline bool List<T>::RemoveLast(const T item)
{

	Node<T>* previous = nullptr;
	Node<T>* current = head;

	while (current != nullptr && current->GetItem() == item) {

		previous = current;
		current = current->GetNext();

	}

	bool removed = current != nullptr;
	if (removed) {

		if (previous == nullptr) {
			head = current->GetNext();
		}
		else {
			previous->Setnext(current->GetNext());
		}

		delete current;
	}
	return removed;

}
