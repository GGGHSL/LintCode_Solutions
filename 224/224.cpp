#include <iostream>
#include <vector>
#include <string>
#include <deque>
using std::deque;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class ThreeStacks {
public:
	/*
	* @param size: An integer
	*/
	ThreeStacks(int size) {
		// do intialization if necessary
		deque<int> q1, q2, q3;
		buffer = { q1, q2, q3 };
	}

	/*
	* @param stackNum: An integer
	* @param value: An integer
	* @return: nothing
	*/
	void push(int stackNum, int value) {
		// Push value into stackNum stack
		buffer[stackNum].push_back(value);
		cout << buffer[stackNum].size();
	}

	/*
	* @param stackNum: An integer
	* @return: the top element
	*/
	int pop(int stackNum) {
		// Pop and return the top element from stackNum stack
		int top = buffer[stackNum].back();
		buffer[stackNum].pop_back();
		return top;
	}

	/*
	* @param stackNum: An integer
	* @return: the top element
	*/
	int peek(int stackNum) {
		// Return the top element
		return buffer[stackNum].back();
	}

	/*
	* @param stackNum: An integer
	* @return: true if the stack is empty else false
	*/
	bool isEmpty(int stackNum) {
		// write your code here
		return buffer[stackNum].empty();
	}
private:
	vector<deque <int>> buffer;
};

int main() {

	system("pause");
	return 0;
}