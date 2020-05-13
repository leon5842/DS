


void removeZeros(vector<int> &nums)
{
	int i = 0, j = 0;

	while (j < nums.size()) {
		if (nums[j] == 0)
			j++;
		else
			swap(nums[i++], nums[j++]);
	}

	return;
}

int removeElement(vector<int> &nums, int val)
{
	int j = 0;

	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] == val)
			continue;
		nums[j++] = nums[i];
	}

	return j+1;
}

/* j point the first duplicate item,
 * i go throung the whole array
 * */
int removeElementSorted(vector<int> &nums)
{
	int j = 0;
	
	for (int j = 1; j  < nums.size(); i++) {
		if (nums[j] != nums[i])
			nums[++j] = nums[i];
	}
	return j+1;
}

int removeElementSorted(vector<int> &nums)
{
	int j = 0;
	int counter = 0;
	
	for (int j = 1; j  < nums.size(); i++) {
		if (nums[j] != nums[i]) {
			counter = 0;
			nums[++j] = nums[i];
		} else {
			counter ++;
			if (counter < 2) {
				nums[++j] = nums[i]:
			}
		}
	}
	return j+1;
}

