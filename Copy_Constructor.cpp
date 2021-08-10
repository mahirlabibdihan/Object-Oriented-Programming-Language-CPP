// In C++, a Copy Constructor may be called in the following cases: 
// 1. When an object of the class is returned by value. 
// 2. When an object of the class is passed (to a function) by value as an argument. 
// 3. When an object is constructed based on another object of the same class. 
// 4. When the compiler generates a temporary object.

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
