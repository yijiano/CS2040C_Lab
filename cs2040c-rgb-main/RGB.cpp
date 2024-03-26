#include "RGB.h"

#include <iostream>

#define BOUND(x, min, max) ((x) < (min) ? (min) : ((x) > (max) ? (max) : (x)))

RGB::RGB(int red, int green, int blue) :
    red_(BOUND(red, 0, 255)),
    green_(BOUND(green, 0, 255)),
    blue_(BOUND(blue, 0, 255)) { }

RGB::~RGB() { }

void RGB::print() {
  std::cout << "RGB(" << red_ << ", " << green_ << ", " << blue_ << ")"
    << std::endl;
}

RGB::mix(RGB& other) {
  
}