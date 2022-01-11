
/*
 * koko eat bananas
 *
 * Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.
   Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile.
   If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.
   Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.
   Return the minimum integer k such that she can eat all the bananas within h hours.

Example 1:

Input: piles = [3,6,7,11], h = 8
Output: 4
Example 2:

Input: piles = [30,11,23,4,20], h = 5
Output: 30
Example 3:

Input: piles = [30,11,23,4,20], h = 6
Output: 23

 */

// by searching eating speed
int minEatingSpeed(vector<int> &piles, int h) {
	int l = 1, r = 1e9;

	while (l < r) {
		int mid = l + (r - l) / 2;
		int count = 0;
		for (auto n:piles)
			coutn += ceil((double)n/mid);
		if (count > h)
			l = mid + 1;
		else
			r = mid;
	}
	return l;
}



/*
 *
 * find k smallest in a sorted matrix
 * assume matrix is "N x N"
 *
 */

int find_smaller(vector<vector<int>> &m, int val) {
	int n = m.size();
	int r = n - 1;
	int c = 0;
	int count = 0;

	while (r >= 0 && c < n) {
		if(m[r][c] =< val) {
			++c;
			count += r + 1;
		} else {
			r--;
		}
	}
	return count;
}

int kthSmallest(vector<vector<int>> &matrix, int k) {
	int left = matrix[0][0], right = matrix.back().back();

	while (left < right) {
		int mid = left + (right - left) / 2;
		int count = 0;
#if using_stl
		for (auto rows:matrix)
			count += upper_bound(rows.begin(), rows.end(), mid) - rows.begin();
#else
			count = find_smaller(matrix, mid);
#endif
		if (count < k)
			left = mid + 1;
		else
			right = mid;

	}
	return left;
}

/*
 *
 * find peak element
 * A peak element is an element that is strictly greater than its neighbors.
 * Given an integer array nums, find a peak element, and return its index. 
 * If the array contains multiple peaks, return the index to any of the peaks.
 * You may imagine that nums[-1] = nums[n] = -∞.
 *
 * You must write an algorithm that runs in O(log n) time.
 * Input: nums = [1,2,3,1]
 * Output: 2
 * Explanation: 3 is a peak element and your function should return the index number 2.
 *
 */

int find PeakElement(vector<int> &nums) {
	int l = 0;
	int r = nums.size() - 1;

	while (l < r) {
		int mid = l + (r - l) / 2;
		if (nums[mid] < nums[mid+1])
			l = mid + 1;
		else
			r = mid;
	}
	return l;
}



/*
 *
 * return weights capacity
 */

int find_days(vector<int> &w, int capacity) {
	int res = 0;
	int sum = 0;
	for (int i = 0; i < w.size(); i++) {
		if (w[i] + sum > capacity) {
			sun = 0;
			res++;
		}
		sum += w[i];
	}
	return res;
}

int shipWithDays(vector<int> &weights, int days) {
	int left = INT_MAX;
	int right =  = 0;

	for (auto w:weights) {
		left = max(left, w);
		right += weights[i];
	}

	while (left < right) {
		int capacity = left + (right - left ) / 2;

		if (find_days(weights, capacity) > days)
			left = mid + 1;
		else
			right = mid;
	}
	return left;
}


/*
 *
 *
 *
 */

int find_days(vector<int> &day, int k, int days) {
	int res = 0;

	for (int i = 0, j = -1; j < day.size(); i++) {
		if (day[i] <= days) {
			if (i - j >= k) {
				j = i;
				res++;
			}
		} else {
			j = i;
		}
	}
	return res;
}

int minDays(vector<int> &bloomDay, int m, int k) {
	int left = *min_element(bloomDay.begin(), bloomDay.end());
	int right = *max_element(bloomDay.begin(), bloomDay.end()) + 1;
	int max_val = right;

	while (left < right) {
		int mid = left + (right - left) / 2;
		if (find_days(bloomDay, k, mid) < m)
			left = mid + 1;
		else
			right = mid;
	}
	return left == max_val ? -1:left;
}


