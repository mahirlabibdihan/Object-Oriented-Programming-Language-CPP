#include <iostream>

namespace {
	int a=10;		// Can't be accessed
	int b=20;
}

int a=30;

int main()
{
	// :: -> Global Scope
	
	std::cout<<b<<" "<<::b<<std::endl;

	std::cout<<::a<<std::endl;

	// std::cout<<a<<std::endl;	// Error
}