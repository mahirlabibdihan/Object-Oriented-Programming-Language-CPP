// 'this' is a Keyword and Pointer in c++
// It points to the object
// Every object in C++ has access to its own address through an important pointer called this pointer. 
// The 'this' pointer is passed as a hidden argument to all nonstatic member function calls and is available as a local variable within the body of all nonstatic functions .

// Friend and Static functions do not have a 'this' pointer .
#include <iostream>
using namespace std;
class Animal{
	static int Count;
	int Height,Weight;

public:
	Animal()
	{
		Height=0;
		Weight=0;
	}
	
	Animal(int Height,int Weight)		// Animal(Animal* this,int Height,int Weight)
	{
		// Height -> Parameter's Height
		// this->Height -> Objects's Height <- Animal::Height
		this->Height = Height;	
		// (*this).Height = Height;	
		this->Weight = Weight;
	}

};

int main()
{
	Animal Tom;
	Animal Jerry(50,100);
}