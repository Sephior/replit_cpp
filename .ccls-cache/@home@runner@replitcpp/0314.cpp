#include <iostream>
#include <string>
using namespace std;

/* 까먹은 개념
- 조건식 ? 참일 때 : 거짓일 때;
- 반복문
- C언어엔 min, max 없는거, 구현하는거
- string 클래스 include하고
- getline : 엔터를 치면 한 줄 전체를 입력받고 줄 바꿈
*/

// 숫자를 6개 입력받아 비교하는 문제
void num1() {
  cout << "6개의 실수를 입력하세요 : ";

  double input, min, max;

  cin >> input;
  min = max = input;

  for (int i = 0; i < 5; i++) {
    cin >> input;
    max < input ? max = input : max;
    min > input ? min = input : min;
  }
  cout << "가장 큰 수" << max << endl;
  cout << "가장 작은 수" << min << endl;
}

// 이름, 나이, 주소를 입력받아 특정한 형태로 출력하는 문제
void num2() {
  string name, address, age;
  cout << "이름 : ";
  getline(cin, name);
  cout << "주소 : ";
  getline(cin, address);
  cout << "나이 : ";
  getline(cin, name);

  cout << name << " (" << age << "세) " << address << endl;
}

// 중국집 주문과정 C++로 작성하기, 메뉴와 사람 수를 입력받고 이를 출력
void num3() {
  cout << "** 중국집 **";

  int input = 0, person = 0;
  while (input != 4) {
    cout << "짬뽕:1, 짜장:2, 탕수육:3, 종료:4 >> ";
    cin >> input;
    switch (input) {
    case 1:
      cout << "몇인분?";
      cin >> person;
      cout << "짬뽕 " << person << "인분 나왔습니다." << endl;
      break;
    case 2:
      cout << "몇인분?";
      cin >> person;
      cout << "짜장 " << person << "인분 나왔습니다." << endl;
      break;
    case 3:
      cout << "몇인분?";
      cin >> person;
      cout << "탕수육 " << person << "인분 나왔습니다." << endl;
      break;
    case 4:
      cout << "영업 종료, 감사합니다.";
      break;
    default:
      cout << "잘못 입력했습니다." << endl;
    }
  }
}

int main() { num3(); }