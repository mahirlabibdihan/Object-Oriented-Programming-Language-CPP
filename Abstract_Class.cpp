#include<iostream>
using namespace std;
// Abstract Class : Class containing atleast one pure virtual function .
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