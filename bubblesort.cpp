#include <bits/stdc++.h>
using namespace std;

int main()
{
	vector<int> data;
	vector<int>::iterator it, iy;
	int tmp, flag;

	flag = 1;
	
	data.push_back(1);
	data.push_back(2);
	data.push_back(3);
	data.push_back(3);
	data.push_back(5);
	data.push_back(6);
	data.push_back(9);

	for (it = data.begin(); it != data.end(); it++) {
		if (!flag)
			break;
		flag = 0;
		for (iy = it + 1; iy != data.end(); iy++) {
			if (*iy < *it) {
				tmp = *it;
				*it = *iy;
				*iy = tmp;
				flag = 1;
			}
		}
	}
#if 1
	for (auto &i:data)
		cout << i << endl;
#endif
	return 0;
}
