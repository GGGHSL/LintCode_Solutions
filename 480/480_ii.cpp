#include <iostream>
#include <vector>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::to_string;

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
	 * @param root: the root of the binary tree
	 * @return: all root-to-leaf paths
	 */
	vector<string> binaryTreePaths(TreeNode * root) {
		// write your code here
		if (!root) {
			return vector<string>{};
		}
		if (!root->left && !root->right) {
			return vector<string>{to_string(root->val)};
		}

		vector<string> ans;
		for (auto p : binaryTreePaths(root->left)) {
			ans.push_back(to_string(root->val) + "->" + p);
		}

		for (auto p : binaryTreePaths(root->right)) {
			ans.push_back(to_string(root->val) + "->" + p);
		}

		return ans;
	}
};

int main() {

	system("pause");
	return 0;
}