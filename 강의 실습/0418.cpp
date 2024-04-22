#include <iostream>
#include <string>
using namespace std;

namespace april_18 {

// Book class
class Book {
  string title;
  int price;
  int pages;

public:
  Book(string title = "", int price = 0, int pages = 0) {
    this->title = title;
    this->price = price;
    this->pages = pages;
  }
  void show() {
    cout << title << ' ' << price << "원 " << pages << " 페이지" << endl;
  }
  string getTitle() { return title; }

  // 연산자 함수 - 멤버 함수
  friend Book &operator+=(Book &b, int n);
  friend Book &operator-=(Book &b, int n);
  friend bool operator<(string a, Book &b);
  /*
    Book &operator+=(int n) {
      price += n;
      return *this;
    }
    Book &operator-=(int n) {
      price -= n;
      return *this;
    }
    */
  bool operator!() {
    if (price == 0)
      return true;
    else
      return false;
  }
};

// 매개변수 b에 해당하는 Book 객체 주소를 불러와서 고치고 반환하겠다는 반환형
Book &operator+=(Book &b, int n) {
  b.price += n;
  return b;
}
Book &operator-=(Book &b, int n) {
  b.price -= n;
  return b;
}
// 서로 다른 타입을 비교하려면 외부 함수
bool operator<(string a, Book &b) {
  if (a < b.getTitle())
    return true;
  else
    return false;
}

void num1() {
  Book a("청춘", 20000, 300), b("미래", 30000, 500);
  a += 500; // 책 a의 가격 500원 증가
  b -= 500; // 책 b의 가격 500원 감소
  a.show();
  b.show();

  Book book("벼룩시장", 0, 50); // 가격은 0
  if (!book)
    cout << "공짜다" << endl;

  Book c("청춘", 20000, 300);
  string d;
  cout << "책 이름을 입력하세요>>";
  getline(cin, d);
  if (d < c)
    cout << c.getTitle() << "이 " << d << "보다 뒤에 있구나!" << endl;
}

// num2
class Stack {
  int *stack;
  int top = 0;
  int size;

public:
  Stack() : Stack(10) {}
  Stack(int n) {
    size = n;
    stack = new int[size];
  }
  Stack &operator<<(int n) {
    // 스택이 최대면 그냥 반환
    if (top == size)
      return *this;
    stack[top++] = n;
    return *this;
  }
  Stack &operator>>(int &n) {
    // 스택이 최소면 그냥 반환
    if (top == 0)
      return *this;
    n = stack[--top];
    return *this;
  }
  bool operator!() {
    if (top == 0)
      return true;
    else
      return false;
  }
  ~Stack() { delete[] stack; }
};

void num2() {
  Stack stack; // 생성자에 인자를 주면 그 크기의 스택을 만들고 없을 경우 기본
               // 크기는 10
  stack << 3 << 5 << 10; // 3, 5, 10을 순서대로 푸시
  while (true) {
    if (!stack)
      break; // 스택 empty
    int x;
    stack >> x; // 스택의 탑에 있는 정수 팝
    cout << x << ' ';
  }
  cout << endl;
}
} // namespace april_18