/*
* https://www.lintcode.com/problem/word-search-ii/leaderboard
*/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::unordered_map;
using std::unordered_set;
using std::pair;

class Solution {
public:
	/**
	 * @param board: A list of lists of character
	 * @param words: A list of string
	 * @return: A list of string
	 */
	vector<string> wordSearchII(vector<vector<char>> &board, vector<string> &words) {
		// write your code here
		if (board.empty() || board[0].empty() || words.empty()) {
			return *new vector<string>;
		}

		unordered_map<string, bool> prefix;
		for (auto word : words) {
			for (int i = 0; i != word.size() - 1; ++i) {
				string str = word.substr(0, i + 1);
				if (prefix.find(str) == prefix.end()) {
					prefix[word.substr(0, i + 1)] = false;
				}
			}
			prefix[word] = true;
		}
		unordered_set<string> results;
		vector<vector <unsigned>> visit(board.size(), vector<unsigned>(board[0].size(), 0));
		for (int i = 0; i != board.size(); ++i) {
			for (int j = 0; j != board[i].size(); ++j) {
				visit[i][j] = 1;
				dfs(board, words, prefix, vector<int>{ i, j }, visit, *new string{board[i][j]}, results);
				visit[i][j] = 0;
			}
		}
		return vector<string>(results.begin(), results.end());
	}
private:
	void dfs(vector<vector<char>> &board, vector<string> &words, unordered_map<string, bool> &prefix,
		vector<int> xy, vector<vector <unsigned>> &visit, string &permutation, unordered_set<string> &results) {
		
		if (prefix.find(permutation) == prefix.end()) {  // 要设为递归出口！！
			return;
		}
		if (prefix[permutation]) {
			results.insert(*new string(permutation));
		}
		
		int x = xy[0], y = xy[1];		
		vector<int> dx{ 0, 0, 1, -1 }, dy{ 1, -1, 0, 0 };
		for (int i = 0; i != 4; ++i) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || nx >= board.size() || ny < 0 || ny >= board[0].size()) {
				continue;
			}
			if (visit[nx][ny]) {
				continue;
			}
			permutation.push_back(board[nx][ny]);
			visit[nx][ny] = 1;
			dfs(board, words, prefix, vector<int>{nx, ny}, visit, permutation, results);
			permutation.pop_back();
			visit[nx][ny] = 0;
		}
	}
};

int main() {

	vector<vector<char>> board{ 
		vector<char>{'d', 'o','a','f'}, 
		vector<char>{'a', 'g','a','i'}, 
		vector<char>{'d', 'c','a','n'} };
	
	vector<string> words{ "dog","dad","dgdg","can","again" };

	Solution s;
	auto res = s.wordSearchII(board, words);
	for (auto word : res) {
		for (auto c : word) {
			cout << c;
		}
		cout << endl;
	}

	system("pause");
	return 0;
}