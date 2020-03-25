#include <bits/stdc++.h>
using namespace std;
class Solution {
	public:
		int lengthOfLongestSubstring(string s) {
			int ans = 0;
			unordered_map<char, int> m;

			for (int j = 0, i = 0; j < s.size();j++) {
				if (m.find(s[j]) != m.end() ) {
					i = max(m[s[j]], i);
				}
				ans = max(ans, j - i + 1);
				m[s[j]] = j + 1;
			}
			return ans;
		}
};


int main ()
{
	unordered_map<string,double> mymap = {
		{"mom",5.4},
		{"dad",6.1},
		{"bro",5.9} };

	string input;
	cout << "who? ";
	getline (cin,input);

	unordered_map<string,double>::const_iterator got = mymap.find (input);

	if ( got == mymap.end() )
		std::cout << "not found";
	else
		std::cout << got->first << " is " << got->second;

	std::cout << std::endl;

	return 0;
}
