// Default arguments must be specified only once: either in (one of) the function’s prototype or in its definition
int sum(int a,int b=0); // int sum(int,int);

int sum(int a,int b)
{
	return a+b;
}

// All default parameters must be to the right of any parameters that don’t have defaults
void f2(int a, int b = 0); // no problem
void f3(int a, int b = 0, int c = 5); // no problem
// void f4(int a = 1, int b); // compiler error
// While specifying non-default values, we have to start from the leftmost parameter and move to the right one by one

// Default arguments must be constants or global variables.
// Default arguments cannot be local variables or other parameters

// It is possible to create copy constructors that take additional arguments, as long as the additional arguments have default values
// MyClass( const MyClass &obj, int x = 0 ) { … }


int main()
{

}