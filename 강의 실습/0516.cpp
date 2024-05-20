#include <iostream>
#include <vector>
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

장점 : 함수 코드의 재사용
단점 : 포팅에 취약(하나의 시스템에서 다른 시스템에 사용 가능하도록 변경)
      - 윈도우에서 만들어진게 리눅스에서 사용할 수 있게 만들기 힘들다?
      컴파일 오류가 빈약 - 디버깅이 어려움


제네릭 프로그래밍 (일반화 프로그래밍) :
제네릭 함수나 클래스를 활용하는 프로그래밍 기법
STL 제공, 활용

일반화된 함수보다 중복된 함수가 우선해서 처리(char print() > T print())

클래스를 일반화할 경우 구체화될 정보를 알 수 없으므로 헤더 파일에 구현부가 필요


표준 템플릿 라이브러리(STL) :
많은 제네릭 클래스와 함수 포함

컨테이너 - 템플릿 클래스 : 데이터를 담아두는 자료구조를 표현한 클래스
                        리스트, 큐, 스택, 맵, 집합, 벡터
iterator - 컨테이너 원소에 대한 포인터
           컨테이너의 원소들을 순회하면서 접근하기 위해 만들어진 포인터
알고리즘 - 템플릿 함수 : 컨테이너 원소에 대한 복사, 검색, 삭제, 정렬 기능 함수
                      컨테이너의 멤버 함수는 아님(객체 지향에서 벗어남)

vector, deque, queue, stack, list, map, set
// #include <vector>, #include <stack> ..

(const) iterator : 다음 원소로
(const) reverse_iterator : 지난 원소로

copy, merge, random, max, min ...  // #include <algoritm>

STL은 std에 선언됨


#include <vector> :
가변 길이 배열을 구현한 제네릭 클래스
  개발자가 벡터의 길이에 대한 고민할 필요 없음
  원소의 저장, 삭제, 검색 등 다양한 멤버 함수 지원
  벡터에 저장된 원소는 인덱스로 접근 가능
  인덱스는 0부터 시작

  push_back(element) : element를 벡터 마지막에 추가
  at(index) : index번째 원소 참조 리턴
  begin() : 참조 리턴
  end()
  empty() : 벡터가 비어있으면 True
*/

namespace may_16 {
class Circle {
  int radius;

public:
  Circle(int radius = 0) { this->radius = radius; }
  int getArea() { return 3.14 * radius * radius; }
};

template <typename T, class T2>
void myswap(T &a, T2 &b) { // T, T2 매개변수 자료형 지정으로 코드 중복 일반화
  T tmp;
  tmp = a;
  a = b;
  b = tmp;
}

void num0() {
  int a = 4, b = 5;
  myswap(a, b);
  double c = 1.4, d = 6.7;
  myswap(c, d);
  Circle donut(5), pizza(10);
  myswap(donut, pizza);

  myswap(a, c);

  cout << a << b << c << d << donut.getArea() << pizza.getArea();
}

template <class T> // 반환형 지정
T bigger(T a, T b) { // 매개변수와 함께 반환형도 T로 지정, 리턴 시 자료형 T
  if (a > b)
    return a;
  else
    return b;
}
// src[]의 n개 원소를 dest[]에 복사하는 함수 (형변환)
template <class T1, class T2>
void mcopy(T1 src[], T2 dest[], int n) { // src[]의 n개 원소를 dest[]에 복사
  for (int i = 0; i < n; i++)
    dest[i] = (T2)src[i]; // T1 타입의 값을 T2 타입으로 명시적 형변환.
}
void num1() {
  int a = 20, b = 50;
  char c = 'a', d = 'z';
  cout << "bigger(20, 50)의 결과는 " << bigger(a, b) << endl;
  cout << "bigger('a', 'z')의 결과는 " << bigger(c, d) << endl;
}

template <class T> // 일반화 T
class MyStack {
  int tos;     // top of stack
  T data[100]; // T 타입의 배열. 스택의 크기는 100
public:
  MyStack();
  void push(T element); // element를 data [] 배열에 삽입
  T pop(); // 스택의 탑에 있는 데이터를 data[] 배열에서 리턴
};

template <class T> MyStack<T>::MyStack() { // 생성자
  tos = 0;                                 // 스택은 비어 있음
}

template <class T> void MyStack<T>::push(T element) {
  if (tos == 99) {
    cout << "stack full";
    return;
  }
  data[tos++] = element;
}

template <class T> T MyStack<T>::pop() {
  T retData;
  if (tos == 0) {
    cout << "stack empty";
    return 0; // 오류 표시
  }
  retData = data[--tos];
  return retData;
}
void num2() {
  MyStack<int> iStack; // int 만 저장하는 스택
  iStack.push(3);
  cout << iStack.pop() << endl;

  MyStack<double> dStack; // double 만 저장하는 스택
  dStack.push(3.5);
  cout << dStack.pop() << endl;

  MyStack<char> *p = new MyStack<char>(); // char만 저장하는 스택
  p->push('a');
  cout << p->pop() << endl;

  delete p;
}

class Point {
  int x, y;

public:
  Point(int x = 0, int y = 0) {
    this->x = x;
    this->y = y;
  }
  void show() { cout << '(' << x << ',' << y << ')' << endl; }
};

void num3() {
  MyStack<int *> ipStack; // int* 만을 저장하는 스택
  int *p = new int[3];
  for (int i = 0; i < 3; i++)
    p[i] = i * 10;        // 0, 10, 20으로 초기화
  ipStack.push(p);        // 포인터 푸시
  int *q = ipStack.pop(); // 포인터 팝
  for (int i = 0; i < 3; i++)
    cout << q[i] << ' '; // 화면 출력
  cout << endl;
  delete[] p;
  MyStack<Point> pointStack; // Point 객체 저장 스택
  Point a(2, 3), b;
  pointStack.push(a);             // Point 객체 a 푸시. 복사되어 저장
  b = pointStack.pop();           // Point 객체 팝
  b.show();                       // Point 객체 출력
  MyStack<Point *> pStack;        // Point* 포인터 스택
  pStack.push(new Point(10, 20)); // Point 객체 푸시
  Point *pPoint = pStack.pop();   // Point 객체의 포인터 팝
  pPoint->show();                 // Point 객체 출력
  MyStack<string> stringStack;    // 문자열만 저장하는 스택
  string s = "c++";
  stringStack.push(s);
  stringStack.push("java");
  cout << stringStack.pop() << ' ';
  cout << stringStack.pop() << endl;
}

void num4() {
  vector<int> v;

  v.push_back(10);
  v.push_back(20);
  v.push_back(30);

  int s = v.size();
  cout << s << endl;
  cout << v.capacity() << endl;
  v[0] = 0;
  v.at(1) = 999;
  for (int i = 0; i < v.size(); i++)
    cout << v[i];
}
} // namespace may_16