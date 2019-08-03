#include <iostream>
#include <vector>
#include <string>
#include "TwoSum.h"
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;


int main() {
	TwoSum ts;
	ts.add(2);
	ts.add(2);
	cout << ts.find(4) << " ";
	ts.add(2);
	ts.add(3);
	cout << ts.find(5) << endl;

	system("pause");
	return 0;
}