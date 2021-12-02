/*
In normal terms Encapsulation is defined as wrapping up of data and information under a single unit. In Object Oriented Programming, Encapsulation is defined as binding together the data and the functions that manipulates them.  Encapsulation is the process or method to contain the information.

Encapsulation also leads to data abstraction. The datas are not accessible from outside. Only the functions can manipulate them. There will be getter setters for every attribute. Objects can only call a list of public functions or methods. In this way data is hidden. This characteristic of data hiding provides greater program security and avoids unintended data corruption.

Encapsulations is used for better data management. It increases data security. It prevents direct access to data members. It is a method of making a complex system easier to handle for end users.
*/

// Encapsulation

#include <string>
using namespace std;
class Animal1 {
public:
	string name;
	void setName(string name) {
		this->name = name;
	}
	string getName() {
		return name;
	}
};

// Encapsulation with data abstraction
class Animal2 {
private:
	string name;
public:
	void setName(string name) {
		this->name = name;
	}
	string getName() {
		return name;
	}
};