#include "include/list.h"

// Entry point for the program
int main(int arg_count, char *args[]) {

	if (arg_count > 1) {
		List simpleList;
		simpleList.name = string{args[1]};
		simpleList.print_menu();
	} else {
		cout << "Please provide a name for the list as a command line "
		        "argument.\n";
	}

	return 0;
}
