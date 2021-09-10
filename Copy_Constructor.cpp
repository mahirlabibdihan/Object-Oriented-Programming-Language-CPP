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
// 1. When an object of the class is returned by value. 
// ( Not applicable for local object of function. For details: NRVO (Named Return Value Optimization) . This is fully depends on compiler. If we make our copy constructor private we can't return local object anyway.)
// 2. When an object of the class is passed (to a function) by value as an argument. 
// 3. When an object is constructed based on another object of the same class. 
// 4. When the compiler generates a temporary object.

// It is, however, not guaranteed that a copy constructor will be called in all these cases, because the C++ Standard allows the compiler to optimize the copy away in certain cases, one example is the return value optimization (sometimes referred to as RVO). [ See case 1 ]


// If we don’t define our own copy constructor, the C++ compiler creates a default copy constructor for each class which does a bit-wise copy between objects. 

// The default copy constructor does only shallow copy. 
// Deep copy is possible only with user defined copy constructor.

// If the class has pointer variables and dynamic memory allocations then bitwise copy is not enough
// Default copy constructor will create problem, If your class contains pointer members, which are dynamically allocated.
// When an object with pointer member is copied to another object with default copy constructor, then both object's member will point to the same location.
// So, when destructor of an object is called it will creates problem

/*
Why argument to a copy constructor must be passed as a reference? 
- A copy constructor is called when an object is passed by value. Copy constructor itself is a function. So if we pass an argument by value in a copy constructor, a call to copy constructor would be made to call copy constructor which becomes a non-terminating chain of calls. Therefore compiler doesn’t allow parameters to be passed by value.
*/

/*
Why copy constructor argument should be const in C++?
- One reason for passing const reference is, we should use const in C++ wherever possible so that objects are not accidentally modified. 
*/

/*
Can we make copy constructor private? 
Yes, a copy constructor can be made private. When we make a copy constructor private in a class, objects of that class become non-copyable. This is particularly useful when our class has pointers or dynamically allocated resources. In such situations, we can either write our own copy constructor like above String example or make a private copy constructor so that users get compiler errors rather than surprises at runtime. 

If we don't want to use copy constructor accidentally we can make it private to get compile error.
Or if we want to check where copy constructor is being used at compile time we can make it private.
Like when we return a local object from a function it doesn't call copy constructor at run time.
But if we make our copy constructor private it will give compilation error. As it is calling copy constructor at compile time.
But to optimize copy, compiler doesn't call copy constructor at run time. That doesn't mean we can make our copy constructor private.
If we don't write copy constructor that will be fine.
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
	// Usually copy constructors takes only one argument(Reference to the object which needs to be copied ).
	// But it is possible to create copy constructors that take additional arguments, as long as the additional arguments have default values
	// Animal(const Animal &a,int x=0) { }
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
	We can easily pass objects by reference to a function. 

	3. When an object is constructed based on another object of the same class.
	We can't replace this with reference. 
	We have to use copy constructor here when there are dynamic allocations in the object.
*/