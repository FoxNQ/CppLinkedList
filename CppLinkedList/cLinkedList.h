#pragma once

#ifndef cLinkedList_h
#define cLinkedList_h

#include <list>
#include <string>
#include "cNode.h"

template <class T>
class LinkedList
{
private:
	Node<T>* nHead;
	Node<T>* nTail;
	int nSize;
	bool bSorted;
public:
	LinkedList();
	~LinkedList();

	Node<T>* nodeHead() { return nHead; };

	T* get_Front();
	T* get_Back();
	T* pop_Back();

	void push(T);
	void push_Sort(T);

	int Size() { return nSize; };

};

template <class T>
LinkedList<T>::LinkedList()
{
	nHead = nTail = nullptr;
	nSize = 0;
	bSorted = false;
};

template <class T>
LinkedList<T>::~LinkedList()
{
	Node<T>* nMain = nHead;
	Node<T>* nTmp;
	{
		nTmp = nMain;
		nMain = nTmp->Next();
		delete[] nTmp;
	}
};

template <class T>
void LinkedList<T>::push(T Val)
{
	bSorted = false;
	nSize++;
	Node<T>* n2 = nullptr;
	Node<T>* ntemp = nullptr;
	if (!nHead)
	{
		nHead = new Node<T>(Val);
		nTail = nHead;
		return;
	}
	else
		ntemp = nTail;
	n2 = new Node<T>(ntemp, Val);
	nTail = n2;
};

template <class T>
void LinkedList<T>::push_Sort(T Val)
{
	bSorted = true;
	nSize++;
	Node<T>* nX = nullptr;
	Node<T>* ntemp = nullptr;
	if (!nHead)
	{
		nHead = new Node<T>(Val);
		nTail = nHead;
		return;
	}
	else
	{
		Node<T>* nPrev = nullptr;
		ntemp = nHead;
		while (ntemp!=nTail)
		{
			if (ntemp && ntemp->GetData() > Val)
			{
				nX = new Node<T>(Val);

				nX->setNext(ntemp);
				if (ntemp->Prev())
				{
					nPrev = ntemp->Prev();
					nX->setPrev(nPrev);
					nPrev->setNext(nX);
					ntemp->setPrev(nX);
				}
				else
				{
					nHead = nX;
				}
				return;
			}

			if(ntemp->Next())
				ntemp = ntemp->Next();
		}
		nX = new Node<T>(ntemp, Val);
		nTail = nX;
	}
};

template <class T>
T* LinkedList<T>::get_Front()
{
	if (nHead)
	{
		return nHead->GetData();
	}
	else
		return NULL;
}

template <class T>
T* LinkedList<T>::get_Back()
{
	if (nTail)
	{
		return nTail->GetData();
	}
	else
		return NULL;
}

template <class T>
T* LinkedList<T>::pop_Back()
{
	if (nTail)
	{

		return nTail->GetData();
	}
	else
		return NULL;
}
#endif


