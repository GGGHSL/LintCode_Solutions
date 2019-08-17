/*
7. 二叉树的序列化和反序列化
	* 设计一个算法，并编写代码来序列化和反序列化二叉树。将树写入一个文件被称为“序列化”，
	  读取文件后重建同样的二叉树被称为“反序列化”。

	* 如何反序列化或序列化二叉树是没有限制的，你只需要确保可以将二叉树序列化为一个字符串，
	  并且可以将字符串反序列化为原来的树结构。

样例
样例 1：
	输入：{3,9,20,#,#,15,7}
	输出：{3,9,20,#,#,15,7}
	解释：
		二叉树 {3,9,20,#,#,15,7}，表示如下的树结构：
			  3
			 / \
			9  20
			  /  \
			 15   7
		它将被序列化为 {3,9,20,#,#,15,7}
样例 2：
	输入：{1,2,3}
	输出：{1,2,3}
	解释：
		二叉树 {1,2,3}，表示如下的树结构：
		   1
		  / \
		 2   3
		它将被序列化为 {1,2,3}

我们的数据是进行 BFS 遍历得到的。当你测试结果 Wrong Answer 时，你可以作为输入调试你的代码。
你可以采用其他的方法进行序列化和反序列化。

注意事项:
	对二进制树进行反序列化或序列化的方式没有限制，LintCode将您的serialize输出作为deserialize的输入，
	它不会检查序列化的结果。
*/
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::queue;

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
	 * This method will be invoked first, you should design your own algorithm
	 * to serialize a binary tree which denote by a root node to a string which
	 * can be easily deserialized by your own "deserialize" method later.
	 */
	string serialize(TreeNode * root) {
		// write your code here
		string ans;
		if (root == NULL) {
			return ans;
		}
		queue<TreeNode*> q;
		q.push(root);
		char val = root->val;
		ans += val;

		while (!q.empty()) {
			auto size = q.size();
			string currLevel;
			for (int _ = 0; _ != size; ++_) {
				TreeNode curr = *(q.front());
				q.pop();

				if (curr.left != NULL) {
					q.push(curr.left);
					val = (curr.left)->val;
					currLevel += val;
				}
				else {
					currLevel += '#';
				}

				if (curr.right != NULL) {
					q.push(curr.right);
					val = (curr.right)->val;
					currLevel += val;
				}
				else {
					currLevel += '#';
				}
			}
			ans += currLevel;
		}
		return ans;
	}


	/**
	 * This method will be invoked second, the argument data is what exactly
	 * you serialized at method "serialize", that means the data is not given by
	 * system, it's given by your own serialize method. So the format of data is
	 * designed by yourself, and deserialize it here as you serialize it in
	 * "serialize" method.
	 */
	TreeNode * deserialize(string &data) {
		// write your code here
		if (data.empty()) {
			return NULL;
		}

		string rdata(data.rbegin(), data.rend());
		int val = rdata.back();
		TreeNode *root = new TreeNode(val);
		rdata.pop_back();

		queue<TreeNode *> q;
		q.push(root);

		while (!q.empty()) {
			// left branch:
			if (!rdata.empty() && rdata.back() != '#') {
				TreeNode *node = new TreeNode(int(rdata.back()));
				q.front()->left = node;
				q.push(node);
			}
			rdata.pop_back();

			// right branch:
			if (!rdata.empty() && rdata.back() != '#') {
				TreeNode *node = new TreeNode(int(rdata.back()));
				q.front()->right = node;
				q.push(node);
			}
			rdata.pop_back();
			q.pop();
		}
		return root;
	}
};

int main() {
	
	system("pause");
	return 0;
}