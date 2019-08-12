/*
183. 木材加工
有一些原木，现在想把这些木头切割成一些长度相同的小段木头，需要得到的小段的数目至少为k。
当然，我们希望得到的小段越长越好，你需要计算能够得到的小段木头的最大长度。

样例
样例 1
	输入:
	L = [232, 124, 456]
	k = 7
	输出: 114
	Explanation: 我们可以把它分成114cm的7段，而115cm不可以
样例 2
	输入:
	L = [1, 2, 3]
	k = 7
	输出: 0
	说明:很显然我们不能按照题目要求完成。
挑战
	O(nlog(Len)), Len为n段原木中最大的长度

注意事项
	木头长度的单位是厘米。原木的长度都是正整数，我们要求切割得到的小段木头的长度也要求是整数。
	无法切出要求至少 k 段的,则返回 0 即可。
*/
#include <iostream>
#include <vector>
#include <algorithm>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::max_element;
using std::min;


class Solution {
public:
	/**
	 * @param L: Given n pieces of wood with length L[i]
	 * @param k: An integer
	 * @return: The maximum length of the small pieces
	 */
	int woodCut(vector<int> &L, int k) {
		// write your code here
		long sum = 0;
		for (auto l : L) {
			sum += l;
		}
		if (sum < k) {
			return 0;
		}
		else if (sum == k) {
			return 1;
		}
		int start = 1;
		int end = *max_element(L.begin(), L.end());
		end = end < sum / k ? end : sum / k;
		while (start + 1 < end) {
			int mid = start + (end - start) / 2;
			int cnt = getPieces(L, mid);
			if (cnt == k) {
				start = mid;
			}
			if (cnt < k) {
				end = mid;
			}
			else {
				start = mid;
			}
		}
		int maxCnt = getPieces(L, start), minCnt = getPieces(L, end);
		if (minCnt >= k) {
			return end;
		}
		else if (maxCnt >= k) {
			return start;
		}
		else {
			return 0;
		}
	}
private:
	int getPieces(vector<int> &L, int size) {
		int cnt = 0;
		for (auto l : L) {
			int c = l / size;
			cnt += c;
		}
		return cnt;
	}
};

int main() {
	vector<int> L{ 232,124,456 };
	Solution s;
	int size = s.woodCut(L, 7);
	cout << size << endl;
	system("pause");
	return 0;
}