/*
 ______   _________ _      _       _
|  ____ \|___   ___| |    | |     | |
| |    \ \   | |   | |____| |     | |
| |    | |   | |   |  ____  |     | |
| |____/ /___| |___| |    | |_____| |
|_______/|_________|_|    |_________|
M A H I R     L A B I B     D I H A N

*/

// In C++, a Copy Constructor may be called in the following cases: 
// 1. When an object of the class is returned by value. ( Not applicable for local object of function. For details: NRVO (Named Return Value Optimization) )
// 2. When an object of the class is passed (to a function) by value as an argument. 
// 3. When an object is constructed based on another object of the same class. 
// 4. When the compiler generates a temporary object.


#include <iostream>
#include <cstring>
using namespace std;
class Animal
{
public:
	int *width,*height;
	Animal()
	{
		cout<<"Default Constructor"<<endl;
		width = new int(0);
		height = new int(0);
	}
	Animal(const Animal &a)
	{
		cout<<"Copy Constructor"<<endl;
		width = new int(*a.width);
		height = new int(*a.height);
	}
	~Animal()
	{
		cout<<"Destructor"<<endl;
		delete width;
		delete height;
	}
};

class Car
{
public:
	Car()
	{
		cout<<"Default Constructor - Car"<<endl;
	}
	Car(const Car &c)
	{
		cout<<"Copy Constructor - Car"<<endl;
	}
	~Car()
	{
		cout<<"Destructor - Car"<<endl;
	}
};
Animal larger(Animal a,Animal b)
{
	cout<<"Call by value"<<endl;
	return (*a.height>*b.height)?a:b;
}

Car larger(Animal a)
{
	Car c;
	return c;
}

Animal larger()
{
	Animal c;
	return c;
}

Animal* larger(Animal *a,Animal *b)
{
	cout<<"Call by address"<<endl;
	return (*a->height>*b->height)?a:b;
}
int main()
{
	Animal dog;

	Animal cat(dog);
	*dog.height=10;
	cout<<"------"<<endl;

	larger(dog,cat);
	cout<<"------"<<endl;

	Animal mouse(larger(dog,cat));;
	cout<<"------"<<endl;

	larger(dog);
	cout<<"------"<<endl;

	larger();
	cout<<"------"<<endl;
	
	Animal Tiger(larger());
	cout<<"------"<<endl;

	
	// cout<<*mouse.height<<endl;
}

/*
	We can use reference to avoid copy constructor. We know copy constructor is called when:
	1. An object is returned by value from a function.
	ALternativly we can return object by reference. There are two cases.
	We may return local or global object. ( Not applicable for local object )
	For local object we can't return by reference. But that's not a issue at all.
	Because we know copy constructor is not called when we return local object by value.
	So we can just return reference of global objects.

	2. When an object is passed by value to a function. 
	We can easily pass objects by reference to a 

	3. When an object is constructed based on another object of the same class.
	We can't replace this with reference. 
	We have to use copy constructor here when there are dynamic allocations in the object.
*/