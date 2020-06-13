#include <stdio.h>
char go[20][20];

void Fb(char x,char y) {
	if (go[x - 1][y] == '.') {
		go[x - 1][y] = 'b';
		Fb(x - 1, y); 
	}
	if (go[x + 1][y] == '.') {
		go[x + 1][y] = 'b';
		Fb(x + 1, y); 
	}
	if (go[x][y - 1] == '.') {
		go[x][y-1] = 'b';
		Fb(x, y - 1); 
	}
	if (go[x][y + 1] == '.') {
		go[x][y+1] = 'b';
		Fb(x, y + 1); 
	}

	if (go[x - 1][y] == 'w') { //다시 공백으로
		go[x - 1][y] = 'c';
		Fb(x - 1, y);
	}
	if (go[x + 1][y] == 'w') {
		go[x + 1][y] = 'c';
		Fb(x + 1, y);
	}
	if (go[x][y - 1] == 'w') {
		go[x][y - 1] = 'c';
		Fb(x, y - 1);
	}
	if (go[x][y + 1] == 'w') {
		go[x][y + 1] = 'c';
		Fb(x, y + 1);
	}
}
void Fw(char x, char y) {
	if (go[x - 1][y] == '.' ) {
		go[x - 1][y] = 'w';
		Fw(x - 1, y);
	}
	if (go[x + 1][y] == '.' ) {
		go[x + 1][y] = 'w';
		Fw(x + 1, y);
	}
	if (go[x][y - 1] == '.') {
		go[x][y - 1] = 'w';
		Fw(x, y - 1);
	}
	if (go[x][y + 1] == '.') {
		go[x][y + 1] = 'w';
		Fw(x, y + 1);
	}

	if (go[x - 1][y] == 'b') {//중립
		go[x - 1][y] = 'c';
		Fw(x - 1, y);
	}
	if (go[x + 1][y] == 'b') {
		go[x + 1][y] = 'c';
		Fw(x + 1, y);
	}
	if (go[x][y - 1] == 'b') {
		go[x][y - 1] = 'c';
		Fw(x, y - 1);
	}
	if (go[x][y + 1] == 'b') {
		go[x][y + 1] = 'c';
		Fw(x, y + 1);
	}
}

void ba(int T, FILE *output) {
	int i, j;
	int b = 0, w = 0;
	for (i = 0; i < T; i++) {
		for (j = 0; j < T; j++) {
			if (go[i][j] == 'B') Fb(i, j);
			}
	}
	for (i = 0; i < T; i++) {
		for (j = 0; j < T; j++) {
			if (go[i][j] == 'W') Fw(i, j);
		}
	}
	for (i = 0; i < T; i++) {
		for (j = 0; j < T; j++) {
			printf("%c ", go[i][j]);
			if (go[i][j] == 'b') b++;
			if (go[i][j] == 'w') w++;
		}
		printf("\n");
	}
	printf("%d %d\n", b, w);
	fprintf(output, "%d %d", b, w);
}
int main() {
	FILE *input = fopen("go.inp", "rt");
	FILE *output = fopen("go.out", "wt");

	int T;
	int i, j;

	fscanf(input, "%d", &T);

	for (i = 0; i < T; i++) {
		fscanf(input, "%s", &go[i]);
	}
	ba(T, output);
	fclose(input);
	fclose(output);
	return 0;
}