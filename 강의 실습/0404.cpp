#include <iostream>
#include <string>
using namespace std;

namespace april_04 {
class Person {
  string name;
  int id;

public:
  Person() { cout << "생성자 : " << name << endl; }
  Person(const Person &p); // 복사 생성자
  ~Person() { cout << "소멸자 : " << name << endl; }
  void changeName(string name) { this->name = name; }
};
Person::Person(const Person &p) {
  this->name = p.name;
  this->id = p.id;
}
void f(Person p) { p.changeName("dummy"); }
Person g() {
  Person m;
  m.changeName("Jane");
  return m;
}
void num0() {
  Person father;
  father.changeName("Kitae");
  Person son = father;
  f(father);
  son = g();
}

//문제 1
void half(double &n) { n = n / 2; } // 참조 매개변수 생성
void num1() {
  double n = 20;
  half(n);           // n의 주소이자 값을 가지는 참조 매개변수
  cout << n << endl; // return으로 반영하지 않아도 적용
}

//문제 2

class MyIntStack {
  int p[10];
  int tos; // 스택의 꼭대기를 가리키는 인덱스
public:
  MyIntStack();
  bool push(int n); // 정수 n 푸시. 꽉 차 있으면 false, 아니면 true 리턴
  bool
  pop(int &n); // 팝하여 n에 저장.스택이 비어 있으면 false, 아니면 true 리턴
};
MyIntStack::MyIntStack() { tos = 0; }
bool MyIntStack::push(int n) {
  if (tos == 10) {
    return false;
  }
  p[tos++] = n;
  return true;
}
bool MyIntStack::pop(int &n) {
  if (tos == 0) {
    return false;
  }
  n = p[--tos];
  return true;
}
void num2() {
  MyIntStack a;
  for (int i = 0; i < 11; i++) { // 11개를 푸시한다.
    if (a.push(i))
      cout << i << ' '; // 푸시된 값 에코
    else
      cout << endl << i + 1 << " 번째 stack full" << endl;
  }
  int n;
  for (int i = 0; i < 11; i++) { // 11개를 팝한다.
    if (a.pop(n))
      cout << n << ' '; // 팝 한 값 출력
    else
      cout << endl << i + 1 << " 번째 stack empty";
  }
  cout << endl;
}

//문제 3
class Dept {
  int size;    // scores 배열의 크기
  int *scores; // 동적 할당 받을 정수 배열의 주소
public:
  Dept(int size) { // 생성자
    this->size = size;
    scores = new int[size];
  }
  // Dept(const Dept &dept); // 복사생성자
  ~Dept(); // 소멸자
  int getSize() { return size; }
  void read(); // size 만큼 키보드에서 정수를 읽어 scores 배열에 저장
  bool isOver60(int index); // index의 학생의 성적이 60보다 크면 true 리턴
};
/*Dept::Dept(const Dept &dept) {
  // deepcopy
  this->size = dept.size;
  this->scores = new int[size];
  for (int i = 0; i < size; i++)
    this->scores[i] = dept.scores[i];
}*/
Dept::~Dept() {
  if (scores != nullptr) // 값이 없는 null인지 검사
    delete[] scores;
}
void Dept::read() {
  for (int i = 0; i < size; i++)
    cin >> scores[i];
}
bool Dept::isOver60(int index) {
  if (scores[index] >= 60)
    return true;
  return false;
}
int countPass(Dept &dept) { // dept 학과에 60점 이상으로 통과하는 학생의 수 리턴
  //해당 코두에서 호출하는 dept에 &를 붙여 참조 매개변수로 만들면 복사를 안함
  int count = 0;
  for (int i = 0; i < dept.getSize(); i++) {
    if (dept.isOver60(i))
      count++;
  }
  return count;
}

void num3() {
  Dept com(10); // 총 10명이 있는 학과 com
  com.read(); // 총 10명의 학생들의 성적을 키보드로부터 읽어 scores 배열에 저장
  int n = countPass(com); // com 학과에 60점 이상으로 통과한 학생의 수를 리턴
  //복사생성자의 깊은복사 없이는 오류발생
  //디폴트 복사생성자는 얕은 복사로 작동하므로 countPass 함수 종료 시 com을 중복
  //소멸하게 됨
  cout << "60점 이상은 " << n << "명";
}
} // namespace april_04