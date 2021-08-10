#include <fstream>
#include <ios>
#include <string>
#include <iostream>
#include <cstring>
using namespace std;

int main(){
	ofstream out("Dat.txt",ios::out|ios::binary);
	out<<"Dihan"<<endl<<"a";
	out.close();

	ifstream in("Dat.txt",ios::in);
	in.seekg(0,ios::end);
	cout<<in.tellg();
	in.close();

}

/*										Read						Write
	Text file + Text Mode 		-> '\r\n' -> '\n'				'\n'  -> '\r\n'
								-> '\n'	  -> '\n'				'\r'  -> '\r'

	Text file + Binary Mode 	-> '\r\n' -> '\r' '\n'			'\n'  -> '\n'
								   '\r'   -> '\r'				'\r'  -> '\r'
								   '\n'   -> '\n'

 	Binary file + Text Mode 	-> '\n'   -> '\n'				'\n'   -> '\n'
 								   '\r'   -> '\r'				'\r'   -> '\r'

	Binary file + Binary Mode	-> '\n'   -> '\n'				'\n'   -> '\n'
								   '\r'   -> '\r'				'\r'   -> '\r'
*/