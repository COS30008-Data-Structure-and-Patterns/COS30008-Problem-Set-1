#pragma once
#include <iostream>
#include <string>
#include "IteratorBase.h"
using namespace std;

class Entity {
private:
	int fEntityID;
	string fName;
	int fHP;

	IteratorBase * iter;

public:
	// Default Constructor and Parameterized Constructor
	Entity();
	Entity(int id, string name, int hp);
	~Entity();

	// Getters and Setters
	int getEntityID();
	string getName();
	int getHP();

	void setEntityID(int id);
	void setName(string name);
	void setHP(int hp);

	string EntityDetails();

	// Print out the entity details
	friend ostream & operator<<(ostream & stream, Entity & entity);

	void Grab(IteratorBase * it);
	void InventoryNext();
	void InventoryPrev();
	void InventoryGet();
};