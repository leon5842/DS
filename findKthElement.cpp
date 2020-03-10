#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	Solution(){}
	vector<int> plusOne(vector<int> &digits) {
		vector<int>::reverse_iterator it;

		for (it = digits.rbegin(); it != digits.rend(); it++) {
			if (*it == 9) {
				*it = 0;
			} else {
				*it = *it + 1;
				return digits;
			}
		}
		digits.insert(digits.begin(), 1);
		return digits;
	}

	int findKthElement(vector<int> &array, int k) {

		priority_queue<int> q;
		int ans = 0;

		for (auto i:array)
			q.push(i);

		while (!q.empty() && k > 0) {
			k--;
			ans = q.top();
			q.pop();
		}
		return ans;
	}
};

void printVec(vector<int> data)
{
	for (auto &i:data)
		cout << i << " "; 
	cout << endl;
}

int main()
{
	Solution s;

	vector<int> vec;
	vec.push_back(1);
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(9);
	vec.push_back(4);

	cout << "original data" << endl;
	printVec(vec);
	cout << "plusOne data" << endl;
	vec = s.plusOne(vec);
	printVec(vec);

	for (auto &i:vec) {
		if (i == 1)
			i++;
	}
	printVec(vec);
	return 0;
}
