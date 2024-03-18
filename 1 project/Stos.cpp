#include "Stos.h"
#include <iostream>

element::element(int var)
	:liczba(var), nastepny(nullptr) {}

stos::stos()
	: top(nullptr) {}

void stos::dodawanie(int wartosc)
{
	element* newNode = new element(wartosc);
	newNode->nastepny = top;
	top = newNode;
}

void stos::usuwanie()
{
	if (top != nullptr) {
			element* temp = top;
			top = top->nastepny;
			delete temp;
		}
	else {
	std::cerr << "Stos jest pusty. Nie mozna usunac elementu.\n";
		}
}
int stos::topValue() const {
	if (top != nullptr) {
		return top->liczba;
	}
	else {
		std::cerr << "Stos jest pusty. Brak wartosci na wierzchu.\n";
		return -1; // Wartosc oznaczajaca b?ad lub pusty stos
	}
}
bool stos::empty() {

	if (top == nullptr)
		return true;
	else
		return false;
}