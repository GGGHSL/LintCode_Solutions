/* https://www.lintcode.com/problem/split-string/description */
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
	 * @param : a string to be split
	 * @return: all possible split string array
	 */
	vector<vector<string>> splitString(string& s) {
		// write your code here
		if (s.empty()) {
			return *new vector<vector<string>>{ vector<string>{} };
		}
		vector<vector<string>> results;
		if (s.size() == 1) {
			results.push_back(vector<string>{s});
			return results;
		}

		dfs(s, *new vector<int>, results);
		return results;
	}
private:
	void dfs(string &s, vector<int> &cuts, vector<vector<string>> &results) {
		if (!cuts.empty() && cuts.back() == s.size()) {
			results.push_back(getString(s, cuts));
			return;
		}
		
		int curr = 0;
		if (!cuts.empty()) {
			curr = cuts.back();
		}
		cuts.push_back(curr + 1);
		dfs(s, cuts, results);
		cuts.pop_back();
		
		if (curr + 2 <= s.size()) {
			cuts.push_back(curr + 2);
			dfs(s, cuts, results);
			cuts.pop_back();
		}
	}
	vector<string> getString(string &s, vector<int> &cuts) {
		vector<string> splits;
		splits.push_back(s.substr(0, cuts[0]));
		for (int i = 1; i != cuts.size(); ++i) {
			splits.push_back(s.substr(cuts[i - 1], cuts[i] - cuts[i - 1]));
		}
		return splits;
	}
};

int main() {
	string str = "123";
	Solution s;
	auto res = s.splitString(str);

	system("pause");
	return 0;
}