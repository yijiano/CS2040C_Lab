# CS2040C RGB Example

This repo provides skeleton code for an example RGB class. You will use this as the basis for implementing operator overloading.

## Building

[CMake](https://cmake.org/) is required to build this project. If you already have CMake installed, building is easy:

```bash
mkdir build && cd build
cmake ..
make && make test
```

If your system doesn't already have CMake installed, follow the instructions below.

### Linux

I would be shocked if your Linux system doesn't have CMake by default. No really. Please check before installing, just run `cmake --version`. If it somehow doesn't already have CMake, installing should be as easy as asking your package managed to install cmake, e.g. `sudo apt-get install cmake`.

### Mac

Mac doesn't generally include CMake out of the box, but it's often installed by other things so it's worth checking. Again, just run `cmake --version` from any command prompt. If you don't have CMake, there are two ways to install it:

1. The official [CMake](https://cmake.org/download) binaries.
2. Install [Homebrew](https://brew.sh/), and then `brew install cmake`.

You can also use XCode if you wish: just run `cmake .. -G XCode` and then open the resulting XCode project.

### Windows

The easiest way to do this lab on Windows (including the SoC computers) is to use Visual Studio Code. In VSCode:

1. Make sure the "C/C++ Extension Pack" is installed. This should include CMake and CMake Tools. You might have to restart after installing the extension pack.
2. Git clone this repo (which you can do from inside VSCode) and open the resulting folder.
3. Press ctrl-shift-p, and type in "CMake run tests". It may ask you for which compiler to use. Choose the most recent Visual Studio available.

Another option is to install the official [CMake](https://cmake.org/download) binaries and use Visual Studio directly:

1. Clone this repo and change to the directory you put it in.
2. Make a "build" directory and change directory to that.
3. Run `cmake ..`
4. Open the Visual Studio solution file generated.


## Unit Tests

Unit tests are in the `RGB_test.cpp` file and run automatically with `make test`. To add a new unit test, just add something like:

```C++
TEST(RGBTest, TestName) {
  // write test code here ...
}
```

Note that test names must be unique.

## Mixing Colours

When you mix two colours, you effectively average each of their components. So if you mix bright red RGB(240, 0, 0) and bright blue RGB(0, 0, 220) you would get something like RGB(120, 0, 110).

## Test Driven Development (TDD)

You are to work in pairs and follow TDD, aka "ping-pong programming". One partner writes a test case, and then the other partner writes the simplest code to satisfy the test case. Then the second partner writes the test case and the first writes the implementation. Continue until the tasks below are complete.

## Tasks

1. Add new method to `RGB` to mix the current colour with a given colour and return the new colour, `RGB RGB::mix(const RGB& c)`
2. Implement colour mixing as an overloaded "+" operator. If `c1` and `c2` are colours, then `RGB c3 = c1 + c2;` should result in the mix of `c1` and `c2`.
3. Write a method brighten a colour by a factor given as a real number. A factor of 1.0 means no change, while 2.0 would mean twice as bright (i.e. double each value) or 0.5 would be half as bright (i.e. halve each value).
4. Implement the method above as an overloaded "*" operator.
5. Implement a `+=` operator that acts as a shortcut for `c1 = c1 + c2`
6. Implement a `*=` operator that acts as a shortcut for `c1 = c1 * f`
7. Implement an equality test operator `==` that returns true if two RGB instances are the same. Can you use this operator to simplify your tests?
8. Implement a not-equals operator `!=` that returns true if two RGB instances are different. Can you use this operator to simplify any tests?
