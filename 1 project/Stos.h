#pragma once

class element {
public:
	int liczba;
	element* nastepny;
	element(int wartosc);
};


class stos {
	private:
		element* top;
	public:
		stos();
		void dodawanie(int wartosc);
		void usuwanie();
		int topValue() const;
		bool empty();
};