/*
67. ���������������
����һ�ö�����,�������������

����
���� 1:
	���룺{1,2,3}
	�����[2,1,3]
	���ͣ�
		   1
		  / \
		 2   3
		���������л�Ϊ{1,2,3}�������
���� 2:
	���룺{1,#,2,3}
	�����[1,3,2]
	���ͣ�
		1
		 \
		  2
		 /
		3
		���������л�Ϊ{1,#,2,3}�������
��ս
	����ʹ�÷ǵݹ��㷨��ʵ��ô?
*/
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
	 * @param root: A Tree
	 * @return: Inorder in ArrayList which contains node values.
	 */
	vector<int> inorderTraversal(TreeNode * root) {
		// write your code here
		vector<int> inorder;
		if (!root) {
			return inorder;
		}

		TreeNode *dummy = new TreeNode(0);
		dummy->right = root;
		
		stack<TreeNode *> s;
		s.push(dummy);

		while (!s.empty()) {
			auto curr = s.top();
			s.pop();

			if (curr->right) {
				curr = curr->right;
				
				while (curr) {
					s.push(curr);
					curr = curr->left;
				}
			}

			if (!s.empty()) {
				inorder.push_back(s.top()->val);
			}
		}

		return inorder;
	}
};

int main() {
	TreeNode *root = &TreeNode(1);
	root->left = &TreeNode(2);
	root->right = &TreeNode(3);

	Solution s;
	auto inorder = s.inorderTraversal(root);
	for (auto n : inorder) {
		cout << n << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}