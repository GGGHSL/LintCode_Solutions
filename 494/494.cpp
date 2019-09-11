#include <iostream>
#include <vector>
#include <string>
#include <queue>
using std::queue;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class Stack {
public:
	/*
	 * @param x: An integer
	 * @return: nothing
	 */
	void push(int x) {
		// write your code here
		q1.push(x);
	}

	/*
	 * @return: nothing
	 */
	void pop() {
		// write your code here
		while (q1.size() > 1) {
			q2.push(q1.front());
			q1.pop();
		}
		q1.pop();  // q1 is empty;
		q1 = *new queue<int>(q2);
		q2 = queue<int>();
	}

	/*
	 * @return: An integer
	 */
	int top() {
		// write your code here
		return q1.back();
	}

	/*
	 * @return: True if the stack is empty
	 */
	bool isEmpty() {
		// write your code here
		return q1.empty();
	}
private:
	queue<int> q1;
	queue<int> q2;
	
};

int main() {

	system("pause");
	return 0;
}