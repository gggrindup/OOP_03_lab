#pragma once
#include "point.h"
#include <iostream>

class Figure {
public:
  virtual ~Figure() = default;

  virtual double getArea() const = 0;
  virtual operator double() const = 0;

  Point getCenter() const;

protected:
  int n;
  Point *p;

  friend std::istream &operator>>(std::istream &is, Figure &figure);
  friend std::ostream &operator<<(std::ostream &os, const Figure &figure);
};