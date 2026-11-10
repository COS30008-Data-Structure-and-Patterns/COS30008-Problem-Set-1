#include "../include/Iterator1D.h"

Iterator1D::Iterator1D(string * arr, int sz) :
	array(arr), size(sz > 10 ? 10 : sz), pointer(0) {}

Iterator1D::Iterator1D(string * arr, int sz, int ptr) :
	array(arr), size(sz > 10 ? 10 : sz), pointer(ptr) {}

int Iterator1D::getPointer() { return pointer; }

int Iterator1D::getSize() { return size; }

void Iterator1D::setPointer(int ptr) { if ( pointer >= 0 && pointer < size ) { pointer = ptr; } }

string Iterator1D::IteratorDetails() {
	string output;
	output += "========== Iterator Details =========\n";
	output += "Iterator Type: 1D Iterator\n";

	for ( int p = 0; p < size; p++ ) {
		output += "~ " + array[pointer] + "\n";
		++*this;
	}

	pointer = 0;
	return output;
}

string & Iterator1D::operator*() { return array[pointer]; }

Iterator1D & Iterator1D::operator++() {
	if ( pointer < size - 1 ) { ++pointer; };
	return *this;
}

Iterator1D & Iterator1D::operator--() {
	if ( pointer >= 0 ) { --pointer; };
	return *this;
}

bool Iterator1D::operator==(const IteratorBase & other) const {
	const Iterator1D * other_ptr = dynamic_cast<const Iterator1D *>(&other); // Convert the type of the IteratorBase
	if ( !other_ptr ) { return false; } // If the other pointer is other type, return false
	return this->array == other_ptr->array && this->pointer == other_ptr->pointer;
}

Iterator1D * Iterator1D::begin() const { return new Iterator1D(array, size); }

Iterator1D * Iterator1D::end() const { return new Iterator1D(array, size, size - 1); }