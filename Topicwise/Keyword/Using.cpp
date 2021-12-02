#include <iostream>
// ​The using keyword is used to:

// 1. Bring a specific member from the namespace into the current scope.

using std::string; // Global Scope

// 2. Bring all members from the namespace into​ the current scope.
using namespace std;

// 3. Bring a base class method ​or variable into the current class’s scope.
class Base {
   public:
      void greet() {
         cout << "Hello from Base" << endl;;
      }
};
class Derived : Base {
   public:
      using Base::greet; 
      void greet(string s) {
         cout << "Hello from " << s << endl;
         // Instead of recursing, the greet() method
         // of the base class is called.
         greet();
      }
};


int main() {
  
  using std::cout;	// Local Scope
  string s = "Hello World";

  Derived D;
  D.greet("Derived");
  cout << s;
  return 0;
}