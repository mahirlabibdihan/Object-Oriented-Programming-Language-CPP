// Giving new implementation of base class method into derived class is called function overriding
// Signature of base class method and derived class must be same Signature involves:
// Number of arguments
// Type of arguments
// Sequence of arguments

#include <iostream>
using namespace std;

class Base{
public:
	void Print(int a)
	{
		cout<<"Base : "<<a<<endl;
	}
}; 

class Derived:public Base{
public:
	void Print(int a)
	{
		cout<<"Derived : "<<a<<endl;
	}
};

int main()
{
	Base A;
	A.Print(5);
	Derived B;
	B.Print(10);
}