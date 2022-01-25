#include <iostream>
using namespace std;

class C
{
public:
	int A;
	C()
	{
		A = 5;
	}
};

template <typename T>
void Print(T A)
{
	cout << A << endl;
}

// Array to function without size
template <typename E, size_t S>
void f(E (&arr)[S])
{
	cout << sizeof(arr) / sizeof(arr[0]);
}
int main()
{
	int arr[100];
	f(arr);
	Print(5);
	Print(5.0);
	Print('5');
	Print("5");

	C A;
	// Print(A);
}