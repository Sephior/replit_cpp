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

부모 클래스가 존재할 시 부모 클래스의 생성자, 소멸자 호출
Student 객체 생성 시 Person생성자 실행 후 Student 생성자 실행
소멸자도 Student 소멸자 실행 후 Person 소멸자 실행
명시된 호출이 없는 경우 기본적으로 부모 클래스의 기본 생성자를 호출하도록 묵시적
삽입 매개변수 생성자만 있으면 오류

파생 클래스는 기본 클래스의 멤버 접근 가능
ㄴ 기본 클래스의 private 멤버엔 접근 불가


업 캐스팅 : 파생 클래스의 포인터를 기본 클래스의 포인터에 치환
ㄴ 파생 클래스를 기본 클래스로 보게 함
ㄴㄴ 파생 클래스의 멤버 접근이 불가능해짐


다운 캐스팅 : 기본 클래스의 포인터를 파생 클래스의 포인터에 치환
ColorPoint pDer = (ColorPoint *)pBase
형변환 사용
ㄴ 기본 클래스를 파생 클래스로 보게 함
ㄴㄴ 기본 클래스가 파생 클래스의 멤버 접근가능, 하지만 오류발생


protected에 대해
cp.x = 100;  에러 발생, 메인 함수도 외부 함수
객체 내부의 함수에서만 접근가능


상속 시의 접근 지정자(protected, public 대상)
public : 그대로 계승
private : private로 변경, 계승
protected : protected로 변경, 계승

예제 8-6 접근 지정의 컴파일 오류


다중 상속
class mp3 : public m4a, public mp4{};

1을 상속받은 (2, 3)을 상속받은 4의 경우
4의 객체가 2에서 온 1의 객체인지 3에서 온 1의 객체인지 모름(중복)

가상 상속 : 기본 클래스 멤버의 중복 상속 해결
2와 3의 클래스 상속에 virtual 키워드
class in : virtual public set{};
class out : virtual public set{};
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