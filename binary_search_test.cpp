#include <iostream>
#include <vector>
using namespace std;

int lower_bound(vector<int> &nums, int target) {
	int left = 0;
	int right = nums.size();

	while (left < right) {
		int m = left + (right - left) / 2;
		cout << "left = " << left << "  right = " << right << endl;
		cout << "mid = " << m << "  " << "nums[mid] = " << nums[m]  << endl;
		if (nums[m] < target)
			left = m + 1;
		else
			right = m;
		cout << "left = " << left << "  right = " << right << endl << endl;
	}

	return left <= nums.size() ? left : -1;
}

int upper_bound(vector<int> &nums, int target) {
	int left = 0;
	int right = nums.size() ;

	while (left < right) {
		int m = left + (right - left) / 2;
		cout << "left = " << left << "  right = " << right << endl;
		cout << "mid = " << m << "  " << "nums[mid] = " << nums[m]  << endl;
		if (nums[m] <= target)
			left = m + 1;
		else
			right = m;
		cout << "left = " << left << "  right = " << right << endl << endl;
	}

	return left <= nums.size() ? left : -1;

}

int main() {
	vector<int> data = {0,0,0,1,1,1,5,5,5,6,7,7,7,7,8,9,9};
	int target;

	for (int d : data)
		cout << d << " ";
	cout << endl;

	cout << " size = " << data.size() << endl;
	target = 10;
	cout << "target = " << target  << endl;
	printf("lower_bound %d, target = %d\n", lower_bound(data, target), target);
	printf("\n\n\n");
	cout << "target = " << target << endl;
	printf("lower_bound %d, target = %d\n", upper_bound(data, target), target);

	int c = -45;
	c = c >> 1;

	cout << c << endl;


	for (int i = 1; i <= 10; i++)
		cout << (i ^ 5) << endl;

	return 0;
}
