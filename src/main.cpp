#include "../include/figure_array.h"
#include "../include/rectangle.h"
#include "../include/square.h"
#include "../include/trapezoid.h"
#include <iostream>

int main() {
  FigureArray *figures = create_array();

  std::cout << "--- Adding figures ---\n";
  try {
    Figure *sqr1 = new Square();
    std::cout << "Enter Square:\n";
    std::cin >> *sqr1;
    add_figure(figures, sqr1);

    Figure *rect1 = new Rectangle();
    std::cout << "\nEnter Rectangle:\n";
    std::cin >> *rect1;
    add_figure(figures, rect1);

    Figure *trap1 = new Trapezoid();
    std::cout << "\nEnter Trapezoid:\n";
    std::cin >> *trap1;
    add_figure(figures, trap1);

  } catch (const std::exception &e) {
    std::cerr << "Error during figure creation: " << e.what() << '\n';
  }

  std::cout << "\n--- All figures in array ---\n";
  for (int i = 0; i < figures->size; ++i) {
    Figure *fig = figures->figures[i];

    std::cout << "Figure " << i << ": " << *fig
              << " Center: " << fig->getCenter() << " Area: " << fig->getArea()
              << "\n";
  }

  std::cout << "\nTotal area: " << total_area(figures) << "\n";

  std::cout << "\n--- Removing figure at index 1 (the rectangle) ---\n";
  if (figures->size > 1) {
    remove_figure(figures, 1);
  }

  std::cout << "\n--- Figures after removal ---\n";
  for (int i = 0; i < figures->size; ++i) {
    Figure *fig = figures->figures[i];
    std::cout << "Figure " << i << ": " << *fig
              << " Center: " << fig->getCenter() << " Area: " << fig->getArea()
              << "\n";
  }

  destroy_array(figures);

  std::cout << "\nProgram finished.\n";
  return 0;
}
