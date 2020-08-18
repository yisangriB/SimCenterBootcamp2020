#include "Square.h"

int Square::numRect = 0;

Square::~Square() {
  numRect--;
  std::cout << "Square Destructor\n";
}

Square::Square(double w)
  :Shape(), width(w)
{
  numRect++;
}

double
Square::GetArea(void) {
  return width*width;
}

void 
Square::PrintArea(std::ostream &s) {
  s << "Square: " << width * width << " numRect: " << numRect << "\n";
}

