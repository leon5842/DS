#include <bits/stdc++.h>
#include <map>
using namespace std;


class solution {
public:
	int length(string s) {
		int left = 0, res = 0;
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
		return res;
	}
};

int main()
{
	string s = "aabcdaeffadcdddddaacde";
	solution ss;
	cout << " len = " << ss.length(s) << endl;
	return 0;
}
