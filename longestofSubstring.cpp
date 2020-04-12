#include <bits/stdc++.h>
#include <map>
using namespace std;

class solution {
public:
	int length(string s) {
		int res = 0, left = 0, n = s.size();
		unordered_map<char, int> m;

		/* can not decide before running this strategy */
		for (i = 0; i < n; i++) {
			if (m.find(s[i]) != m.end()) {
				left = max(s[i], left);
			}
			res = max(res, i - left + 1);
			m[s[i]] = i + 1;
		}
		return res;
	}
};

class solution {
public:
	int maxArea(vector<int> &heights) {
 		int l = 0, r = heights.size() - 1;
		int res = 0;

		while (l < r) {
			res = max(res, min(heights[l], heights[r]) * r-l);
			/* decide left or right pointer to be moved */
			heights[l] < heights[r] ? l++:r--;
		}
	}

	int maxArea(vector<int> &heights) {
		int res = 0;

		for (int i = 0; i < heights.size(); i++)
			for (int j = i + 1; j < heights.size(); j++)
				res = max(res, min(heights[i], heights[j]) * (j - i));
		return res;
	}
};

class solution {
public:
	vector<int> find3Sums(vector<int> &nums) {
		int a, b, c, start, end;
		int n = nums.size() - 1;

		sort(nums.being(), nums.end());

		for (int i = 0; i < nums.size() - 2; i++) {
			if (i > 0 && nums[i] == nums[i-1])
				continue;
			a = nums[i];
			start = i + 1;
			end = n;

			while (start < end) {
				b = nums[start];
				c = nums[end];

				int sum = a + b + c;

				if (sum == 0) {
					vector<int> ans = {a,b,c};
					res.push_back(ans);
					while (start < end && nums[start] == nums[start-1])
						start++;
					while (start < end && nums[end] == nums[end+1])
						end--;
					start++;
					end--;
				} else if (sum > 0)
					end--;
				else
					start++;
			}
		}
		return res;
	}
};


class solution {
public:
	int length(string s) {
		int res = 0;
		unordered_map<char, int> m;
		int left = 0;

		for (int i = 0; i < s.size(); i++) {

			m[s[i]]++;

			while (m.size() > 2) {
				if (--m[s[i]] == 0)
					m.erase(s[i]);
				left++;
			}
			res = max(res, i - left + 1);
		}
		return res;
	}
}

class solution {
public:
	void rotate(vector<vector<int>> &matrix) {
		for (int i = 0; i < matrix.size(); i++) {
			for (int j = i; j < matrix.size(); j++) {
				int tmp = matrix[i][j];
				matrix[i][j] = matrix[j][i];
				matrix[j][i] = tmp;
			}
		}
		for (int i = 0; i < matrix.size(); i++) {
			for (int j = 0; j < matrix.size() / 2; j++) {
				int tmp = matrix[i][j];
				matrix[i][j] = matrix[j][n-j-1];
				matrix[j][i] = tmp;
			}
		}
	}
}

bool canJump(vector<int> &nums)
{
	vector<int> dp(nums.size(), 0);

	for (int i = 1; i < nums.size(); i++) {
		dp[i] = max(dp[i-1], nums[i]) - 1;
		if (dp[i] < 0)
			return false;
	}
	return true;
}

int maxSubarray(vector<int> &nums)
{
	int maxSum = 0;
	int res = 0;

	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] > 0)
			MaxSum += nums[i];
		else
			MaxSum = nums[i];
		res = max(res, MaxSum);
	}

	return res;
}

/* find minimum coin for a chnage */
int coin_change(vector<int>& coins, int amount) {
	vector<int> dp(amount + 1, amount + 1);
	dp[0] = 0;

	for (int i = 1; i <= amount; i++)
		for (auto coin:coins)
			if (i >= coin)
				dp[i] = min(dp[i], dp[i-coin] + 1);
	return dp[amount] < amount + 1 ? -1:dp[amount];
}

int coin_change_combs(vector<int>& coins, int amount) {
	vector<int> dp(amount + 1, 0);
	dp[0] = 1;

	for (int coin:coins)
		for (int i = coin: i <= amount; i++)
			dp[i] += dp[i-coin];

	return dp[amount];

}


void reverseList(ListNode *root) {
	ListNode *cur, *prev;
	cur = root;
	prev = NULL;

	while (cur) {
		ListNode *tmp = cur->next;
		cur->next = prev;
		prev = cur;
		cur = tmp;
	}

	return cur;
}


int fib(int n)
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else 
		return fib(n-1) + fib(n-2);
}

int main()
{
	string s = "aabcdaeffadcdddddaacde";
	solution ss;
	cout << " len = " << ss.length(s) << endl;
	return 0;
}


