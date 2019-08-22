/*
93. ƽ�������
����һ��������,ȷ�����Ǹ߶�ƽ��ġ�
�����������,һ�ø߶�ƽ��Ķ������Ķ����ǣ�һ�ö�������ÿ���ڵ������������������ᳬ��1��

����
���� 1:
	����: tree = {1,2,3}
	���: true
	��������:
		���£���һ��ƽ��Ķ�������
			  1
			 / \
			2  3

���� 2:
	����: tree = {3,9,20,#,#,15,7}
	���: true
	��������:
		���£���һ��ƽ��Ķ�������
			  3
			 / \
			9  20
			  /  \
			 15   7

���� 3:
	����: tree = {1,#,2,3,4}
	���: false
	��������:
		���£���һ����ƽ��Ķ�������1�����������߶Ȳ�2
			  1
			   \
			   2
			  /  \
			 3   4
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
	/**
	 * @param root: The root of binary tree.
	 * @return: True if this Binary tree is Balanced, or false.
	 */
	bool isBalanced(TreeNode * root) {
		// write your code here
		if (!root) {
			return true;
		}
		if (!root->left && !root->right) {
			return true;
		}

		if (!root->left) {
			int diff = hight(root->right);
			return diff <= 1;
		}
		if (!root->right) {
			int diff = hight(root->left);
			return diff <= 1;
		}

		bool left = isBalanced(root->left);
		bool right = isBalanced(root->right);
		return left && right;
	}
private:
	int hight(TreeNode * root) {
		if (!root) {
			return 0;
		}
		if (!root->left && !root->right) {
			return 1;
		}
		int left = hight(root->left);
		int right = hight(root->right);
		return left < right ? right + 1 : left + 1;
	}
};

int main() {

	system("pause");
	return 0;
}