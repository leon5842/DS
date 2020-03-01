#include <iostream>
#include <vector>
using namespace std;


class Solution {
	public:
		int maxSubArray(vector<int>& nums) {
			int maxSum, i;

			maxSum = nums[0];

			for (i = 1; i < nums.size(); i++)
			{
				if (nums[i-1] >0)
					nums[i] += nums[i-1];
				maxSum = max(nums[i], maxSum);
			}
			return maxSum;
		}
};


int main()
{
	vector<int> data;
	Solution nice;

	data.push_back(-1);
	data.push_back(5);
	data.push_back(9);
	data.push_back(-2);
	data.push_back(-3);
	data.push_back(3);
	data.push_back(2);

	cout << "ans = " << nice.maxSubArray(data) << endl;
	return 0;
}
