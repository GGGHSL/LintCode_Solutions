#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <forward_list>
using std::forward_list;
using std::unordered_map;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class LinkedNode {
public:
	int key;
	int value;
	LinkedNode *next;

	LinkedNode(int key, int val) {
		this->key = key;
		this->value = val;
		this->next = NULL;
	}
};

class LRUCache {
public:
	/*
	* @param capacity: An integer
	*/
	LRUCache(int capacity) {
		// do intialization if necessary
		this->capacity = capacity;
		this->dummy = new LinkedNode(0, 0);
		this->tail = dummy;  // ��ʼ tail �󶨵� dummy
	}

	/*
	 * @param key: An integer
	 * @return: An integer
	 */
	int get(int key) {
		// write your code here
		if (key2prev.find(key) == key2prev.end()) {
			return -1;
		}
		// ע�����ﲻҪ����ֲ�����prev: kick ������ı� prev->next.
		kick(key2prev[key]);
		return key2prev[key]->next->value;
	}

	/*
	 * @param key: An integer
	 * @param value: An integer
	 * @return: nothing
	 */
	void set(int key, int value) {
		// write your code here
		if (key2prev.find(key) != key2prev.end()) {
			kick(key2prev[key]);
			key2prev[key]->next->value = value;
		}
		else {  
			/* ��push_back, �����׸�node����ʱ,dummy=tail=node,
			   ����dummy�᲻����ʼ��, ���� dummy->next Ϊ nullptr,
			   ���� pop_front ʱ���ñ���.
			*/ 
			push_back(new LinkedNode(key, value));
			
			if (key2prev.size() > capacity) {
				pop_front();
			}
		}
	}
private:
	int capacity;
	unordered_map<int, LinkedNode *> key2prev;
	LinkedNode *dummy;
	LinkedNode *tail;

	void pop_front() {
		auto head = dummy->next;
		key2prev.erase(head->key);
		dummy->next = head->next;
		key2prev[head->next->key] = dummy;
	}

	void push_back(LinkedNode *node) {
		// tail�󶨵�ǰβԪ��
		key2prev[node->key] = tail;
		tail->next = node;
		// ����tailΪ��push������Ԫ��
		tail = node;
	}

	void kick(LinkedNode *prev) { 
		auto node = prev->next;
		if (node == tail) {
			return;
		}
		prev->next = node->next;
		// Ϊʲô���ﻹҪ�ж� node->next �Ƿ�Ϊ NULL?
		if (node->next != NULL) {
			key2prev[node->next->key] = prev;
			node->next = NULL;
		}
		push_back(node);
	}
};

int main() {
	LRUCache cache(2);
	cache.set(2, 1);
	cache.set(1, 1);
	cout << cache.get(2) << endl;
	cache.set(4, 1);
	cache.get(1);
	cache.get(2);

	system("pause");
	return 0;
}