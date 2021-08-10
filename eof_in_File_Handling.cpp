/*
	When we try to read a whole file we depends on the end of file(eof) indicator.
	We usually keep reading from file until eof is reached. Once eof is reached it sets 'eofbit' flag(which signals that the End-of-File has been reached by the last input operation). Thus ios::eof will return true after that. And once the ios::eof returns true we stop reading from file. That's the general approach. 
*/

// We can read a whole file character by character.

while(true)
{
	char ch;
	in>>ch;
	// in.get(ch);		// binary mode
	if(in.eof()) break;
	cout<<ch<<endl;
}	


// We can read a whole file line by line.
While(true){
	string str;
	getline(in, Word);
	cout<<str;
	if(in.eof()) break;
}