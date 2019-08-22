/*
93. 平衡二叉树
给定一个二叉树,确定它是高度平衡的。
对于这个问题,一棵高度平衡的二叉树的定义是：一棵二叉树中每个节点的两个子树的深度相差不会超过1。

样例
样例 1:
	输入: tree = {1,2,3}
	输出: true
	样例解释:
		如下，是一个平衡的二叉树。
			  1
			 / \
			2  3

样例 2:
	输入: tree = {3,9,20,#,#,15,7}
	输出: true
	样例解释:
		如下，是一个平衡的二叉树。
			  3
			 / \
			9  20
			  /  \
			 15   7

样例 3:
	输入: tree = {1,#,2,3,4}
	输出: false
	样例解释:
		如下，是一个不平衡的二叉树。1的左右子树高度差2
			  1
			   \
			   2
			  /  \
			 3   4
*/
#include <iostream>
#include <vector>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

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
	 * @param root: The root of binary tree.
	 * @return: True if this Binary tree is Balanced, or false.
	 */
	bool isBalanced(TreeNode * root) {
		// write your code here
		if (!root) {
			return true;
		}
		if (!root->left && !root->right) {
			return true;
		}

		if (!root->left) {
			int diff = hight(root->right);
			return diff <= 1;
		}
		if (!root->right) {
			int diff = hight(root->left);
			return diff <= 1;
		}

		bool left = isBalanced(root->left);
		bool right = isBalanced(root->right);
		return left && right;
	}
private:
	int hight(TreeNode * root) {
		if (!root) {
			return 0;
		}
		if (!root->left && !root->right) {
			return 1;
		}
		int left = hight(root->left);
		int right = hight(root->right);
		return left < right ? right + 1 : left + 1;
	}
};

int main() {

	system("pause");
	return 0;
}