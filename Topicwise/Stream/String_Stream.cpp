#include <iostream>
#include <sstream>
using namespace std;

int main()
{
	stringstream ss;
	ss<<"Mahir Labib Dihan";
	string word;
	ss>>word;
	cout<<word<<endl;
	ss<<"Noushin Tarannum Subha";
	ss>>word;
	cout<<word<<endl;

	stringstream ssnum("12345");
	int x=0;
	ssnum>>x;
	cout<<x<<endl;

	istringstream iss("12345");
	iss>>x;
	cout<<x<<endl;

	iss.str("2345");
	iss>>x;
	cout<<x<<endl;


	ostringstream oss("I am Dihan");
	cout<<oss.str()<<endl;
	oss<<"I am Ohi";
	cout<<oss.str()<<endl;
	oss<<"I am Subha";
	cout<<oss.str()<<endl;
}