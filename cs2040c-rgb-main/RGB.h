#ifndef EXAMPLE_RGB_H
#define EXAMPLE_RGB_H

class RGB {
private:
  int red_;
  int green_;
  int blue_;

public:
  RGB(int red, int green, int blue);
  ~RGB();

  int red() const { return red_; }
  int green() const { return green_; }
  int blue() const { return blue_; }

  void print();
  RGB mix(RGB& other);
};

#endif  // EXAMPLE_RGB_H