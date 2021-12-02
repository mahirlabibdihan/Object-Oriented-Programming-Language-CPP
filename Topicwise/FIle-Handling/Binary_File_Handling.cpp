/*
 ______   _________ _      _       _
|  ____ \|___   ___| |    | |     | |
| |    \ \   | |   | |____| |     | |
| |    | |   | |   |  ____  |     | |
| |____/ /___| |___| |    | |_____| |
|_______/|_________|_|    |_________|
M A H I R     L A B I B     D I H A N

*/

#include <fstream>
#include <iostream>
#include <cstring>
using namespace std;


int main(){

	// ostream::write will always write into file in hexadecimal form whether we open the file ase binary mode or not.
	// The only difference with binary and text mode is,
	// In binary mode '\n' will be written as '\n' , but in text mode '\n' will be written as '\r\n'
	ofstream ob("Binary.txt",ios::out|ios::binary);
	int id=1905072;
	char* name="Mahir Labib Dihan";

	ob.write((char*)&id,sizeof(int));
	ob.write((char*)name,strlen(name)+1);

	ob.close();

	ifstream ib("Binary.txt",ios::in|ios::binary);
	int id2;
	char name2[30];

	ib.seekg(0,ios::beg);
	ib.read((char*)&id2,sizeof(int));
	ib.read(name2,20*sizeof(char));		
	// istream &read(char *buf, streamsize num)
	// Reads num number of bytes from the stream and puts them in buf
	// ib.gcount() = How many bytes have read in last istream::read() function. By using this, we can find out if num number of bytes is successfully read or not.

	cout<<id2<<" "<<name2;


	// We can also read the whole file at once by getting file size
	// Get file size
	// ib.seekg(0,ios::end);
	// int sz=ib.tellg();

	// ib.seekg(0,ios::beg);
	// ib.read(name2,sz);	
}