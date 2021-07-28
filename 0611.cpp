
/* get the k smallest sum of two array pair */
class Solution {
public:
    struct mycmp {
        bool operator () (pair<int, int> &a, pair<int, int> &b) {
            return a.first + a.second < b.first + b.second;
        }
    };
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, mycmp> pq;
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> res;
        
        for (int i = 0; i < n; i++) {
            For (int j = 0; j < m; j++) {
                if (pq.size() < k)
                    pq.push({nums1[i], nums2[j]});
                else if (pq.top().first + pq.top().second > nums1[i] + nums2[j]) {
                    pq.pop();
                    pq.push({nums1[i], nums2[j]});
                }
            }
        }
 
        while (!pq.empty()) {
            auto it = pq.top(); pq.pop();
            res.push_back({it.first, it.second});
        }
        return res;
    }
};

/* get top 5 student score avg sorted with their id */
class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        map<int, priority_queue<int, vector<int>, greater<int>>> m;
        vector<vector<int>> res;
        
        for (auto &v : items) {
            if (m[v[0]].size() < 5)
                m[v[0]].push(v[1]);
            else if (m[v[0]].top() < v[1]) {
                m[v[0]].push(v[1]);
                m[v[0]].pop();
            }
        }
        
        for (auto [id, pq] : m) {
            int sum = 0;
            while (!pq.empty()) {
                sum += pq.top(); pq.pop();
            }
            res.push_back({id, sum/5});
        }
        return res;
    }
};


/* sliding window max value with k size */
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> deq;
        for (int i = 0; i < nums.size(); i++) {
            while (!deq.empty() && deq.front() <= i - k)
                deq.pop_front();
            while(!deq.empty() && nums[deq.back()] <= nums[i])
                deq.pop_back();
            deq.push_back(i);
            if (i >= k - 1)
                res.push_back(nums[deq.front()]);
        }
        return res;
    }
};


class Solution {
public:
    static bool mycmp(vector<int> &a, vector<int> &b) {
        return a[0] < b[0];
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> merged;
        if (intervals.size() < 2)
            return intervals;
        sort(intervals.begin(), intervals.end(), mycmp);
        merged.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {
            if (merged.back()[1] >= intervals[i][0])
                merged.back()[1] = max(intervals[i][1], merged.back()[1]);
            else
                merged.push_back(intervals[i]);
        }
        return merged;
    }
};



const arr = [
	one
	two
	three
	one
	one
	one
	one
	three
	two
	three
	two
	three
	two
	three
]
