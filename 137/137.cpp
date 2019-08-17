/*
137. 克隆图
克隆一张无向图. 无向图的每个节点包含一个 label 和一个列表 neighbors. 保证每个节点的 label 互不相同.

你的程序需要返回一个经过深度拷贝的新图. 新图和原图具有同样的结构, 并且对新图的任何改动不会对原图造成任何影响.

样例
样例1
	输入:
	{1,2,4#2,1,4#4,1,2}
	输出:
	{1,2,4#2,1,4#4,1,2}
	解释:
		1------2
		 \     |
		  \    |
		   \   |
			\  |
			  4
说明
	关于无向图的表示: http://www.lintcode.com/help/graph/

注意事项
	你需要返回与给定节点具有相同 label 的那个节点.
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
					// 新建：
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