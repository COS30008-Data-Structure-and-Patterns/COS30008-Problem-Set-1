#include <sstream>;
#include "../include/Entity.h"
#include "../include/Iterator1D.h"
#include "../include/Iterator2D.h"
using namespace std;

static int ConvertInterger(string value, int origin) {
	// If the value cannot convert into number, then return the original value
	try {
		int num;
		num = stoi(value);
		return num;
	} catch ( const invalid_argument ) {
		return origin;
	}
}

static Entity CommandLine(string cmd, string value, Entity e) {
	if ( cmd == "print" ) {
		// Print out the details for the specific entity
		cout << e;

	} else if ( cmd == "name" ) {
		// Change the name for the Entity 1
		// If the value is not empty, then change the name
		// If the value is empty, stay original
		if ( value != "" ) {
			e.setName(value);
			cout << "Entity name changing '" << e.getName() << "' successful." << endl << endl;
		} else {
			cout << "Empty value ERROR." << endl << endl;
		}
		cout << endl;


	} else if ( cmd == "id" ) {
		// Change the id for the Entity
		// If the value is empty or the value cannot convert to interger, stay it original
		if ( value != "" ) {
			int num = ConvertInterger(value, e.getEntityID());
			e.setEntityID(num);
			cout << "Entity id changing '" << e.getEntityID() << "' successful." << endl << endl;
		} else {
			cout << "Empty value ERROR." << endl << endl;
		}

	} else if ( cmd == "hp" ) {
		// Change the hp value for the Entity
		// Logic same with the id part
		if ( value != "" ) {
			int num = ConvertInterger(value, e.getHP());
			e.setHP(num);
			cout << "Entity HP have change to " << num << " point. " << endl;
		} else {
			cout << "Empty value ERROR." << endl;
		}

	} else if ( cmd == "next" ) {
		// If user input next, then move the pointer to next
		// If the entity doesn`t grabbing the iter, then return nothing
		e.InventoryNext();

	} else if ( cmd == "previous" ) {
		// If user input previous, then move the pointer to next
		// If the entity doesn`t grabbing the iter, then return nothing
		e.InventoryPrev();

	} else if ( cmd == "get" ) {
		// If user input get, return the current pointer
		// If the entity doesn`t grabbing the iter, then return nothing
		e.InventoryGet();

	} else if ( cmd == "" ) {
		// Do nothing

	} else {
		cout << "Unknown command: " << cmd << endl;

	}

	return e;
}

static Entity CommandLineGrab(string cmd, Entity e, IteratorBase * i) {
	if ( cmd == "grab" ) {
		e.Grab(i);
	}
	return e;
}

int main() {
	// Create two entity
	Entity e1(1001, "Alice", 100);
	Entity e2(1002, "Bob", 150);

	// Create four string array, two 1D array and two 2D array
	// 1D array
	string bag1da[] = { "Sword", "Shield", "Potion", "Bow", "Arrow", "Helmet", "Armor" };
	string bag1db[] = { "Axe", "Dagger", "Staff", "Robe", "Ring" };

	// 2D arrays
	string bag2da[4][4] = {
		{ "helmet", "armor", "boots", "gloves" },
		{ "axe", "spear", "bow", "arrow" },
		{ "medicine", "bandage", "herbs", "salve" },
		{ "lantern", "candle", "flint", "oil" }
	};

	string bag2db[4][4] = {
		{ "diary", "letter", "note", "card" },
		{ "ruby", "emerald", "diamond", "pearl" },
		{ "lockpick", "crowbar", "hammer", "nail" },
		{ "mirror", "lens", "prism", "glass" }
	};

	// 1D Iterator
	Iterator1D * iter1 = new Iterator1D(bag1da, 7);
	Iterator1D * iter2 = new Iterator1D(bag1db, 5);

	// 2D Iterator
	Iterator2D * iter3 = new Iterator2D(bag2da, 4, 4);
	Iterator2D * iter4 = new Iterator2D(bag2db, 4, 4);

	cout << "Entity 1:" << endl << e1;
	cout << "Entity 2:" << endl << e2;
	cout << "Iterator 1:\n" << *iter1 << endl;
	cout << "Iterator 2:\n" << *iter2 << endl;
	cout << "Iterator 3:\n" << *iter3 << endl;
	cout << "Iterator 4:\n" << *iter4 << endl;


	cout << "Enter command (enter 'help' for more details):" << endl;
	while ( true ) {
		string command, first, second, third;

		cout << "> ";
		getline(cin, command);

		// Break the command
		istringstream iss(command);
		iss >> first >> second >> third;

		if ( first == "exit" ) {
			// Exit the program
			cout << "End the program..." << endl;
			break;

		} else if ( first == "help" ) {
			// Show the help to user
			cout << "=============================================" << endl;
			cout << "\tProgram Help Menu" << endl;
			cout << "=============================================" << endl << endl;

			cout << "Command Type 1: Basic Commands" << endl;
			cout << "---------------------------------------------" << endl;
			cout << "\thelp\t\t\tShow all available commands and details." << endl;
			cout << "\texit\t\t\tExit the program." << endl << endl;

			cout << "Command Type 2: Entity Commands" << endl;
			cout << "---------------------------------------------" << endl;
			cout << "\tFormat:" << endl;
			cout << "\t\te[entity_number] [command] [value]" << endl << endl;

			cout << "\tParameters:" << endl;
			cout << "\t\te[entity_number]\t-> Select the entity to modify (e1 or e2)." << endl;
			cout << "\t\t[command]\t\t-> Command to execute." << endl;
			cout << "\t\t[value]\t\t\t-> Additional value or name (some commands may not need it)." << endl << endl;

			cout << "\tAvailable Commands:" << endl;
			cout << "\t\tprint\t\tShow all details of the specific entity." << endl;
			cout << "\t\tname [value]\tRename the entity to [value]." << endl;
			cout << "\t\tid [value]\tChange the entity ID to [value]." << endl;
			cout << "\t\thp [value]\tSet new HP for the entity. If HP < 0, it will be replaced with 0." << endl;
			cout << "\t\tnext\t\tMove the entity to the next item (requires iterator support)." << endl;
			cout << "\t\tprevious\tMove the entity to the previous item (requires iterator support)." << endl;
			cout << "\t\tget\t\tDisplay the entity's current item." << endl << endl;

			cout << "\tExamples:" << endl;
			cout << "\t\te1 name Dragon" << endl;
			cout << "\t\te2 hp 150" << endl;
			cout << "\t\te1 get" << endl << endl;

			cout << "Command Type 3: Iterator Commands" << endl;
			cout << "---------------------------------------------" << endl;
			cout << "\tNew Format:" << endl;
			cout << "\t\te[entity_number] grab i[iterator_number]" << endl << endl;

			cout << "\tParameters:" << endl;
			cout << "\t\te[entity_number]\t-> Select the entity to grab iterator (e1 or e2)." << endl;
			cout << "\t\ti[iterator_number]\t-> Choose the iterator (i1 - i4)." << endl;
			cout << "\t\t\t\t  i1, i2 are 1D Iterators." << endl;
			cout << "\t\t\t\t  i3, i4 are 2D Iterators." << endl << endl;

			cout << "\tAvailable Command:" << endl;
			cout << "\t\tgrab\t\tLet the entity grab the specified iterator." << endl << endl;

			cout << "\tExamples:" << endl;
			cout << "\t\te1 grab i3" << endl << endl;

			cout << "---------------------------------------------" << endl;
			cout << "Additional Notes:" << endl;
			cout << "---------------------------------------------" << endl;
			cout << "\t- Type 'help' to view this help menu anytime." << endl;
			cout << "\t- Type 'exit' to safely close the program." << endl;
			cout << "\t- If an invalid command format is entered, the program will display usage hints." << endl;
			cout << "=============================================" << endl;

		} else if ( first == "e1" ) {
			if ( second == "print" || second == "name" || second == "id" || second == "hp" || second == "next" || second == "previous" || second == "get" ) {
				e1 = CommandLine(second, third, e1);

			} else if ( second == "grab" ) {
				if ( third == "i1" ) { e1 = CommandLineGrab(second, e1, iter1); } else if ( third == "i2" ) { e1 = CommandLineGrab(second, e1, iter2); } else if ( third == "i3" ) { e1 = CommandLineGrab(second, e1, iter3); } else if ( third == "i4" ) { e1 = CommandLineGrab(second, e1, iter4); } else { cout << "Unknown Iterator (i1 ~ i4): " << third << endl; }

			} else {
				cout << "Unknown command: " << second << endl;
			}

		} else if ( first == "e2" ) {
			if ( second == "print" || second == "name" || second == "id" || second == "hp" || second == "next" || second == "previous" || second == "get" ) {
				e2 = CommandLine(second, third, e2);

			} else if ( second == "grab" ) {
				if ( third == "i1" ) { e2 = CommandLineGrab(second, e2, iter1); } else if ( third == "i2" ) { e2 = CommandLineGrab(second, e2, iter2); } else if ( third == "i3" ) { e2 = CommandLineGrab(second, e2, iter3); } else if ( third == "i4" ) { e2 = CommandLineGrab(second, e2, iter4); } else { cout << "Unknown Iterator (i1 ~ i4): " << third << endl; }

			} else {
				cout << "Unknown command: " << second << endl;
			}

		} else if ( first == "" ) {
			// Do nothing

		} else {
			cout << "Unknown command or entity: " << first << endl;
			cout << "Entity (e1, e2)" << endl << endl;
		}
	}
}