#pragma once
#include "Node.h"


template <typename T>
class PriorityQueue
{
private:
	Node<T>* frontPtr;
	Node<T>* backPtr;
public:
	PriorityQueue();
	bool isEmpty() const;
	bool enqueue(const T& newEntry);
	bool dequeue(T& frntEntry);
	bool peekFront(T& frntEntry)  const;
	~PriorityQueue();
};


// TODO: copy constructor
template<typename T>
PriorityQueue<T>::PriorityQueue() :frontPtr(NULL), backPtr(NULL)
{
}

/*
	Checks whether the priority queue is empty or not
	@pre none
	@post none
	@param none
	@return true if the PriorityQueue is empty, false otherwise
*/

template <class T>
bool PriorityQueue<T>::isEmpty() const
{
	return (frontPtr == NULL);
}

/*
	Inserts an element into the priority queue according to it's priority (sorted)
	@pre none
	@post An element is added in the priority queue according to the priority
	@param The element to be added
	@return Returns true if the element is added successfully, false otherwise
*/

template <class T>
bool PriorityQueue<T>::enqueue(const T& newEntry)
{
	Node<T>* tempPtr;
	tempPtr = new Node<T>(newEntry);
	if (!tempPtr)
		return false;

	if (this->isEmpty())
		frontPtr = backPtr = tempPtr;
	else
	{
		Node<T>* l_ptr;
		Node<T>* r_ptr;

		if (newEntry < frontPtr->getItem()) // checks if the element is to be inserted in the front
		{
			tempPtr->setNext(frontPtr);
			frontPtr = tempPtr;
			return true;
		}

		l_ptr = frontPtr;
		r_ptr = frontPtr->getNext();

		while (r_ptr) // loops until next element is bigger
		{
			if (newEntry > r_ptr->getItem())
				break;
			l_ptr = l_ptr->getNext();
			r_ptr = r_ptr->getNext();
		}
		tempPtr->setNext(r_ptr);
		l_ptr->setNext(tempPtr);

		if (backPtr == l_ptr) //if the element is inserted in the back, then update the back
			backPtr = l_ptr->getNext();
	}

	return true;
}

/*
	Removes an element from the front of the queue
	@pre PriorityQueue is not empty
	@post An element is removed from the front of the queue
		  and it is returned as a parameter
	@param Dummy variable to return the element removed in it
	@return True if the element is removed successfully, false otherwise

*/

template <class T>
bool PriorityQueue<T>::dequeue(T& frntEntry)
{
	if (this->isEmpty())
		return false;
	frntEntry = frontPtr->getItem();

	if (frontPtr == backPtr) // if there is a single element in the queue, change the back to null
		backPtr = backPtr->getNext();

	frontPtr = frontPtr->getNext();
	return true;
}

/*
	Returns the element in the front of the queue
	@pre The PriorityQueue is not empty
	@post none
	@param Dummy variable to return the element in
	@return true if the element is returned successfully
			false if the queue is empty (element not returned) 
*/

template <class T>
bool PriorityQueue<T>::peekFront(T& frntEntry) const
{
	if (this->isEmpty())
		return false;
	frntEntry = frontPtr->getItem();
	return true;
}


// Destructor, deletes all nodes

template<typename T>
PriorityQueue<T>::~PriorityQueue()
{
	Node<T>* toBeDeleted;
	while (frontPtr)
	{
		toBeDeleted = frontPtr;
		frontPtr = frontPtr->getNext();

		toBeDeleted->setNext(NULL);
		delete toBeDeleted;
	}

	toBeDeleted = NULL;
	frontPtr = NULL;
	backPtr = NULL;
}


