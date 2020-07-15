#include <iostream>
#include <map>
using namespace std;

/*
 * 
 * Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.
 * Example 1:
 * Input:nums = [1,1,1], k = 2
 * Output: 2
 *
 */

int subarrySum(int k, vector<int> &nums)
{
	int res = 0;
	int sum = 0;
	unordered_map<int, int>> m;

	m[0] = 1;

	for (int i = 0; i < nums.size(); i++) {
		sum += nums[i];
		res += m[sum - k];
		m[sum]++;
	}
	return res;
}


/*
 *
 * Your are given an array of positive integers nums.
 * Count and print the number of (contiguous) subarrays where the product of all the elements in the subarray is less than k.
 * Example 1:
 * Input: nums = [10, 5, 2, 6], k = 100
 * Output: 8
 * Explanation: The 8 subarrays that have product less than 100 are: [10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6].
 * Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.
 *
 */
int numSubarrayProductLessThanK(vector<int>& nums, int k) {
	int product = 1;
	if (k <= 1)
		return 0;
	int res = 0;

	for (int i = 0, j = 0; j < nums.size(); j++) {
		product *= nums[j];
		while (product >= k)
			product /= nums[i++];
		res += j - i + 1;
	}

	return res;
}

/*
 *  Given an array of distinct integers arr, find all pairs of elements with the minimum absolute difference of any two elements. 
 *  Return a list of pairs in ascending order(with respect to pairs), each pair [a, b] follows
 *  a, b are from arr
 *  a < b
 *  b - a equals to the minimum absolute difference of any two elements in arr
 *
 */

vector<vector<int>> minimumAbsDifference(vector<int>& nums) {
	int min_diff = INT_MAX;
	vector<vector<int>> res;
	sort(nums.begin(), nums.end());

	for (int i = 0; i < nums.size() - 1; i++)
		min_diff = min(min_diff, nums[i + 1] - nums[i]);
	for (int i = 0; i < nums.size() - 1; i++) {
		if (nums[i+1] - nums[i] == min_diff)
			res.push_back({nums[i], nums[i+1]});
	}
	return res;
}

/*
 *  Given an array of integers nums, write a method that returns the "pivot" index of this array.
 *  We define the pivot index as the index where the sum of all the numbers to the left of the index is equal to the sum of
 *  all the numbers to the right of the index.
 *  If no such index exists, we should return -1. If there are multiple pivot indexes, you should return the left-most pivot index.
 *  Example 1:
 *  Input: nums = [1,7,3,6,5,6]  Output: 3
 *  Explanation:
 *  The sum of the numbers to the left of index 3 (nums[3] = 6) is equal to the sum of numbers to the right of index 3.
 *  Also, 3 is the first index where this occurs.
 */
int pivotIndex(vector<int>& nums) {
	int sum = 0, left_sum = 0;
	for (auto n:nums)
		sum += n;

	for (int i = 0; i < nums.size(); i++) {
		if (left_sum == sum - left_sum - nums[i])
			return i;
		left_sum += nums[i];
	}
	return -1;
}

/*
 * two sum, find the index so that the two number located in an array such that
 * a + b == target
 */
vector<int> twoSum(vector<int>& nums, int target) {
	unordered_map<int, int> m;

	for (int i = 0; i < nums.size(); i++) {
		int complement = target - nums[i];
		if (m.count(complement))
			return {m[complement], i};
		m[nums[i]] = i;
	}
	return {};
}

/*
 * two sum  (array was sorted)
 * assume the array was sorted in ascending order, find the two index (1 based instead of 0)
 * so that a + b == target
 * Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.
 * The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.
 * Your returned answers (both index1 and index2) are not zero-based.
 * You may assume that each input would have exactly one solution and you may not use the same element twice
 */

vector<int> twoSum_Sorted(vector<int> &nums, int target) {
	int left = 0, right = nums.size() - 1;
	while (left < right) {
		if (nums[left] + nums[right] == target)
			return {left + 1, right + 1};
		else if (nums[left] + nums[right] < target)
			left++;
		else
			right --;
	}
	return {};
}


/*
 * Given an array A of integers and integer K, return the maximum S such that there exists i < j with A[i] + A[j] = S and S < K.
 * If no i, j exist satisfying this equation, return -1;
 * Example 1:
 * Input: A = [34,23,1,24,75,33,54,8], K = 60
 * Output: 58
 * Explanation: 
 * We can use 34 and 24 to sum 58 which is less than 60.
 */

int twoSumLessThanK(vector<int>& nums, int K) {
	int maxSum = -1;
	int l = 0, r = nums.size() - 1;
	sort(nums.begin(), nums.end());

	while (l<r) {
		if (nums[l] + nums[r] < K) {
			maxSum = max(maxSum, nums[l] + nums[r]);
			l++;
		} else
			r--;
	}
	return maxSum;
}


/*
 *  three Sum , find a + b + c == 0
 *
 *
 */

vector<vector<int>> threeSum(vector<int>& nums) {
	int a = 0, b = 0, c = 0, start = 0, end = 0;
	vector<vector<int>> res;

	if (nums.empty())
		return {};
	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size(); i++) {
		if (i > 0 && nums[i] == nums[i-1])
			continue;
		a = nums[i];
		start = i + 1;
		end = nums.size() - 1;
		while (start < end) {
			b = nums[start];
			c = nums[end];
			if (a + b + c == 0) {
				res.push_back({a,b,c});
				while (start < end && nums[end] == nums[end-1])
					end--;
				while (start < end && nums[start] == nums[start+1])
					start++;
				start++;
				end--;
				cout<< "aaa" << endl;
			} else if (a + b + c < 0)
				start++;
			else
				end--;
		}
	}
	return res;
}

int main() {
	return 0;
}
