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
} // namespace may_27