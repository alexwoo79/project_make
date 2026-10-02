#include "include/user_management.h"

bool UserManagement::load_user(const string &username, List &user) {
	user.name = username;
	return database.read(username, user.list);
}

bool UserManagement::save_user(const List &user) {
	return database.write(user.name, user.list);
}