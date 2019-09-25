#include <iostream>
#include <vector>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int func(int n) {
	if (n == 0) {
		return 1;
	}
	int m = n;
	int cnt = 0;
	while (m != 1)
	{
		if (m % 2 == 0){
			m /= 2;
		}
		else {
			if (m == 3) {
				m /= 3;
			}
			else
			{
				++m;
			}
		}
		++cnt;
	}	
	return cnt;
}

int main() {
	int n;
	while (cin >> n) {
		cout << func(n) << endl;
	}
	system("pause");
	return 0;
}