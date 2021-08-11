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


class Vehicle{
public:
	virtual void start()=0;
};

// We have created a Vehicle(Abstract Class) which have start method.
// But we have not defined the start method. 
// In other words, we have hidden the details ,about how the start method works, from user.
// And this is abstraction.

class Car:public Vehicle{
public:
	void start(){
		cout<<"Starting with key"<<endl;
	}
};

class Bike:public Vehicle{
public:
	void start(){
		cout<<"Starting with kick"<<endl;
	}
};


int main()
{
	Vehicle* v=new Car();
	v->start();
}