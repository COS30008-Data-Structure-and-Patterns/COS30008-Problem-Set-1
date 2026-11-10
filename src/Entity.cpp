#include "../include/Entity.h"

Entity::Entity() :
	fEntityID(0), fName("Untitiled"), fHP(100), iter(nullptr) {}

Entity::Entity(int id, string name, int hp) :
	fEntityID(id), fName(name), fHP(hp), iter(nullptr) {}

Entity::~Entity() {}

int Entity::getEntityID() { return fEntityID; }

string Entity::getName() { return fName; }

int Entity::getHP() { return fHP; }

void Entity::setEntityID(int id) { fEntityID = id; }

void Entity::setName(string name) { fName = name; }

void Entity::setHP(int hp) { fHP = (hp < 0) ? 0 : hp; }

string Entity::EntityDetails() {
	string output;
	output += "----- Entity Details -----\n";
	output += "Entity ID: " + to_string(fEntityID) + "\n";
	output += "Name: " + fName + "\n";
	output += "HP: " + to_string(fHP) + "\n";
	output += "\n";
	return output;
}

ostream & operator<<(ostream & stream, Entity & entity) {
	// Print out the EntityDetails()
	stream << entity.EntityDetails();
	return stream;
}

void Entity::Grab(IteratorBase * it) {
	// Delete the prevoius item if exists
	if ( iter != nullptr ) {
		delete iter;
	}

	iter = it;
	cout << fName << " grabbed a bag." << endl;
}

void Entity::InventoryNext() {
	// If the iterator is empty, then return nothing.
	if ( iter == nullptr ) {
		cout << "No item grabbed." << endl;

		// Stop to move the pointer front when the item is last item.
	} else if ( (*iter) == *iter->end() ) {
		cout << fName << " have taking the last item: " << **iter << endl;

		// Else move the pointer to next item and print out.
	} else {
		++(*iter);
		cout << fName << " change to next item: " << **iter << endl;

	}
}

void Entity::InventoryPrev() {
	// If the iterator is empty, then return nothing.
	if ( iter == nullptr ) {
		cout << "No item grabbed." << endl;

		// Stop to move the pointer back when the item is first item.
	} else if ( (*iter) == *iter->begin() ) {
		cout << fName << " have taking the first item: " << **iter << endl;

		// Else move the pointer to previous item and print out.
	} else {
		--(*iter);
		cout << fName << " change to previous item: " << **iter << endl;

	}
}

void Entity::InventoryGet() {
	// Print out the current item
	// if the iter is empty, then print nothing
	if ( iter != nullptr ) {
		cout << fName << " current items: " << **iter << endl;

	} else {
		cout << "No item grabbed." << endl;
	}
}