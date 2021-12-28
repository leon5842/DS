
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
