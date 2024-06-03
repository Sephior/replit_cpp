#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
텍스트 파일 : 문자와 특수문자, 이스케이프 시퀀스로 이루어진 파일
            txt, html, 소스 파일 등
            enter 입력 시 \n, \r

바이너리 파일 : 문자와 특수문자 외에도 그림, 사진, 동영상 등이 포함된 파일
              문자로 해석 안됨
              jpeg, mp4, hwp(포맷, 표 등), obj, exe

파일 읽기 시 ifstream, 파일 쓰기 시 ofstream
둘 다 fstream

>> 연산자와 istream의 get, read() 함수
n 연결된 장치로부터 읽는 함수
n 키보드에 연결되면 키 입력을, 파일에 연결되면 파일에서 입력

<< 연산자와 ostream의 put(), write() 함수
n 연결된 장치에 쓰는 함수
n 스크린에 연결되면 화면에, 파일에 연결되면 파일에 출력


*/

namespace june_03 {
void num1() {
  string from = "/etc/passwd.txt";
  string to = "./new_passwd.txt";
  // fstream text;
  // text.open(to);
  ifstream fin(from);
  if (!fin) {
    cout << "읽기 실패";
    return;
  }
  ofstream fout(to);
  if (!fout) {
    cout << "쓰기 실패";
    return;
  }
  // 파일 읽기
  int ch;
  while ((ch = fin.get()) != EOF) {
    if (ch >= 'a' && ch <= 'z')
      fout.put(ch - 32);
    else
      fout.put((char)ch);
  }
  fin.close();
  fout.close();
}

class Words {
  vector<string> wordVector;
  ifstream fin;

public:
  Words() {
    fin.open("words.txt");
    if (!fin) {
      cout << "읽기 실패";
      exit(0);
    }

    string word;
    while (getline(fin, word))
      wordVector.push_back(word);
    cout << "words.txt 로딩 완료" << wordVector.size() << endl;
  }
  ~Words() { fin.close(); }

  bool exist(string word) {
    for (int i = 0; i < wordVector.size(); i++)
      if (wordVector[i] == word)
        return true;
    return false;
  }

  void search(string word) {
    int length = word.length();
    for (int i = 0; i < wordVector.size(); i++) {
      if (wordVector[i].size() == length)
        if (wordVector[i] == word)
          continue;
      for (int j = 0; j < word.size(); j++) {
        string orig = word;
        string dic = wordVector[i];
        // 특정 글자를 같은 형태로 바꿔서 같은지 비교
        orig[j] = dic[j] = '*';
        if (orig == dic) {
          cout << wordVector[i] << endl;
          break;
        }
      }
    }
  }
};

void num2() {
  string from = "words.txt";
  ifstream word(from);
  if (!word) {
    cout << "읽기 실패";
    return;
  }

  vector<string> words;
  int ch;
  string ans;
  while ((ch = word.get()) != EOF) {
    if (ch == '\n') {
      words.push_back(ans);
      ans = "";
    } else
      ans += (char)ch;
  }
  cout << "words.txt 파일에서 단어를 읽어들였습니다." << endl;
  cout << "검색을 시작합니다. 단어를 입력해주세요." << endl;
  cout << "단어 >> ";
  cin >> ans;
  for (int i = 0; i < words.size(); i++) {
    int count = 0;
    for (int j = 0; j < ans.size(); j++)
      if (words[i][j] == ans[j])
        count++;
    if (count == ans.size() - 1 && ans.size() == words[i].size())
      cout << words[i] << endl;
  }
}
} // namespace june_03