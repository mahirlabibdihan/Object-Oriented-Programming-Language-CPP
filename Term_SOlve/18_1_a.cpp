#include<iostream>
using namespace std;
class Student{
private:
	static int count;
	int ID;
public:
	Student(){
		ID=count++;
	}
};

int Student::count=1;

int main(){
	Student *s=new Student[120];
}