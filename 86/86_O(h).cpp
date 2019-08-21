/*
86. 二叉查找树迭代器
	设计实现一个带有下列属性的二叉查找树的迭代器：
		- next()返回BST中下一个最小的元素
		- 元素按照递增的顺序被访问（比如中序遍历）
		- next()和hasNext()的询问操作要求均摊时间复杂度是O(1)

样例
样例 1:
	输入：{10,1,11,#,6,#,12}
	输出：[1, 6, 10, 11, 12]
	解释：
		二叉查找树如下 :
		  10
		  /\
		 1 11
		  \  \
		   6  12
		可以返回二叉查找树的中序遍历 [1, 6, 10, 11, 12]
样例 2:
	输入：{2,1,3}
	输出：[1,2,3]
	解释：
		二叉查找树如下 :
		  2
		 / \
		1   3
		可以返回二叉查找树的中序遍历 [1,2,3]
挑战:
	额外空间复杂度是O(h)，其中h是这棵树的高度

Super Star:
	使用O(1)的额外空间复杂度
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