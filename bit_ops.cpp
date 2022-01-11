/*
 * 1318 Minimum Flips to Make a OR b Equal to c
 * Given 3 positives numbers a, b and c. Return the minimum flips required in some bits of a and b to make ( a OR b == c ).
 * (bitwise OR operation).
 * Flip operation consists of change any single bit 1 to 0 or change the bit 0 to 1 in their binary representation.
 *
 */

int get_bits(int target, int pos) {
	return (target >> pos) & 1;
}

int minFlips(int a, int b , int c) {
	int flips = 0;
	for (int i = 0; i < 32; i++) {
		if (get_bits(c, i) == 1)
			flips += (get_bits(a, i) | get_bits(b, i)) == 0;
		else
			flips += get_bits(a, i) + get_bits(b, i);

	}
	return flips;
}


int flipBits(unsigned a) {
	if (~a == 0)
		return 8 * sizeof(int);

	int cur_len = 0, prev_len = 0, max_len = 0;

	while (a) {
		if (a & 1)
			cur_len++;
		else {
			prev_len = (a & 2) == 0 ? 0:cur_len;
			cur_len = 0;
		}
		max_len = max(cur_len + prev_len, max_len);
		a >>= 1;
	}

	return max_len + 1;
}

int countSetBit(int n) {

	int count = 0;
	while (n) {
		n = n & (n - 1);
		count++;
	}
	return count;

}

/*
 * leetcode 338, counting set bits
 * Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), 
 * ans[i] is the number of 1's in the binary representation of i.
 * Input: n = 2
 * Output: [0,1,1]
 * Explanation:
 * 0 --> 0
 * 1 --> 1
 * 2 --> 10
 */

vector<int> countSetBits(int n) {
	vector<int> res (n + 1, 0);
	for (int i = 1; i <= n; i++)
		res[i] = res[i & (i-1)] + 1; // clear one right most bits and then add back one
	return res;
}


/*
 * 461. calculate the hamming distance
 * check how many bit you need to flip to turn one interger to another
 * hamming distance is the bits diff between a (1000) and b (1011) distance = 2
 * we have 2 bits in different (bit 0 and bit 1)
 */

int hamming_distance(int x, int y) {
	int res = 0;
	// get different bits
	int target = x ^ y;

	while (target) {
		// turn off the rightmost bits
		target = target & (target - 1);
		// calculate bits in differents
		res+;
	}
	return res;
}

/*
 * find a circular permutation in binary representation
 * Given 2 integers n and start. Your task is return any permutation p of (0,1,2.....,2^n -1) such that :
 * p[0] = start
 * p[i] and p[i+1] differ by only one bit in their binary representation.
 * p[0] and p[2^n -1] must also differ by only one bit in their binary representation.
 */ 
// using gray code, also study pcm 
vector<int> circularPermutation(int n, int start) {
	vector<int> res;
	for (int i = 0; i < 1 << n; i++) {
		res.push_back(start ^ i ^ i >> 1 );
	}
	return res;
}

// using gray code to generate such sequence
