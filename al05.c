#include <stdio.h>

char A[7];
char B[7];

int cmp(char S[], char C[][7], int N) {
	int i, j;
	for (i = 1; i <= 6; i++) {
		if (S[i] != C[N][i]) return 0;
	}

	return 1;
}
int finish(char S[], char C[]) {
	int i;
	int N = 0;
	char ch;
	ch = S[1];
	for (i = 1; i <= 6; i++) {
		if (S[i] == ch) N++;
	}
	for (i = 1; i <= 6; i++) {
		if (C[i] == ch) N++;
	}

	if (N == 12) return 1;
	else return 0;
}
int dice(char A[], char B[]) {
	int i, j;
	int n = 0;
	char temp;
	char ddd[24][7];
	ddd[0][1] = A[1]; ddd[0][2] = A[2]; ddd[0][3] = A[3]; ddd[0][4] = A[4]; ddd[0][5] = A[5]; ddd[0][6] = A[6];
	ddd[1][1] = A[1]; ddd[1][2] = A[3]; ddd[1][3] = A[5]; ddd[1][4] = A[2]; ddd[1][5] = A[4]; ddd[1][6] = A[6];
	ddd[2][1] = A[1]; ddd[2][2] = A[5]; ddd[2][3] = A[4]; ddd[2][4] = A[3]; ddd[2][5] = A[2]; ddd[2][6] = A[6];
	ddd[3][1] = A[1]; ddd[3][2] = A[4]; ddd[3][3] = A[2]; ddd[3][4] = A[5]; ddd[3][5] = A[3]; ddd[3][6] = A[6];

	ddd[4][1] = A[2]; ddd[4][2] = A[6]; ddd[4][3] = A[3]; ddd[4][4] = A[4]; ddd[4][5] = A[1]; ddd[4][6] = A[5];
	ddd[5][1] = A[2]; ddd[5][2] = A[3]; ddd[5][3] = A[1]; ddd[5][4] = A[6]; ddd[5][5] = A[4]; ddd[5][6] = A[5];
	ddd[6][1] = A[2]; ddd[6][2] = A[1]; ddd[6][3] = A[4]; ddd[6][4] = A[3]; ddd[6][5] = A[6]; ddd[6][6] = A[5];
	ddd[7][1] = A[2]; ddd[7][2] = A[4]; ddd[7][3] = A[6]; ddd[7][4] = A[1]; ddd[7][5] = A[3]; ddd[7][6] = A[5];

	ddd[8][1] = A[3]; ddd[8][2] = A[1]; ddd[8][3] = A[2]; ddd[8][4] = A[5]; ddd[8][5] = A[6]; ddd[8][6] = A[4];
	ddd[9][1] = A[3]; ddd[9][2] = A[2]; ddd[9][3] = A[6]; ddd[9][4] = A[1]; ddd[9][5] = A[5]; ddd[9][6] = A[4];
	ddd[10][1] = A[3]; ddd[10][2] = A[6]; ddd[10][3] = A[5]; ddd[10][4] = A[2]; ddd[10][5] = A[1]; ddd[10][6] = A[4];
	ddd[11][1] = A[3]; ddd[11][2] = A[5]; ddd[11][3] = A[1]; ddd[11][4] = A[6]; ddd[11][5] = A[2]; ddd[11][6] = A[4];

	ddd[12][1] = A[4]; ddd[12][2] = A[1]; ddd[12][3] = A[5]; ddd[12][4] = A[2]; ddd[12][5] = A[6]; ddd[12][6] = A[3];
	ddd[13][1] = A[4]; ddd[13][2] = A[5]; ddd[13][3] = A[6]; ddd[13][4] = A[1]; ddd[13][5] = A[2]; ddd[13][6] = A[3];
	ddd[14][1] = A[4]; ddd[14][2] = A[6]; ddd[14][3] = A[2]; ddd[14][4] = A[5]; ddd[14][5] = A[1]; ddd[14][6] = A[3];
	ddd[15][1] = A[4]; ddd[15][2] = A[2]; ddd[15][3] = A[1]; ddd[15][4] = A[6]; ddd[15][5] = A[5]; ddd[15][6] = A[3];

	ddd[16][1] = A[5]; ddd[16][2] = A[1]; ddd[16][3] = A[3]; ddd[16][4] = A[4]; ddd[16][5] = A[6]; ddd[16][6] = A[2];
	ddd[17][1] = A[5]; ddd[17][2] = A[3]; ddd[17][3] = A[6]; ddd[17][4] = A[1]; ddd[17][5] = A[4]; ddd[17][6] = A[2];
	ddd[18][1] = A[5]; ddd[18][2] = A[6]; ddd[18][3] = A[4]; ddd[18][4] = A[3]; ddd[18][5] = A[1]; ddd[18][6] = A[2];
	ddd[19][1] = A[5]; ddd[19][2] = A[4]; ddd[19][3] = A[1]; ddd[19][4] = A[6]; ddd[19][5] = A[3]; ddd[19][6] = A[2];

	ddd[20][1] = A[6]; ddd[20][2] = A[2]; ddd[20][3] = A[4]; ddd[20][4] = A[3]; ddd[20][5] = A[5]; ddd[20][6] = A[1];
	ddd[21][1] = A[6]; ddd[21][2] = A[4]; ddd[21][3] = A[5]; ddd[21][4] = A[2]; ddd[21][5] = A[3]; ddd[21][6] = A[1];
	ddd[22][1] = A[6]; ddd[22][2] = A[5]; ddd[22][3] = A[3]; ddd[22][4] = A[4]; ddd[22][5] = A[2]; ddd[22][6] = A[1];
	ddd[23][1] = A[6]; ddd[23][2] = A[3]; ddd[23][3] = A[2]; ddd[23][4] = A[5]; ddd[23][5] = A[4]; ddd[23][6] = A[1];
	
	for (i = 0; i < 24; i++) {
		int check = 0;
		for (j = 1; j < 7; j++) {
			if (B[j] == ddd[i][j]) check++;
		}
		if (check == 6) return 1;
	}
	return 0;
}
int main() {
	FILE *input = fopen("cube.inp", "rt");
	FILE *output = fopen("cube.out", "wt");

	char ch, charTemp;
	int N = 0;
	int i, j;
	while (!feof(input)) {
		for (i = 1; i <= 12; i++) {
			ch = fgetc(input);
			if (i <= 6) A[i] = ch;
			else if (i > 6 && i <= 12) B[i - 6] = ch;
		}
		ch = fgetc(input);
		if (finish(A, B) == 1) {
			fprintf(output, "TRUE\n");
			break;
		}


		if (dice(A, B) == 1) fprintf(output, "TRUE\n");
		else if (dice(A, B) == 0)fprintf(output, "FALSE\n");

	}
	fclose(input);
	fclose(output);
	return 0;
}