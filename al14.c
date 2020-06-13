#include <stdio.h>
int card[1001];
int table[1001][1001] = { 0, };
int num;
int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a < b ? a : b; }

int game() {
	int temp_result = 0;
	int i, j,k;
	int x, y, z;
	for (k = 0; k < num; ++k) {
		for (i = 0, j = k; j < num; ++i, ++j) {
			
			x = ((i + 2) <= j) ? table[i + 2][j] : 0;
			y = ((i + 1) <= (j - 1)) ? table[i + 1][j - 1] : 0;
			z = (i <= (j - 2)) ? table[i][j - 2] : 0;
			table[i][j] = max(card[i] + min(x, y), card[j] + min(y, z));
		}
	}
	for (i = 0; i < num; i++) {
		for (j = 0; j < num; j++) {
			printf("%d ", table[i][j]);
		}
		printf("\n");
	}
	return table[0][num-1];
}
int main() {
	FILE *input = fopen("card.inp", "rt");
	FILE *output = fopen("card.out", "wt");


	int T;
	fscanf(input, "%d", &T);
	int i, j;
	for (i = 0; i < T; i++) {
		fscanf(input, "%d", &num);
		for (j = 0; j < num; j++) {
			fscanf(input, "%d ", &card[j]);
		}
		fprintf(output, "%d\n", game());
		printf("---------------\n");
	}


	fclose(input);
	fclose(output);
	return 0;
}