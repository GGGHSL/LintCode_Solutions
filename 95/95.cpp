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
	 * @param root: The root of binary tree.
	 * @return: True if the binary tree is BST, or false
	 */
	bool isValidBST(TreeNode * root) {
		// write your code here
		if (!root || !root->left && !root->right) {
			return true;
		}

		long currVal = -2147483949;
		stack<TreeNode *> s;
		TreeNode *dummy = new TreeNode(0);
		dummy->right = root;
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
				if (s.top()->val <= currVal) {
					return false;
				}
				currVal = s.top()->val;
			}
		}
		return true;
	}
};
int main() {

	system("pause");
	return 0;
}