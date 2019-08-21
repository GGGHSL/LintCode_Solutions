/*
67. 二叉树的中序遍历
给出一棵二叉树,返回其中序遍历

样例
样例 1:
	输入：{1,2,3}
	输出：[2,1,3]
	解释：
		   1
		  / \
		 2   3
		它将被序列化为{1,2,3}中序遍历
样例 2:
	输入：{1,#,2,3}
	输出：[1,3,2]
	解释：
		1
		 \
		  2
		 /
		3
		它将被序列化为{1,#,2,3}中序遍历
挑战
	你能使用非递归算法来实现么?
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
	 * @param root: A Tree
	 * @return: Inorder in ArrayList which contains node values.
	 */
	vector<int> inorderTraversal(TreeNode * root) {
		// write your code here
		vector<int> inorder;
		if (!root) {
			return inorder;
		}

		TreeNode *dummy = new TreeNode(0);
		dummy->right = root;
		
		stack<TreeNode *> s;
		s.push(dummy);

		while (!s.empty()) {
			auto curr = s.top();
			s.pop();

			if (curr->right) {
				curr = curr->right;
				
				while (curr) {
					s.push(curr);
					curr = curr->left;
				}
			}

			if (!s.empty()) {
				inorder.push_back(s.top()->val);
			}
		}

		return inorder;
	}
};

int main() {
	TreeNode *root = &TreeNode(1);
	root->left = &TreeNode(2);
	root->right = &TreeNode(3);

	Solution s;
	auto inorder = s.inorderTraversal(root);
	for (auto n : inorder) {
		cout << n << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}