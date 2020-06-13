#include <stdio.h>
#define MAX 100000
int arr[2][MAX+1];

int max(int a, int b) { return a > b ? a : b; }

int cube(int n) {
	int i, j;
	
	int D[2][MAX + 1];
	D[0][0] = 0; D[0][1] = arr[0][1];
	D[1][0] = 0; D[1][1] = arr[1][1];
	for (i = 2; i <= n; i++) {
		D[0][i] = max(D[1][i - 1], D[1][i - 2]) + arr[0][i];
		D[1][i] = max(D[0][i - 1], D[0][i - 2]) + arr[1][i];
	}
	
	return max(D[0][n], D[1][n]);
}

int main()
{
	FILE *input = fopen("stickers.inp", "rt");
	FILE *output = fopen("stickers.out", "wt");
	int T;//test case
	fscanf(input, "%d\n", &T);
	int i, j,t;
	
	int n;//n개의 정수 배열 n x n
	for (t = 0; t < T; t++) {
		fscanf(input, "%d", &n);
		for (i = 1; i <= n; i++) {
			fscanf(input, "%d ", &arr[0][i]);
		}
		
		for (i = 1; i <= n; i++) {
			fscanf(input, "%d ", &arr[1][i]);
		}
		
		fprintf(output,"%d\n", cube(n));
	}


	return 0;
}