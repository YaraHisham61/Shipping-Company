#pragma once
template<typename T>

class PriorityNode
{
private:
	int Priority;
	T Item;
	PriorityNode<T>* Next;

public:
	PriorityNode();
	PriorityNode(const T& r_Item);
	PriorityNode(const T& r_Item, int p, PriorityNode<T>* nextNodePtr = nullptr);
	void SetPriority(int p);
	int GetPriority() const;
	void SetItem(const T& r_Item);
	T GetItem() const;
	void SetNext(PriorityNode<T>* nextNodePtr);
	PriorityNode<T>* GetNext() const;
};

template < typename T>
PriorityNode<T>::PriorityNode()
{
	Next = nullptr;
}

template < typename T>
PriorityNode<T>::PriorityNode(const T& r_Item)
{
	Item = r_Item;
	next = nullptr;
}

template < typename T>
PriorityNode<T>::PriorityNode(const T& r_Item, int p, PriorityNode<T>* nextNodePtr)
{
	Item = r_Item;
	Priority = p;
	Next = nextNodePtr;
}

template < typename T>
void PriorityNode<T>::SetPriority(int p)
{
	Priority = p;
}

template < typename T>
int PriorityNode<T>::GetPriority() const
{
	return Priority;
}

template < typename T>
void PriorityNode<T>::SetItem(const T& r_Item)
{
	Item = r_Item;
}

template < typename T>
T PriorityNode<T>::GetItem() const
{
	return Item;
}

template < typename T>
void PriorityNode<T>::SetNext(PriorityNode<T>* nextNodePtr)
{
	Next = nextNodePtr;
}

template < typename T>
PriorityNode<T>* PriorityNode<T>::GetNext() const
{
	return Next;
}