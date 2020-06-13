#include <stdio.h>
#include <stdlib.h>
#define MAX 100000


int isprime(int N) {
	int i;
	int finish = 0;
	finish = N / 2;

	for (i = 2; i <= finish; i++) {
		if ((N%i) == 0) {
			return 0;
		}
	}
	return 1;
}

int prime(int N) {
	int i=2;
	int num[MAX] = { 0, };
	int n = 0, result = 0;
	int last = N; 

	while (last != 1) {
		if (last%i == 0) {
			last = last / i;
			num[n++] = i;
			i = 2;
		}
		else {
			i++;
		}
		
	}
	if (n == 1) return 0;
	for (i = 0; i < n; i++) {
		result += num[i];
	}

	return result;
}

int main() {
	FILE *input_fp = fopen("primefactor.inp", "rt");
	FILE *output_fp = fopen("primefactor.out", "wt");

	int T;//test num
	int N;
	fscanf(input_fp, "%d", &T);

	int i;
	for (i = 0; i < T; i++) {
		fscanf(input_fp, "%d", &N);

		int num = prime(N);

		if (num == 0) {
			fprintf(output_fp, "Prime Number\n");
		}
		else {
			fprintf(output_fp, "%d\n", num);
		}
	}

	fclose(input_fp);
	fclose(output_fp);
	return 0;
}
