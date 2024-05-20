#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

/*
iterator : 반복자
           컨테이너의 원소를 가리키는 포인터

vector<int>::iterator it;
*it = 원소의 값

begin() : 컨테이너의 시작 원소에 대한 주소
erase(), insert()에서 iterator 사용. 삽입, 삭제 후 벡터 조절


map 컨테이너 : 키, 값의 쌍을 원소로 저장하는 제네릭 컨테이너
              키로 값 검색

map <string, string> dict;
넣을 원소는 make_pair(key, value) 혹은 dict[key]=value 형태
dict.find(key) : key가 존재하면 key의 iterator 반환


알고리즘 함수 : 템플릿(자료형에 따라 구체화), 전역 함수(클래스의 멤버 아님)
              with iterator
              #include <algorithm>

sort() : start부터 stop-1까지 정렬
sort(v.begin(), v.end());


auto : 타입을 자동으로 선언하도록 하는 지정자
       초기값 없이 쓰면 컴파일 에러
auto i = 3 : int i = 3;
auto ret = square(3); // 험수의 리턴값으로 타입 지정 가능

iterator 선언 없이 사용 가능
// vector<int>::iterator it;
for (auto it = v.begin(); it != v.end(); it++)
    cout << *it << endl;


람다식 ,람다 함수, 익명 함수 : 수학 함수를 단순하게 표현
                            클래스처럼 함수식 끝에 세미콜론

[ ](int x, int y) { cout << x + y; }; // 매개변수 x, y의 합을 출력
[ ](int x, int y) -> int { return x + y; }; // 매개변수 x, y의 합을 int로 리턴
[ ](int x, int y) { cout << x + y; } (2, 3); // x에 2, y에 3을 대입하여 실행
*/

namespace may_20 {
void num1() {
  vector<string> v;
  for (int i = 0; i < 5; i++) {
    string s;
    getline(cin, s, '\n');
    v.at(i) = s;
  }
  for (int i = 0; i < v.size(); i++)
    cout << v[i];
}

void num2() {
  map<string, string> dict;

  dict.insert(make_pair("love", "사랑"));
  dict["apple"] = "사과";

  cout << dict.size();

  while (true) {
    string q;
    cout << "찾을 단어>> ";
    getline(cin, q);
    if (q == "exit")
      break;
    if (dict.find(q) == dict.end()) {
      cout << "없음" << endl;
    } else {
      cout << dict[q] << endl;
    }
  }
}

void num3() {
  double area;
  double pi = 3.14;
  auto love = [](string a, string b) {
    cout << a << "보다"
         << " " << b << "가 더 좋다." << endl;
  };
  love("돈", "너");

  auto getArea = [&area, pi](int r) { area = pi * r * r; };
  getArea(3);
  cout << area;

  vector<int> v = {1, 2, 3, 4, 5};
  // for_each()는 벡터 v의 첫번째 원소부터 끝까지 검색하면서,
  // 각 원소에 대해 3번째 매개변수인 람다식 호출. 매개변수 n에 각 원소 값 전달
  for_each(v.begin(), v.end(), [](int n) { cout << n << " "; });
}

void num4() {
  vector<int> v;
  int put;
  while (true) {
    cout << "정수를 입력하세요(0을 입력하면 종료)>> ";
    cin >> put;
    if (put == 0)
      break;
    v.push_back(put);

    double sum = 0;
    /*
      for (int i = 0; i < v.size(); i++) {
      cout << v[i] << " ";
      sum += v[i];
    }
    */
    for_each(v.begin(), v.end(), [&sum](int n) {
      cout << n << " ";
      sum += n;
    });
    cout << endl << "평균 = " << sum / v.size() << endl;
  }
}

class Book {
  string title;
  string author;
  int year;

public:
  Book(int year, string title, string author) {
    this->year = year;
    this->title = title;
    this->author = author;
  }
  int getyear() { return year; }
  string getauthor() { return author; }
  void print() { cout << year << "년도, " << title << ", " << author << endl; }
}; // namespace may_20
void num5() {
  vector<Book> v;
  cout << "입고할 책을 입력하세요. 년도에 -1을 입력하면 입고를 종료합니다."
       << endl;
  while (true) {
    string title;
    string author;
    int year;

    cout << "년도 >> ";
    cin >> year;
    if (year == -1) {
      break;
    } else {
      cout << "제목 >> ";
      cin >> title;
      cout << "저자 >> ";
      cin >> author;
      Book book(year, title, author);
      v.push_back(book);
    }
  }
  cout << "총 입고된 책은 " << v.size() << "권입니다." << endl;

  int year;
  string author;

  cout << "검색하고자 하는 저자 이름을 입력하세요 >> ";
  cin >> author;
  for_each(v.begin(), v.end(), [author](Book b) {
    if (b.getauthor() == author) {
      b.print();
    }
  });

  cout << "검색하고자 하는 연도를 입력하세요 >> ";
  cin >> year;
  for_each(v.begin(), v.end(), [year](Book b) {
    if (b.getyear() == year) {
      b.print();
    }
  });
}
} // namespace may_20