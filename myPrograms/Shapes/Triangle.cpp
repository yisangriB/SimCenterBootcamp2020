#include "Triangle.h"

int Triangle::numTri = 0;

Triangle::~Triangle() {
  numTri--;
  std::cout << "Triangle Destructor\n";
}

Triangle::Triangle(double w, double d)
  :Shape(), width(w), height(d)
{
  numTri++;
}

double
Triangle::GetArea(void) {
  return 1./2.*width*height;
}

void 
Triangle::PrintArea(std::ostream &s) {
  s << "Triangle: " << 1./2.*width * height << " numRectTri: " << numTri << "\n";
}

