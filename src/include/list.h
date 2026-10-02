#include <iostream>
#include <vector>

using namespace std;

class List {
  private:
  protected:
  public:
	List() {
		// constructor for the List class
		/*
		multiline comment
		*/
	}

	~List() {
		// destructor for the List class
	}
	vector<string> list;
	string name;
	void print_menu();
	void print_list();
	void add_item();
	void delete_item();
};