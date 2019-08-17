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
	 * @param root: A tree
	 * @return: buttom-up level order a list of lists of integer
	 */
	vector<vector<int>> levelOrderBottom(TreeNode * root) {
		// write your code here
		vector<vector<int>> ans;
		if (root == NULL) {
			return ans;
		}
		queue<TreeNode*> q;
		q.push(root);
		
		while (!q.empty()) {
			auto size = q.size();
			vector<int> currLevel;
			for (int _ = 0; _ != size; ++_) {
				TreeNode *currNode = q.front();
				q.pop();
				currLevel.push_back(currNode->val);

				if (currNode->left != NULL) {
					int left = currNode->left->val;
					q.push(currNode->left);
				}
				if (currNode->right != NULL) {
					int right = currNode->right->val;
					q.push(currNode->right);
				}
			}
			ans.push_back(currLevel);
		}
		vector<vector<int>> res(ans.rbegin(), ans.rend());
		return res;
	}
};
int main() {
	
	system("pause");
	return 0;
}