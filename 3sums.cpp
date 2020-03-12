#include <bits/stdc++.h>
using namespace std;

class Solution {
	vector<vector<int>> calculate_3Sums(vector<int> &nums) {
		int a, b, c, start, end, n;
		vector<vector<int>> ans;

		sort(nums);
		n = nums.size();

		for (int i = 0; i < n-2; i++) {
			if (i > 0 && nums[i] == nums[i-1])
				continue;
			a = nums[i];
			start = i + 1;
			end = n -1;

			while (start < end) {

				b = nums[start];
				c = nums[end];
				int sum = a + b + c;

				if (sum == 0) {

					vector<int> tmp = {a, b, c};
					ans.push_back(tmp);

					while (start < end && nums[start] == nums[start+1]) start++;
					while (start < end && nums[end] == nums[end-1]) end--;
					start++;
					end--;

				} else if (sum > 0)
					start++;
				else 
					end--;
			}
		}
		return ans;
	}
};
