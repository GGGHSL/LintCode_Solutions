/*
200. 最长回文子串
给出一个字符串（假设长度最长为1000），求出它的最长回文子串，你可以假定只有一个满足条件的最长回文串。

样例
	样例 1:
		输入:"abcdzdcab"
		输出:"cdzdc"
	样例 2:
		输入:"aba"
		输出:"aba"
挑战
	O(n2) 时间复杂度的算法是可以接受的，如果你能用 O(n) 的算法那自然更好。
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
					// 至少当(len == 1)时,一定是回文
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