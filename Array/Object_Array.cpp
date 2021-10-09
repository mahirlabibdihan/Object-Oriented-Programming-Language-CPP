#include <iostream>
using namespace std;
class Animal
{
public:
	Animal()
	{
		cout<<9<<endl;
	}
	Animal(int n)
	{
		cout<<n<<endl;
	}
	Animal(int a,int b)
	{
		cout<<a<<" "<<b<<endl;
	}
};

int main()
{
	Animal a[5]={Animal(0),Animal(10)};

	Animal b[5]={0,10};		// First two element of this array will call Animal(int n) , last thre element will call Animal()

	Animal c[5]={Animal(),Animal(1),Animal(1,2)};

	Animal *d=new Animal[10];	
	// Can't be initialized . In order to dynamically create an array of a class that class must have a default constructor .

	// Possible in C++11
	// Animal *d=new Animal[10]{0,10};	
}