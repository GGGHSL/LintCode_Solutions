#include <iostream>
#include <vector>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

/**
 * Definition of ListNode
 */
class ListNode {
public:
	int val;
	ListNode *next;
	ListNode(int val) {
		this->val = val;
		this->next = NULL;
	}
};

class Solution {
public:
	/**
	 * @param hashTable: A list of The first node of linked list
	 * @return: A list of The first node of linked list which have twice size
	 */
	vector<ListNode*> rehashing(vector<ListNode*> hashTable) {
		// write your code here
		int cap = hashTable.size();
		cap *= 2;
		vector<ListNode*> res(cap, NULL);

		for (auto node : hashTable) {
			auto curr = node;
			while (curr) {
				int idx = (curr->val % cap + cap) % cap;
				if (res[idx] == NULL) {
					res[idx] = new ListNode(curr->val);
				}
				else {
					auto nxt = res[idx];
					while (nxt->next != NULL) {
						nxt = nxt->next;
					}
					nxt->next = new ListNode(curr->val);
				}
				curr = curr->next;
			}
		}
		return res;
	}
};

int main() {

	system("pause");
	return 0;
}