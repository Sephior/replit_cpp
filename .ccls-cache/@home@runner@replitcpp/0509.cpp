#include <iostream>
using namespace std;

/*


가상 함수 : virtual 키워드로 선언된 함수
동적 바인딩 지시어
컴파일러에게 함수에 대한 호출 바인딩을 실행 시간까지 미루도록 지시

함수 오버라이딩(함수 재정의) :
파생 클래스에서 기본 클래스의 가상 함수와 동일한 이름의 함수 선언
자바는 전부 오버라이딩

기본 클래스의 가상 함수의 존재감 상실시킴
파생 클래스에서 오버라이딩한 함수가 호출되도록 동적 바인딩
함수 재정의라고도 부름
다형성의 한 종류

*/

namespace may_9 {
class Base {
public:
  void f() { cout << "Base::f() called" << endl; }
  virtual void g() { cout << "Base::g() called" << endl; }
};
class Derived : public Base {
public:
  void f() { cout << "Derived::f() called" << endl; }
  virtual void g() { cout << "Derive::g() called" << endl; }
};
void num1() {
  Derived d, *pDer;
  pDer = &d;
  pDer->f(); // Derived::f() 호출

  Base *pBase;
  pBase = pDer; // 업캐스팅
  pBase->f();   // Base::f() 호출

  // 가상 함수를 통한 함수 재정의
  pDer->g();
  pBase->g();
}

} // namespace may_9