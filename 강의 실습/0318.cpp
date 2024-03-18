#include <iostream>
using namespace std;

/*
 - 생성자는 반드시 호출, 없으면 컴파일러가 생성
 - 소멸자도 반드시 호출, 없으면 컴파일러가 생성

 - 만약 매개변수를 받는 생성자만 있는 상황에 매개변수 없는 생성자가 호출되면
   컴파일러가 생성자를 생성하지 않으므로 컴파일 에러
*/
namespace march_18 {

// 선언부
class Circle {      // 클래스 이름은 대문자
public:             // 접근 지정자
  int radius;       // 선언부에서 초기화 불가
  double getArea(); // 함수는 함수 원형 상태로만 선언

  Circle();      // 클래스 이름과 동일, 반환형 X - 생성자
  Circle(int r); // 매개변수의 차이에 따라 여러 개의 생성자 가능

  ~Circle(); // 반환형 X - 소멸자

}; // 클래스 끝에 세미콜론

// 구현부
double Circle::getArea() {       // Circle 클래스 내부에 getArea 선언
  return 3.14 * radius * radius; // 객체 내부의 멤버 변수 사용가능
}

Circle::Circle() : Circle(1) { // 코드 간소화를 위한 위임 생성자
  // radius = 1;
  // cout << "반지름 " << radius << " 원 생성" << endl;
}

Circle::Circle(int r) { // 타겟 생성자
  radius = r;
  cout << "반지름 " << radius << " 원 생성" << endl;
}

Circle::~Circle() { // 소멸자, 매개변수 X
  cout << "반지름 " << radius << " 원 소멸" << endl;
}

void num1() {
  Circle donut;
  donut.radius = 1;
  double area = donut.getArea();
  cout << "donut 면적은 " << area << endl;

  cout.clear();

  Circle pizza(15);
  // pizza.radius = 15;
  area = pizza.getArea();
  cout << "pizza 면적은 " << area << endl;
}

//

class Rectangle {
public:
  int width = 10, height = 10; // C++11부터 선언부에 초기화 가능
  int getArea();
  Rectangle();
  Rectangle(int a, int b);
};

int Rectangle::getArea() { return width * height; }

Rectangle::Rectangle() : Rectangle(1, 1) {} // 생성자 서두에 초기화
Rectangle::Rectangle(int a, int b) : width(a), height(b) {}

void num2() {
  Rectangle rect1, rect2, rect3,
      rect4(15, 15); // 동시에 두 개 이상의 객체 생성 가능
  rect1.width = 10;
  rect1.height = 20;
  rect2.width = 3;
  rect2.height = 5;
  cout << "rect1 면적은 " << rect1.getArea() << endl
       << "rect2 면적은 " << rect2.getArea() << endl
       << "rect3 면적은 " << rect3.getArea() << endl
       << "rect4 면적은 " << rect4.getArea() << endl;
}
} // namespace march_18
