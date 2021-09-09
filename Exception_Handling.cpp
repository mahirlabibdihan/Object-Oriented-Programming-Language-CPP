#include<iostream>
#include <string>
using namespace std;
int main()
{
	int a=0;
	try{
		if(a)
		{
			cout<<5/a<<endl;	
		}
		else
		{
			throw std::runtime_error("Can't divide by Zero");
		}
	}catch(exception& e)
	{
		cout<<e.what()<<endl;
	}


	try{
		cout<<stoi("Dihan")<<endl;
	}catch(exception& e)
	{
		cout<<e.what()<<endl;
	}
}