#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// [ capture clause ] (parameters) -> return-type  
// {   
//    definition of method   
// } 
int main()
{
	vector<int> v;

	sort(v.begin(),v.end(),[](int a,int b)->bool
	{
		return a>b;
	});

	// Generally return-type in lambda expression are evaluated by compiler itself and we don’t need to specify that explicitly and -> return-type part can be ignored but in some complex case as in conditional statement, compiler can’t make out the return type and we need to specify that.
	sort(v.begin(),v.end(),[](int a,int b)
	{
		return a>b;
	});



	//  We can capture external variables from enclosing scope by three ways :
    // Capture by reference
    // Capture by value
    // Capture by both (mixed capture)

	// Syntax used for capturing variables :
	//       [&] : capture all external variable by reference
	//       [=] : capture all external variable by value
	//       [a, &b] : capture a by value and b by reference

	int a=5,b=10;
	int Max=0;
	[&]()
	{
		cout<<Max;
		Max=(a>b?a:b);
		Max++;
	};

	cout<<Max;

}