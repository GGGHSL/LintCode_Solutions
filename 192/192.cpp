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
	 * @param s: A string
	 * @param p: A string includes "?" and "*"
	 * @return: is Match?
	 */
	bool isMatch(string &s, string &p) {
		// write your code here
		return helper(s, p, 0, 0, *new unordered_map<string, bool>);
	}
private:
	bool helper(string &s, string &p, int i, int j, unordered_map<string, bool> &memo) {
		string curr{ char(i+1), char(j+1) };
		if (memo.find(curr) != memo.end()) {
			return memo[curr];
		}

		if (i == s.size()) {
			if (j == p.size() || p.substr(j, p.size()-j) == "*") {
				return true;
			}
			else {
				return false;
			}
		}
		if (j == p.size()) {
			return false;
		}
		
		if (p[j] == '*') {
			// '*' represents 0 chars or at least one char:
			memo[curr] = helper(s, p, i, j + 1, memo) || helper(s, p, i + 1, j, memo);
		}
		if (p[j] == '?' || p[j] == s[i]) {
			memo[curr] = helper(s, p, i + 1, j + 1, memo);
		}
		return memo[curr];
	}
};

int main() {
	string str = "a";
	string p = "a*";
	Solution s;
	cout << s.isMatch(str, p) << endl;

	system("pause");
	return 0;
}