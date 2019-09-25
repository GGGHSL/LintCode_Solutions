/* [Time Limit Exceeded]: O(2^n), n is the hight of the triangle.*/
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
	 * @param triangle: a list of lists of integers
	 * @return: An integer, minimum path sum
	 */
	int minimumTotal(vector<vector<int>> &triangle) {
		// write your code here
		if (triangle.empty() || triangle[0].empty()) {
			return 0;
		}

		traverse(0, 0, 0, minimum, triangle);
		return minimum;
	}
private:
	int minimum = INT8_MAX;
	void traverse(int x, int y, int pathSum, int &min, vector<vector<int>> &triangle) {
		if (x == triangle.size()) {
			if (pathSum < min) {
				min = pathSum;
			}
			return;
		}

		traverse(x + 1, y, pathSum + triangle[x][y], min, triangle);
		traverse(x + 1, y + 1, pathSum + triangle[x][y], min, triangle);
	}
};
