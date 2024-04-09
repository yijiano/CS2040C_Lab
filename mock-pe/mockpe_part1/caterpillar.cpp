#include <iostream>
#include <string>
using namespace std;

string caterpillar(int n)
{
	if (n < 0) throw std::out_of_range("n is negative");
	std::string caterpillar = "<";
	for (int i = 0; i < n; i++) {
		caterpillar += "Q";
	}
	caterpillar += "6";
	return caterpillar;
}