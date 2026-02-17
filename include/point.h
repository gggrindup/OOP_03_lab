#pragma once
#include <cmath>
#include <iostream>

class Point {
public:
  Point();
  Point(double x, double y);

  Point &operator=(const Point &other);

  double length(const Point &other) const;
  bool is_equal(const Point &other) const;

  double x;
  double y;

  friend std::istream &operator>>(std::istream &is, Point &p);
  friend std::ostream &operator<<(std::ostream &os, const Point &p);
};