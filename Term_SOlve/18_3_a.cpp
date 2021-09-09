// For multiplevel inheritence
// Constructor functions are executed in the order of derivation
// base class constructor will be called first. Then derived class constructor will be called
// For multiple inheritence base class constructor will be called left to right

// For multiplevel inheritence
// Destructor functions are executed in the reverse order of derivation
// derived class constructor will be called first. Then base class constructor will be called
// For multiple inheritence base class denstructor will be called right to left

#include <iostream>
using namespace std;
class A{
public:
	A(){
		cout<<"Base default constructor"<<endl;
	}
	~A(){
		cout<<"Base destructor"<<endl;
	}
};

class B{
public:
	B(){
		cout<<"Base default constructor"<<endl;
	}
	~B(){
		cout<<"Base destructor"<<endl;
	}
};

class derived:public A,B{
public:
	derived()	
	{
		cout<<"Derived default constructor"<<endl;
	}
	~derived(){
		cout<<"Derived destructor"<<endl;
	}
};

int main(){
	derived d;
}