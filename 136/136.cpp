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
	 * @param s: A string
	 * @return: A list of lists of string
	 */
	vector<vector<string>> partition(string &s) {
		// write your code here
		vector<vector<string>> results;
		if (s.empty()) {
			return results;
		}
		if (s.size() == 1) {
			results.push_back(vector<string>{s});
			return results;
		}
		vector<int> cuts;
		for (int i = 1; i != s.size() + 1; ++i) {
			cuts.push_back(i);
		}
		dfs(s, cuts, 0, *new vector<int>, results);
		return results;
	}
private:
	void dfs(string &s, vector<int> &cuts, int startIndex, vector<int> &subset, vector<vector<string>> &results) {
		if (!subset.empty()) {
			if (subset.back() == s.size()) {
				if (subset.size() == 1) {  // 之所以要加一条判断，是因为"ab"切[1]和切[1,2]结果是相同的，避免重复
					results.push_back(getString(s, subset));
				}
				return;
			}
			string str = s.substr(subset.back(), s.size() - subset.back());
			if (isPalindrome(str)) {
				results.push_back(getString(s, subset));
			}
		}
		for (int i = startIndex; i != cuts.size(); ++i) {
			int last = subset.empty() ? 0 : subset.back();
			string currStr = s.substr(last, cuts[i] - last);
			if (!isPalindrome(currStr)) {
				continue;
			}

			subset.push_back(cuts[i]);
			dfs(s, cuts, i + 1, subset, results);
			subset.pop_back();
		}

	}
	vector<string> getString(string &s, vector<int> &subset) {
		vector<string> splits;
		splits.push_back(s.substr(0, subset[0]));
		for (int i = 1; i != subset.size(); ++i) {
			splits.push_back(s.substr(subset[i - 1], subset[i] - subset[i - 1]));
		}
		if (subset.back() != s.size()) {
			splits.push_back(s.substr(subset.back(), s.size() - subset.back()));
		}
		return splits;
	}
	bool isPalindrome(string &str) {
		if (str.size() == 1) {
			return true;
		}
		for (int i = 0, j = str.size() - 1; i < j; ++i, --j) {
			if (str[i] != str[j]) {
				return false;
			}
		}
		return true;
	}
};

int main() {
	string str = "abb";
	Solution s;
	auto res = s.partition(str);

	system("pause");
	return 0;
}