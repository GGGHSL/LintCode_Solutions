/*
521. ȥ���ظ�Ԫ��
��һ���������飬ȥ���ظ���Ԫ�ء�

��Ӧ������Щ��
	1.��ԭ�����ϲ���
	2.��ȥ���ظ�֮���Ԫ�ط�������Ŀ�ͷ
	3.����ȥ���ظ�Ԫ��֮���Ԫ�ظ���

����
	��1:
	����:
		nums = [1,3,1,4,4,2]
	���:
		[1,3,4,2,?,?]
		4
	����:
		1. ���ظ��������ƶ��� nums ��β�� => nums = [1,3,4,2,?,?].
		2. ���� nums ��Ψһ����������  => 4.
		��ʵ�����ǲ����������ʲô������ ? ��, ֻ����û���ظ������Ĳ���.
	
	��2:
	����:
		nums = [1,2,3]
	���:
		[1,2,3]
		3
��ս
	1.O(n)ʱ�临�Ӷ�.
	2.O(nlogn)ʱ�临�Ӷȵ�û�ж���ռ�

ע������
	����Ҫ����ԭ�����˳��
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::unordered_multiset;

int main() {

	system("pause");
	return 0;
}

class Solution {
public:
	/**
	 * @param nums: an array of integers
	 * @return: the number of unique integers
	 */
	//int deduplication(vector<int> &nums) {
	//	// write your code here
	//	unordered_multiset<int> cnt;
	//	cnt.insert(nums.begin(), nums.end());
	//	auto fast = nums.begin(), slow = nums.begin();
	//	while (fast != nums.end()) {
	//		cnt.insert(*fast);
	//		if (cnt.count(*fast) == 1) {
	//			if (cnt.count(*slow) > 1) {
	//				std::swap(*fast, *slow);
	//			}
	//			++slow;
	//		}
	//		++fast;
	//	}
	//	return slow - nums.begin();
	//}
	//int deduplication(vector<int> &nums) {
	//	// write your code here
	//	unordered_multiset<int> cnt;
	//	int dcnt = 0;
	//	auto it = nums.begin();
	//	for (; it != nums.end();) {
	//		cnt.insert(*it);
	//		if (cnt.count(*it) > 1) {
	//			it = nums.erase(it);
	//			++dcnt;
	//		}
	//		else {
	//			++it;
	//		}
	//	}
	//	while (dcnt > 0) {
	//		nums.push_back(0);
	//		--dcnt;
	//	}
	//	return it - nums.begin();
	//}
	//int deduplication(vector<int> &nums) {
	//	// write your code here
	//	if (nums.begin() == nums.end()) {
	//		return 0;
	//	}
	//	else if (nums.end() - nums.begin() == 1) {
	//		return 1;
	//	}
	//	std::sort(nums.begin(), nums.end());
	//	// auto n = nums.size();
	//	int cnt = 0;
	//	auto it = nums.begin() + 1;
	//	while (it != nums.end()) {
	//		if (*it == *(it - 1)) {
	//			it = nums.erase(it);
	//			++cnt;
	//		}
	//		else {
	//			++it;
	//		}
	//	}
	//	while (cnt > 0) {
	//		nums.push_back(0);
	//	}
	//	return it - nums.begin();
	//}
	int deduplication(vector<int> &nums) {
		// write your code here
		if (nums.begin() == nums.end()) {
			return 0;
		}
		else if (nums.end() - nums.begin() == 1) {
			return 1;
		}
		std::sort(nums.begin(), nums.end());
		// auto n = nums.size();
		auto it = nums.begin(), pos = nums.begin();
		for (; it != nums.end(); ++it) {
			if (*it != *pos) {
				*(++pos) = *it;
			}
		}
		return pos - nums.begin();
	}
};