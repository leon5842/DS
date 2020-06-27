#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int> &arr)
{
	int len = arr.size();
	bool swapped = false;

	for (int i = 0; i < len - 1; i++) {
		swapped = false;
		for (int j = 0; j < len - i - 1; j++) {
			if (arr[j] > arr[j+1]) {
				swap(arr[j], arr[j+1]);
				swapped = true;
			}
		}
		if (!swapped)
			break;
	}
}

int part(int low, int hi, vector<int> &arr)
{
	int pivot = arr[hi];
	int i = low - 1;

	for (int j = low; j < hi; j++) {
		if (arr[j] <= pivot) {
			swap(arr[++i], arr[j]);
		}
	}

	i++;
	swap(arr[i], arr[hi]);

	return i;
}


void quickSort(int low, int hi, vector<int> &arr)
{
	if (low < hi) {
		int pivot = part(low, hi, arr);
		quickSort(low, pivot - 1, arr);
		quickSort(pivot + 1, hi, arr);
	}
}


void print(vector<int> &arr)
{
	for (auto n:arr)
		printf("%d ", n);
	printf("\n");
}

int main()
{
	vector<int> data = {11,24,22,5,7,23,88,3,5,8,72};
	quickSort(0, data.size() - 1, data);
	print(data);
	return 0;
}
