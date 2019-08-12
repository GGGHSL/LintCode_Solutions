/*
183. ľ�ļӹ�
��һЩԭľ�����������Щľͷ�и��һЩ������ͬ��С��ľͷ����Ҫ�õ���С�ε���Ŀ����Ϊk��
��Ȼ������ϣ���õ���С��Խ��Խ�ã�����Ҫ�����ܹ��õ���С��ľͷ����󳤶ȡ�

����
���� 1
	����:
	L = [232, 124, 456]
	k = 7
	���: 114
	Explanation: ���ǿ��԰����ֳ�114cm��7�Σ���115cm������
���� 2
	����:
	L = [1, 2, 3]
	k = 7
	���: 0
	˵��:����Ȼ���ǲ��ܰ�����ĿҪ����ɡ�
��ս
	O(nlog(Len)), LenΪn��ԭľ�����ĳ���

ע������
	ľͷ���ȵĵ�λ�����ס�ԭľ�ĳ��ȶ���������������Ҫ���и�õ���С��ľͷ�ĳ���ҲҪ����������
	�޷��г�Ҫ������ k �ε�,�򷵻� 0 ���ɡ�
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