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
	/*
	 * @param root: The root of the binary search tree.
	 * @param A: A TreeNode in a Binary.
	 * @param B: A TreeNode in a Binary.
	 * @return: Return the least common ancestor(LCA) of the two nodes.
	 */
	TreeNode * lowestCommonAncestor(TreeNode * root, TreeNode * A, TreeNode * B) {
		// write your code here
		if (A == root || B == root) {
			return root;
		}
		TreeNode *flags[] = {
			findNode(root->left, A), findNode(root->right, A),
			findNode(root->left, B), findNode(root->right, B) };
		if (flags[0] && flags[3] || flags[1] && flags[2]) {
			return root;
		}
		else if (flags[0] && flags[2]) {
			return lowestCommonAncestor(root->left, A, B);
		}
		else if (flags[1] && flags[3]) {
			return lowestCommonAncestor(root->right, A, B);
		}
		return NULL;
	}
private:
	TreeNode *findNode(TreeNode *root, TreeNode *node) {
		if (!root) {
			return NULL;
		}
		if (node == root) {
			return root;
		}
		if (findNode(root->left, node)) {
			return root->left;
		}
		if (findNode(root->right, node)) {
			return root->right;
		}
		return NULL;
	}
};

int main() {

	system("pause");
	return 0;
}