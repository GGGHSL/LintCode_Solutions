/*
900. 二叉搜索树中最接近的值
给一棵非空二叉搜索树以及一个target值，找到在BST中最接近给定值的节点值

样例
样例1
	输入: root = {5,4,9,2,#,8,10} and target = 6.124780
	输出: 5
	解释：
		二叉树 {5,4,9,2,#,8,10}，表示如下的树结构：
				5
			   / \
			 4    9
			/    / \
		   2    8  10
样例2
	输入: root = {3,2,4,1} and target = 4.142857
	输出: 4
	解释：
		二叉树 {3,2,4,1}，表示如下的树结构：
			 3
			/ \
		  2    4
		 /
		1
注意事项:
	- 给出的目标值为浮点数
	- 我们可以保证只有唯一一个最接近给定值的节点
*/
#include <iostream>
#include <vector>
#include <string>
#include <stack>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::stack;

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
	 * @return: the value in the BST that is closest to the target
	 */
	int closestValue(TreeNode * root, double target) {
		// write your code here
		if (!root->left && !root->right || target == root->val) {
			return root->val;
		}

		TreeNode *pre = new TreeNode(0);
		pre->right = root;
		stack<TreeNode *> s;
		s.push(pre);

		TreeNode *curr = NULL;
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
				pre = curr;
				curr = s.top();
				if (s.top()->val >= target) {
					break;
				}
			}
		}
		if (!pre || curr->val - target < target - pre->val) {
			return curr->val;
		}
		return pre->val;
	}
};

int main() {

	system("pause");
	return 0;
}