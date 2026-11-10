#pragma once
#include <iostream>
#include "IteratorBase.h"
using namespace std;

class Iterator2D : public IteratorBase {
private:
	string(*array)[4];
	int rows;
	int cols;
	int rowPtr;
	int colPtr;

public:
	Iterator2D(string arr[][4], int r, int c);
	Iterator2D(string arr[][4], int r, int c, int rp, int cp);

	// Getters
	int getRowPointer();
	int getColPointer();
	int getRows();
	int getCols();

	// Setters
	void setRowPointer(int rp);
	void setColPointer(int cp);

	// Details
	string IteratorDetails() override;

	// Derefrence, addition and substitution
	string & operator*() override;
	Iterator2D & operator++() override;
	Iterator2D & operator--() override;

	bool operator==(const IteratorBase & other) const override;

	Iterator2D * begin() const override;
	Iterator2D * end() const override;
};