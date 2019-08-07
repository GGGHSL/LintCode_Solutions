#include <iostream>
#include <vector>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::swap;

class Solution {
public:
	/**
	 * @param A: an integer array
	 * @return: nothing
	 */
	void sortIntegers2(vector<int> &A) {
		// write your code here
		if (A.empty()) {
			return;
		}
		helper(A, A.begin(), A.end() - 1);
	}
private:
	void helper(vector<int> &A, vector<int>::iterator left, vector<int>::iterator right) {
		if (left - right >= 0) {
			return;
		}
		auto pivot = *(left + (right - left) / 2);
		auto i = left, j = right;
		while (i - j <= 0) {
			while (i - j <= 0 && *i < pivot) {
				++i;
			}
			while (i - j <= 0 && *j > pivot) {
				--j;
			}
			if (i - j <= 0) {
				swap(*(i++), *(j--));
			}
		}
		helper(A, left, j);
		helper(A, i, right);
	}
};

int main() {
	Solution s;
	vector<int> A = { 3,2,1,4,5 };
	s.sortIntegers2(A);
	for (auto num : A) {
		cout << num << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}
