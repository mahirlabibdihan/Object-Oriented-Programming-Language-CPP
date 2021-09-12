#include <iostream>
using namespace std;
class A{
	
};

class B:public A{

};

void f(B b){

}
int main(){
	f(A());
}
