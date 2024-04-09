#include <iostream>
using namespace std;

int superFib(int n){
	if (n < 0) throw std::out_of_range("n is negative");
	if (n <= 1) return 1;
	return 2 * superFib(n - 1);
};
