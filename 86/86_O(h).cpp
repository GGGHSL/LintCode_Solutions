/*
86. ���������������
	���ʵ��һ�������������ԵĶ���������ĵ�������
		- next()����BST����һ����С��Ԫ��
		- Ԫ�ذ��յ�����˳�򱻷��ʣ��������������
		- next()��hasNext()��ѯ�ʲ���Ҫ���̯ʱ�临�Ӷ���O(1)

����
���� 1:
	���룺{10,1,11,#,6,#,12}
	�����[1, 6, 10, 11, 12]
	���ͣ�
		������������� :
		  10
		  /\
		 1 11
		  \  \
		   6  12
		���Է��ض����������������� [1, 6, 10, 11, 12]
���� 2:
	���룺{2,1,3}
	�����[1,2,3]
	���ͣ�
		������������� :
		  2
		 / \
		1   3
		���Է��ض����������������� [1,2,3]
��ս:
	����ռ临�Ӷ���O(h)������h��������ĸ߶�

Super Star:
	ʹ��O(1)�Ķ���ռ临�Ӷ�
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

/**
 * Example of iterate a tree:
 * BSTIterator iterator = BSTIterator(root);
 * while (iterator.hasNext()) {
 *    TreeNode * node = iterator.next();
 *    do something for node
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

class BSTIterator {
public:
	/*
	 * @param root: The root of binary tree.
	 */
	BSTIterator(TreeNode *root) {
		// do intialization if necessary
		TreeNode *dummy = new TreeNode(0);
		dummy->right = root;
		s.push(dummy);
		next();
	}

	/*
	 * @return: True if there has next node, or false
	 */
	bool hasNext() {
		// write your code here
		return !s.empty();
	}

	/*
	 * @return: return next node
	 */
	TreeNode *next() {
		auto curr = s.top();
		s.pop();
		
		auto node = curr;
		if (node->right) {
			node = node->right;
			while (node) {
				s.push(node);
				node = node->left;
			}
		}

		return curr;
	}
private:
	stack<TreeNode *> s;
};

int main() {

	system("pause");
	return 0;
}