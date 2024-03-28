#include "CoffeeVendingMachine.h"
#include <iostream>
using namespace std;

void CoffeeVendingMachine::fill() {
  for (int i = 0; i < 3; i++)
    tong[i].fill(10);
  cout << "커피 10, 물 10, 설탕 10" << endl;
}
void CoffeeVendingMachine::selectEspresso() {
  if (!tong[0].consume(1) || !tong[1].consume(1)) {
    cout << "원료가 부족합니다." << endl;
    return;
  }
  cout << "에스프레소 드세요" << endl;
}
void CoffeeVendingMachine::selectAmericano() {
  if (!tong[0].consume(1) || !tong[1].consume(2)) {
    cout << "원료가 부족합니다." << endl;
    return;
  }
  cout << "아메리카노 드세요" << endl;
}
void CoffeeVendingMachine::selectSugarCoffee() {
  if (!tong[0].consume(1) || !tong[1].consume(2) || !tong[2].consume(1)) {
    cout << "원료가 부족합니다." << endl;
    return;
  }
  cout << "설탕커피 드세요" << endl;
}
void CoffeeVendingMachine::show() {
  cout << "커피 " << tong[0].getSize() << ", 물 " << tong[1].getSize()
       << ", 설탕 " << tong[2].getSize() << endl;
}
bool CoffeeVendingMachine::checkInputError() {
  if (cin.fail()) {
    cin.clear();
    cin.ignore(100, '\n');
    cout << "입력 오류" << endl;
    return true;
  } else
    return false;
}
void CoffeeVendingMachine::run() {
  while (true) {
    cout << "** 커피자판기 작동 시작 **" << endl;
    cout << "메뉴를 눌러주세요(1:에스프레소, 2:아메리카노, 3:설탕커피, "
            "4잔량보기, 5:채우기)>> ";
    int option;
    cin >> option;
    if (checkInputError())
      continue;

    if (option == 0)
      break;

    switch (option) {
    case 1:
      selectEspresso();
      break;
    case 2:
      selectAmericano();
      break;
    case 3:
      selectSugarCoffee();
      break;
    case 4:
      show();
      break;
    case 5:
      fill();
      break;
    }
  }
}