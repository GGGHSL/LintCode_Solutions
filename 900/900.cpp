/*
900. ��������������ӽ���ֵ
��һ�÷ǿն����������Լ�һ��targetֵ���ҵ���BST����ӽ�����ֵ�Ľڵ�ֵ

����
����1
	����: root = {5,4,9,2,#,8,10} and target = 6.124780
	���: 5
	���ͣ�
		������ {5,4,9,2,#,8,10}����ʾ���µ����ṹ��
				5
			   / \
			 4    9
			/    / \
		   2    8  10
����2
	����: root = {3,2,4,1} and target = 4.142857
	���: 4
	���ͣ�
		������ {3,2,4,1}����ʾ���µ����ṹ��
			 3
			/ \
		  2    4
		 /
		1
ע������:
	- ������Ŀ��ֵΪ������
	- ���ǿ��Ա�ֻ֤��Ψһһ����ӽ�����ֵ�Ľڵ�
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
	 * @param root: the given BST
	 * @param target: the given target
	 * @return: the value in the BST that is closest to the target
	 */
	int closestValue(TreeNode * root, double target) {
		// write your code here
		if (!root->left && !root->right || target == root->val) {
			return root->val;
		}

		TreeNode *pre = new TreeNode(0);
		pre->right = root;
		stack<TreeNode *> s;
		s.push(pre);

		TreeNode *curr = NULL;
		while (!s.empty()) {
			auto node = s.top();
			s.pop();
			if (node->right) {
				node = node->right;
				while (node) {
					s.push(node);
					node = node->left;
				}
			}
			if (!s.empty()) {
				pre = curr;
				curr = s.top();
				if (s.top()->val >= target) {
					break;
				}
			}
		}
		if (!pre || curr->val - target < target - pre->val) {
			return curr->val;
		}
		return pre->val;
	}
};

int main() {

	system("pause");
	return 0;
}