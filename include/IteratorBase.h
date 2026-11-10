#pragma once
#include <iostream>
using namespace std;

class IteratorBase {
public:
	virtual string IteratorDetails() = 0;
	friend ostream & operator<<(ostream & stream, IteratorBase & iter) {
		stream << iter.IteratorDetails();
		return stream;
	};

	// Derefrence, addition and substitution
	virtual string & operator*() = 0;
	virtual IteratorBase & operator++() = 0;
	virtual IteratorBase & operator--() = 0;

	virtual bool operator==(const IteratorBase & other) const = 0;

	virtual IteratorBase * begin() const = 0;
	virtual IteratorBase * end() const = 0;

	virtual ~IteratorBase() {};
};