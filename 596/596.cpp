/*
596. ��С����
��һ�ö�����, �ҵ���Ϊ��С������, ��������ڵ㡣

����
���� 1:
	����:
		{1,-5,2,1,2,-4,-5}
	���:1
	˵��
		�����������ʾ��
			 1
		   /   \
		 -5     2
		 / \   /  \
		1   2 -4  -5
		�������ĺ�����С�ģ����Է��ظ��ڵ�1.
���� 2:
	����:
		{1}
	���:1
	˵��:
		�����������ʾ��
		   1
		�����ֻ��������һ�����������Է���1.
ע������
	LintCode���ӡ���ڵ�Ϊ�㷵�ؽڵ��������
	��ֻ֤��һ�ú���С���������Ҹ����Ķ���������һ�ÿ�����
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

class ResultType {
public:
	int sum;
	int min;
	TreeNode *minNode = NULL;
};

class Solution {
public:
	/**
	 * @param root: the root of binary tree
	 * @return: the root of the minimum subtree
	 */
	TreeNode * findSubtree(TreeNode * root) {
		// write your code here
		auto rootSum = subtreeSum(root);
		return rootSum.minNode;
	}
private:
	ResultType subtreeSum(TreeNode * root) {
		ResultType res;
		if (!root) {
			res.min = INT8_MAX;
			res.sum = 0;
			return res;
		}
		ResultType leftSubtree = subtreeSum(root->left);
		ResultType rightSubtree = subtreeSum(root->right);
		res.sum = leftSubtree.sum + rightSubtree.sum + root->val;

		int subtreeMin = leftSubtree.min < rightSubtree.min ? leftSubtree.min : rightSubtree.min;
		TreeNode *subNode = leftSubtree.min < rightSubtree.min ? leftSubtree.minNode : rightSubtree.minNode;
		
		if (res.sum < subtreeMin) {
			res.min = res.sum;
			res.minNode = root;
		}
		else {
			res.min = subtreeMin;
			res.minNode = subNode;
		}
		return res;
	}
};


int main() {
	
	system("pause");
	return 0;
}