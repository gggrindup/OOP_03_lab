#include "../include/square.h"
#include <cmath>
#include <stdexcept>

const double EPS = 1e-6;

Square::Square() {
  n = 4;
  p = new Point[n];
}

Square::Square(const Point &p1, const Point &p2, const Point &p3,
               const Point &p4) {
  double side1 = p1.length(p2);
  double side2 = p2.length(p3);
  double side3 = p3.length(p4);
  double side4 = p4.length(p1);

  // диагонали не равны нулю и равны между собой
  if (p1.length(p3) < EPS || p2.length(p4) < EPS ||
      p1.length(p3) - p2.length(p4) > EPS) {
    throw std::logic_error("This is not a square");
  }

  // все стороны равны
  if (std::abs(side1 - side2) > EPS) {
    throw std::logic_error("This is not a square");
  }

  n = 4;
  p = new Point[n];
  p[0] = p1;
  p[1] = p2;
  p[2] = p3;
  p[3] = p4;
}

Square::~Square() {
  delete[] p;
  p = nullptr;
}

double Square::getArea() const {
  double side1 = p[0].length(p[1]);
  double side2 = p[0].length(p[3]);
  return side1 * side2;
}

Square::operator double() const { return getArea(); }

Square &Square::operator=(const Square &other) {
  if (this != &other) {
    for (int i = 0; i < n; ++i) {
      p[i] = other.p[i];
    }
  }
  return *this;
}

bool Square::operator==(const Square &other) const {
  return static_cast<double>(*this) == static_cast<double>(other);
}