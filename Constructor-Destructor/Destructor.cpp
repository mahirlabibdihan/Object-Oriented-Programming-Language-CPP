#include <iostream>
#include <string>
using namespace std;

// Mainly used to de-allocate dynamic memory allocations . (Good practice)
class Animal {
private:
	int height;
	int weight;
	// Destructor can't be declared private / protected .
public:
	// Public function member
	// Same name as class
	// Preceded with ~
	// No parameter
	// No return value( But return statement can be used )
	// void ~Animal() ; // Invalid

	// Only one destructor is possible in a class .
	// Destructor can't be overloaded .
	~Animal()
	{
		cout<<"Animal destroyed"<<endl;
	}
};

class Dog: public Animal {
private:
	string name;
public:
	~Dog()
	{
		cout<<"Dog destroyed"<<endl;
	}
};


// When returning an object from a function , if another object receives the returned object , then destructor is not called . Otherwise destructor is called .
int main()
{
	// Destructor is automatically called by the compiler when an object is destroyed . (Not a pointer).

	Animal A;
	// Objects are destroyed when they go out of scopee .
	
	Animal *a=new Animal;
	delete a;	// Pointer's destructor should be called manually .


	Dog d;
	// Base class's destructor is automatically called with the derived class's destructor .


	// Destructors are called in pass object by value to function and return object from function , constructors are not called .

}