#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <random>
using std::rand;
using std::unordered_map;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class RandomizedSet {
public:
	RandomizedSet() {
		// do intialization if necessary
	}

	/*
	 * @param val: a value to the set
	 * @return: true if the set did not already contain the specified element or false
	 */
	bool insert(int val) {
		// write your code here
		if (num2idx.find(val) == num2idx.end()) {
			num2idx[val] = vec.size();
			vec.push_back(val);
			return true;
		}
		else {
			return false;
		}
	}

	/*
	 * @param val: a value from the set
	 * @return: true if the set contained the specified element or false
	 */
	bool remove(int val) {
		// write your code here
		if (num2idx.find(val) == num2idx.end()) {
			return false;
		}
		int idx = num2idx[val];
		num2idx.erase(val);

		vec[idx] = vec.back();
		num2idx[vec.back()] = idx;
		
		vec.pop_back();
		return true;
	}

	/*
	 * @return: Get a random element from the set
	 */
	int getRandom() {
		// write your code here
		if (vec.size() == 1) {
			return vec[0];
		}
		return vec[rand() % vec.size()];
	}
private:
	unordered_map<int, int> num2idx;
	vector<int> vec;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param = obj.insert(val);
 * bool param = obj.remove(val);
 * int param = obj.getRandom();
 */


int main() {

	system("pause");
	return 0;
}