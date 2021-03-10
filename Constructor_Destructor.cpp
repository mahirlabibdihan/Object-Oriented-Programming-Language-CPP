// Multiple constructor is possible , but only one destructor is possible in a class .
// Constructor can be overloaded .



#include <iostream>
#include <string>
using namespace std;

class Animal {
private:
	int height;
	int weight;

public:
	Animal()
	{
		this->height = 0;
		this->weight = 0;
		cout<<"Created"<<endl;
	}

	Animal(int height, int width)
	{
		this->height = height;
		this->weight = weight;
		cout<<"Created"<<endl;
	}

	~Animal()
	{
		
	}
};

int main()
{
	
}