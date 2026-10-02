#pragma once

#include "database.h"
#include "list.h"

class UserManagement {
  public:
	bool load_user(const string &username, List &user);
	bool save_user(const List &user);

  private:
	Database database;
};