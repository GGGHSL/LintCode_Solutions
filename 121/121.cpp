/* https://www.lintcode.com/problem/word-ladder-ii/description */
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::unordered_set;
using std::unordered_map;
using std::queue;

class Solution {
public:
	/*
	 * @param start: a string
	 * @param end: a string
	 * @param dict: a set of string
	 * @return: a list of lists of string
	 */
	vector<vector<string>> findLadders(string &start, string &end, unordered_set<string> &dict) {
		// write your code here
		vector<vector <string>> results;
		if (start == end) {
			results.push_back(vector<string>{start, end});
			return results;
		}
		if (dict.empty()) {
			return results;
		}
		dict.insert(start);
		dict.insert(end);
		auto patternDict = buildPatternDict(dict);
		auto distances = bfs(end, patternDict);
		dfs(start, end, *new vector <string>{ start }, patternDict, distances, results);
		return results;
	}
private:
	// 1.递归定义
	void dfs(string &curr, string &target, vector <string> &path, unordered_map<string, unordered_set<string>> &patternDict, unordered_map<string, int> &distances, vector<vector <string>> &results) {
		// 2.递归出口
		if (curr == target) {
			results.push_back(*new vector<string>(path));
		}
		// 3.递归拆解
		auto words = getNextWords(curr, patternDict);
		for (auto word : words) {
			if (distances[word] != distances[curr] - 1) {
				continue;
			}
			path.push_back(word);
			dfs(word, target, path, patternDict, distances, results);
			path.pop_back();
		}
	}
	unordered_map<string, int> bfs(string &start, unordered_map<string, unordered_set<string>> &patternDict) {
		// 用于记录从 start 开始到所有可能的 nextWord 的最短距离
		unordered_map<string, int> distances;
		queue<string> q;
		
		q.push(start);
		distances[start] = 1;
		
		while (!q.empty()) {
			string curr = q.front();
			q.pop();

			auto words = getNextWords(curr, patternDict);
			for (auto word : words) {
				if (distances.find(word) == distances.end()) {  // 尚未到达过word
					q.push(word);
					distances[word] = distances[curr] + 1;
				}
			}
		}
		return distances;
	}
	vector<string> getNextWords(string &word, unordered_map<string, unordered_set<string>> &patternDict) {
		vector<string> words;
		for (int i = 0; i != word.size(); ++i) {
			string pattern = *new string(word);
			pattern[i] = '*';
			if (patternDict.find(pattern) != patternDict.end()) {
				for (auto w : patternDict[pattern]) {
					words.push_back(w);
				}
			}
		}
		return words;
	}
	unordered_map<string, unordered_set<string>> buildPatternDict(unordered_set<string> &dict) {
		unordered_map<string, unordered_set<string>> patternDict;
		for (auto word : dict) {
			for (int i = 0; i != word.size(); ++i) {
				string pattern = *new string(word);
				pattern[i] = '*';
				if (patternDict.find(pattern) == patternDict.end()) {
					patternDict[pattern] = *new unordered_set<string>{ word };
				}
				else {
					patternDict[pattern].insert(word);
				}
			}
		}
		return patternDict;
	}
};

int main() {

	system("pause");
	return 0;
}