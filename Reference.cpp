/*
 ______   _________ _      _       _
|  ____ \|___   ___| |    | |     | |
| |    \ \   | |   | |____| |     | |
| |    | |   | |   |  ____  |     | |
| |____/ /___| |___| |    | |_____| |
|_______/|_________|_|    |_________|
M A H I R     L A B I B     D I H A N

*/

// Alternative to copy constructor
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
#include<stdio.h>
#include<vector>
#include<iostream>
using namespace std;

class C{
int& ref;
public:
	C(int& n):ref(n)	// Initialization of reference member
	{

	}
};
// More memory efficient than pointers
void swap(int& a,int& b)  // New copy of variables is not created in function parameter .
{
	a^=b^=a^=b;
}

int R;
// We can't return reference to local variable from a function
int& Reference()
{
	// int x;
	// return x;	// invalid
	return R;
}
int main()
{
	// When a variable is declared as a reference, it becomes an alternative name for an existing variable.
	int x=10;
	int& ref=x;    // Reference must be initialized when declared .// Not applicable for class member

			       // No new memory is allocated for reference
	const int& ref2=10;

	// void& ref=x;	// Can't be declared as void

	int y;
	// &ref=y;   // Once a reference is created, it cannot be later made to reference another object;
	ref=20;
	printf("%d %d\n",x,ref);
	printf("%p %p\n",&x,&ref);

	int a=10,b=20;
	swap(a,b);
	printf("a:%d  b:%d\n",a,b);


	// Range based for loop
	vector<int> v{1,2,3,4,5};
	for(int& i:v)	// Avoid copy of vector elements
	{
		i=i+1;
	}
	for(int i:v)	// Creates copy of vector elements
	{
		cout<<i<<" ";
	}

	//rvalue reference
	int&& rref=10;
	//lvalue reference
	int& lref=a;
	int& Lref=rref;


	Reference()=a;
}