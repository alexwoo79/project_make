#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Database {
  private:
  protected:
  public:
	Database() {
		// constructor for the Database class
		/*
		multiline comment
		*/
	}

	~Database() {
		// destructor for the Database class
	}
	bool write(const string &username, const vector<string> &list);
	bool read(const string &username, vector<string> &list);
};