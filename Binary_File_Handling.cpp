
#include <fstream>
#include <iostream>
#include <cstring>
using namespace std;


// istream &get(char& ch)vie

int main(){
	ofstream ob("Binary.txt",ios::out|ios::binary|ios::trunc);
	int n=12345;
	ob.write((char *)(&n),2);	// Writing integer
	ob.write("12345",6);	// Writing string
	ob.close();


	// char ch;

	// char str[10];
	// ifstream ib("Binary.txt",ios::in|ios::binary);

	// while(!ib.eof())
	// {
	// 	ib.read(str,7);
	// 	cout<<str<<endl;
	// 	for(int i=0;i<7;i++){
	// 		cout<<str[i];
	// 	}
	// 	cout<<endl;
	// 	memset(str,'\0',sizeof str);
	// }
	// // while(true)
	// // {
	// // 	ib.get(ch);
	// // 	if(ib.eof()) break;		// Get set eof on failure
	// // 	cout<<ch<<endl;
	// // }	
	// ib.close();



	// We should not
}