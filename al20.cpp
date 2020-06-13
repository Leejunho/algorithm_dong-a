#include <stdio.h>
int P, K, S; //P:x¹è¼ö K:1~K move S:start
char D[8][1000001];


int che(int a, int n) {
	int i, j;
	int check = 0;
	for (i = 0; i <= K; i++) {
		if (D[i][a] == 'W'&& i != n) { 
			return 0; //lose
		}
	}

	return 1;
}
void coin(FILE *output) {
	int i, j;
	for (j = 0; j <= S; j++) {
		for (i = 1; i <= K; i++) {
			if ((j - i) < 0) { D[i][j] = 'L'; continue; }
			if((j - i)%P == 0 &&(j-i) >=P) { D[i][j] = 'X'; continue; }
			if (che(j - i,i) == 0) D[i][j] = 'L';
			else D[i][j] = 'W';
		}
	}
	
	int result = 0;
	for (i = 1; i <= K; i++) {
		if (D[i][S] == 'W') {
			result = S - i;
			break;
		}
	}
	if (result != 0) fprintf(output,"%d\n", result);
	else fprintf(output,"-1\n");
}

int main() {
	FILE *input = fopen("coinmove.inp", "rt");
	FILE *output = fopen("coinmove.out", "wt");

	int T;//test case
	fscanf(input, "%d", &T);
	for (int i = 0; i < T; i++) {
		fscanf(input, "%d %d %d", &P, &K, &S);
		coin(output);
	}

	fclose(input);
	fclose(output);
	return 0;
}