#include <iostream>
#include <stdint.h>
#include <vector>
using namespace std;

bool solution[5];

void backtrack(int n)
{
		if (n == 5)
		{
			for (int i=0; i<5; i++)
				if (solution[i])
					cout << i << ' ';
			cout << endl;
			return;
		}

	solution[n] = true;
	backtrack(n+1);

	solution[n] = false;
	backtrack(n+1);
}

void enumerate_combinations()
{
	backtrack(0);
}

// find first x so that x > target
int binarySearch2(vector<int> &nums, int target)
{
	int left = 0, right = nums.size();
	while (left < right) {
		int mid = left + (right - left) / 2;

		if (nums[mid] <= target)
			left = mid + 1;
		else
			right = mid;
	}
	return left == nums.size() ? -1 : left;
}

// lower bound, find first x so that x >= target
int binarySearch(vector<int> &nums, int target)
{
	int left = 0, right  = nums.size();

	while (left < right) {
		int mid = left + (right - left) / 2;

		if (nums[mid] < target)
			left = mid + 1;
		else
			right = mid;
	}

	// this kind of return will return first x so that x >= target
	// if do not exists such value, return -1 (all value < target)
	return left == nums.size() ? -1:left;
#if 0
	if (left == nums.size())
		return -1;
	else {
		// this kind of return will find whether the target value existed
		return nums[left] == target ? left:-1;
	}
#endif
}

int32_t float_to_fixed(float x)
{
    return (int32_t)(x * 65536.0f / 16.0f);
}

int main()
{
#if 0
	enumerate_combinations();
#endif
	vector<int> tmp(5,0);

	//vector<int> data = {2,2,2,5,5,5,7,7,8,9,9,9};
	//vector<int> data = {9,9,8,6,6,6,5,5,4,3,2,2,1};
	vector<int> data = {1};

	for (int i = 0; i < 5; i++)
		tmp[i] = i + 1;
	printf("%d\n", 5%4);

	auto f = tmp.begin();
	auto s = tmp.begin() + 1;

	printf("begin = %d, begin + 1 = %d\n", *f, *s);
	
	printf("bs search ret = %d\n", binarySearch(data, 1));

	printf("fixed %8x\n", float_to_fixed(0.000156575398));

}
