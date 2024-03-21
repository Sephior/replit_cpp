#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
using namespace std;

namespace march_21 {

/*
객체의 상태인 멤버 변수 보호 - private, protect
중요한 멤버(변수, 함수)를 다른 객체에서 접근 방지
외부와의 인터페이스(정보 교환)을 위해 일부 멤버는 외부에 접근 - public

접근 지정자는 중복 사용 가능

rand 라이브러리와 time 라이브러리 용법 까먹었따
*/

// 선언부
class Circle {
  //디폴트값은 private - 같은 멤버끼리만 접근 가능
  int radius;

public: // 접근 지정자 중복
private:
public: // 모든 다른 클래스에 허용되는 접근 지정자
  // int radius;
  double getArea(); // 기능적인 멤버 함수

  Circle(); // 객체 생성 멤버 함수
  Circle(int r);

  void setRadius(int r); // 멤버 변수 액세스(저장)
  int getRadius();       // 멤버 변수 액세스(조회)
};

// 구현부
double Circle::getArea() { return 3.14 * radius * radius; }

Circle::Circle() : Circle(1) {}

Circle::Circle(int r) {
  // radius = r;
  setRadius(r);
}

void Circle::setRadius(int r) {
  if (r < 0) { // 정상적인 범위 설정 가능
    cout << "정상적인 반지름 값이 아닙니다" << endl;
    radius = 1;
  } else {
    radius = r;
  }
}
int Circle::getRadius() { return radius; }

void num1() {
  Circle c1; // 멤버 변수가 public이면 아래와 같은 문제 혹은 변수명 문제 발생
  // c1.radius = -100;
  c1.setRadius(-100);
  cout << "c1의 면적은 " << c1.getArea() << endl;
  Circle c2(-100);
  cout << "c2의 면적은 " << c2.getArea() << endl;
  cout << "c2의 반지름은 " << c2.getRadius() << endl;
}

//
//

class Account {

private:
  string name;
  int id;
  int balance;

public:
  Account(string name, int id, int balance);
  void deposit(int money);
  string getOwner();
  int withdraw(int money);
  int inquiry();
};

void Account::deposit(int money) { balance += money; }
string Account::getOwner() { return name; }
int Account::withdraw(int money) {
  balance -= money;
  return money;
}
int Account::inquiry() { return balance; }

Account::Account(string a, int b, int c) {
  name = a;
  id = b;
  balance = c;
}

void num2() {
  Account a("youn", 1, 5000); // id 1번, 잔액 5000, 이름 youn
  a.deposit(50000);           // 50000저금
  cout << a.getOwner() << "의 잔액은 " << a.inquiry() << endl;
  int money = a.withdraw(20000);
  cout << a.getOwner() << "의 잔액은 " << a.inquiry() << endl;
}

//
//

class Random {
public:
  Random();
  int next();
  int nextInRange(int a, int b);
};

Random::Random() { srand((unsigned)time(0)); }
int Random::next() { return rand(); }
int Random::nextInRange(int a, int b) { return rand() % (b - a + 1) + a; }

void num3() {
  Random r;
  cout << "0에서 " << RAND_MAX << "까지의 랜덤 정수 10개 —" << endl;
  for (int i = 0; i < 10; i++) {
    int n = r.next();
    cout << n << " ";
  }
  cout << endl << endl << "2에서 4까지의 랜덤 정수 10개" << endl;
  for (int i = 0; i < 10; i++) {
    int n = r.nextInRange(2, 4);
    cout << n << " ";
  }
  cout << endl;
}
} // namespace march_21