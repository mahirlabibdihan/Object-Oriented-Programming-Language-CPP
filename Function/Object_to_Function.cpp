#include<iostream>
using namespace std;

class Animal{
	static int count;
public:
	Animal()
	{
		count++;
		cout<<count<<" objects created ."<<endl;
	}
	Animal(Animal& a)
	{
		count++;
		cout<<count<<" animals created ."<<endl;
	}
	~Animal()
	{
		count--;
		cout<<"One object destroyed ."<<count<<" objects remains ."<<endl;
	}
};

int Animal::count=0;

// In call by value, while making a copy, copy constructors are called
void f1(Animal a)
{	
	cout<<"Parameter object destroying ."<<endl;
}

// When an object is returned by a function, a temporary object (invisible to us) is automatically created which holds the return value
// While creaing this object, copy constructors are called
Animal f2()
{
	Animal *a=new Animal;
	cout<<"Return object destroying ."<<endl;
	return *a;
}
int main()
{
	
	Animal a;
	f1(a);

	a=f2();
	cout<<"Main object destroying ."<<endl;
}