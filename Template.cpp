#include<iostream>
using namespace std;


class C{
public:
	int A;
	C(){
		A=5;
	}
};

template<typename T>
void Print(T A)
{
	cout<<A<<endl;
}

int main()
{
	Print(5);
	Print(5.0);
	Print('5');
	Print("5");

	C A;
	// Print(A);
}