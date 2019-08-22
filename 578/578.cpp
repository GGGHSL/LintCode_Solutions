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
	 * @param root: The root of the binary tree.
	 * @param A: A TreeNode
	 * @param B: A TreeNode
	 * @return: Return the LCA of the two nodes.
	 */
	TreeNode * lowestCommonAncestor3(TreeNode * root, TreeNode * A, TreeNode * B) {
		// write your code here
		if (!root) {
			return NULL;
		}

		if (root == A) {
			if (findHelper(root, B)) {
				return root;
			}
			else {
				return NULL;
			}
		}
		if (root == B) {
			if (findHelper(root, A)) {
				return root;
			}
			else {
				return NULL;
			}
		}
		
		auto left = lowestCommonAncestor3(root->left, A, B);
		if (left) {
			return left;
		}
		auto right = lowestCommonAncestor3(root->right, A, B);
		if (right) {
			return right;
		}

		auto leftA = findHelper(root->left, A);
		auto rightB = findHelper(root->right, B);
		if (leftA && rightB) {
			return root;
		}
		auto leftB = findHelper(root->left, B);
		auto rightA = findHelper(root->right, A);
		if (leftB && rightA) {
			return root;
		}
		return NULL;
	}
private:
	TreeNode *findHelper(TreeNode * root, TreeNode * A) {
		if (!root) {
			return NULL;
		}
		if (root == A) {
			return root;
		}

		auto left = findHelper(root->left, A);
		if (left) {
			return left;
		}

		auto right = findHelper(root->right, A);
		if (right) {
			return right;
		}
		return NULL;
	}
};

int main() {

	system("pause");
	return 0;
}