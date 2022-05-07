#include "cLinkedList.h"
#include <iostream>
#include <random>

int main()
{
	int length;

	LinkedList<int> list;

	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> Range{ 0,99999 };
	std::cout << "Input Length Of List: ";
	std::cin >> length;

	for (int i = 0;i<length;i++)
	{
		list.push_Sort(Range(mt));
	}


	Node<int>* ntemp = list.nodeHead();
	while (ntemp)
	{
		std::cout << ntemp->GetData() << "\n ";
		if (ntemp->Next())
		{
			ntemp = ntemp->Next();
		}
		else
			break;
	}
}