#include <iostream>
using namespace std;
// 디폴트 매개변수와 함수중복
//함수 원형
void star(int a = 5);
void msg(int id, string text = "");

namespace april_08 {
void star(int a = 5) {
  for (int i = 0; i < a; i++)
    cout << "*";
  cout << endl;
}

void msg(int id, string text = "") { cout << id << " : " << text << endl; }
} // namespace april_08