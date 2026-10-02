#include "include/database.h"
#include "include/list.h"

// Entry point for the program
int main(int arg_count, char *args[]) {

	List simpleList;
	Database data;

	if (arg_count > 1) {
		data.read(simpleList.list);
		simpleList.name = string{args[1]};
		simpleList.print_menu();
		data.write(simpleList.list);
	} else {
		cout << "Please provide a name for the list as a command line "
		        "argument.\n";
	}

	return 0;
}
