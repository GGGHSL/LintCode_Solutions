/*
120. 单词接龙
给出两个单词（start和end）和一个字典，找出从start到end的最短转换序列，输出最短序列的长度。

变换规则如下：
	每次只能改变一个字母。
	变换过程中的中间单词必须在字典中出现。(起始单词和结束单词不需要出现在字典中)
样例
样例 1:
	输入：start = "a"，end = "c"，dict =["a","b","c"]
	输出：2
	解释：
		"a"->"c"
样例 2:
	输入：start ="hit"，end = "cog"，dict =["hot","dot","dog","lot","log"]
	输出：5
	解释：
		"hit"->"hot"->"dot"->"dog"->"cog"
注意事项
	如果不存在这样的转换序列，返回 0。
	所有单词具有相同的长度。
	所有单词只由小写字母组成。
	字典中不存在重复的单词。
	你可以假设 beginWord 和 endWord 是非空的，且二者不相同。
*/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::unordered_map;
using std::unordered_set;
using std::queue;
using std::pair;


class Solution {
public:
	/*
	 * @param start: a string
	 * @param end: a string
	 * @param dict: a set of string
	 * @return: An integer
	 */
	int ladderLength(string &start, string &end, unordered_set<string> &dict) {
		// write your code here
		if (start == end) {
			return 1;
		}
		else if (dict.empty()) {
			return 0;
		}
		
		dict.insert(end);
		queue<string> q;
		q.push(start);
		unordered_map<string, int> distance;  // 用于记录每个word与start的距离
		distance.insert(pair<string, int>(start, 1));
		
		while (!q.empty()) {
			auto size = q.size();
			string curr = q.front();
			q.pop();

			vector<string> nextWords = getNextWords(curr, dict);
			for (auto word : nextWords) {
				if (word == end) {  // 存在转换序列时的唯一出口
					return distance[curr] + 1;
				}
				if (distance.find(word) == distance.end()) {  // 'word'尚未访问过
					q.push(word);
					distance.insert(pair<string, int>(word, distance[curr] + 1));
				}
			}
		}
		return 0;
	}
private:
	vector<string> getNextWords(string currWord, unordered_set<string> &dict) {
		vector<string> nextWords;
		string variants(currWord);
		string candidates = "abcdefghijklmnopqrstuvwxyz";
		
		for (auto it = variants.begin(); it != variants.end(); ++it) {
			char tmp = *it;
			for (char c : candidates) {
				*it = c;
				if (tmp != c && dict.count(variants)) {
					nextWords.push_back(variants);
				}
			}
			*it = tmp;
		}
		return nextWords;
	}
};

int main() {

	system("pause");
	return 0;
}