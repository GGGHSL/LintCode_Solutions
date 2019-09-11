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
	/*
	 * @param A: Given an integer array
	 * @return: nothing
	 */
	void heapify(vector<int> &A) {
		// write your code here
		if (A.empty()) {
			return;
		}
		for (int i = A.size() - 1; i != 0; --i) {
			siftDown(A, i);
		}
	}
private:
	void siftDown(vector<int> &A, int idx) {
		while(2 * idx + 1 < A.size() - 1) {
			int son = 2 * idx + 1;
			if (2 * idx + 2 < A.size() && A[2 * idx + 2] < A[son]) {
				son = 2 * idx + 2;
			}
			if (A[son] >= A[idx]) {
				break;
			}
			std::swap(A[idx], A[son]);
			idx = son;
		}
	}
};

int main() {
	
	system("pause");
	return 0;
}