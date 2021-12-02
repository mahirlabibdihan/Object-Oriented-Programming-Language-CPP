#include<iostream>
using namespace std;
// Abstract Class : Class containing atleast one pure virtual function .

// Can't instantiate abstract class. We cannot create any objects of such classes.
// We can still create a pointer to an abstract class

// While inheriting from abstract class, pure virtual functions of that class must be overriden and defined. Otherwise they become abstract too.
class Animal{
public:
	virtual void f()=0;
};

class Dog:public Animal{
public:
	void f()
	{
		cout<<"Vau Vau"<<endl;
	}
};

int main()
{
	Dog Tom;
	Animal* A=&Tom;

	Tom.f();
	A->f();
}
