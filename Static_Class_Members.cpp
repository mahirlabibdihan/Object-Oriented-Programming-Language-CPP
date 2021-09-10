#include <iostream>
using namespace std;
class Animal{
	static int Count;
	int Height,Weight;

public:
	Animal()
	{
		this->Height=0;
		this->Weight=0;
		Count++;
	}

	Animal(int Height,int Weight)
	{
		this->Height = Height;
		this->Weight = Weight;
		Count++;
	}

	// Only static variables can be used in a static function
	static int GetCount()
	{
		// A static member function does not have a this pointer since only one copy of the function is shared by all the objects of the class

		//this->Height : Error
		return Count;
	}
};

// Virtual static member function is not allowed


// To ensure that the storage for a static member is allocated it has to be defined second time outside the class using the class-name and scope operator
int Animal::Count=0;


class A{
public:
	A(){
		cout<<"A created"<<endl;
	}
	~A(){
		cout<<"A destroyed"<<endl;
	}
};
class B{
public:
	static A *a;
	B(){
		
	}
	~B(){
		
	}
};
A *B::a=new A();


int main()
{
	Animal Tom;

	Animal Jerry(50,100);

	cout<<Jerry.GetCount()<<endl;
	cout<<Animal::GetCount()<<endl;

	delete B::a;
}

