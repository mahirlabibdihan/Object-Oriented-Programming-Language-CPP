/*
 ______   _________ _      _       _
|  ____ \|___   ___| |    | |     | |
| |    \ \   | |   | |____| |     | |
| |    | |   | |   |  ____  |     | |
| |____/ /___| |___| |    | |_____| |
|_______/|_________|_|    |_________|
M A H I R     L A B I B     D I H A N

*/

#include <iostream>
#include <string>
using namespace std;
// Pointer of parent class can point to child class .
// Pointer of child class can't point to parent class .


// Virtual static member function is not allowed


// Constructors cannot be virtual, but destructors can be virtual
// It ensures that the derived class destructor is called when a base class pointer is used while deleting a dynamically created derived class object


class Animal {
public:

	virtual void Details()
	{
		cout<<"Base"<<endl;
	}
	virtual ~Animal() {		// Without virtual, destructor of derived class won't be called while using delete
		cout<<"Destructing Base"<<endl;
	}
};

class Dog: public Animal {
public:
	void Details()
	{
		cout<<"Derived"<<endl;
	}
	~Dog(){
		cout<<"Destructing Derived"<<endl;
	}
};


// Without virtual keyword i will create ambiguity
class Base{
public:
	int i;
};

class D1:virtual public Base{

};

class D2:virtual public Base{

};

class D3:public D1,public D2{
	// contains only one copy of 'i'
};

// Run time polymorphism
// Late binding
void runtimePolymorphism(){
	// Dog Tom;
	Animal* A=new Dog;		

	// Tom.Details();
	A->Details();
	delete A;
}

// Virtual base class 
void virtualBaseClass(){
	D3 Obj;
	Obj.i=10;
	Obj.D1::i=100;
	Obj.D2::i=1000;
}

// Pure virtual function
// If we want to omit the body of a virtual function in a base class, we can use pure virtual functions 
// virtual void f()=0;
// It forces derived classes to override it
// A class conatining a pure virtual function becomes a abstract class

int main()
{
	runtimePolymorphism();
	virtualBaseClass();
}