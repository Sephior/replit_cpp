#include <iostream>
using namespace std;

namespace april_15 {
/*
int add(int x[], int size) {
  int result;
  for (int i = 0; i < size; i++)
    result += x[i];
  return result;
}

int add(int x[], int size, int y[]) { return add(x, size) + add(y, size); }
*/

int add(int x[], int size, int y[] = nullptr, int size2 = -1);

void num1() {
  int a[] = {1, 2, 3, 4, 5};
  int b[] = {6, 7, 8, 9, 10};
  int c = add(a, 5);
  int d = add(a, 5, b);
  cout << c << endl;
  cout << d << endl;
}

int add(int x[], int size, int y[], int size2) {
  int result = 0;
  for (int i = 0; i < size; i++) {
    result += x[i];
    //(y != nullptr ? result += y[i] : 0);
  }
  if (y != nullptr) {
    for (int i = 0; i < (size2 == -1 ? size : size2); i++) {
      result += y[i];
    }
  }
  return result;
}

//문제 2
/*
int big(int a, int b) { return (a > b ? a : b); }
int big(int a, int b, int c) { return (big(a, b) > c ? big(a, b) : c);}
*/
int big(int a, int b, int c = 100) {
  int max = (a > b ? a : b);
  return (max > c ? c : max);
}
void num2() {
  int x = big(3, 5);
  int y = big(300, 60);
  int z = big(30, 60, 50);
  cout << x << ' ' << y << ' ' << z << endl;
}

//문제 3
#include <cstdlib>
#include <ctime>
class random {
public:
  // 항상 다른 랜덤수를 발생시키기 위한 seed를 설정하는 함수
  static void seed() { srand((unsigned)time(0)); } // 씨드 설정
  static int nextInt(int min = 0,
                     int max = 32767); // min과 max 사이의 랜덤 정수 리턴
  static char nextAlphabet();
  static double nextDouble(); // 0보다 크거나 같고 1보다 적은 실수 리턴
};
int random::nextInt(int min, int max) { return rand() % (max - min + 1) + min; }
char random::nextAlphabet() {
  char result = rand() % 52;
  return (result < 26 ? result + 'A' : result - 26 + 'a');
}
double random::nextDouble() { return rand() / (double)RAND_MAX; }
void num3() {
  cout << "1에서 100까지 랜덤한 정수 10개를 출력합니다" << endl;
  random::seed();
  for (int i = 0; i < 10; i++)
    cout << random::nextInt(1, 100) << ' ';
  cout << endl;

  cout << "알파벳을 랜덤하게 10개 출력합니다" << endl;
  random::seed();
  for (int i = 0; i < 10; i++)
    cout << random::nextAlphabet() << ' ';
  cout << endl;

  cout << "0에서 1 사이의 실수 10개를 출력합니다" << endl;
  random::seed();
  for (int i = 0; i < 10; i++)
    cout << random::nextDouble() << ' ';
  cout << endl;
}

//문제 4

class ArrayUtility2 {
public:
  static int *concat(int s1[], int s2[], int size);
  static int *remove(int s1[], int s2[], int size, int &retSize);
};
int *ArrayUtility2::concat(int *s1, int *s2, int size) {
  int *p = new int[size * 2];
  /**/ if (!p)
    return nullptr;
  for (int i = 0; i < size; i++) {
    p[i] = s1[i];
    p[i + size] = s2[i];
  }
  return p;
}
int *ArrayUtility2::remove(int *s1, int *s2, int size, int &retSize) {
  int *p = new int[size];
  /**/ if (!p) {
    retSize = 0;
    return nullptr;
  }
  int index = 0;
  for (int i = 0; i < size; i++) {
    int j;
    for (j = 0; j < size; j++) {
      if (s1[i] == s2[j])
        break;
    }
    if (j == size) {
      p[index] = s1[i];
      index++;
    }
  }
  retSize = index;
  if (index == 0)
    return nullptr;
  int *q = new int[retSize];
  if (!q) {
    retSize = 0;
    return nullptr;
  }
  for (int i = 0; i < retSize; i++)
    q[i] = p[i];
  delete[] p;
  return q;
}
void num4() {
  int retSize = 5;

  int x[5], y[5];
  cout << "정수를 5개 입력하라. 배열 x에 삽입한다>>";
  for (int i = 0; i < 5; i++)
    cin >> x[i];
  cout << "정수를 5개 입력하라. 배열 y에 삽입한다>>";
  for (int i = 0; i < 5; i++)
    cin >> y[i];

  int *r1 = ArrayUtility2::concat(x, y, 5);
  int *r2 =
      ArrayUtility2::remove(x, y, 5, retSize); // 배열의 크기를 retSize에 저장
  for (int i = 0; i < 10; i++)
    cout << r1[i] << ' ';
  cout << endl;
  for (int i = 0; i < retSize; i++)
    cout << r2[i] << ' ';
  cout << endl;

  delete[] r1;
  delete[] r2;
}
} // namespace april_15