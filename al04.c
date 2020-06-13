#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 20000
int p[MAX];
void sort(int S[], int N) {
	int i, j;
	int temp = 0;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N - 1; j++) {
			if (S[j] > S[j + 1]) {
				temp = S[j];
				S[j] = S[j + 1];
				S[j + 1] = temp;
			}
		}
	}
}
int cmp(int S[], int C[],int N) {
	int i, j;
	for (i = 0; i < N; i++) {
		if (S[i] != C[i]) return 0;
	}

	return 1;
}

int solve(int S[],int R[], int N) {
	int i, j;
	int k = 0;
	int temp;
	for (i = 0; i < N; i++) {
		if (cmp(S, R, N) == 1) { 
			
			return 1; 
		}
		else {
			temp = R[N - 1];
			for (j = N-1; j > 0; j--) {
				R[j] = R[j - 1];
			}
			R[0] = temp;
		}
	}
	return 0;
}
int main() {
	FILE *input_fp = fopen("polygon.inp", "rt");
	FILE *output_fp = fopen("polygon.out", "wt");

	int T;//Test Case
	fscanf(input_fp, "%d", &T);

	int i,j,t;
	int N;//Vertex 꼭지점
	int S1[MAX]; int SR[MAX];
	int S2[MAX];
	for (t = 0; t < T; t++) {
		fscanf(input_fp, "%d", &N);
		for (j = 0; j < N; j++) {
			fscanf(input_fp, "%d ", &S1[j]);
		}
		for (j = 0; j < N; j++) {
			fscanf(input_fp, "%d ", &S2[j]);
		}

		int check = solve(S2, S1, N);
		if (check == 1) fprintf(output_fp, "1\n"); //기본상태에서 확인시 맞으면 1
		else {
			for (i = 0, j = N - 1; i < N; i++, j--) {//아니면 역순 만들어서 반대에서 시작하는 경우 생각해서 구해야함
				int k = j - 1;
				if (k < 0) k = N - 1;
				SR[i] = abs(S1[j]);
				SR[i] = S1[k] < 0 ? SR[i] : -SR[i];

			}
			int check2 = solve(S2, SR, N);
			if (check2 == 1) fprintf(output_fp, "1\n");
			else fprintf(output_fp, "0\n");
		}
		
		
	}

	fclose(input_fp);
	fclose(output_fp);
	return 0;
}