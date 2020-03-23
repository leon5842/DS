#include <bits/stdc++.h>
using namespace std;


class solution {
public:
	vector<string> findRepeatK(vector<string> &s, int k) {
		unorder_map<string, int> freq;
		map<int, set<string> m;

		for (string str : s)
			freq[str]++;

		for (auto i : freq)
			m[i.second].insert(i.first);
		
		for (auto it = m.rbeing; it != m.rend(); it++) {
			if (k <= 0)
				break;
			auto v = it.second;
			vector<string> c(v.begin(), v.end());
			
			if (k >= v.size())
				res.insert(res.end(), c.begin(), c.end());
			else
				res.insert(res.end(), c.begin, c.begin() + k);
			k -= v.size();
		}
	}
};

