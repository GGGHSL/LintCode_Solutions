/*
137. ��¡ͼ
��¡һ������ͼ. ����ͼ��ÿ���ڵ����һ�� label ��һ���б� neighbors. ��֤ÿ���ڵ�� label ������ͬ.

��ĳ�����Ҫ����һ��������ȿ�������ͼ. ��ͼ��ԭͼ����ͬ���Ľṹ, ���Ҷ���ͼ���κθĶ������ԭͼ����κ�Ӱ��.

����
����1
	����:
	{1,2,4#2,1,4#4,1,2}
	���:
	{1,2,4#2,1,4#4,1,2}
	����:
		1------2
		 \     |
		  \    |
		   \   |
			\  |
			  4
˵��
	��������ͼ�ı�ʾ: http://www.lintcode.com/help/graph/

ע������
	����Ҫ����������ڵ������ͬ label ���Ǹ��ڵ�.
*/

/*
Graph
	For example:
		{1,2,4#2,1,4#3,5#4,1,2#5,3} represents follow graph:

		1------2  3
		 \     |  |
		  \    |  |
		   \   |  |
			\  |  |
			  4   5
	we use # to split each node information.
	1,2,4 represents that 2, 4 are 1's neighbors
	2,1,4 represents that 1, 4 are 2's neighbors
	3,5 represents that 5 is 3's neighbor
	4,1,2 represents that 1, 2 are 4's neighbors
	5,3 represents that 3 is 5's neighbor
*/
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
using std::cin;
using std::cout;
using std::endl;
using std::queue;
using std::vector;
using std::unordered_set;
using std::unordered_map;
using std::pair;


struct UndirectedGraphNode {
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
	/*
	 * @param node: A undirected graph node
	 * @return: A undirected graph node
	 */
	UndirectedGraphNode* cloneGraph(UndirectedGraphNode* node) {
		// write your code here
		if (!node) {
			return nullptr;
		}

		UndirectedGraphNode *newNode = new UndirectedGraphNode(node->label);
		unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> link;
		link.insert(pair<UndirectedGraphNode *, UndirectedGraphNode *>{ node, newNode });

		queue<UndirectedGraphNode *> q;
		q.push(node);

		while (!q.empty()) {
			UndirectedGraphNode * currOld = q.front();
			UndirectedGraphNode * currNew = link[currOld];
			q.pop();

			for (auto neighbor : currOld->neighbors) {
				if (link.find(neighbor) != link.end()) {
					currNew->neighbors.push_back(link[neighbor]);
				}
				else {
					// �½���
					UndirectedGraphNode *newN = new UndirectedGraphNode(neighbor->label);
					currNew->neighbors.push_back(newN);
					q.push(neighbor);
					link.insert(pair<UndirectedGraphNode *, UndirectedGraphNode *>{ neighbor, newN });
				}
			}
		}
		return newNode;
	}
};


int main() {

	system("pause");
	return 0;
}