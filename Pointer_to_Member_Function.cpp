#include <cstdio>
class A {
public:
 int f();
};

int A::f() {
 return 1;
}


int main() {
 A a;
 printf("%d\n",(a.*(&A::f))()); // use together with an object of its class
}