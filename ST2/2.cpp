#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <forward_list>
using std::forward_list;
using std::sort;
using std::cin;
using std::getline;
using std::cout;
using std::endl;
using std::string;
using std::vector;



int main() {
	string str1;
	getline(cin, str1);
	int n = int(str1[0]) - 48;
	int m = int(str1[2]) - 48;
	
	string str2;
	getline(cin, str2);
	sort(str2.begin(), str2.end(), [](int a, int b) {return a > b; });
	forward_list<int> a;
	for (auto c : str2) {
		// cout << c;
		if (c != ' ') {
			a.push_front(int(c) - 48);
		}
	}
	

	string str;
	for (int i = 0; i != m; ++i) {
		getline(cin, str);
		int l = str[0] - 49, r = str[2] - 49, k = str[4] - 48;
		
		auto b = a.before_begin();
		for (int j = 0; j != l; ++j) {
			++b;
		}
		auto curr = a.begin();
		for (int i = 0; i != l; ++i) {
			++curr;
		}
		
		auto e = a.before_begin();
		for (int i = 0; i != r; ++i) {
			if (e == a.end()) {
				break;
			}
			++e;
			--r;
		}
		if (k != 0 && b == e) {  // ÈôÃ»ÓÐÊý×Ö
			while (i != m) {
				cout << -1 << endl;
				++i;
			}
			break;
		}
		else {
			++e;
			while (k != 0) {
				if (b == e) {
					cout << *curr << endl;
					break;
				}
				++curr;
				b = a.erase_after(b);
				--k;
			}
		}
	}

	system("pause");
	return 0;
}