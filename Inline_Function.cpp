// Functions that are not actually called but, rather, are expanded in line, at the point of each call
// Faster than function

// Inline function must be declared and defined in single file .
#include <iostream>
using namespace std;

// All the functions defined inside the class are implicitly inline.
class INLINE {
public:
	/* inline */ void Print()		// Inline function  // inline keyword at the starting is optional
	{
		cout << "Hello World" << endl;
	}

	// If you need to explicitly declare inline function in the class then just declare the function inside the class and define it outside the class using inline keyword.

	void SayHello();
};

inline void INLINE::SayHello()	// inline keyword at the starting is mandatory
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