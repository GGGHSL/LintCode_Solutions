/*
200. ������Ӵ�
����һ���ַ��������賤���Ϊ1000�����������������Ӵ�������Լٶ�ֻ��һ����������������Ĵ���

����
	���� 1:
		����:"abcdzdcab"
		���:"cdzdc"
	���� 2:
		����:"aba"
		���:"aba"
��ս
	O(n2) ʱ�临�Ӷȵ��㷨�ǿ��Խ��ܵģ���������� O(n) ���㷨����Ȼ���á�
---------------------------------------------------------------------------------------------
* @param s: input string
* @return: the longest palindromic substring
*/
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

int main() {

	system("pause");
	return 0;
}

class Solution {
public:
	/**
	 * @param s: input string
	 * @return: the longest palindromic substring
	 */
	string longestPalindrome(string &s) {
		// write your code here
		auto n = s.size();
		if (n <= 1) {
			return s;
		}
		else {
			string palindrome;
			bool flag = false;
			unsigned len = n;
			while (!flag && len >= 1) {
				for (unsigned i = 0; i < n + 1 - len; ++i) {
					string tmp = s.substr(i, len);
					// ���ٵ�(len == 1)ʱ,һ���ǻ���
					bool isPalindrome = false;
					auto m = tmp.size();
					unsigned x = 0, y = m - 1;
					while (x < y) {
						if (tmp[x] == tmp[y]) {
							++x;
							--y;
						}
						else
							break;
					}
					if (x == y || x - y == 1)
						isPalindrome = true;
					// 
					if (isPalindrome) {
						palindrome = tmp;
						flag = true;
						break;
					}
				}
				--len;
			}
			return palindrome;
		}
	}
};