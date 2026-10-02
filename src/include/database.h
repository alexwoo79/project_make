#include <fstream>
#include <iostream>
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
	vector<string> list;
	string name;
	void write(const vector<string> &list);
	void read(vector<string> &list);
};