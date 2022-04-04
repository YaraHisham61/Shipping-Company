#pragma once
#include "Node.h"
template <typename T>
class queuelist
{
private:

	Node<T>* backPtr;
	Node<T>* frontPtr;
public:
	//LinkedQueue();
	//LinkedQueue(const LinkedQueue& aQueue);
	//~LinkedQueue() {



	//}
	bool isEmpty() const{ return (frontPtr == nullptr); }
	bool enqueue(const T&  newEntry)
	{
		Node<T>* newNodePtr = new Node<T>(newEntry);
		// Insert the new node 
		if (isEmpty())
			frontPtr = newNodePtr; // The queue was empty 
		else
			backPtr->setNext(newNodePtr); // The queue was not empty 
		backPtr = newNodePtr; // New node is at back 
		return true; }
	bool dequeue() {

		bool result = false;
		if (!isEmpty())
		{
			// Queue is not empty; remove front 
			Node<T>* nodeToDeletePtr = frontPtr;
			if (frontPtr == backPtr)
			{ // Special case: one node in queue 
				frontPtr = nullptr;
				backPtr = nullptr;
			}
			else
				frontPtr = frontPtr->getNext();
			// Return deleted node to system 
			nodeToDeletePtr->setNext(nullptr);
			delete nodeToDeletePtr;
			nodeToDeletePtr = nullptr;
			result = true;
		} // end if 
		return result;
	}
}; // end LinkedQueue

