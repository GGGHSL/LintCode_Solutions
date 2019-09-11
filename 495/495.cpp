#include <iostream>
#include <vector>
#include <string>
#include <deque>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::deque;

class Stack {
public:
	/*
	 * @param x: An integer
	 * @return: nothing
	 */
	void push(int x) {
		// write your code here
		dq.push_back(x);
	}

	/*
	 * @return: nothing
	 */
	void pop() {
		// write your code here
		dq.pop_back();
	}

	/*
	 * @return: An integer
	 */
	int top() {
		// write your code here
		return dq.back();
	}

	/*
	 * @return: True if the stack is empty
	 */
	bool isEmpty() {
		// write your code here
		return dq.empty();
	}
private:
	deque<int> dq;
};

int main() {
	
	system("pause");
	return 0;
}