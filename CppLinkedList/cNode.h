#pragma once

#ifndef cNode_h
#define cNode_h

template <class T>
class Node
{
private:
	T Val;
	Node<T>* nNext, * nPrev;

public:
	Node<T>(T item)
	{
		nNext = nPrev = nullptr;
		Val = item;
	}
	Node<T>(Node<T>*, T);

	T GetData() { return Val; };
	Node<T>* Next() { return nNext ? nNext :  nullptr; };
	Node<T>* Prev() { return nPrev ? nPrev :  nullptr; };

	void setVal(T val) { Val = val; };
	void setPrev(Node<T>* nodePrev) { nPrev = nodePrev; };
	void setNext(Node<T>* nodeNext) { nNext = nodeNext; };

	void Swap(Node<T>&);
	Node<T>* pop();
};

template <class T>
Node<T>::Node(Node<T>*  Prev, T item)
{
	Prev->setNext(this);
	nNext = nullptr;
	nPrev = Prev;
	Val = item;
};


template <class T>
void Node<T>::Swap(Node<T>& node2)
{
	if (this && node2)
	{
		T valtmp = Val;
		Val = node2.GetData();
		node2.setVal(valtmp);
	}
}

template<class T>
Node<T>* Node<T>::pop()
{
	if (nPrev && nNext)
	{
		nPrev->setNext(nNext);
		nNext->setPrev(nPrev);
	}
	if (this)
		return this;
};


#endif