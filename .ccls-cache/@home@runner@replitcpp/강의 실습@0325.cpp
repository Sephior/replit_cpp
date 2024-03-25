#include <iostream>
#include <string>
using namespace std;

namespace march_25 {
void num1() {
  string str;
  cout << "문자열을 입력하세요 : ";
  getline(cin, str, '\n');
  int length = str.length();
  cout << "입력받은 문자열의 길이는 " << length << "입니다." << endl;

  for (int i = 0; i < length; i++) {
    string first = str.substr(0, 1);
    string last = str.substr(1, length - 1);
    str = last + first;
    cout << str << endl;
  }
}

void num2(){
  
}
} // namespace march_25