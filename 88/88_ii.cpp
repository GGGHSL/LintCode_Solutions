/*
88. 最近公共祖先
给定一棵二叉树，找到两个节点的最近公共父节点(LCA)。
最近公共祖先是两个节点的公共的祖先节点且具有最大深度。

样例
样例 1:
	输入：{1},1,1
	输出：1
	解释：
	 二叉树如下（只有一个节点）:
			 1
	 LCA(1,1) = 1
样例 2:
	输入：{4,3,7,#,#,5,6},3,5
	输出：4
	解释：
	 二叉树如下:

		  4
		 / \
		3   7
		   / \
		  5   6

	 LCA(3, 5) = 4
注意事项:
	假设给出的两个节点都在树中存在。
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
	/*
	 * @param root: The root of the binary search tree.
	 * @param A: A TreeNode in a Binary.
	 * @param B: A TreeNode in a Binary.
	 * @return: Return the least common ancestor(LCA) of the two nodes.
	 */
	TreeNode * lowestCommonAncestor(TreeNode * root, TreeNode * A, TreeNode * B) {
		if (!root) {
			return NULL;
		}
		if (A == root || B == root) {
			return root;
		}
		auto left = lowestCommonAncestor(root->left, A, B);
		auto right = lowestCommonAncestor(root->right, A, B);

		if (left && right) {
			return root;
		}
		if (left) {
			return left;
		}
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