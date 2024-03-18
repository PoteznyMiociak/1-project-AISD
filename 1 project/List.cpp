#include "List.h"
#include <iostream>
using namespace std;

void List::PrintList(element* first) const
{
	element* tmp = first;
	while (tmp != nullptr)
	{
		cout << tmp->liczba;
		tmp = tmp->nastepny;
	}
}

int List::GetListLen(element* first) const
{
	int index = 0;
	element* tmp = first;
	while (tmp != nullptr)
	{
		index += 1;
		tmp = tmp->nastepny;
	}
	return index;
}

//void List::AddFirst(element* first, element* nowy) {
//	nowy->nastepny = first;
//}
element* List::AddLast(element* first, element* nowy)
{
	nowy->nastepny = nullptr;
	if (first == nullptr)
		return nowy;
	element* tmp = first;
	while (tmp != nullptr)
		tmp = tmp->nastepny;
	tmp->nastepny = nowy;
	return first;
}

element* List::RemoveFirst(element* first)
{
	if (first == nullptr)
		return nullptr;
	return first->nastepny;
}