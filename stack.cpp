/*
 * all these are using monotonic stack, either increasing or decreasing
 * monotonic stack (strickly increasing or decreasing) in stack item.
 * if you are process an item which may conflict the monotonic defintion of the stack
 * stack operation will pop the stack top in order to keep the stack monotonic
 * when you poped out an item, keep some calculation for either first big or first small item
 */


/*
 next greater element
 Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
 Output: [-1,3,-1]
 Explanation: The next greater element for each value of nums1 is as follows:
 - 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
 - 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
 - 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
*/

vector<int> nextGreaterElement(vector<int> &A, vector<int> &B) {
	int n = A.size();
	vector<int> res(n, -1);
	unordered_map<int, int> m;
	stack<int> stk;

	for (int i = 0; i < B.size(); i++) {
		while (!stk.empty() && B[i] >= stk.top()) {
			m[stk.top()] = B[i];
			stk.pop();
		}
		stk.push(B[i]);
	}

	for (int i = 0; i < n; i++)
		if (m.count(A[i]))
			res[i] = m[A[i]];

	return res;
}


/*
 Design an algorithm that collects daily price quotes for some stock and returns the span of that stock's price for the current day.
 The span of the stock's price today is defined as the maximum number of consecutive days (starting from today and going backward) for
 which the stock price was less than or equal to today's price.
 For example, if the price of a stock over the next 7 days were [100,80,60,70,60,75,85], then the stock spans would be [1,1,1,2,1,4,6].
 Implement the StockSpanner class:
 StockSpanner() Initializes the object of the class.
 int next(int price) Returns the span of the stock's price given that today's price is price.
 Input
 ["StockSpanner", "next", "next", "next", "next", "next", "next", "next"]
 [[], [100], [80], [60], [70], [60], [75], [85]]
 Output
 [null, 1, 1, 1, 2, 1, 4, 6]

 Explanation
 StockSpanner stockSpanner = new StockSpanner();
 stockSpanner.next(100); // return 1
 stockSpanner.next(80);  // return 1
 stockSpanner.next(60);  // return 1
 stockSpanner.next(70);  // return 2
 stockSpanner.next(60);  // return 1
 stockSpanner.next(75);  // return 4, because the last 4 prices (including today's price of 75) were less than or equal to today's price.
 stockSpanner.next(85);  // return 6
 */

stack<pair<int, int>> stk;

int next(int price) {
	int res = 1;

	while (!stk.empty() && price > stk.top().first) {
		res += stk.top().second;
		stk.pop();
	}
	stk.push({price, res});
	return res;
}


/*
 * Given an array of integers temperatures represents the daily temperatures,
 * return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature.
 * If there is no future day for which this is possible, keep answer[i] == 0 instead.
 *
 *  Input: temperatures = [73,74,75,71,69,72,76,73]
    Output: [1,1,4,2,1,1,0,0]
 */

vector<int> dailyTemperatures(vector<int> &nums) {
	int n = nums.size();
	vector<int> res(n, 0);
	stack<pair<int, int>> stk;

	for (int i = 0; i < n; i++) {
		while (!stk.empty() && nums[i] > stk.top().first) {
			res[stk.top().second] = i - s.top().second;
			stk.pop();
		}
		stk.push({nums[i], i});
	}
	return res;
}


/*
 * Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]),
 * return the next greater number for every element in nums.
 * The next greater number of a number x is the first greater number to its traversing-order next in the array,
 * which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.
 *
 * Input: nums = [1,2,3,4,3]
 * Output: [2,3,4,-1,4]
 */

vector<int> nextGreaterElement(vector<int> &nums) {
	vector<int> res(nums.size(), -1);
	int n = nums.size();
	stack<pair<int,int>> stk;

	for (int i = 0; i < n * 2; i++) {
		while (!stk.empty() && nums[i] > stk.top().first) {
			res[stk.top().second] = nums[i % n];
			stk.pop();
		}
		stk.push({nums[i%n], i % n});
	}

	return res;
}

/*
 * valid parenthesis, return true if the valid thesis () {} (({})) etc.
 */

bool validParenthesis(string s) {
	stack<char> stk;

	for (auto c:s) {
		if (c == '(' || c == '{' || c == '[') {
			stk.push(c);
		} else {
			if (stk.empty())
				return false;
			if (stk.top == '(' && c != ')')
				return false;
			if (stk.top == '[' && c != ']')
				return false;
			if (stk.top == '{' && c != '}')
				return false;
			stk.pp();
		}
	}

	return stk.empty() ? true : false;
}
