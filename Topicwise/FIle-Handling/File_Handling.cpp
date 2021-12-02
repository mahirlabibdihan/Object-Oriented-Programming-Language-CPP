/*
 ______   _________ _      _       _
|  ____ \|___   ___| |    | |     | |
| |    \ \   | |   | |____| |     | |
| |    | |   | |   |  ____  |     | |
| |____/ /___| |___| |    | |_____| |
|_______/|_________|_|    |_________|
M A H I R     L A B I B     D I H A N

*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main()
{	
	/*
		 void ifstream::open(const char *filename,openmode mode=ios::in);
		 void ofstream::open(const char *filename,openmode mode=ios::out);
		 void fstream::open(const char *filename,openmode mode=ios::in | ios::out);
	*/	 

	/*
		openmode is an enumeraion defined by ios class.
		( Details in openmode.cpp )
	*/

	string Word="Dihan";
	/* Write */ 

	// ofstream inherits from ostream
	ofstream out("Data.txt",ios::out|ios::binary);
	// ofstream out("Data.txt",ios::out);


	if (!out)	// if(!out.is_open())
	{
		cerr << "Error in file opening" << endl;
		return 0;
	}
	// getline(cin,Word);
	out<<Word<<endl<<Word;
	out.close();


	/* Read */	
	// ifstream inherits from istream
	ifstream in("Data.txt");
	// ifstream in("Data.txt", ios::in);


	if (!in)	// if(!in.is_open())
	{
		cerr << "Error in file opening" << endl;
		return 0;	
	}
	


	while(!in.eof())
	{
		// char ch;
		// in>>ch;
		// printf("%d\n",ch);
		// cout<<ch<<endl;

		char str[2];
		in.read(str,1);
		cout<<str<<endl;
		
		// getline(in,Word);
		// cout<<Word<<endl;
	}	

	// Getting file size
	in.seekg(0,ios::end);
	cout<<in.tellg()<<endl;

	in.close();

	/* Read and Write */
	// fstream inherits from iostream . iostream inherits from istream,ostream ( fstream doesn't inherits from ifstream and ofstream. )
	fstream io("Data.txt");


	// Use cases:

	/** 1 **/
	// Reading from a file
		//1
		/*
			ifstream in("file.txt"); 
			ifstream in("file.txt",ios::in); 
		*/
		//2
		/*
			fstream in("file.txt",ios::in);
		*/
	
	/** 2 **/
	// Writing to a file ( Deleting previous content )
		//1
		/*
			ofstream out("file.txt"); 
			ofstream out("file.txt",ios::out);
		*/

		//2
		/*
			fstream out("file.txt",ios::out);
		*/

	/** 3 **/
	// Writing to a file ( Without Deleting previous content )
		//1
		/*
			ofstream out("file.txt",ios::out|ios::app);
				Here previous content is not deleted. But we can only append to this file.
				That means we can only write at the end of that file. We can not overwrite previous content.
				So if we want to overwrite previous content this is not a optimum solution.
		*/

		//2
		/* 
			fstream out("file.txt",ios::in|ios::out);
				Here we can write from beginning of the file. If there was any content previously, that will be replaced by newly written content.
				We can also append to the file by seeking at the end of the file using seekp(0,ios::end); 
		*/

	/** 4 **/
	// Writing at the end of the file ( Appending )
		//1
		/*
			ofstream out("file.txt",ios::out|ios::app);
				Here we can only append to this file.
				We can't seek to any position and write to file.
				Because it sets the stream's position indicator to the end of the stream before each output operation.
				It means the write position in the file is "sticky" -- all writes are at the end, no matter where you seek.
		*/

		//2
		/* 
			fstream out("file.txt",ios::in|ios::out);
				We can append to the file by seeking at the end of the file using seekp(0,ios::end); 
		*/

		//3
		/* 
			fstream out("file.txt",ios::in|ios::out|ios::ate);	
				ios::ate sets the stream's position indicator to the end of the stream on opening.
				So by default all the write operation will be at the end of the file.
				If we want to seek to random positions to write we can also do that.
		*/

	/** 5 **/
	// Open a file for both read and write, with deleting its content.
		//1
		/*
			fstream out("file.txt",ios::in|ios::out|ios::trunc);
				Here we will have read and write access to the file.
				And all the contents of the file will be deleted at the beginning.
		*/
}