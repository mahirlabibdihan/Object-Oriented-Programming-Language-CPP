/*
 ______   _________ _      _       _
|  ____ \|___   ___| |    | |     | |
| |    \ \   | |   | |____| |     | |
| |    | |   | |   |  ____  |     | |
| |____/ /___| |___| |    | |_____| |
|_______/|_________|_|    |_________|
M A H I R     L A B I B     D I H A N

*/

/*
	We should open a file written in binary mode for random access.
	But if we open text file it will also be valid.
	But we will face problem if we try to randomly access in text file.
	Because we know new lines translated to '\r\n' which holds 2 bytes.
	So it creates problems,when we try to randomly access in text mode.

	---------------
	File.txt:
	---------------
	Dihan
	a
	---------------


	If we look at this file we will think that,
	'n' is at 5th(offset:4) position,
	new line('\n') is at 6th position,
	'a' is at 7th position.


	But.... 



	in.seekg(4,ios::beg);
	cout<<in.get();
	in.seekg(5,ios::beg);
	cout<<in.get();
	in.seekg(6,ios::beg);
	cout<<in.get();
	in.seekg(7,ios::beg);
	cout<<in.get();

	Output: (if we open this file in text mode.)
	110 ('n')
	10 ('\n')
	10 ('\n')
	97 ('a')



	Output: (if we open this file in binary mode.)
	110 ('n')
	13 ('\r')
	10 ('\n')
	97 ('a')
*/


/*
	seekdir is an enumeration defined in ios with the following values:
	ios::beg
	ios::cur
	ios::end
*/
#include <iostream>
#include <fstream>
using namespace std;

int main(){
	ifstream in("Binary.txt",ios::in|ios::binary);
	// istream &seekg(off_type offset, seekdir origin) -> Moves the current get pointer offset number of bytes from the specified origin. Get pointer is the pointer which is used for reading. Reading will start from where this pointer is located.

	// pos_type tellg() -> Returns current position of get pointer

	cout<<in.tellg()<<endl;

	in.seekg(2,ios::beg);	// 2 bytes left from the beginning
	cout<<in.tellg()<<endl;

	in.seekg(3,ios::cur);	// 3 bytes left from current position
	cout<<in.tellg()<<endl;
	
	in.seekg(-4,ios::end);	// 4 bytes right from the end
	cout<<in.tellg()<<endl;

	in.close();


	ofstream out("Binary.txt",ios::out|ios::binary);

	// ostream &seekp(off_type offset, seekdir origin) -> Moves the current put pointer offset number of bytes from the specified origin. Get pointer is the pointer which is used for writing. Writing will start from where this pointer is located.

	// pos_type tellp() -> Returns current position of put pointer

	cout<<in.tellg()<<endl;

	in.seekg(2,ios::beg);	// 2 bytes left from the beginning
	cout<<in.tellg()<<endl;

	in.seekg(3,ios::cur);	// 3 bytes left from current position
	cout<<in.tellg()<<endl;
	
	in.seekg(-4,ios::end);	// 4 bytes right from the end
	cout<<in.tellg()<<endl;

	out.close();

}