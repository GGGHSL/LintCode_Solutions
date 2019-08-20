#include <iostream>
#include <vector>
#include <string>
#include <queue>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::queue;

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
	 * @param root: a TreeNode, the root of the binary tree
	 * @return: nothing
	 */
	void flatten(TreeNode * root) {
		// write your code here
		if (!root) {
			return;
		}
		if (root->left) {
			auto tmp = root->right;
			root->right = root->left;
			root->left = NULL;

			auto curr = root->right;
			while (curr->right) {
				curr = curr->right;
			}
			curr->right = tmp;
		}
		flatten(root->right);
	}
};

int main() {

	system("pause");
	return 0;
}