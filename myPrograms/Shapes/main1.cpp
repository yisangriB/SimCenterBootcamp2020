#include "Rectangle.h"
#include "Circle.h"
#include "Square.h"
#include "Triangle.h"

int main(int argc, char **argv) {
  Circle s1(2.0);
  Shape *s2 = new Rectangle(1.0, 2.0);
  Shape *s3 = new Rectangle(3.0,2.0);
  Shape *s4 = new Square(4.0);
  Shape *s5 = new Triangle(1.0,2.0);
  Shape *s6 = new Triangle(10.0,5.0);

  s1.PrintArea(std::cout);
  s2->PrintArea(std::cout);
  s3->PrintArea(std::cout);
  s4->PrintArea(std::cout);
  s5->PrintArea(std::cout);
  s6->PrintArea(std::cout);

  return 0;
}


