#include<iostream>
using namespace std;

// A Class is a user defined data-type which has data members and member functions.
// Data members are the data variables and member functions are the functions used to manipulate these variables and together these data members and member functions defines the properties and behavior of the objects in a Class.	

// Class Members :
// Attributes / Properties ( Variables )
// Methods / Behaviour ( Functions )


// An Object is an instance of a Class.

// When a class is defined, no memory is allocated but when it is instantiated (i.e. an object is created) memory is allocated.

class Animal
{
public:
	Animal()
	{
		a=10;
		print();
	}
	// Function and variable declarations can be below the reference .
	void print()
	{
		cout<<"Hello"<<endl;
	}
	int a;
};

//  When a class is defined, no memory is allocated but when it is instantiated (i.e. an object is created) memory is allocated.

int main()
{
	Animal Tom;
}