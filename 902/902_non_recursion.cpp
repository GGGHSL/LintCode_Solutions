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
		stack<TreeNode *> s;
		
		auto curr = root;
		s.push(curr);
		while (curr->left) {
			curr = curr->left;
			s.push(curr);
		}

		if (k == 1) {
			return s.top()->val;
		}
		
		for (int i = 0; i != k; ++i) {
			curr = s.top();
			s.pop();

			if (curr->right) {
				nextBigger(curr, s);
			}
		}
		return curr->val;
	}

private:
	void nextBigger(TreeNode *curr, stack<TreeNode *> &s) {
		auto next = curr->right;
		s.push(next);

		while (next->left) {
			next = next->left;
			s.push(next);
		}
	}
};

int main() {

	system("pause");
	return 0;
}