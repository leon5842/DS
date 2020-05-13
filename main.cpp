#include <iostream>
using namespace std;

bool solution[5];   // 索引儲存

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

	// 不取數字n，然後繼續枚舉之後的位置。
	solution[n] = false;
	backtrack(n+1);
}

void enumerate_combinations()
{
	backtrack(0);
}

int main()
{
	enumerate_combinations();
}
