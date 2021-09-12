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
using namespace std;

class base{
public:
	base(){
		cout<<"Base default constructor"<<endl;
	}
	base(int a){
		cout<<"Base parameterized constructor"<<endl;
	}
	~base(){
		cout<<"Base destructor"<<endl;
	}
};

class derived:public base{
public:
	// When derived class construtor is called , Base class constructor is also called implicitly
	// derived()
	// {

	// }

	// We can also call it explicitly 
	derived():base()		
	{
		cout<<"Derived default constructor"<<endl;
	}

	// There are two case when the default contructor of base class is called
	// Compiler provided default constructor
	// User defined default constructor
	// User defained parameterized constructor( No default constructor)

	/*
		If we haven't written any constructor for base class there is nothing to worry. 
		Compiler provided default constructor will automatically called.

		But if there is a user defined default constructor in the base class, that constructor must inheritable.
		It means that constructor must be protected or public(Can't be private). So that derived class can inherit it. 
		Otherwise it will be compile error. This is also valid for parameterized constructors.

		If there is(/are) other parameterized constructors in base class but no user defined default constructor, and we write
		derived(){}
		It will also be invalid
	*/

	/*
		If a base class constructor takes parameters then it is the responsibility of the derived class constructor(s) to collect them and pass them to the base class constructor explicitly
	*/
	derived(int a):base(a)
	{
		// base(a); // If we write like this, it will just create a new base class instance. 
		cout<<"Derived parameterized constructor"<<endl;
	}
	~derived(){
		cout<<"Derived destructor"<<endl;
	}
};

int main(){
	derived d;
	// Constructor functions are executed in the order of derivation
	// base class constructor will be called first. Then derived class constructor will be called
	// For multiple inheritence base class constructor will be called left to right

	// Destructor functions are executed in the reverse order of derivation
	// derived class constructor will be called first. Then base class constructor will be called
	// For multiple inheritence base class denstructor will be called right to left
}