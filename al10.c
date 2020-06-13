#include <stdio.h>
#include <stdlib.h>

void fraction(FILE *output, long long M, long long N) {
	long long a = 0, b = 1, c = 1, d = 0, e = 1, f = 1;

	while (1) {
		if (e == M && f == N) break;
		if (e * N > f * M) {
			fprintf(output, "L");
			b = e;
			d = f;
		}
		else {
			fprintf(output, "R");
			a = e;
			c = f;
		}
		e = a + b; 
		f = c + d;
	}

	
}
int main() {
	FILE *input = fopen("fraction.inp", "rt");
	FILE *output = fopen("fraction.out", "wt");

	long long M, N;
	while (1) {
		fscanf(input, "%lld %lld", &M, &N);
		if (M == 1 && N == 1) break;

		fraction(output, M, N);
		fprintf(output, "\n");
	}

	fclose(input);
	fclose(output);
	return 0;
}
