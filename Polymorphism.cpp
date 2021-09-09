/*
Objects are designed to share behaviors and they can take on more than one form. The program will determine which meaning or usage is necessary for each execution of that object from a parent class, reducing the need to duplicate code. A child class is then created, which extends the functionality of the parent class. Polymorphism allows different types of objects to pass through the same interface.
*/

// Polymorphism
// Compile time polymorphism
// Function Overloading ( Different form of same method for same class )
// Operator Overloading ( Different form of same operator for same class )

// Run time polymorphism
// Virtual function 	( Different form of same method for different class )	
// Operator Overriding

// Pointer to an abstract class is the heart of run time polymorphism
#include<iostream>
using namespace std;
class Vehicle{
public:
	virtual void start()=0;
};

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
	Vehicle* v1=new Car();
	Vehicle* v2=new Bike();
	v1->start();
	v2->start();
}