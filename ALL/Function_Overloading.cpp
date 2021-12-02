#include<iostream>
using namespace std;

namespace overload{
	// Constructor can be overloaded
	// Destructor can't be overloaded
	int sum(int x,int y)
	{
		return x+y;
	}

	// Two or more functions can share the same name as long as either

	// The type of their arguments differs, or
	double sum(double x,double y)
	{
		return x+y;
	}

	// The number of their arguments differs
	int sum(int x,int y,int z)
	{
		return x+y+z;
	}
}

// Ambiguity
/*
	It’s a well known fact in Function Overloading, that the compiler decides which function needs to be invoked among the overloaded functions. 
	If the compiler can not choose a function amongst two or more overloaded functions, the situation is -” Ambiguity in Function Overloading”.
*/
namespace ambiguity{
	/** 1 **/
	// The return type alone is not a sufficient difference to allow function overloading
	// This is a compile error
	// double sum(int x,int y,int z)
	// {
	// 	return x+y+z;
	// }

	// int sum(int x,int y,int z)
	// {
	// 	return x+y+z;
	// }

	/** 2 **/
	// Due to identical parameter types
	// This is not a compile error until we call this functions
	// double sum(float x,float y)
	// {
	// 	return x+y;
	// }

	// double sum(int x,int y)
	// {
	// 	return x+y;
	// }
	/*
		It will create ambiguity if we call sum(3.5,5.6) 
		The reason behind the ambiguity in above code is that the floating literals 3.5 and 5.6 are actually treated as double by the compiler. 
		As per C++ standard, floating point literals (compile time constants) are treated as double unless explicitly specified by a suffix. Since compiler could not find a function with double argument and got confused if the value should be converted from double to int or float.
	*/

	/** 3 **/
	// Due to the use of default arguments
	// This is not a compile error until we call this functions
	// int sum(int x,int y,int z,int w=0)
	// {
	// 	return x+y+z+w;
	// }

	// int sum(int x,int y,int z)
	// {
	// 	return x+y+z;
	// }

	/** 4 **/
	// Due to the use of reference parameters
	// This is not a compile error until we call this functions
	// int sum(int x,int y){
	// 	return x+y;
	// }

	// int sum(int x,int &y)
	// {
	// 	return x+y;
	// }
}


// Finding the address of an overloaded function

/*
Example:
	void space( int a ) { … }
	void space( int a, char c ) { … }
	void (*fp1)(int);
	void (*fp2)(int, char);
	fp1 = space; //  gets address of space(int)
	fp2 = space; //  gets address of space(int, char)

So, it is the declaration of the pointer that determines which function’s address is assigned
*/
int main(int argc,char *argv[])
{
	int a=overload::sum(1,2,3);
	int b=overload::sum(1,2);

	// ambiguity::sum(4.5,5.6);
}

