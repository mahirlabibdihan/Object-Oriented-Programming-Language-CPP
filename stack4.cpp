#include <iostream>
using namespace std;

#define SIZE 10

class stack
{
private:
    char s[SIZE]; // holds the stack
    int top; // index of top of stack
public:
    stack()
    {
        top = 0;
    }

    // Push a character
    void push(char c)
    {
        if(top == SIZE)
        {
            cout<<"Stack is full"<<endl;
            return;
        }
        s[top++] = c;
    }

    // Pop a character
    char pop()
    {
        if(top == 0)
        {
            cout<<"Stack is empty"<<endl;
            return 0; // return null on empty stack
        }
        return s[--top];
    }

    bool empty()
    {
        return top == 0;
    }

};





int main(void)
{
	stack s1;

	s1.push('a');
	s1.push('b');
	s1.push('c');

    while(!s1.empty())
	{
	    cout<<"Pop stack : "<<s1.pop()<<endl;
	}

	return 0;
}
