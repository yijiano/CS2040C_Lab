#include "food.h"

Food Food::operator+(const Food &rhs) const {
  // Passing lhs by value helps optimized chained a+b+c otherwise, both
  // parameters may be const references.
  std::string output_name = name() + " " + rhs.name();
  float total_calories = calories() + rhs.calories();
  return Food(output_name, total_calories);
}

bool Food::operator<(const Food &rhs) const {
  // Typically, once operator< is provided, the other relational operators
  // are implemented in terms of operator<.
  return calories() < rhs.calories();
}

bool Food::operator==(const Food &rhs) const {
  // Likewise, the inequality operator is typically implemented in terms of
  // operator==.
  return calories() == rhs.calories();
}
