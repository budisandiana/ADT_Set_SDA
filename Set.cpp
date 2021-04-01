#include <iostream>
#include "Set.h"
#include "SetITerator.h"


//Complexitate: theta(1)
Set::Set() {
	//TODO - Implementation
	memory = 100; //memorie
	array = new TElem[memory]; //array nou
	l = 0; //lungimea incepe de la 0 la inceput
	for (int i = 0; i < l; i++)
		array[i] = NULL_TELEM;
}

bool Set::add(TElem elem) {
	//TODO - Implementation
	//Complexitate: O(n), daca nu e gol
	for (int i = 0; i < l; i++) {
		if (l == memory) { //verificam daca mai este spatiu disponibil, altfel dublam memoria
			memory *= 2; //dublez memoria
			TElem* v = new TElem[memory]; //vector nou
			for (int j = 0; j < l; j++)
				v[j] = array[j]; //mutam din vectorul initial in cel nou
			delete[]array; //stergem vectorul initial
			array = v; //initializam
		}

		//cautam elemente in vector
		if (search(elem) == true) {
			return false;
		}
		else {
			array[l++] = elem;
		}
		return true;
	}

	//Complexitate: theta(0), daca e gol
	//verificam daca e gol
	if (isEmpty() == true) {
		l += 1;
		array[0] = elem;
		return true;
	}
}


bool Set::remove(TElem elem) {
	//TODO - Implementation
	//cautam elemente
	if (search(elem) == false)
		return false;
	//verificam daca e gol
	if (isEmpty() == true)
		return false;

	//Complexitate: O(n)
	for (int i = 0; i < l; i++) {
		if (array[i] == elem) {
			int x = i; //retine pozitia lui x
			for (int j = x; j < l - 1; j++)
				array[j] = array[j + 1]; //shift la stanga
			l -= 1; //lungimea scade
			return true;
		}

		//Complexitate: O(1), daca elem e la final
		if (array[l - 1] == elem) {
			l -= 1; //lungimea scade
			return true;
		}
	}

}

/*Complexitate:
1. O(n), daca elem e primul (best case)
2. theta(1), daca elem este la final (worst case)*/
bool Set::search(TElem elem) const {
	//TODO - Implementation
	for (int i = 0; i < l; i++) {
		if (array[i] == elem) {
			return true; //daca gaseste elementul, returneaza true
		}
	}
	return false; //altfel returneaza false
}

//Complexitate: theta(1)
int Set::size() const {
	//TODO - Implementation
	return l; //dimensiunea
}

//Complexitate: theta(1)
bool Set::isEmpty() const {
	//TODO - Implementation
	if (l != 0)
	{
		return false; //not empty
	}
	return true; //empty
}

//Complexitate: theta(1)
Set::~Set() {
	//TODO - Implementation
	delete[]array; //dealocare
}


SetIterator Set::iterator() const {
	return SetIterator(*this);
}


