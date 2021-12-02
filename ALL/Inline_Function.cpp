// Functions that are not actually called but, rather, are expanded in line, at the point of each call
// Faster than function
/*
When the program executes the function call instruction the CPU stores the memory address of the instruction following the function call, copies the arguments of the function on the stack and finally transfers control to the specified function. The CPU then executes the function code, stores the function return value in a predefined memory location/register and returns control to the calling function. This can become overhead if the execution time of function is less than the switching time from the caller function to called function (callee).
*/
/*
C++ provides an inline functions to reduce the function call overhead. Inline function is a function that is expanded in line when it is called. When the inline function is called whole code of the inline function gets inserted or substituted at the point of inline function call. This substitution is performed by the C++ compiler at compile time. Inline function may increase efficiency if it is small.
*/

/*
Remember, inlining is only a request to the compiler, not a command. Compiler can ignore the request for inlining. Compiler may not perform inlining in such circumstances like:
	1) If a function contains a loop. (for, while, do-while)
	2) If a function contains static variables.
	3) If a function is recursive.
	4) If a function return type is other than void, and the return statement doesn’t exist in function body.
	5) If a function contains switch or goto statement.
*/

/*
If we call our function 10 times, compiler will place that code 10 times in our executable. So the size of our execcutable will increase.
*/
#include <iostream>
using namespace std;

// All the functions defined inside the class are implicitly inline.  // Automatic In-lining
class INLINE {
public:
	/* inline */ void Print()		// Inline function  // inline keyword at the starting is optional
	{
		cout << "Hello World" << endl;
	}

	// If you need to explicitly declare inline function in the class then just declare the function inside the class and define it outside the class using inline keyword.

	void SayHello();
};

inline void INLINE::SayHello()	// inline keyword at the starting is mandatory // If we don't use inline it will be a regular function
{
	cout << "Hello World" << endl;
}


// More like parameterized macros , but Safer than parameterized macros .
#define unsafe(i)  ( (i) >= 0 ? (i) : -(i) )
int safe(int i)
{
	return i >= 0 ? i : -i;
}


inline int F(int a, int b)
{
	return a + b;
}

int main()
{
	cout << F(5, 10) << endl;

	int ans, x = 5;
	ans = unsafe(x++);   // Error! x is incremented twice
	ans = unsafe(F(5, 10));  // Danger! f() is called twice
	ans = safe(x++);     // Correct! x is incremented once
	ans = safe(F(5, 10));    // Correct! f() is called once

}


// Inline function must be declared and defined in single file .
/*
	Let's say we have two files.
	T1.cpp:
		inline void f();
		int main()
		{
			f();
		}
	T1.cpp has the declaration of inline f.

	T2.cpp:
		inline void f(){

		}
	T2.cpp has the defination of inline f.

	If we compile T1.cpp and T2.cpp it will be error. Because when we call f()
	But we know for normal functions, we can write the declaration and definitions in different files. But for inline functions we can't do that. Because all functions must be declared before use; an inline function must also be defined.
*/

/*
	From the beginning lesson:
	class INLINE {
	public:
		// If you need to explicitly declare inline function in the class then just declare the function inside the class and define it outside the class using inline keyword.
		void SayHello();
	};

	inline void INLINE::SayHello()	// inline keyword at the starting is mandatory
	{
		cout << "Hello World" << endl;
	}

So if we want to define inline function of a class like this we have to do it in one file. We can't do:
	T1.h:
	class INLINE {
	public:
		void SayHello();
	};

	T1.cpp:
	#include "t1.h"
	inline void INLINE::SayHello(){

	}

	T2.cpp:
	#include "t1.h"
	int main(){
		INLINE a;
		a.SayHello();
	}

a.SayHello() won't find the definition of SayHello. So if we want to have our declaration and defintion in different files we have to use normal functions.

	T1.h:
	class INLINE {
	public:
		void SayHello();
	};

	T1.cpp:
	#include "t1.h"
	void INLINE::SayHello(){

	}

	T2.cpp:
	#include "t1.h"
	int main(){
		INLINE a;
		a.SayHello();
	}


*/