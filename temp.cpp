class MyBase {
public:
   int x;
   MyBase(int m) { x = m; }
};
class MyDerived : public MyBase {
public:
   int y;
   MyDerived() : MyBase(0) { y = 0; }
   MyDerived(int a) : MyBase(a)
   {
      y = 0;
   }
   MyDerived(int a, int b) : MyBase(a)
   {
      y = b;
   }
};

void main() {
   MyDerived o1; // x = 0, y = 0
   MyDerived o2(5); // x = 5, y = 0
   MyDerived o3(6, 7); // x = 6, y = 7
}
