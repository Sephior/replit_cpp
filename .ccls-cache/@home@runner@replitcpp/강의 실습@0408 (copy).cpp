#include <iostream>
#include <string>
using namespace std;
// 디폴트 매개변수와 함수중복
//함수 원형
void star(int a = 5);
void msg(int id, string text = "");

namespace april_08 {
//함수 원형에 디폴트 매개변수 선언 시 함수 구현부에는 디폴트 매개변수 없어도
//됨(역은 성립 X)
void star(int a = 5) {
  for (int i = 0; i < a; i++)
    cout << "*";
  cout << endl;
}

void msg(int id, string text = "") { cout << id << " : " << text << endl; }

// 전역 함수/변수는 객체마다 초기화되지 않음
class Person {
public:
  static int age; // 전역 변수
  string name;
  static void setAge(int a) { age = a; } // 전역 함수
  Person() {}
};

// 전역 초기화
int Person::age = 20;
void num1() {
  Person lee;
  lee.setAge(19); // 전역 멤버 함수를 통해 전역 멤버 변수 변경
  // public이 아니면 직접 접근 불가
  cout << Person::age << endl;
  cout << lee.age << endl;
  Person::age = 18; // 범위 지정 연산자 사용
  cout << lee.age << endl;

  Person *p = &lee;
  // p = &lee;
  p->setAge(19); // 포인터로 활용하는 사례
  p->name = "Kim";
}
} // namespace april_08