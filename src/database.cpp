#include "include/database.h"

void Database::write(const vector<string> &list) {
	// implementation for writing the database
	ofstream db("db/lists.sl");
	if (db.is_open()) {
		for (unsigned int list_index = 0; list_index < list.size();
		     list_index++) {
			db << list[list_index] << "\n";
		}

	} else {
		cout << "Failed to open the database file." << endl;
	}

	db.close();
}

void Database::read(vector<string> &list) {
	// implementation for reading the database
	string line;
	ifstream db("db/lists.sl");
	if (db.is_open()) {
		list.clear();
		while (getline(db, line)) {
			list.push_back(line);
		}
	} else {
		cout << "Failed to open the database file." << endl;
	}
	db.close();
}