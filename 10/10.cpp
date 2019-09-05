#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::sort;

class Solution {
public:
	/**
	 * @param str: A string
	 * @return: all permutations
	 */
	vector<string> stringPermutation2(string &str) {
		// write your code here
		if (str.empty()) {
			return *new vector<string>{ str };
		}
		sort(str.begin(), str.end());
		vector<string> results;
		dfs(str, *new vector<bool>(str.size(), false), *new string, results);
		return results;
	}
private:
	void dfs(const string &str, 
		vector<bool> &visit, 
		string &permutation, 
		vector <string> &results) {
		if (permutation.size() == str.size()) {
			results.push_back(*new string(permutation));
			return;
		}
		for (int i = 0; i != str.size(); ++i) {
			if (visit[i]) {
				continue;
			}
			if (i != 0 && str[i] == str[i - 1] && !visit[i - 1]) {
				continue;
			}
			permutation.push_back(str[i]);
			visit[i] = true;
			dfs(str, visit, permutation, results);
			permutation.pop_back();
			visit[i] = false;
		}
	}
};

int main() {

	system("pause");
	return 0;
}