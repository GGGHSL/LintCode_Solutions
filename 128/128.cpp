#include <iostream>
#include <vector>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class Solution {
public:
	/**
	 * @param key: A string you should hash
	 * @param HASH_SIZE: An integer
	 * @return: An integer
	 */
	int hashCode(string &key, int HASH_SIZE) {
		// write your code here
		long idx = 0;
		for (auto c : key) {
			idx = (idx * 33 + c) % HASH_SIZE;
		}
		return int(idx);
	}
};

int main() {

	system("pause");
	return 0;
}