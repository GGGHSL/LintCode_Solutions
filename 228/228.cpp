/*
228. Middle of the Linked List
*/
#include <iostream>
#include <vector>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int val) : val(val), next(nullptr) {}
	ListNode(int val, ListNode* next) : val(val), next(next) {}
};

class Solution {
public:
	/*
	 * @param head: the head of linked list.
	 * @return: a middle node of the linked list
	 */
	ListNode* middleNode(ListNode* head) {
		auto fast = head;
		auto slow = head;
		while (fast->next && fast->next->next) {
			fast = fast->next->next;
			slow = slow->next;
		}
		// leetcode°æ±¾
		if (fast->next)  // Å¼Êı
			return slow->next;
		else  // ÆæÊı
			return slow;
	}
};

int main() {
	return 0;
}