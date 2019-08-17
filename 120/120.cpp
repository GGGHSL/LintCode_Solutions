/*
120. ���ʽ���
�����������ʣ�start��end����һ���ֵ䣬�ҳ���start��end�����ת�����У����������еĳ��ȡ�

�任�������£�
	ÿ��ֻ�ܸı�һ����ĸ��
	�任�����е��м䵥�ʱ������ֵ��г��֡�(��ʼ���ʺͽ������ʲ���Ҫ�������ֵ���)
����
���� 1:
	���룺start = "a"��end = "c"��dict =["a","b","c"]
	�����2
	���ͣ�
		"a"->"c"
���� 2:
	���룺start ="hit"��end = "cog"��dict =["hot","dot","dog","lot","log"]
	�����5
	���ͣ�
		"hit"->"hot"->"dot"->"dog"->"cog"
ע������
	���������������ת�����У����� 0��
	���е��ʾ�����ͬ�ĳ��ȡ�
	���е���ֻ��Сд��ĸ��ɡ�
	�ֵ��в������ظ��ĵ��ʡ�
	����Լ��� beginWord �� endWord �Ƿǿյģ��Ҷ��߲���ͬ��
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
		unordered_map<string, int> distance;  // ���ڼ�¼ÿ��word��start�ľ���
		distance.insert(pair<string, int>(start, 1));
		
		while (!q.empty()) {
			auto size = q.size();
			string curr = q.front();
			q.pop();

			vector<string> nextWords = getNextWords(curr, dict);
			for (auto word : nextWords) {
				if (word == end) {  // ����ת������ʱ��Ψһ����
					return distance[curr] + 1;
				}
				if (distance.find(word) == distance.end()) {  // 'word'��δ���ʹ�
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