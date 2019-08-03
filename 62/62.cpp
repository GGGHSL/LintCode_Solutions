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
	 * @param A: an integer rotated sorted array
	 * @param target: an integer to be searched
	 * @return: an integer
	 */
	int search(vector<int> &A, int target) {
		// write your code here
		if (A.empty())
			return -1;
		auto n = A.size();
		if (n == 1) {
			if (A[0] == target)
				return 0;
			else
				return -1;
		}
		if (target == A[0])
			return 0;
		if (target == A[n - 1])
			return n - 1;

		int start = 0, end = n - 1, mid = 0;
		if (A[start] > A[end]) {  // rotated point inside:
			while (A[start] > A[end]) {
				if (end - start == 1)
					return -1;
				mid = start + (end - start) / 2;
				if (target == A[mid])
					return mid;
				else {
					if (target > A[start]) {
						if (A[mid] > target) {
							end = mid;
							break;  // goto sorted search
						}
						else {  // A[mid] < target
							if (A[mid] >= A[start])
								start = mid;
							else // A[mid] <= A[end]
								end = mid;
						}
					}
					else if (target < A[end]) {
						if (A[mid] < target) {
							start = mid;
							break;  // goto sorted search
						}
						else {  // A[mid] > target
							if (A[mid] <= A[end])
								end = mid;
							else  // A[mid] >= A[start]
								start = mid;
						}
					}
					else  // A[end] < target < A[start]
						return -1;
				}
			}

		}
		// A[start] < A[end], rotated point inside:
		while (start + 1 < end) {
			mid = start + (end - start) / 2;
			if (target == A[mid])
				return mid;
			else if (target < A[mid])
				end = mid;
			else
				start = mid;
		}
		return -1;
	}
};

int main() {
	return 0;
}