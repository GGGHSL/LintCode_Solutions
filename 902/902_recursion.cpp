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
	 * @param k: the given k
	 * @return: the kth smallest element in BST
	 */
	int kthSmallest(TreeNode * root, int k) {
		// write your code here
		stack<int> s;
		helper(root, s);
		for (int i = 0; i != k - 1; ++i) {
			s.pop();
		}
		return s.top();
	}
private:
	void helper(TreeNode * root, stack<int> &s) {
		if (!root) {
			return;
		}
		helper(root->right, s);
		s.push(root->val);
		helper(root->left, s);
	}
};


int main() {

	system("pause");
	return 0;
}