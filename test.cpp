#include <iostream>
using namespace std;
class A{
public:
	A(){
		cout<<"A created"<<endl;
	}
	~A(){
		cout<<"A destroyed"<<endl;
	}
};
class B{
public:
	static A *a;
	B(){
		
	}
	~B(){
		
	}
};
A *B::a=new A();

int main(){


	delete B::a;
}
