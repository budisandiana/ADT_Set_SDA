#include <iostream>
#include "SetIterator.h"
#include "Set.h"

using namespace std;


SetIterator::SetIterator(const Set& m) : set(m)
{
	//TODO - Implementation
	current = 0;
}


void SetIterator::first() {
	//TODO - Implementation
	current = 0;
}


void SetIterator::next() {
	//TODO - Implementation
	//verificam daca e valida pozitia
	if (valid())
		current++;
	else {
		//exceptie
		exception indexoutofrange;
		throw indexoutofrange;
	}
}


TElem SetIterator::getCurrent()
{
	//TODO - Implementation
	//verificam daca e valid
	if (valid())
		return this->set.array[this->current];
	else{	
		//exceptie
		exception indexoutofrange;
		throw indexoutofrange;
	}
	return NULL_TELEM;
}

bool SetIterator::valid() const {
	//TODO - Implementation
	if (current >= 0 && current < set.size())
		return true;
	return false;
}



