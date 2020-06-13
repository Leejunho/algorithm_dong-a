#include <bits/stdc++.h>
using namespace std;

int arr[3];
int cube[201][201][201];

int m[3] = { 0, };

void divide(int SIZE) {
	for (int i = 1; i <= SIZE; i++)
	{
		for (int j = 1; j <= SIZE; j++) {
			for (int k = 1; k <= j; k++) {

				if (cube[i][j][k] > 0)
					continue;
				if (i == j && j == k) {
					cube[i][j][k] = 1;
					continue;
				}
				if (k == 1) {
					cube[i][j][1] = i * j;
					cube[i][1][j] = i * j;
					continue;
				}
				if (j == 1) {
					cube[i][1][k] = i * k;
					continue;
				}
				if (i == 1) {
					cube[1][j][k] = j * k;
					cube[1][k][j] = j * k;
					continue;
				}

				int min = 9999999;
				int tmp;
				for (int l = 1; l <= i / 2; l++) {
					tmp = cube[l][j][k] + cube[i - l][j][k];
					if (min > tmp)
						min = tmp;
				}
				for (int l = 1; l <= j / 2; l++) {
					tmp = cube[i][l][k] + cube[i][j - l][k];
					if (min > tmp)
						min = tmp;
				}

				for (int l = 1; l <= k / 2; l++) {
					tmp = cube[i][j][l] + cube[i][j][k - l];
					if (min > tmp)
						min = tmp;
				}

				cube[i][j][k] = cube[i][k][j] = cube[j][i][k] = cube[j][k][i] = cube[k][i][j] = cube[k][j][i] = min;
			}
		}
	}
}

int main()
{
	FILE *input = fopen("cube.inp", "rt");
	FILE *output = fopen("cube.out", "wt");
	int T;//test case
	fscanf(input, "%d\n", &T);
	int i, j, t, k;

	int max = 0;
	int arr_temp[201][3];
	for (t = 0; t < T; t++) {
		fscanf(input, "%d %d %d", &arr[0], &arr[1], &arr[2]);
		if (arr[0] > m[0]) m[0] = arr[0];
		if (arr[1] > m[1]) m[1] = arr[1];
		if (arr[2] > m[2]) m[2] = arr[2];

		arr_temp[t][0] = arr[0]; arr_temp[t][1] = arr[1]; arr_temp[t][2] = arr[2];
	}
	sort(m, m + 3);
	divide(m[2]);
	printf("%d\n", m[2]);
	for (t = 0; t < T; t++) {
		arr[0] = arr_temp[t][0]; arr[1] = arr_temp[t][1]; arr[2] = arr_temp[t][2];
		fprintf(output, "%d\n", cube[arr[0]][arr[1]][arr[2]]);
	}
	fclose(input);
	fclose(output);

	return 0;
}