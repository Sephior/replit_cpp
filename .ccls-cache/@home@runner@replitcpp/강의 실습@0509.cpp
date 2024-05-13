#include <iostream>
using namespace std;

/*
동적 바인딩 <-> 정적 바인딩 :
실행시간 바인딩, 런타임 바인딩, 늦은 바인딩
가상 함수 호출 시
실행 중에 객체 내에 오버라이딩한 파생 클래스의 함수를 찾아 실행


가상 함수 : virtual 키워드로 선언된 함수
동적 바인딩 지시어
컴파일러에게 함수에 대한 호출 바인딩을 실행 시간까지 미루도록 지시
파생 클래스에서 재정의할 함수를 알려주는 역할
= 실행할 코드를 작성할 목적이 아님
  기본 클래스의 가상 함수를 굳이 구현할 필요가 있을까?

순수 가상 함수 : 함수의 코드가 없고 선언만 있는 가상 멤버 함수
               virtual void draw()=0; // 순수 가상 함수 선언

추상 클래스 : 최소한 하나의 순수 가상 함수를 가진 클래스
            온전한 클래스가 아니므로 객체 생성 불가
            포인터 생성은 가능
            상속 시의 기본 클래스 역할을 수행하기 위해 생성
파생 클래스에서 구현할 함수의 형태(원형)을 보여주는 인터페이스

단순하게 추상 클래스 상속 시 파생 클래스에서도 객체 생성 불가
(기본 클래스의 생성자를 호출하는 과정에서 오류 발생)


함수 오버라이딩(함수 재정의) :
파생 클래스에서 기본 클래스의 가상 함수와 동일한 이름의 함수 선언
자바는 전부 오버라이딩
가상 함수 이름, 매개 변수 타입과 개수, 리턴 타입이 모두 일치 필요
        (매개변수 타입과 개수만 다를 경우 함수 중복)
파생 클래스의 virtual 키워드는 생략 가능


기본 클래스의 가상 함수의 존재감 상실시킴
파생 클래스에서 오버라이딩한 함수가 호출되도록 동적 바인딩
함수 재정의라고도 부름
다형성의 한 종류
 - 기본 클래스에 draw() 클래스를 만들고
   자식 클래스에 자신만의 draw() 함수를 만들 수 있음
   기본 클래스의 포인터로 모든 파생 클래스의 객체 이용 가능


   void paint(Shape* p) { // 가상 함수의 재정의를 이용한 예제
   p->draw();
   }
   paint(new Circle()); // Circle을 그린다.
   paint(new Rect()); // Rect을 그린다.
   paint(new Line()); // Line을 그린다.


  실제로 만든 건 자식 클래스의 객체이므로
  기본 클래스의 포인터 delete 시 오류 발생 가능
  이를 해결하는 것이 가상 소멸자
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

// num2
class Shape {
public:
  void paint() { draw(); }
  virtual ~Shape() { cout << "del Shape" << endl; }

protected:
  virtual void draw() { cout << "Shape::draw() called" << endl; }
};

// Shape 클래스의 파생 클래스
class Circle : public Shape {
public:
  virtual void draw() {
    Shape::draw(); // 범위지정자로 함수 정적 바인딩 가능
    cout << "Circle::draw() called" << endl;
  }
  virtual ~Circle() { cout << "del Circle" << endl; }
};

class Line : public Shape {
public:
  // 파생 클래스의 virtual 키워드 생략 가능
  void draw() { cout << "Line::draw() called" << endl; }
  ~Line() { cout << "del Line" << endl; }
};

void num2() {
  Shape *pShape = new Circle(); // 업캐스팅
  // 동적 바인딩된 Circle의 draw() 호출
  pShape->paint();

  pShape = new Line(); // 업캐스팅
  pShape->paint();
  delete pShape;
}

// num3
class Calculator {
  void input() {
    cout << "정수 2 개를 입력하세요>> ";
    cin >> a >> b;
  }

protected:
  int a, b;
  virtual int calc(int a, int b) = 0; // 순수 가상 함수
public:
  void run() {
    input();
    cout << "계산된 값은 " << calc(a, b) << endl;
  }
};

class Adder : public Calculator {
public:
  int calc(int a, int b) { return a + b; }
};

class Subtracter : public Calculator {
public:
  int calc(int a, int b) { return a - b; }
};

void num3() {
  // Calculator cal;  // 추상 클래스라 객체 생성 시 오류
  Adder adder;
  Calculator *pCalc = new Subtracter;
  adder.run();
  pCalc->run();
}
} // namespace may_9