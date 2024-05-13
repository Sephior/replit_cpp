#include <iostream>
using namespace std;

namespace may_13 {

class Shape {
protected:
  string name;       // 도형의 이름
  int width, height; // 도형이 내접하는 사각형의 너비와 높이
public:
  Shape(string n = "", int w = 0, int h = 0) {
    name = n;
    width = w;
    height = h;
  }
  virtual double getArea() = 0;
  // dummy 값 리턴
  string getName() { return name; } // 이름 리턴
};

class Oval : public Shape {
public:
  Oval(string n, int w, int h) : Shape(n, w, h) {}
  double getArea() { return 3.14 * (width / 2) * (height / 2); }
};
class Triangular : public Shape {
public:
  Triangular(string n, int w, int h) : Shape(n, w, h) {}
  double getArea() { return width * height / 2; }
};
class Rect : public Shape {
public:
  Rect(string n, int w, int h) : Shape(n, w, h) {}
  double getArea() { return width * height; }
};
void num1() {
  Shape *p[3];
  p[0] = new Oval("빈대떡", 10, 20); // 매개변수가 있는 생성자를 호출
  p[1] = new Rect("찰떡", 30, 40);   // 매개변수 생성자 명시 필요
  p[2] = new Triangular("토스트", 30, 40);
  for (int i = 0; i < 3; i++)
    cout << p[i]->getName() << " 넓이는 " << p[i]->getArea() << endl;
  for (int i = 0; i < 3; i++)
    delete p[i];
}

class Converter {
protected:
  double ratio;
  virtual double convert(double src) = 0; // src를 다른 단위로 변환한다.
  virtual string getSourceString() = 0;   // 소스 단위 명칭
  virtual string getDestString() = 0;     // dest 단위 명칭
public:
  Converter(double ratio) { this->ratio = ratio; }
  void run() {
    double src;
    cout << getSourceString() << "을 " << getDestString() << "로 바꿉니다.";
    cout << getSourceString() << "을 입력하세요>> ";
    cin >> src;
    cout << "변환 결과 : " << convert(src) << getDestString() << endl;
  }
};

class WonToDollar : public Converter {
protected:
  string source = "원화";
  string dest = "달러";
  string getSourceString() { return source; } // 함수 재정의
  string getDestString() { return dest; }
  double convert(double src) { return src / ratio; }

public:
  WonToDollar(double ratio) : Converter(ratio) {} // 비율이 다른 객체 생성
};
class KmToMile : public Converter {
protected:
  string source = "km";
  string dest = "mile";
  string getSourceString() { return source; }
  string getDestString() { return dest; }
  double convert(double src) { return src / ratio; }

public:
  // KmToMile(double ratio) : Converter(ratio) {}
  KmToMile() : Converter(1.609344) {}
};

void num2() {
  WonToDollar wd(1300); // 1 달러에 1300원 임의
  wd.run();
  KmToMile toMile; // 1mile은 1.609344 Km 고정
  toMile.run();
}
} // namespace may_13