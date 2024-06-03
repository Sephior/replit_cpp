#include <cctype>
#include <iomanip>
#include <iostream>
using namespace std;

namespace may_27 {
void num1() {
  for (int i = 0; i < 4; i++)
    cout << setw(4) << "dec" << setw(5) << "hexa" << setw(5) << "char";
  cout << endl;

  for (int i = 0; i < 4; i++)
    cout << setw(4) << "---" << setw(5) << "----" << setw(5) << "----";
  cout << endl;

  for (int i = 0; i < 32; i++) {
    for (int j = 0; j < 4; j++) {
      cout << setw(4) << dec << 4 * i + j << setw(5) << hex << 4 * i + j;
      if (isprint(i))
        cout << setw(5) << 4 * i + j;
      else
        cout << setw(5) << '.';
    }
    cout << endl;
  }
}

class Phone { // 전화 번호를 표현하는 클래스
  string name;
  string telnum;
  string address;

public:
  Phone(string name = "", string telnum = "", string address = "") {
    this->name = name;
    this->telnum = telnum;
    this->address = address;
  }
  // private에 접근하기 위한 friend
  friend istream &operator>>(istream &stream, Phone &p) {
    // stream == cin
    cout << "이름 : ";
    stream >> p.name;
    cout << "전화번호 : ";
    stream >> p.telnum;
    cout << "주소 : ";
    cin >> p.address;
    return stream;
  }
  // private에 접근하기 위한 friend
  friend ostream &operator<<(ostream &stream, Phone p) {
    // stream == cout
    stream << "(" << p.name << ", " << p.telnum << ", " << p.address << ")";
    return stream;
  }
};

void num2() {
  Phone girl, boy;
  cin >> girl >> boy; //전화 번호를 키보드로부터 읽는다.
  cout << girl << endl << boy << endl; // 전화 번호를 출력한다.
}

istream &question(istream &ins) {
  cout << "거울아 거울아 누가 제일 예쁘니?";
  return ins;
}
void num3() {
  string answer;
  cin >> question >> answer;
  cout << "세상에서 제일 예쁜 사람은 " << answer << "입니다." << endl;
}
}
} // namespace may_27