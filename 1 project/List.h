#pragma once
#include "Stos.h"

class List {
private:
	element* pierwszy;
public:
	void PrintList(element* first) const;
	int GetListLen(element* first) const;
	//void AddFirst(element* first, element* new_element);
	element* AddLast(element* first, element* new_element);
	element* RemoveFirst(element* first);

};