/*
(1) istream& getline (istream& is, string& str, char delim);

(2) istream& getline (istream& is, string& str);

The extraction also stops if the end of file is reached in is or if some other error occurs during the input operation.

Extracts characters from is and stores them into str until the delimitation character delim is found (or the newline character, '\n', for (2)).
*/


/*getline extracts character from istream and  stores into given string.
It stops extraction for two reason.
1. The delimitation character(Defualt: '\n') is found
2. The end of file is reached in istream. ( or if some other error occurs during the input operation. )

For reason 2 generally end of file occurs.
When end of file is reached it sets 'eofbit error state flag'(which signals that the End-of-File has been reached by the last input operation).

For example, while reading a 'istream in'. When end of file is reached getline will stop reading from in.
And in.eof() will be true.

That's why, while taking input from a file using getline in a loop, getline will be executed n times. ( n=number of lines in the file ).*/

// So we usually read in this way

while (!in.eof()){
	string str;
	getline(in, Word);
	cout<<str;
}

// Or

While(true){
	string str;
	getline(in, Word);
	cout<<str;
	if(in.eof()) break;
}