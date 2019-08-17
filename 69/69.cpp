#include <iostream>
#include <vector>
#include <queue>
using std::cin;
using std::cout;
using std::endl;
using std::queue;
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
	 * @return: Level order a list of lists of integer
	 */
	vector<vector<int>> levelOrder(TreeNode * root) {
		// write your code here
		vector<vector<int>> ans;
		if (root == NULL) {
			return ans;
		}
		queue<TreeNode*> q;
		q.push(root);
		// ans.push_back(vector<int>{root->val});

		while (!q.empty()) {
			auto size = q.size();
			vector<int> currLevel;
			for (int _ = 0; _ != size; ++_) {
				TreeNode *currNode = q.front();
				q.pop();
				currLevel.push_back(currNode->val);

				if (currNode->left != NULL) {
					// int left = currNode->left->val;
					// currLevel.push_back(left);
					q.push(currNode->left);
				}
				if (currNode->right != NULL) {
					// int right = currNode->right->val;
					// currLevel.push_back(right);
					q.push(currNode->right);
				}
			}
			/*if (!currLevel.empty()) {
				ans.push_back(currLevel);
			}*/
			ans.push_back(currLevel);
		}
		return ans;
	}
};

int main() {
	
	system("pause");
	return 0;
}