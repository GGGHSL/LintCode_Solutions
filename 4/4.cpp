#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
using std::unordered_set;
using std::priority_queue;
using std::greater;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class Solution {
public:
	/**
	 * @param n: An integer
	 * @return: return an integer as description.
	 */
	int nthUglyNumber(int n) {
		// write your code here
		priority_queue<long, vector<long>, greater<long>> q;
		unordered_set<long> visit;
		q.push(1);
		visit.insert(1);
		vector<int> factors{ 2, 3, 5 };
		long min = 1;

		while (n != 0) {
			min = q.top();
			q.pop();
			
			for (auto i : factors) {
				long curr = min * i;
				if (visit.find(curr) == visit.end()) {
					q.push(curr);
					visit.insert(curr);
				}
			}
			--n;
		}
		return min;
	}
};

int main() {

	system("pause");
	return 0;
}