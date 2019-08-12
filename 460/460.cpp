#include <iostream>
#include <vector>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class Solution {
public:
	/**
	 * @param A: an integer array
	 * @param target: An integer
	 * @param k: An integer
	 * @return: an integer array
	 */
	vector<int> kClosestNumbers(vector<int> &A, int target, int k) {
		// write your code here
		if (target <= A[0]) {
			// vector<int>ans(A.begin(), A.begin() + k);
			return vector<int>(A.begin(), A.begin() + k);
		}
		else if (target >= *(A.end() - 1)) {
			return vector<int>(A.rbegin(), A.rbegin() + k);
		}
		vector<int> ans;
		int r = findUpperClosest(A, target), l = r - 1;
		for (int _ = 0; _ != k; ++_) {
			if (isLeftCloser(A, target, l, r)) {
				ans.push_back(A[l]);
				--l;
			}
			else {  // l < 0: 左边到界,则右边一定没到
				ans.push_back(A[r]);
				++r;
			}
		}
		return ans;
	}
private:
	// find the first number not smaller than target.
	int findUpperClosest(vector<int> &A, int target) {
		int start = 0, end = A.size() - 1;
		while (start + 1 < end) {
			int mid = start + (end - start) / 2;
			if (target > A[mid]) {
				start = mid;
			}
			else {
				end = mid;
			}
		}
		if (A[start] >= target) {
			return start;
		}
		else {
			return end;
		}
	}
	bool isLeftCloser(vector<int> &A, int target, int l, int r) {
		if (l < 0) {  // 左边到界, 则右边一定没到
			return false;
		}
		if (r >= A.size()) {  // 右到到界, 则左边一定没到
			return true;
		}
		return (A[r] - target) < (target - A[l]) ? false : true;
	}
};

int main() {
	Solution s;
	vector<int> A = { 1,2,3 };
	auto ans = s.kClosestNumbers(A, 2, 3);
	for (auto num : ans) {
		cout << num << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}