#include "RGB.h"

#include <gtest/gtest.h>

namespace testing {

TEST(RGB, test_public_Constructor) {
	RGB rgb(1, 2, 3);
	EXPECT_EQ(1, rgb.red());
	EXPECT_EQ(2, rgb.green());
	EXPECT_EQ(3, rgb.blue());
}

TEST(RGB, test_public_Constructor_LimitValues) {
	RGB rgb(-1, 42, 256);
	EXPECT_EQ(0, rgb.red());
	EXPECT_EQ(42, rgb.green());
	EXPECT_EQ(255, rgb.blue());
}

TEST(RGB, test_public_Print) {
	// just test that print doesn't crash
	RGB rgb(200, 0, 200);
	rgb.print();
}

TEST(RGB, test_public_Mix) {
	RGB rgb1(200, 20, 30);
	RGB rgb2(10, 5, 100);
	RGB rgb3 = rgb1.mix(rgb2);
	EXPECT_EQ(210, rgb3.red());
	EXPECT_EQ(25, rgb3.green());
	EXPECT_EQ(130, rgb3.blue());
}

TEST(RGB, test_public_Scale) {
	RGB rgb1(200, 100, 150);
	RGB rgb2 = rgb1.scale(0.1);
	EXPECT_EQ(20, rgb2.red());
	EXPECT_EQ(10, rgb2.green());
	EXPECT_EQ(15, rgb2.blue());
}


}  // namespace testing