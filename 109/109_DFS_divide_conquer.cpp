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
		return divide_conquer(triangle, 0, 0);
	}
private:
	int divide_conquer(vector<vector<int>> &triangle, int x, int y) {
		if (x == triangle.size()) {
			return 0;
		}
		int left = divide_conquer(triangle, x + 1, y);
		int right = divide_conquer(triangle, x + 1, y + 1);
		
		int curr = left < right ? left : right;
		return curr + triangle[x][y];
	}
};
