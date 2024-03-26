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
		 /**
		  * @brief Mixes this RGB with another RGB and return the result. Each
		  * component of the result is the sum of the inputs color channels.
		  * 
		  * @param other color to mix with this color.
		  * @return RGB the result of mixing this color with the other color.
		  */
		 RGB mix(const RGB& other);
		 /**
		  * @brief Scale the color by a factor. Each component of the returned
		  * color is the input component multiplied by the factor.
		  * 
		  * @param factor factor to apply to channel values.
		  * @return RGB result of applying the factor.
		  */
		 RGB scale(double factor);
};

#endif  // EXAMPLE_RGB_H
