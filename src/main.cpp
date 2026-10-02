#include "include/user_management.h"

// Entry point for the program
int main(int arg_count, char *args[]) {

	List simpleList;
	UserManagement user_management;

	if (arg_count > 1) {
		if (user_management.load_user(string{args[1]}, simpleList)) {
			simpleList.print_menu();
			user_management.save_user(simpleList);
		}
	} else {
		cout << "Please provide a name for the list as a command line "
		        "argument.\n";
	}

	return 0;
}
