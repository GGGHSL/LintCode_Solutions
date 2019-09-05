#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::unordered_set;

class Solution {
public:
	/*
	 * @param n: The number of queens
	 * @return: All distinct solutions
	 */
	vector<vector<string>> solveNQueens(int n) {
		// write your code here
		if (n == 0) {
			return *new vector<vector<string>>{ vector<string>{""} };
		}
		if (n == 1) {
			return *new vector<vector<string>>{ vector<string>{"Q"} };
		}
		vector<int> cols;
		for (int i = 0; i != n; ++i) {
			cols.push_back(i);
		}
		vector<vector<string>> results;
		unordered_set<int> sum;
		unordered_set<int> diff;
		dfs(n, *new vector<bool>(n, false), sum, diff, *new vector<int>, results);
		return results;
	}
private:
	void dfs(int n,
		vector<bool> &visit, unordered_set<int> &sum, unordered_set<int> &diff,
		vector<int> &permutation, vector<vector<string>> &results) {
		vector<int> cols;
		for (int i = 0; i != n; ++i) {
			cols.push_back(i);
		}

		if (permutation.size() == cols.size()) {
			vector<string> loc;
			for (int i = 0; i != cols.size(); ++i) {
				string row(cols.size(), '.');
				row[permutation[i]] = 'Q';
				loc.push_back(row);
			}
			results.push_back(loc);
			return;
		}

		int row = permutation.size();
		for (int i = 0; i != cols.size(); ++i) {
			if (!isValid(cols[i], permutation, visit, sum, diff)) {
				continue;
			}
			permutation.push_back(cols[i]);
			visit[i] = true;
			sum.insert(row + cols[i]);
			diff.insert(row - cols[i]);
			dfs(n, visit, sum, diff, permutation, results);
			
			permutation.pop_back();
			visit[i] = false;
			sum.erase(row + cols[i]);
			diff.erase(row - cols[i]);
		}
	}
	inline bool isValid(int col, vector<int> &permutation, vector<bool> &visit, unordered_set<int> &sum, unordered_set<int> &diff) {
		if (visit[col]) {
			return false;
		}
		int row = permutation.size();
		if (sum.find(row + col) != sum.end()) {
			return false;
		}
		if (diff.find(row - col) != diff.end()) {
			return false;
		}
		return true;
	}
};

int main() {

	system("pause");
	return 0;
}