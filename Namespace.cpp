// Namespaces allow to group entities like classes, objects (variables) and functions under a name
// namespace identifier {
// entities
// }


// Global scope is divided into "sub-scopes", each one with its own name
#include <iostream>

namespace ns1{
	int a=10;

	void Print()
	{
		std::cout<<"1st Hello"<<std::endl;
	}
}

namespace ns2{
	int a=20;

	void Print()
	{
		std::cout<<"2nd Hello"<<std::endl;
	}
}

// Unnamed namespace 

// Within the file that contains the namespace
// the members can be used directly, without qualification
// Outside of the file
// the identifiers are unknown 

namespace {			
	int a=30;
	void Print();
}

// Unnamed namespace can be extended
namespace {
	void Print()
	{
		std::cout<<"3rd Hello"<<std::endl;
	}
}

// int a=40;		
// If declared using only a it will give error
// but using ::a it will access the global a

int main()
{
	// namespace ns3{}		// Can only declared globally

	std::cout<<ns1::a<<std::endl;

	std::cout<<ns2::a<<std::endl;

	std::cout<<a<<" "<<::a<<std::endl;

	ns1::Print();

	ns2::Print();

	Print();
}