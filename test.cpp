#include <iostream>
using namespace std;
class Animal{
public:
	Animal(){
		cout<<"Base constructor"<<endl;
	}
	~Animal(){
		cout<<"Base destructor"<<endl;
	}
};

class Dog:public Animal{
public:
	Dog(int x){
		cout<<"Derive constructor"<<endl;
	}
	~Dog(){
		cout<<"Derive destructor"<<endl;
	}
};

int main(){
	Dog d(1);
}
