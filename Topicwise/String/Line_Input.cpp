#include <iostream>
#include <string>
using namespace std;

int main()
{
	char str1[100];
	cin.getline(str1,100);
	cout<<str1<<endl;
	cin.get(str1,100);
	cout<<str1<<endl;
	// get() leaves the delimiter(\n) in the input buffer thus letting you able to consider it as part of the next input. getline() discards it, so the next input will be just after it.

	string str2;
	getline(cin,str2);
	cout<<str2<<endl;
}