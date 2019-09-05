#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::unordered_map;

class Solution {
public:
	/**
	 * @param digits: A digital string
	 * @return: all posible letter combinations
	 */
	vector<string> letterCombinations(string &digits) {
		// write your code here
		if (digits.empty()) {
			return *new vector<string>;
		}

		vector<string> letters{ "abc", "def", "ghi", "jkl","mno", "pqrs", "tuv", "wxyz" };
		vector<string> results;
		dfs(digits, letters, 0, *new string, results);
		return results;
	}
private:
	void dfs(string &digits, vector<string> &letters, 
		int index, string &permutation , vector<string> &results) {
		if (index == digits.size()) {
			results.push_back(permutation);
			return;
		}
		for (auto c : letters[digits[index] - 50]) {
			permutation.push_back(c);
			dfs(digits, letters, index + 1, permutation, results);
			permutation.pop_back();
		}
	}
};

int main() {
	string digits = "23";
	Solution s;
	auto res = s.letterCombinations(digits);

	system("pause");
	return 0;
}