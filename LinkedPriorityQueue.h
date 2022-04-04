#pragma once
#include "PriorityNode.h"

template <typename T>
class LinkedPriorityQueue
{
private:
	PriorityNode <T>* FrontPtr;
	PriorityNode <T>* BackPtr;
public:
	LinkedPriorityQueue();
	bool IsEmpty() const;
	bool Enqueue(const T& newEntry, int p);
	bool Dequeue(T& frntEntry);
	bool Peek(T& frntEntry) const;
};

template < typename T>
LinkedPriorityQueue<T>::LinkedPriorityQueue()
{
	FrontPtr = BackPtr = nullptr;
}

template < typename T>
bool LinkedPriorityQueue<T>::IsEmpty() const
{
	return(FrontPtr == nullptr);
}

template < typename T>
bool LinkedPriorityQueue<T>::Enqueue(const T& newEntry, int p)
{
	PriorityNode<T>* NewNode = new PriorityNode<T>(newEntry, p);

	if (IsEmpty() || p > FrontPtr->GetPriority())
	{
		NewNode->SetNext(FrontPtr);
		FrontPtr = NewNode;
		return true;
	}

	PriorityNode<T>* ptr = FrontPtr;
	while (ptr->GetNext() && ptr->GetNext()->GetPriority() >= p)
	{
		ptr = ptr->GetNext();
	}
	NewNode->SetNext(ptr->GetNext());
	ptr->SetNext(NewNode);
	return true;
}

template < typename T>
bool LinkedPriorityQueue<T>::Dequeue(T& frntEntry)
{
	if (IsEmpty())
		return false;

	PriorityNode<T>* nodeToDeletePtr = FrontPtr;
	frntEntry = FrontPtr->GetItem();
	FrontPtr = FrontPtr->GetNext();

	if (nodeToDeletePtr == BackPtr)
	{
		BackPtr = nullptr;
	}
	delete nodeToDeletePtr;
	return true;
}

template < typename T>
bool LinkedPriorityQueue<T>::Peek(T& frntEntry) const
{
	if (IsEmpty())
		return false;

	frntEntry = FrontPtr->GetItem();
	return true;

}