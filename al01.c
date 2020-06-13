#include <stdio.h>
#include <stdlib.h>
#define MAX 15
int path(int N, int M, int K) {

	int i,j;

	int arr[MAX][MAX];
	int arr2[MAX][MAX];
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
				arr[i][j] = 1;
				arr2[i][j] = 1;
			}
	}
	

	int check = 0;
	if (K == 0) {
		for (i = 0; i < N; i++) {
			for (j = 0; j < M; j++) {
				if ((i != 0) && (j != 0)) {
					arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
				}
			}
		}
		check = arr[N-1][M-1];
	}
	else {
		int num = 0;
		int check2 = 0;
		int N1, M1;
		int N2, M2;
		for (i = 0; i < N; i++) { //K까지 
			for (j = 0; j < M; j++) {
				num++;
				if (num == K) { 
					N1 = i+1;
					M1 = j+1;
					N2 = N - i;
					M2 = M - j;
				}
			}
		}
		
		for (i = 0; i < N1; i++) {
			for (j = 0; j < M1; j++) {
				if ((i != 0) && (j != 0)) {
					arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
				}
			}
		}
		check = arr[N1 - 1][M1 - 1];

		for (i = 0; i < N2; i++) {
			for (j = 0; j < M2; j++) {
				if ((i != 0) && (j != 0)) {
					arr2[i][j] = arr2[i - 1][j] + arr2[i][j - 1];
				}
			}
		}
		check2 = arr2[N2 - 1][M2 - 1];

		check = check*check2;
	}

	

	return check;
}
int main() {
	FILE *input_fp = fopen("path.inp", "rt");
	FILE *output_fp = fopen("path.out", "wt");

	int T; // test number
	int N, M, K; //N:행 M:열 K:ㅇ표시

	fscanf(input_fp, "%d", &T);

	int i;
	for (i = 0; i < T; i++) {
		fscanf(input_fp, "%d %d %d", &N, &M, &K);
		int num = path(N, M, K);

		fprintf(output_fp, "%d\n", num);
	}

	fclose(input_fp);
	fclose(output_fp);
	return 0;
}