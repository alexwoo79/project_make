#include "include/database.h"

#include <algorithm>

namespace {
struct UserData {
	string username;
	vector<string> items;
};

bool load_users(vector<UserData> &users) {
	ifstream db("db/lists.sl");
	if (!db.is_open()) {
		return false;
	}

	string line;
	vector<UserData>::size_type current_user = users.size();
	while (getline(db, line)) {
		if (!line.empty() && line[0] == '#') {
			string username = line.substr(1);
			vector<UserData>::size_type user_index = 0;
			while (user_index < users.size() &&
			       users[user_index].username != username) {
				++user_index;
			}
			if (user_index == users.size()) {
				users.push_back(UserData{username, vector<string>()});
			}
			current_user = user_index;
		} else if (line == "%") {
			current_user = users.size();
		} else if (current_user < users.size()) {
			users[current_user].items.push_back(line);
		}
	}

	return !db.bad();
}

vector<UserData>::iterator find_user(vector<UserData> &users,
                                     const string &username) {
	return find_if(users.begin(), users.end(),
	               [&username](const UserData &user) {
		               return user.username == username;
	               });
}
} // namespace

bool Database::write(const string &username, const vector<string> &list) {
	vector<UserData> users;
	if (!load_users(users)) {
		cout << "Failed to read the database file." << endl;
		return false;
	}

	vector<UserData>::iterator user = find_user(users, username);
	if (user == users.end()) {
		users.push_back(UserData{username, list});
	} else {
		user->items = list;
	}

	ofstream db("db/lists.sl", ios::trunc);
	if (!db.is_open()) {
		cout << "Failed to open the database file for writing." << endl;
		return false;
	}

	for (const UserData &entry : users) {
		db << '#' << entry.username << '\n';
		for (const string &item : entry.items) {
			db << item << '\n';
		}
		db << "%\n";
	}

	return db.good();
}

bool Database::read(const string &username, vector<string> &list) {
	vector<UserData> users;
	if (!load_users(users)) {
		cout << "Failed to open the database file." << endl;
		return false;
	}

	list.clear();
	vector<UserData>::const_iterator user =
	    find_if(users.begin(), users.end(), [&username](const UserData &entry) {
		    return entry.username == username;
	    });
	if (user != users.end()) {
		list = user->items;
	}

	return true;
}