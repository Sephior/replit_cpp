#include "CoffeeVendingMachine.h"
#include "Container.h"
#include <iostream>
#include <string>
using namespace std;

namespace march_28 {
void num1() {
  cout << "문자열 입력 > ";
  string str;
  getline(cin, str, '\n');

  char bet;
  int alpha[26] = {
      0,
  }; //모든 초기값을 0으로 채우겠다.

  for (int i = 0; i < str.length(); i++)
    if (str[i] >= 'a' && str[i] <= 'z')
      alpha[str[i] - 'a']++;

  for (int i = 0; i < 26; i++) {
    if (alpha[i] > 0) {
      bet = i + 'a';
      cout << bet << " : " << alpha[i] << endl;
    }
  }
}

//해설 정답
void answer1() {
  cout << "문자열 입력 > ";
  string text;
  getline(cin, text, '\n');

  int startIndex = 0;
  int counts['z' - 'a' + 1] = {
      0,
  };

  for (char c = 'a'; c <= 'z'; c++) {
    while (true) {
      if (text.find(c, startIndex) == -1)
        break;
      counts[c - 'a']++;
      startIndex++;
    }
  }

  for (int i = 0; i < 26; i++)
    cout << counts[i];

  for (char c = 'a'; c <= 'z'; c++)
    if (counts[c - 'a'] != 0)
      cout << c << " : " << counts[c - 'a'] << endl;
}

//문제 2
class Circle {
private:
  int radius;

public:
  Circle();
  Circle(int r);
  double getArea();
};
Circle::Circle() { radius = 1; }
Circle::Circle(int r) { radius = r; }
double Circle::getArea() { return 3.14 * radius * radius; }

void num2() {

  cout << "원의 개수 >> ";
  int n, r, count = 0;
  cin >> n;
  Circle *p = new Circle[n]; // 동적 메모리 생성

  for (int i; i < n; i++) {
    cout << "원의 반지름 >> ";
    cin >> r;
    p[i] = Circle(r);
    if (p[i].getArea() >= 100)
      count++;
  }

  cout << "면적이 100보다 큰 원은 " << count << "개 입니다.";
  delete[] p; //동적 메모리 반환
}

//문제 3
void num3() {
  CoffeeVendingMachine VM;
  VM.run();
  cout << "정상적으로 출력되었습니다.";
}

} // namespace march_28