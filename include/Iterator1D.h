#pragma once
#include <iostream>
#include "IteratorBase.h"
using namespace std;

class Iterator1D : public IteratorBase {
private:
	string * array;
	int size;
	int pointer;

public:
	// Constructor
	Iterator1D(string * arr, int sz);
	Iterator1D(string * arr, int sz, int ptr);

	// Getters
	int getPointer();
	int getSize();

	// Setters
	void setPointer(int ptr);

	// Details
	string IteratorDetails() override;

	// Derefrence, addition and substitution
	string & operator*() override;
	Iterator1D & operator++() override;
	Iterator1D & operator--() override;

	bool operator==(const IteratorBase & other) const override;

	Iterator1D * begin() const override;
	Iterator1D * end() const override;
};