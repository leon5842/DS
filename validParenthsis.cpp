#include <bits/stdc++.h>
using namespace std;

class solution {
public:
	bool validParenthsis(string s) {
		stack<string> stk;
		int n = s.size();
		if (s.size() == 0)
			return false;
		for (int i = 0; i < size; i++ ) {
			if (s[i] == '(' || s[i] == '[' || s[i] == '{')
				stk.push_back(s[i]);
			else {
				if (s[i] == ']' && stk.top() != '[')
					return false;
				if (s[i] == '}' && stk.top() != '{')
					return false;
				if (s[i] == ')' && stk.top() != '(')
					return false;
				stk.pop();
			}
		}
		return stk.empty();
	}
};
