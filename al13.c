#include <stdio.h>
int card[1001];
int num;

int selection() {
	int table[3][1001];
	table[0][0] = card[0]; table[0][1] = card[1]; table[0][2] = card[2];
	table[1][0] = -999999; table[1][1] = -999999; table[1][2] = -999999;
	table[2][0] = -999999; table[2][1] = -999999; table[2][2] = -999999;
	

	int i, j,k;
	for (i = 3; i < num; i++) {
		int temp;
		if (i == 3) {
			table[0][i] = -999999;
		}
		else {
			temp = table[0][i - 4];
			for (j = 1, k = (i - 4); j < 3; j++) {
				if (temp < table[j][k]) temp = table[j][k];
			}
			table[0][i] = temp+card[i];
		}
		temp = table[0][i - 3];
		for (j = 1, k = (i - 3); j < 3; j++) {
			if (temp < table[j][k]) temp = table[j][k];
		}
		table[1][i] = temp + card[i];
		temp = table[0][i - 2];
		for (j = 1, k = (i - 2); j < 2; j++) {
			if (temp < table[j][k]) temp = table[j][k];
		}
		table[2][i] = temp + card[i];
		
	}

	int result = table[0][num - 1];
	for (j = 1; j < 3; j++) {
		if (result < table[j][num - 1]) result = table[j][num - 1];
	}
	return result;
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
		fprintf(output, "%d\n", selection());
		
	}


	fclose(input);
	fclose(output);
	return 0;
}