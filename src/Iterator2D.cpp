#include "../include/Iterator2D.h"

Iterator2D::Iterator2D(string arr[][4], int r, int c) :
	array(arr), rows(r > 4 ? 4 : r), cols(c > 4 ? 4 : c), rowPtr(0), colPtr(0) {}

Iterator2D::Iterator2D(string arr[][4], int r, int c, int rp, int cp) :
	array(arr), rows(r > 4 ? 4 : r), cols(c > 4 ? 4 : c), rowPtr(rp), colPtr(cp) {}

int Iterator2D::getRowPointer() { return rowPtr; }

int Iterator2D::getColPointer() { return colPtr; }

int Iterator2D::getRows() { return rows; }

int Iterator2D::getCols() { return cols; }

void Iterator2D::setRowPointer(int rp) { if ( rp >= 0 && rp < rows ) { rowPtr = rp; } }

void Iterator2D::setColPointer(int cp) { if ( cp >= 0 && cp < cols ) { colPtr = cp; } }

string Iterator2D::IteratorDetails() {
	string output;

	output += "========== Iterator Details =========\n";
	output += "Iterator Type: 2D Iterator\n";

	for ( int r = 0; r < rows; r++ ) {
		for ( int c = 0; c < cols; c++ ) { // Its means c = c + 1, not c++ language :)
			output += "~ " + array[rowPtr][colPtr] + "\n";
			++*this;
		}
	}

	rowPtr = 0;
	colPtr = 0;

	return output;
}

string & Iterator2D::operator*() { return array[rowPtr][colPtr]; }

Iterator2D & Iterator2D::operator++() {
	if ( colPtr < cols - 1 ) {
		++colPtr;
	} else if ( rowPtr < rows - 1 ) {
		colPtr = 0;
		++rowPtr;
	}
	return *this;
}

Iterator2D & Iterator2D::operator--() {
	if ( colPtr > 0 ) {
		--colPtr;
	} else if ( rowPtr > 0 ) {
		colPtr = cols - 1;
		--rowPtr;
	}
	return *this;
}

bool Iterator2D::operator==(const IteratorBase & other) const {
	const Iterator2D * other_ptr = dynamic_cast<const Iterator2D *>(&other); // Convert the type of the IteratorBase
	if ( !other_ptr ) { return false; } // If the other pointer is other type, return false
	return this->array == other_ptr->array && this->rowPtr == other_ptr->rowPtr && this->colPtr == other_ptr->colPtr;
}

Iterator2D * Iterator2D::begin() const { return new Iterator2D(array, rows, cols, 0, 0); }

Iterator2D * Iterator2D::end() const { return new Iterator2D(array, rows, cols, rows - 1, cols - 1); }