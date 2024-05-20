#include <iostream>
using namespace std;

/*
함수 중복의 약점 : 매개변수의 종류만 다르고 코드는 중복인 경우(char, string)

제네릭(일반화) :
함수나 클래스를 일반화시키고, 매개변수를 지정해 함수나 클래스 코드를 생성

템플릿 : 함수나 클래스를 일반화, template 키워드
        함수나 클래스 선언(코드 부분이 동일한 함수 일반화)
        제네릭 타입 : 일반화를 위한 데이터 타입

template <class T>
void myswap(T & a, T & b) { T tmp; } // T(임의의 타입)으로 변수 선언

int a, b;
myswap(a, b);     // 이때 int타입으로 함수 구체화
int a; double b;
myswap(a, b);     // 두 종류의 타입으로 함수 구체화 불가(같은 T)
*/

namespace may_16 {
class Circle {
  int radius;

public:
  Circle(int radius = 0) { this->radius = radius; }
  int getArea() { return 3.14 * radius * radius; }
};

template <typename T> void myswap(T &a, T &b) {
  T tmp;
  a = tmp;
  a = b;
  b = tmp;
}

void num0() {
  int a = 4, b = 5;
  myswap(a, b);
  double c = 1.4, d = 6.7;
  myswap(c, d);
  cout << a << b << c << d;
}
} // namespace may_16