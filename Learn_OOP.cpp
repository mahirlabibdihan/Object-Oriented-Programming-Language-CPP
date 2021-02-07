#include <iostream>
using namespace std;
class OOP{

public:
	OOP()
	{
		cout<<"Created Array"<<endl;
	}
	OOP(const OOP& a)
	{
		cout<<"Copied"<<endl;
	}
	OOP(int a)
	{
		cout<<"Created Element"<<endl;
	}

	
	
};

int main()
{
	OOP a[10]={1,2,3,4,5};	  // Array can't be created when there is constructor in a class , but no constructor without parameter .

	OOP b;

	OOP c=b;
}