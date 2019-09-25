#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using std::unordered_map;
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
		return memorized_search(triangle, 0, 0, *new unordered_map<string, int>);
	}
private:
	int memorized_search(vector<vector<int>> &triangle, int x, int y, unordered_map<string, int> &memo) {
		if (x == triangle.size()) {
			return 0;
		}
		string str{ char(x), char(y) };
		if (memo.find(str) != memo.end()) {
			return memo[str];
		}
		
		int left = memorized_search(triangle, x + 1, y, memo);
		int right = memorized_search(triangle, x + 1, y + 1, memo);
		
		int curr = left < right ? left : right;
		curr += triangle[x][y];
		memo[str] = curr;
		return curr;
	}
};

int main() {

	system("pause");
	return 0;
}