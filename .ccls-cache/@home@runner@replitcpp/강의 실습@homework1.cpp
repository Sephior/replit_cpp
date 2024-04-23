#include <iostream>
#include <string>
using namespace std;

namespace hw1 {
// list 출력
void printList(string list[], int size) {
  for (int i = 0; i <= size; i++)
    cout << list[i] << ' ';
  cout << endl;
}
// 부호 판단, 함수중복
inline string isOperator(string c) {
  if (c == "+" || c == "-" || c == "*" || c == "/")
    return c;
  else
    return "0";
}

// 올바른 수식인지 확인
bool isValueError(string list[], int listIndex) {
  // 연산자가 2개 이상 연속으로 나오면 에러
  for (int i = 0; i < listIndex; i++)
    if (isOperator(list[i]) != "0" && isOperator(list[i + 1]) != "0")
      return true;
  // 연산자로 수식이 시작하거나 끝나면 에러
  if (isOperator(list[listIndex]) != "0" || isOperator(list[0]) != "0")
    return true;

  return false;
}

void calculate(string list[], int listIndex) {
  int index = 0;
  // 우선순위 먼저인 나눗셈/곱셈
  while (index < listIndex) {
    // 기호가 나오면 이전 인덱스 숫자와 이후 인덱스 숫자로 계산
    if (isOperator(list[index]) == "*") {
      list[index - 1] =
          to_string(stoi(list[index - 1]) * stoi(list[index + 1]));
      // 비는 인덱스가 없게 수정
      for (int j = index; j <= listIndex; j++)
        list[j] = list[j + 2];
      index--;
    }
    // 기호가 나오면 이전 인덱스 숫자와 이후 인덱스 숫자로 계산
    if (isOperator(list[index]) == "/") {
      list[index - 1] =
          to_string(stoi(list[index - 1]) / stoi(list[index + 1]));
      // 비는 인덱스가 없게 수정
      for (int j = index; j <= listIndex; j++)
        list[j] = list[j + 2];
      index--;
    }
    index++;
  }
  // 우선순위 이후인 덧뺄셈
  index = 0;
  while (index < listIndex) {
    // 기호가 나오면 이전 인덱스 숫자와 이후 인덱스 숫자로 계산
    if (isOperator(list[index]) == "+") {
      list[index - 1] =
          to_string(stoi(list[index - 1]) + stoi(list[index + 1]));
      // 비는 인덱스가 없게 수정
      for (int j = index; j <= listIndex; j++)
        list[j] = list[j + 2];
      index--;
    }
    // 기호가 나오면 이전 인덱스 숫자와 이후 인덱스 숫자로 계산
    if (isOperator(list[index]) == "-") {
      list[index - 1] =
          to_string(stoi(list[index - 1]) - stoi(list[index + 1]));
      // 비는 인덱스가 없게 수정
      for (int j = index; j <= listIndex; j++)
        list[j] = list[j + 2];
      index--;
    }
    index++;
  }
  // 계산 결과로 나온 첫 번째 리스트 값을 출력
  cout << endl << "결과 : " << list[0] << endl;
}

void hw1() {
  string s;
  cout << "입력식 : ";
  getline(cin, s, '\n'); // 문자열 입력
  if (cin.fail()) {
    cout << "잘못된 입력입니다." << endl;
    cin.clear();
    cin.ignore(100, '\n');
  }

  string tmp = ""; // 문자열 내에 검색할 시작 인덱스
  string *list = new string[s.length()]; // 새로운 동적 리스트 생성
  int listIndex = 0;                     // 리스트의 시작 인덱스

  // 문자 탐색
  // 탐색한 문자를 문자열 형태로 list에 저장
  for (int i = 0; i < s.length(); i++) {
    // 부호가 나왔는지 판단
    if (isOperator(string(1, s[i])) != "0") {
      // 부호가 나오면 tmp의 숫자를 리스트에 저장 후 연산자 저장
      if (tmp != "") {
        list[listIndex] = tmp;
        tmp = "";
        listIndex++;
      }
      list[listIndex] = isOperator(string(1, s[i]));
      listIndex++;
    } else // 숫자면 tmp에 추가
      tmp += s[i];
  }
  // 마지막으로 남은 숫자가 있으면 저장
  if (tmp != "")
    list[listIndex] = tmp;
  else
    listIndex--;

  // 검산 및 계산
  if (isValueError(list, listIndex)) {
    cout << "입력식이 잘못되었습니다." << endl;
  } else {
    calculate(list, listIndex);
    delete[] list;
  }
}
} // namespace hw1