#include <iostream>
using namespace std;

namespace may_2 {
class BaseArray {
private:
  int capacity; // 동적 할당된 메모리 용량
  int *mem;

protected:
  BaseArray(int capacity = 100) {
    this->capacity = capacity;
    mem = new int[capacity];
  }
  ~BaseArray() { delete[] mem; }
  void put(int index, int val) { mem[index] = val; }
  int get(int index) { return mem[index]; }
  int getCapacity() { return capacity; }
};
class MyQueue : protected BaseArray {
  int head, tail;

public:
  MyQueue(int capacity = 100) : BaseArray(capacity) {
    head = 0; // 새로운 값이 들어갈 인덱스
    tail = 0; // 값을 가져올 인덱스
  }
  void enqueue(int n) {
    if (head - tail == capacity()) // 또 까먹은 가득 찼을 때
      return;
    put(head++, n);
    head = head % capacity();
  }
  int dequeue() {
    if (head - tail == 0) // 또 까먹은 비었을 때
      return -1;
    tail = tail % capacity();
    return get(tail++);
  }
  int capacity() { return getCapacity(); }
  int length() { return head - tail; }
};
void num1() {
  MyQueue mQ(100);
  int n;
  cout << "큐에 삽입할 5개의 정수를 입력하라>> ";
  for (int i = 0; i < 5; i++) {
    cin >> n;
    mQ.enqueue(n); // 큐에 삽입
  }
  cout << "큐의 용량:" << mQ.capacity() << ", 큐의 크기:" << mQ.length()
       << endl;
  cout << "큐의 원소를 순서대로 제거하여 출력한다>> ";
  while (mQ.length() != 0) {
    cout << mQ.dequeue() << ' '; // 큐에서 제거하여 출력
  }
  cout << endl << "큐의 현재 크기 : " << mQ.length() << endl;
}

// stack
class MyStack : protected BaseArray {
  int tos = 0;

public:
  MyStack(int capacity = 100) : BaseArray(capacity) {}
  void push(int n) {
    if (tos == capacity())
      return;
    put(tos++, n);
  }
  int pop() {
    if (tos == 0)
      return -1;
    return get(--tos);
  }
  int capacity() { return getCapacity(); }
  int length() { return tos; }
};
void num2() {
  MyStack mStack(100);
  int n;
  cout << "스택에 삽입할 5개의 정수를 입력하라>> ";
  for (int i = 0; i < 5; i++) {
    cin >> n;
    mStack.push(n); // 스택에 푸시
  }
  cout << "스택 용량:" << mStack.capacity() << ", 스택 크기:" << mStack.length()
       << endl;
  cout << "스택의 모든 원소를 팝하여 출력한다>> ";
  while (mStack.length() != 0) {
    cout << mStack.pop() << ' '; // 스택에서 팝
  }
  cout << endl << "스택의 현재 크기 : " << mStack.length() << endl;
}
} // namespace may_2