#pragma once
#include "figure.h"

class Square : public Figure {
public:
  Square();
  Square(const Point &p1, const Point &p2, const Point &p3, const Point &p4);
  ~Square();

  double getArea() const override;
  operator double() const override;

  Square &operator=(const Square &other);
  bool operator==(const Square &other) const;
};