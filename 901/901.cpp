/*
901. ��������������ӽ���ֵ II
	����һ�÷ǿն����������Լ�һ��targetֵ���ҵ� BST ����ӽ�����ֵ�� k ������

����
���� 1:
	����:
		{1}
		0.000000
		1
	���:
		[1]
	���ͣ�
		������ {1}����ʾ���µ����ṹ��
		 1
���� 2:
	����:
		{3,1,4,#,2}
		0.275000
		2
	���:
		[1,2]
	���ͣ�
		������ {3,1,4,#,2}����ʾ���µ����ṹ��
		  3
		 /  \
		1    4
		 \
		  2
��ս
	������һ��ƽ��������������������ʱ�临�Ӷȵ���O(n)���㷨���������( n Ϊ�ڵ����)��

ע������
	- ������targetֵΪ������;
	- ����Լ��� k ���Ǻ���ģ��� k �� �ܽڵ���;
	- ���ǿ��Ա�֤������ BST ��ֻ��Ψһһ����ӽ�����ֵ�� k ��ֵ�ļ���.
*/
#include <iostream>
#include <vector>
#include <stack>
#include <deque>
using std::cin;
using std::cout;
using std::endl;
using std::stack;
using std::vector;
using std::deque;
using std::pair;

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
	 * @param k: the given k
	 * @return: k values in the BST that are closest to the target
	 */
	vector<int> closestKValues(TreeNode * root, double target, int k) {
		// write your code here
		if (!root) {
			return vector<int>{};
		}
		if (!root->left && !root->right) {
			return vector<int>{root->val};
		}

		deque<int> ans;
		stack<TreeNode *> s;
		TreeNode *dummy = new TreeNode(0);
		dummy->right = root;
		s.push(dummy);

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
				if (ans.size() >= 2 * k) {
					ans.pop_front();
				}
				ans.push_back(s.top()->val);

				if (ans.size() == 2 * k && *(ans.begin() + k) >= target) {
					break;
				}
			}
		}

		if (ans.back() <= target) {
			return vector<int>(ans.end() - k, ans.end());
		}
		if (ans.front() >= target) {
			return vector<int>(ans.begin(), ans.begin() + k);
		}

		auto e = ans.begin() + k, b = e - 1;
		for (int _ = 0; _ != k; ++_) {
			if (e != ans.end() && *e - target < target - *b) {
				++e;
			}
			else if (b - ans.begin() >= 0) {
				--b;
			}
		}
		++b;
		--e;
		return vector<int>(b, e + 1);
	}
};


int main() {
	system("pause");
	return 0;
}