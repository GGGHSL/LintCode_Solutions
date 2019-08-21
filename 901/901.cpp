/*
901. 二叉搜索树中最接近的值 II
	给定一棵非空二叉搜索树以及一个target值，找到 BST 中最接近给定值的 k 个数。

样例
样例 1:
	输入:
		{1}
		0.000000
		1
	输出:
		[1]
	解释：
		二叉树 {1}，表示如下的树结构：
		 1
样例 2:
	输入:
		{3,1,4,#,2}
		0.275000
		2
	输出:
		[1,2]
	解释：
		二叉树 {3,1,4,#,2}，表示如下的树结构：
		  3
		 /  \
		1    4
		 \
		  2
挑战
	假设是一棵平衡二叉搜索树，你可以用时间复杂度低于O(n)的算法解决问题吗( n 为节点个数)？

注意事项
	- 给出的target值为浮点数;
	- 你可以假设 k 总是合理的，即 k ≤ 总节点数;
	- 我们可以保证给出的 BST 中只有唯一一个最接近给定值的 k 个值的集合.
*/
#include <iostream>
#include <vector>
#include <stack>
#include <deque>
using std::cin;
using std::cout;
using std::endl;
using std::stack;
using std::vector;
using std::deque;
using std::pair;

class TreeNode {
public:
	int val;
	TreeNode *left, *right;
	TreeNode(int val) {
		this->val = val;
		this->left = this->right = NULL;
	}
};

class Solution {
public:
	/**
	 * @param root: the given BST
	 * @param target: the given target
	 * @param k: the given k
	 * @return: k values in the BST that are closest to the target
	 */
	vector<int> closestKValues(TreeNode * root, double target, int k) {
		// write your code here
		if (!root) {
			return vector<int>{};
		}
		if (!root->left && !root->right) {
			return vector<int>{root->val};
		}

		deque<int> ans;
		stack<TreeNode *> s;
		TreeNode *dummy = new TreeNode(0);
		dummy->right = root;
		s.push(dummy);

		while (!s.empty()) {
			auto node = s.top();
			s.pop();
			if (node->right) {
				node = node->right;
				while (node) {
					s.push(node);
					node = node->left;
				}
			}

			if (!s.empty()) {
				if (ans.size() >= 2 * k) {
					ans.pop_front();
				}
				ans.push_back(s.top()->val);

				if (ans.size() == 2 * k && *(ans.begin() + k) >= target) {
					break;
				}
			}
		}

		if (ans.back() <= target) {
			return vector<int>(ans.end() - k, ans.end());
		}
		if (ans.front() >= target) {
			return vector<int>(ans.begin(), ans.begin() + k);
		}

		auto e = ans.begin() + k, b = e - 1;
		for (int _ = 0; _ != k; ++_) {
			if (e != ans.end() && *e - target < target - *b) {
				++e;
			}
			else if (b - ans.begin() >= 0) {
				--b;
			}
		}
		++b;
		--e;
		return vector<int>(b, e + 1);
	}
};


int main() {
	system("pause");
	return 0;
}