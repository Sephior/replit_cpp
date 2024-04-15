#include <iostream>
using namespace std;

namespace april_15 {
int add(int* a, int b);
int add(int* a, int b, int* c);
void num1() {
  int a[] = {1, 2, 3, 4, 5};
  int b[] = {6, 7, 8, 9, 10};
  int c = add(a, 5);
  int d = add(a, 5, b);
  cout << c << endl;
  cout << d << endl;
}
int add(int a, int b, int c) { return a + b + c; }
int add(int a, int b) { return a + b; }
} // namespace april_15