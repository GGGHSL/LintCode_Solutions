/*
596. 最小子树
给一棵二叉树, 找到和为最小的子树, 返回其根节点。

样例
样例 1:
	输入:
		{1,-5,2,1,2,-4,-5}
	输出:1
	说明
		这棵树如下所示：
			 1
		   /   \
		 -5     2
		 / \   /  \
		1   2 -4  -5
		整颗树的和是最小的，所以返回根节点1.
样例 2:
	输入:
		{1}
	输出:1
	说明:
		这棵树如下所示：
		   1
		这棵树只有整体这一个子树，所以返回1.
注意事项
	LintCode会打印根节点为你返回节点的子树。
	保证只有一棵和最小的子树并且给出的二叉树不是一棵空树。
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

class ResultType {
public:
	int sum;
	int min;
	TreeNode *minNode = NULL;
};

class Solution {
public:
	/**
	 * @param root: the root of binary tree
	 * @return: the root of the minimum subtree
	 */
	TreeNode * findSubtree(TreeNode * root) {
		// write your code here
		auto rootSum = subtreeSum(root);
		return rootSum.minNode;
	}
private:
	ResultType subtreeSum(TreeNode * root) {
		ResultType res;
		if (!root) {
			res.min = INT8_MAX;
			res.sum = 0;
			return res;
		}
		ResultType leftSubtree = subtreeSum(root->left);
		ResultType rightSubtree = subtreeSum(root->right);
		res.sum = leftSubtree.sum + rightSubtree.sum + root->val;

		int subtreeMin = leftSubtree.min < rightSubtree.min ? leftSubtree.min : rightSubtree.min;
		TreeNode *subNode = leftSubtree.min < rightSubtree.min ? leftSubtree.minNode : rightSubtree.minNode;
		
		if (res.sum < subtreeMin) {
			res.min = res.sum;
			res.minNode = root;
		}
		else {
			res.min = subtreeMin;
			res.minNode = subNode;
		}
		return res;
	}
};


int main() {
	
	system("pause");
	return 0;
}