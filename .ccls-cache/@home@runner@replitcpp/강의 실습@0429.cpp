#include <iostream>
#include <string>
using namespace std;

/*
C++에서 상속 : 클래스 사이에서 상속관계 정의
             객체  사이에서 상속관계 없음
기본 클래스의 속성과 기능을 파생 클래스에 물려주는 것

기본 클래스 : 상속해주는 부모 클래스(super)
파생 클래스 : 상속받는 자식 클래스(sub)

상속관계는 다중 상속 가능 ㅡ 클래스의 재활용성
파생 클래스로 갈수록 클래스(의 개념) 구체화

class [클래스명] : public [부모 클래스명]{};


상속의 장점 :
1. 간결한 파생 클래스 작성
2. 클래스 간의 계층적 분류 및 관리 용이(구조 파악)
3. 클래스 재사용과 확장을 통한 생산성 향상

클래스의 객체 지향적 설계 필요

기본적인 기능을 가지는 Person
아래로 공부하기를 추가로 가지는 Student,
     연구하기를 추가로 가지는 Researcher

class Student : public Person
class Student : private Person
Studetn 클래스는 Person 클래스의 기능과 멤버를 물려받음
*/
namespace april_29 {
class Base {
public:
  Base() { cout << "Base 생성자" << endl; }
  ~Base() { cout << "Base 소멸자" << endl; }
};
class Point : public Base {
  int x, y;

public:
  Point();
  Point(int x, int y);
  ~Point();
  void set(int x, int y);
  void showPoint();
};
Point::Point() : Point(0, 0) {}
Point::Point(int x, int y) {
  this->x = x;
  this->y = y;
  cout << "Point 생성자(" << x << ", " << y << ")" << endl;
}
Point::~Point() { cout << "Point 소멸자(" << x << ", " << y << ")" << endl; }
void Point::set(int x, int y) {
  this->x = x;
  this->y = y;
}
void Point::showPoint() { cout << "(" << x << ", " << y << ")" << endl; }

// 상속
class ColorPoint : public Point {
  string color;

public:
  ColorPoint();
  ~ColorPoint();
  void setColor(string color);
  void showColorPoint();
};
ColorPoint::ColorPoint() {
  color = "무색";
  cout << "ColorPoint 생성자 (" << color << ")" << endl;
}
ColorPoint::~ColorPoint() {
  cout << "ColorPoint 소멸자 (" << color << ")" << endl;
}
void ColorPoint::setColor(string color) { this->color = color; }
void ColorPoint::showColorPoint() {
  cout << this->color;
  showPoint();
}

// 상속된 생성자와 소멸자의 호출 순서
void num1() {
  Point p;
  p.set(100, 200);
  p.showPoint();
  Point p2(300, 400);
  p2.showPoint();

  ColorPoint cp;
  cp.showPoint();
  cp.setColor("분홍");
  cp.showColorPoint();
}

// 업캐스팅, 다운캐스팅
void num2() {
  ColorPoint cp;
  cp.setColor("분홍");
  ColorPoint *pDer = &cp; // 포인터에 cp의 주소 입력, 업캐스팅
  Point *pBase = pDer;    // pDer - ColorPoint  !=  pBase - Point
  pBase->showPoint();     // Point 클래스의 객체에 showPoint()
  // pBase->showColorPoint();  Point 클래스에 showColorPoint()가 없으므로 실행X
  pDer = (ColorPoint *)pBase; // 다운캐스팅

  Point p;
  pDer = (ColorPoint *)&p; // Point p를 억지로 다운캐스팅
  pDer->showPoint();
  pDer->showColorPoint(); // 컴파일 가능하나 오류 발생
}
} // namespace april_29