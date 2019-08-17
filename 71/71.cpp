/*
71. 二叉树的锯齿形层次遍历
	给出一棵二叉树，返回其节点值的锯齿形层次遍历（先从左往右，下一层再从右往左，层与层之间交替进行）

样例
样例 1:
	输入:{1,2,3}
	输出:[[1],[3,2]]
	解释:
			1
		   / \
		  2   3
		它将被序列化为 {1,2,3}
样例 2:
	输入:{3,9,20,#,#,15,7}
	输出:[[3],[20,9],[15,7]]
	解释:
			3
		   / \
		  9  20
			/  \
		   15   7
		它将被序列化为 {3,9,20,#,#,15,7}
*/
#include <iostream>
#include <vector>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;


/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

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
	 * @param root: A Tree
	 * @return: A list of lists of integer include the zigzag level order traversal of its nodes' values.
	 */
	vector<vector<int>> zigzagLevelOrder(TreeNode * root) {
		// write your code here
		vector<vector<int>> ans;
		if (root == NULL) {
			return ans;
		}

		bool isLeft = false;
		queue<TreeNode *> q;
		q.push(root);

		while (!q.empty()) {
			auto size = q.size();
			vector<int> currLevel;
			isLeft = !isLeft;
			for (int _ = 0; _ != size; ++_) {
				TreeNode *curr = q.front();
				currLevel.push_back(curr->val);
				q.pop();

				if (curr->left != NULL) {
					q.push(curr->left);
				}
				if (curr->right != NULL) {
					q.push(curr->right);
				}
			}
			if (isLeft) {
				ans.push_back(currLevel);
			}
			else {
				ans.push_back(vector<int>(currLevel.rbegin(), currLevel.rend()));
			}
		}
		return ans;
	}
};


int main() {

	system("pause");
	return 0;
}