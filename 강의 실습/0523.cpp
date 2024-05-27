#include <iomanip>
#include <iostream>
using namespace std;

/*
스트림 : 데이터의 흐름, 데이터를 전송하는 소프트웨어 모듈
스트림의 양 끝에는 프로그램과 장치 연결
보낸 순서대로 데이터 전달
기본 단위 바이트(8 bit)

입력 스트림 : 입력 장치, 네트워크, 파일로부터 데이터 전달
출력 스트림 : 출력 데이터를 출력 장치, 네트워크, 파일로 전달

C++입출력 시스템은 버퍼를 가짐
(입력 데이터를 전달하기 전에 임시로 저장)
(키 입력 도중 수정 가능, Enter를 기점)
(출력 장치 반복 사용의 비효율성 개선, 버퍼가 꽉 차거나 강제 출력 시 출력)
                                                cout.flush()


저수준 입출력 방식 : 키가 입력되는 즉시 전달(Backspace도 전달)
게임의 이동 등 즉각적인 전달이 필요할 때 사용
호환성 낮음(각기 다른 API)

ios : 모든 입출력 클래스의 기본 클래스, 공통 함수 선언
istream, ostream : 문자 단위 입력 / 출력 클래
ifstream, ofstream, fstream : 파일을 읽기 / 쓰기 / 편집 클래스

cin, cout
cerr : ostream, 오류 메세지 출력, 내부 버퍼 거치지 않고 출력
clog : ostream, 오류 메세지 출력, 내부 버퍼 거치고 출력

put(char) : char형 문자를 스트림에 출력
write(char*, int) : char형 배열에서 n개의 문자를 스트림에 출력
flush : 버퍼에 있는 값 강제 출력

int get() : 입력 스트림에서 문자를 읽어 리턴
get(char) : 입력 스트림에서 문자를 읽어 char에 저장하고 리턴
get(char*, int) : n-1개의 문자를 읽고 '\0'을 붙여 배열에 저장 후 리턴
                  이 경우 \n을 만나면 버퍼에 남아서 문제 발생, get이나 ignore
get(char*, int, char) : n-1개의 문자를 읽고 char을 만나면 배열에 저장 후 리턴
getline(char*, int, char) : n-1개의 문자를 읽고 char를 만나면 배열에 저장
                            버퍼에서 char를 제거한 후 반환
ignore(int, char) : char를 만나면 제거하고 반환, 아니면 int개 제거 후 반환
gcount() : 가장 최근에 스트림에서 읽은 문자 개수 리턴


포맷 플래그 : 입출력 형식을 지정하기 위한 플래그
            (버퍼 없이 출력, 공백 무시, 대소문자, 진수 표현, 소수점, 정렬 등)

setf(long) : long 자료형의 플래그를 출력 스트림의 플래그로 설정 후 이전 것 반환
unsetf(long) : 플래그에 따라 포맷 플래그를 해제하고 이전 플래그 반환

int width(int) : 출력 스트림의 플래그에 int로 최소 너비 설정 후 이전 값 반환
char fill(char) : 빈칸을 char로 채우고 이전 문자 반환
int precision(int) : 출력 스트림의 플래그에 int로 정수 + 소수 자리 수 설정


manipulator : 조작자, 포맷을 지정하는 함수, with <<, >>
#include <iomanip>

<<, >>에 대해 연산자 중복 사용(반드시 외부 함수)
ostream& operator << (ostream& stream, Book b){
  stream << b.title << b.author << b.price;
  return stream;
}
istream& operator >> (istream& stream, Book b){
  stream >> b.title >> b.author >> b.price;
  return stream;


사용자 정의 조작자 :
매개변수 없는 경우 : istream& NAME(istream& stream){return istream;}
매개변수 있는 경우 : ostream& NAME(ostream& stream, TYPE& var){return ostream;}
}
*/

namespace may_23 {
void num1() {
  cout.setf(ios::dec | ios::internal);

  cout.put('J');
  cout.put('K');
  cout.put('-').put('F').put('F');
  char str[] = "Homework";
  cout.write(str, 8);

  char string;
  cin.get();
  cin.get(string);
}

void num2() {
  cout << hex << showbase << 30 << endl;
  cout << dec << showpos << 90 << endl;
  cout << true << ' ' << false << endl;
  cout << boolalpha << true << ' ' << false << endl;
}

void num3() {
  for (int i = 0; i <= 50; i += 5) {
    cout << setw(10) << dec << i;
    cout << setw(10) << oct << i;
    cout << setw(10) << hex << i << endl;
  }
}
} // namespace may_23