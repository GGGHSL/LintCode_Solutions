/*
7. �����������л��ͷ����л�
	* ���һ���㷨������д���������л��ͷ����л�������������д��һ���ļ�����Ϊ�����л�����
	  ��ȡ�ļ����ؽ�ͬ���Ķ���������Ϊ�������л�����

	* ��η����л������л���������û�����Ƶģ���ֻ��Ҫȷ�����Խ����������л�Ϊһ���ַ�����
	  ���ҿ��Խ��ַ��������л�Ϊԭ�������ṹ��

����
���� 1��
	���룺{3,9,20,#,#,15,7}
	�����{3,9,20,#,#,15,7}
	���ͣ�
		������ {3,9,20,#,#,15,7}����ʾ���µ����ṹ��
			  3
			 / \
			9  20
			  /  \
			 15   7
		���������л�Ϊ {3,9,20,#,#,15,7}
���� 2��
	���룺{1,2,3}
	�����{1,2,3}
	���ͣ�
		������ {1,2,3}����ʾ���µ����ṹ��
		   1
		  / \
		 2   3
		���������л�Ϊ {1,2,3}

���ǵ������ǽ��� BFS �����õ��ġ�������Խ�� Wrong Answer ʱ���������Ϊ���������Ĵ��롣
����Բ��������ķ����������л��ͷ����л���

ע������:
	�Զ����������з����л������л��ķ�ʽû�����ƣ�LintCode������serialize�����Ϊdeserialize�����룬
	�����������л��Ľ����
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