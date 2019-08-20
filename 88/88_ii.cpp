/*
88. �����������
����һ�ö��������ҵ������ڵ������������ڵ�(LCA)��
������������������ڵ�Ĺ��������Ƚڵ��Ҿ��������ȡ�

����
���� 1:
	���룺{1},1,1
	�����1
	���ͣ�
	 ���������£�ֻ��һ���ڵ㣩:
			 1
	 LCA(1,1) = 1
���� 2:
	���룺{4,3,7,#,#,5,6},3,5
	�����4
	���ͣ�
	 ����������:

		  4
		 / \
		3   7
		   / \
		  5   6

	 LCA(3, 5) = 4
ע������:
	��������������ڵ㶼�����д��ڡ�
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
	/*
	 * @param root: The root of the binary search tree.
	 * @param A: A TreeNode in a Binary.
	 * @param B: A TreeNode in a Binary.
	 * @return: Return the least common ancestor(LCA) of the two nodes.
	 */
	TreeNode * lowestCommonAncestor(TreeNode * root, TreeNode * A, TreeNode * B) {
		if (!root) {
			return NULL;
		}
		if (A == root || B == root) {
			return root;
		}
		auto left = lowestCommonAncestor(root->left, A, B);
		auto right = lowestCommonAncestor(root->right, A, B);

		if (left && right) {
			return root;
		}
		if (left) {
			return left;
		}
		if (right) {
			return right;
		}
		return NULL;
	}
};

int main() {

	system("pause");
	return 0;
}