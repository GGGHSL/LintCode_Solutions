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
	 * @param root: the root of the binary tree
	 * @return: all root-to-leaf paths
	 */
	vector<string> binaryTreePaths(TreeNode * root) {
		// write your code here
		vector<string> ans;
		if (!root) {
			return ans;
		}
		string path = std::to_string(root->val);
		ans = helper(root, path);
		return ans;
	}
private:
	vector<string> helper(TreeNode * root, string path) {
		vector<string> ans;
		if (!root->left && !root->right) {
			ans.push_back(path);
		}
		if (root->left) {
			string l = path + "->" + std::to_string(root->left->val);
			auto leftPath = helper(root->left, l);
			for (auto p : leftPath) {
				ans.push_back(p);
			}
		}
		if (root->right) {
			string r = path + "->" + std::to_string(root->right->val);
			auto rightPath = helper(root->right, r);
			for (auto p : rightPath) {
				ans.push_back(p);
			}
		}
		return ans;
	}
};

int main() {
	
	system("pause");
	return 0;
}