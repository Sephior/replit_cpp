#include <iostream>
#include <string>
using namespace std;

namespace march_11 {
void example() {
  std::cout << "Hello World!\n";

  int width, height;
  /*
  cout << "너비 : ";
  cin >> width;

  cout << "높이 : ";
  cin >> height;
  */
  cout << "너비와 높이를 입력하세요 : ";
  cin >> width;  // 공백 문자로 구분해서 한꺼번에 입력 가능
  cin >> height; // 두개가 기대되었는데 3개를 입력받으면 하나는 버퍼에 저장 -
                 // 다음 cin에 사용

  int area = width * height;
  cout << "넓이 : " << area << endl;

  cin >> area;
  cout << area << "\n\n.";

  char address[99];
  // cin >> address; // 띄워쓰기 불가능
  cin.getline(address, 99, '\n'); // '\n'이 나올때까지 입력받음, 띄워쓰기 가능
  cout << "주소 : " << address;

  std::string song("Falling in love with you");
  string singer;
  getline(cin, singer);
  cout << song << singer;
}
} // namespace march_11
