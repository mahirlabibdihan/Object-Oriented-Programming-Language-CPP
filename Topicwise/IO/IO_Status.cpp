/*
template <class _Dummy>
class _Iosb {
	enum _Iostate { // constants for stream states
	        _Statmask = 0x17
	    };

	    static constexpr _Iostate goodbit = static_cast<_Iostate>(0x0);
	    static constexpr _Iostate eofbit  = static_cast<_Iostate>(0x1);
	    static constexpr _Iostate failbit = static_cast<_Iostate>(0x2);
	    static constexpr _Iostate badbit  = static_cast<_Iostate>(0x4);
}
class _CRTIMP2_PURE_IMPORT ios_base : public _Iosb<int> { // base class for ios
public:
    using iostate  = int;
}
*/

// C++ I/O System maintains status information about the outcome of each I/O operation

/* The current status of an I/O stream is described in an object of type iostate, which is an enumeration defined in ios with the following values:

	ios::goodbit
	ios::eofbit
	ios::failbit
	ios::badbit
*/

#include <iostream>
#include <fstream>
using namespace std;


// There are two ways to know current IO status
// 1
// We can use rdstate() function
// ios::iostate rdstate()
// rdstate returns the current iostate
// Deffault iostate is 0 (goodbit)

void checkStatus1(ifstream &in) {
	ios::iostate s;
	s = in.rdstate();
	if (s & ios::eofbit)
		cout << "EOF encountered" << endl;
	else if (s & ios::failbit)
		cout << "Non - Fatal I / O error encountered" << endl;
	else if (s & ios::badbit)
		cout << "Fatal I / O error encountered" << endl;
}

//2
//We can also use ios member functions:
/*
	bool eof()
	bool good()
	bool fail()
	bool bad()
*/

void checkStatus2(ifstream &in) {
	if (in.eof())
		cout << "EOF encountered" << endl;
	else if (in.fail())
		cout << "Non - Fatal I / O error encountered" << endl;
	else if (in.bad())
		cout << "Fatal I / O error encountered" << endl;
}


int main() {

}