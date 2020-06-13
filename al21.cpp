#include <stdio.h>
#include <stdlib.h>
#include <iostream> 
#include <vector> 
#include <string.h>
#include <algorithm>
#include <iterator>
#define MOD 1000000007
using namespace std;

int tails[100001];
int t[200001];
int dp[100001];
const int Num = 100000;

int n;
std::vector<int> arr(n, 0);
void update(int i, int val) {
	for (val %= MOD, t[i += Num] = val; i > 1; i >>= 1) {
		t[i >> 1] = (t[i] + t[i ^ 1]) % MOD;
	}
}

int query(int l, int r) {
	int sum = 0;
	for (l += Num, r += Num; l < r; l >>= 1, r >>= 1) {
		if (l & 1) sum = (sum + t[l++]) % MOD;
		if (r & 1) sum = (sum + t[--r]) % MOD;
	}
	return sum;
}


int CeilIndex(std::vector<int>& v, int l, int r, int key)
{
	while (r - l > 1) {
		int m = l + (r - l) / 2;
		if (v[m] >= key)
			r = m;
		else
			l = m;
	}

	return r;
}

int LIS(std::vector<int>& v)
{
	if (v.size() == 0)
		return 0;

	std::vector<int> tail(v.size(), 0);
	int length = 1;

	tail[0] = v[0];
	for (size_t i = 1; i < v.size(); i++) {


		if (v[i] < tail[0])
			tail[0] = v[i];

		else if (v[i] > tail[length - 1])
			tail[length++] = v[i];
		else
			tail[CeilIndex(tail, -1, length - 1, v[i])] = v[i];
	}

	return length;
}


int main() {
	FILE *input = fopen("LIS.inp", "rt");
	FILE *output = fopen("LIS.out", "wt");

	int T;//Test case
	fscanf(input, "%d", &T);
	int i, j;
	int temp;
	for (i = 0; i < T; i++) {
		fscanf(input, "%d", &n);
		for (j = 0; j < n; j++) {
			fscanf(input, "%d", &temp);
			arr.push_back(temp);
		}

		int k = LIS(arr);
		for (int i = 0; i < n; ++i) dp[i] = 1;
		for (int i = 2; i <= k; ++i) {
			memset(t, 0, sizeof(t));
			for (int j = 0; j < n; ++j) {
				update(arr[j], t[Num + arr[j]] + dp[j]);
				dp[j] = query(1, arr[j]);
			}
		}

		int ans = 0;
		for (int i = 0; i < n; ++i) ans = (ans + dp[i]) % MOD;
		fprintf(output, "%d %d\n", k, ans);
		arr.clear();
	}

	fclose(input);
	fclose(output);
	return 0;
}