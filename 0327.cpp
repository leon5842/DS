class solution {
	int longestSubstringWithoutRepeat(string s) {
			int res = 0;
			unordered_map<char, int> m;

			for (int i = 0, left = 0; i < s.size(); i++) {
				if (m.find(s[i]) != m.end()) {
					left = max(s[i], left);
				}
				res = max(res, i- left + 1);
				m[s[i]] = i + 1;
			}
			// test
			return res;
	}
};


class Solution {
	public:
		int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
			int n = obstacleGrid.size();
			int m = obstacleGrid[0].size();

			vector<vector<long>> dp(n, vector<long>(m,0));
			if (obstacleGrid[0][0])
				return 0;
			dp[0][0] = 1;

			for (int col = 1; col < m; col++) {
				if (obstacleGrid[0][col] != 1)
					dp[0][col] = 1;
				else
					break;
			}

			for (int row = 1; row < n; row++) {
				if (obstacleGrid[row][0] != 1)
					dp[row][0] = 1;
				else
					break;
			}

			for (int i = 1; i < n; i++)
				for (int j = 1; j < m; j++)
					if (!obstacleGrid[i][j])
						dp[i][j] = dp[i-1][j] + dp[i][j-1];
			return dp[n-1][m-1];
		}
};

// enumreate all posiible permutations for int n;
int backtrack(int n) {
	if (n == 5) {
		cout << "solution"  << endl;
		return;
	}

	for (i = 0; i < 5; i++ ) {
		if (!visited[i]) {
			visited[i] = true;
			soltion[i] = n;
			bactrack(n+1);
			visited[i] = false'
		}
	}
}



class Solution {
	public:
		int uniquePaths(int m, int n) {
			vector<vector<int>> cases(2, vector<int>(m, 1));

			for (int i = 1; i < n; i++)
				for (int j = 1; j < m; j++)
					cases[i%2][j] = cases[(i-1)%2][j] + cases[i%2][j-1];

			return cases[(n-1)%2][m-1];
		}
};

class Solution {
	public:
		int minFallingPathSum(vector<vector<int>>& A) {
			int n = A.size();
			int res = INT_MAX;

			if (A.size() == 1) 
				return A[0][0];

			for (int i = 1; i < n; i++) {
				for (int j = 0; j < n; j++) {
					int pre = A[i-1][j];
					if (j > 0)
						pre = min(pre, A[i-1][j-1]);
					if (j < n - 1)
						pre = min(pre, A[i-1][j+1]);
					A[i][j] += pre;
					if (i == n - 1)
						res = min(res, A[i][j]);
				}
			}
			return res;
		}
};



/*
 * Brain Kernighan algorithm
 *
 */

unsigned int countSetBits(int n)
{
	unsigned int count = 0;
	while (n) {
		n &= (n - 1);
		count++;
	}
	return count;
}

class Solution {
	public:
		bool isExpressive(string dst,string src) {
			int i=0,j=0;

			while(i<dst.size() && j<src.size()) {
				if(dst[i] != src[j]) return false;
				int dstCount = 1,srcCount = 1;


				while(i<dst.size() && dst[i]==dst[++i]) { dstCount++;} 
				while(j<src.size() && src[j]==src[++j]) { srcCount++;}

				if(dstCount != srcCount && (srcCount > dstCount || dstCount <3))
					return false;
			}

			return i==dst.size() && j==src.size();
		}

		int expressiveWords(string S, vector<string>& words) {
			int res = 0;

			for(auto w : words) {
				res += isExpressive(S,w);
			}

			return res;

		}
};


int maxSubArrayLen(vector<int>& nums, int k) {
	unordered_map<int,int> m;
	int maxLen = INT_MIN;
	int cur_sum = 0;
	m[0] = -1;

	for (int i = 0; i < nums.size(); i++) {
		cur_sum += nums[i];

		if (m.count(cur_sum - k)) {
			maxLen = max(maxLen, i - m[cur_sum-k]);
			cout << maxLen << endl;
		}

		if (!m.count(cur_sum))
			m[cur_sum] = i;
	}
	return maxLen == INT_MIN  ? 0:maxLen;
}

/*
 * Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s.
 * If there isn't one, return 0 instead.
 */

int minSubArraySum(int s, vector<int> &nums)
{
	int w_e = 0, w_s = 0;
	int minLen = INT_MAX;
	int cur_sum = 0;


	for (w_e; w_e < nums.size(); w_e++) {
		cur_sum += nums[w_e];
		while (cur_sum >= s) {
			minLen = min(minLen, w_e - w_s + 1);
			cur_sum -= nums[w_s];
			w_s++;
		}
	}
	return minLen == INT_MAX ? 0 : minLen;
}

/*
 * Given a string, find the length of the longest substring T that contains at most k distinct characters.
 * Input: s = "eceba", k = 2
 * Output: 3
 * Explanation: T is "ece" which its length is 3.
 *
 */

class solution {
public:
	int longestSubstringTinKDinstinct(string s, int k) {
		int maxLen = 0;
		unordered_map<char, int>> m;
		int window_start = 0;

		for (int window_end = 0; window_end < s.size(); window_end++) {
			m[s[window_end]]++;

			while (m.size() > k) {
				if (--m[s[window_start]] == 0)
					m.erase(s[window_start]);
				window_start++;
			}
			maxLen = max(maxLen, window_end - widnow_start + 1);
		}
		return maxLen;
	}
};


class solution {
	int FindMaxArea(vector<int> &heights) {
		int maxArea = 0;

		for (int i = 0; i < heights.size(); i++)
			for (int j = i + 1; j < heights.size(); j++)
				maxArea = max(maxArea, min(height[i], height[j]) *  j-i)
	}
};


class solution {
	int FindMaxArea(vector<int> &height) {
		int maxArea = 0;
		int i = 0, j = height.size() - 1;

		while (i < j) {
			maxArea = max(maxArea, min(height[i], height[j]) * (j - i));
			height[i] < height[j] ? i++ : j--;
		}
		return maxArea;
	}
};

class solution {
	vector<vector<int>> find3Sum(vector<int> &nums) {
		vector<vector<int>> ans;
		int a, b , c, start, end;
		int i = 0;

		sort(nums.begin(), nums.end());

		for (i = 0; i < nums.size() - 2; i++) {
			if ( i > 0 &&  nums[i] == nums[i-1])
				continue;
			a = nums[i];
			start = i + 1;
			end = nums.size() - 1;

			while (start < end) {
				int result = a+b+c;
				if (result == 0) {
					vector<int> tmp = {a,b,c};
					ans.push_back(tmp);
					while (start < end && nums[start] == nums[start+1]) start++;
					while (start < end && nums[end] == nums[end-1]) end--;
				} else if (result < 0) {
					start++;
				} else {
					end--;
				}
			}
		}
		return ans;
	}
};

class solution {
public:
	void rotate(vector<vector<int>> &matrix) {
		int i, j ,tmp;
		for (i = 0; i < matrix.size(); i++) {
			for (j = 0; j < maxtrix.size(); j++) {
				tmp = matrix[j][i];
				matrix[j][i] = matrix[i][j];
				matrix[i][j] = tmp;
			}
		}
		for (i = 0; i < matrix.size(); i++) {
			for (j = 0; j < matrix.size() / 2; j++){
				int tmp = matrix[i][j];
				matrix[i][j] = matrix[i][n-j-1];
				matrix[i][n-j-1] = tmp;
			}
		}

	}
};


class solution {
public:
	vector<int> plusOne(vector<int> &nums) {

		for (auto it = nums.rbegin(); it != nums.rend(); it++) {
			if (*it == 9) {
				*it = 0;
			} else {
				*it = *it + 1;
				return nums;
			}
			nums.insert(nums.begin(),1);
			return nums;
		}
	}
}


void DFS(int vertex)
{
	visited[vertex] = true;

	cout << vertex is being visited
	for(int i = 0 ; i < matrix.size();i++)
		if (!visited[i] && matrix[vertex][i])
			DFS(i);
}

void BFS(vector<vector<int>> matrix)
{
	int vertex;
	vector<int> visited(matrix.size(), 0);
	queue<int> q;

	for (int i = 0; i < visited.size(); i++) {
		if (visited[i] == false) {
			q.push_back(i);
			visited[i] = true;
			printf("visited node %d\n", visited[i]);

			while (!q.empty()) {
				int node_traversal  = q.front();
				q.pop();

				for (int j = 0; j < visited.size(); j++) {
					if(matrix[i][j] && !visited[i]{
						q.push_back(j);
						visited[j] = true;
					}
				}

			}
		}
	}
}


class solution {
public:
	string minSubstring(string s, string t) {

		string sub;
		int left = 0, minlen = 0, cnt = 0;
		unordered_map<char, int> letterCnt;
		
		for (char c:t)
			m[t[c]]++;

		for (int i = 0; i < s.size(); i++) {
			if (--letterCnt[s[i]] > 0)
				cnt++;

			/* if we get all target string in source window */
			while (cnt == t.size()) {
				if (minlen > i - left + 1) {
					minlen = i - left + 1;
					sub = s.substr(left, minlen);
				}
				if (++letterCnt[s[i]] > 0)
					cnt--;
				++left;
			}
		}
	}
};


class solution {
public:
	string findminSubStr(string s, string t) {
		string res = "";
		int minlen = 0, i = 0, left = 0;
		int cnt = 0;
		unordered_map<char,int> letterCnt;

		for (char c:t)
			letterCnt(t[c]])++;
		for (i = 0; i < s.size(); i++) {
			if (--letterCnt(s[i]) > 0)
					cnt++;
			while (cnt == t.size()) {
				if (minLen > i - left + 1) {
					minLen = i - left + 1;
					res = s.substr(left,minLen);
				}
				if (++letterCnt[left] > 0)
					cnt--;
				left++;
			}
		}
		return res;
	}
};

class solution {
public:
	int lengofDistinct(string s) {
		int res = 0;
		int left = 0;
		unordered_map<char, int> m;

		for (int i = 0; i < s.size(); i++) {
			m[s[i]]++;
			while (m.size() > 2) {
				if (--m[s[left]] == 0)
					m.erase(s[left]);
				left++;
			}
			res = max(res, i - left + 1);
		}

	}
};


class solution {

    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
		string res;
		vector<pair<int,int>> loc;

		for (int i = 0; i < indexes.size(); i++)
			loc.push_back(make_pair{indexes[i],i});
		sort(loc.rbegin(), loc.rend());
		
		for (auto &a:loc) {
			int i = loc.first;
			string s = sources[loc.second];
			string t = targets[loc.second];

			if (S.substr(i, s.size()) == s) {
				S = S.substr(0, i) + t + S.substr(i + s.size());
			}
		}
	}
};

class solution {
piublic:
	bool validParenthsis(string str) {

		stack<char> stk;

		for (int i = 0; i < str.size(); i++) {
			if (str[i] == '[' || str[i] == '{' || str[i] == '(') {
				stk.push(str[i]);
			} else {
				if (!stk.empty()) return false;
				if (stk[i] == '[' && stk.top() != ']')
					return false;
				if (stk[i] == '{' && stk.top() != '}')
					return false;
				if (stk[i] == '(' && stk.top() !=  ')')
					return false;

			}
		}
		return true;
	}
}

class solution {
	ListNode* mergeKsorted(vector<ListNode*> &lists) {
		int n = lists.size();
		if (n == 0)
			return NULL;

		while (n > 1) {
			int k = (n + 1) / 2;
			for (int i = 0; i < n / 2; i++)
				lists[i] = mergeTwoLists(lists[i], lists[i + k]);
			n = k;
		}
		return lists[0];
	}

	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode *dummy = new ListNode(0);
		ListNode *cur;

		cur = dummy;
		
		while (l1 && l2) {
			if (l1->val > l2->val) {
				cur->next = l2;
				l2 = l2->next;
			} else {
				cur->next = l1;
				l1 = l1->next;
			}
			cur = cur->next;
		}
		if (l1)
			cur->next = l1;
		if (l2)
			cur->next = l2;
		return dummy;

	}
};


class solution {
public:
	int findKLarget(vector<int> &nums, int k) {
		priority_queue<int> pq;

		for (int a:nums)
			pq.push(a);

		while (!pq.emtpy() && k > 0) {
			pq.pop();
			k--;
		}
		return pq.top();
	}
};
