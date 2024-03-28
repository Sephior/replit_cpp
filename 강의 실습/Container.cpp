#include "Container.h"
#include <iostream>
void Container::fill(int n) {
  size += n;
  if (size > 10)
    size = 10;
}
bool Container::consume(int n) {
  if (size - n < 0) {
    return false;
  }
  size -= n;
  return true;
}
int Container::getSize() { return size; }