// // ios_base
// class _CRTIMP2_PURE_IMPORT ios_base : public _Iosb<int> { // base class for ios
// }


// // basic_ios
// class basic_ios : public ios_base


// // ios
// using ios           = basic_ios<char, char_traits<char>>;

/*
                    ios
            _________|_________
           |                   |
        istream             ostream
    _______|_______     _______|_______
   |               |___|               |
ifstream             |              ofstream
                 iostream
                     |
                 fstream
*/

#include<iostream>
#include<fstream>
using namespace std;
void f(istream& in){

}

int main(){
    f(cin);
}