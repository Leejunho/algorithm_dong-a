#include <stdio.h>
int T;

void sort(int S[], int N) {
	int i, j;
	int temp = 0;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N-1; j++) {
			if (S[j] > S[j+1]) {
				temp = S[j];
				S[j] = S[j + 1];
				S[j + 1] = temp;
			}
		}
	}
}
int cmp_sc(int S[], int C[]) {
	int i, j;
	for (i = 0; i < T; i++) {
		if (S[i] != C[i]) return 0;
	}

	return 1;
}
int main() {
	FILE *input_fp = fopen("sequence.inp", "rt");
	FILE *output_fp = fopen("sequence.out", "wt");


	fscanf(input_fp, "%d", &T);


	int S[1000];
	int C[1000];
	int B[1000];
	int i, j,k;
	for (j = 0; j < 2; j++) {
		for (i = 0; i < T; i++) {
			if (j == 0) {
				fscanf(input_fp, "%d", &S[i]);
			}
			else {
				fscanf(input_fp, "%d", &C[i]);
			}
		}
	}
	sort(S, T);
	
	int temp;
	
		for (i = T - 1; i >= 0; i--) {
			temp = S[i];
			S[i] = S[C[i]];
			S[C[i]] = temp;

			sort(S, i);
			

		}

	for (i = 0; i < T; i++) {
		fprintf(output_fp, "%d\n", S[i]);
	}

	fclose(input_fp);
	fclose(output_fp);
	return 0;
}