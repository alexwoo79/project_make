#include "include/list.h"

// function definition for print_menu
void List::print_menu() {

	int choice;
	cout << "**** " << name << " ****\n";
	cout << "1 - Print list.\n";
	cout << "2 - Add item to list.\n";
	cout << "3 - Remove item from list.\n";
	cout << "4 - Exit.\n";
	cout << "Enter your choice and press Enter: \n";
	cin >> choice;

	if (choice == 4) {
		return;
	} else {
		switch (choice) {
		case 1:
			print_list();
			break;
		case 2:
			add_item();
			break;
		case 3:
			delete_item();
			break;
		default:
			cout << "Sorry choice has not been implemented." << endl;
		}
	}
}
// add_item function definition
void List::add_item() {

	cout << "\n\n\n\n\n\n\n\n";
	cout << "*** Add Item ***\n";
	cout << "Type in an item and press enter: ";

	string item;
	cin >> item;

	list.push_back(item);

	cout << "Successfully added an item to the list \n\n\n\n\n";
	cin.clear();

	print_menu();
}

// delete_item function definition
void List::delete_item() {

	cout << "*** Delete Item ***\n";
	cout << "Select an item index number to delete: \n";

	if (list.size()) {
		for (unsigned int i = 0; i < list.size(); i++) {
			cout << i << ": " << list[i] << "\n";
		}
		int choiceNum;
		cin >> choiceNum;
		list.erase(list.begin() + choiceNum);
	} else {
		cout << "No items in the list or to delete.\n";
	}

	print_menu();
}

// void print_list function definition
void List::print_list() {

	cout << "\n\n\n\n\n\n\n\n";
	cout << "*** Printing List ***\n";

	for (unsigned int list_index = 0; list_index < list.size(); list_index++) {
		cout << " * " << list[list_index] << "\n";
	}

	cout << "M - Menu \n";
	char choice;
	cin >> choice;

	if (choice == 'M' || choice == 'm') {
		print_menu();
	} else {
		cout << "Invalid Choice. Quitting..\n";
	}
}