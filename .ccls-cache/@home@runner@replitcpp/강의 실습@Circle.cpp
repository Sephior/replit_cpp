#include "Circle.h"

double Circle::getArea() { return 3.14 * radius * radius; }

Circle::Circle() { radius = 1; }
Circle::Circle(int r) { radius = r; }