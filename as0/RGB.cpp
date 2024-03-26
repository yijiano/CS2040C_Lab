#include "RGB.h"

#include <iostream>

#define BOUND(x, min, max) ((x) < (min) ? (min) : ((x) > (max) ? (max) : (x)))

RGB::RGB(int red, int green, int blue) :
    red_(BOUND(red, 0, 255)),
    green_(BOUND(green, 0, 255)),
    blue_(BOUND(blue, 0, 255)) { }

RGB::~RGB() { }

void RGB::print() {
  std::cout << "RGB(" << red_ << ", " << green_ << ", " << blue_ << ") 	"
    << std::endl;
}

RGB RGB::mix(const RGB& other) {
	red_ += other.red();
	green_ += other.green();
	blue_ += other.blue(); 
  	return RGB(red_, green_, blue_);
}

RGB RGB::scale(double factor) {
	double output_R = red_ * factor;
	double output_G = green_ * factor;
	double output_B = blue_ * factor;
  	return RGB((int)output_R, (int)output_G, (int)output_B);
}