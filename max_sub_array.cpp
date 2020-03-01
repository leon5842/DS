#include <iostream>
#include <vector>
using namespace std;

/* using kadane algo */
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


class Solution_Brute {
	public:
		int maxSubArray(vector<int>& nums) {
			int maxSum, i, j;

			maxSum = nums[0];
			
			for (i = 0; i < nums.size(); i++)
			{
				int partial_sum = 0;

				for (j = i; j < nums.size(); j++)
				{
					partial_sum += nums[j];
					maxSum = max(partial_sum, maxSum);
				}

			}
			return maxSum;
		}
};



int main()
{
	vector<int> data;
	Solution nice;
	Solution_Brute bad;

	data.push_back(-1);
	data.push_back(5);
	data.push_back(9);
	data.push_back(-2);
	data.push_back(-3);
	data.push_back(3);
	data.push_back(2);

	//cout << "ans = " << nice.maxSubArray(data) << endl;
	cout << "ans = " << bad.maxSubArray(data) << endl;
	return 0;
}
