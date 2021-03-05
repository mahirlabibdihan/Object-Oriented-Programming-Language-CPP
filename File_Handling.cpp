#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{	
	string Word;
	ofstream out("Data.txt", ios::out);
	// ofstream out;
	// out.open("Binary.txt", ios::out);

	if (!out)	// if(!out.is_open())
	{
		cerr << "Error in file opening" << endl;
		return 0;
	}
	getline(cin,Word);
	out<<Word<<endl;
	out.close();

	
	ifstream in("Data.txt", ios::in);
	// ofstream in;
	// in.open("Data.txt", ios::in);

	if (!in)	// if(!in.is_open())
	{
		cerr << "Error in file opening" << endl;
		return 0;	
	}
	
	while(!in.eof())
	{
		getline(in,Word);
		cout<<Word;
	}	
	in.close();
}