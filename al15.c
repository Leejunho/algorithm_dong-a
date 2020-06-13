#include <stdio.h>
int coin[3];



void co(FILE *output) {
	int a, b, c;
	int check = 0;
	a = coin[0];
	b = coin[1];
	c = coin[2];

	if (coin[0] >= 4)
		a = coin[0] % 4;
	if (coin[1] >= 4)
		b = coin[1] % 4;
	if (coin[2] >= 4)
		c = coin[2] % 4;

	int cc = a^b^c;

	if (a > 1 || b > 1 || c > 1) {
		if (cc == 0) fprintf(output,"(%d %d %d) : -1\n", coin[0], coin[1], coin[2]);
		else fprintf(output, "(%d %d %d) : 1\n", coin[0], coin[1], coin[2]);
	}
	else if (a <= 1 && b <= 1 && c <= 1) {
		int check = (a+b+c)%2;
		
		if (check == 0) fprintf(output, "(%d %d %d) : 1\n", coin[0], coin[1], coin[2]);
		else fprintf(output, "(%d %d %d) : -1\n", coin[0], coin[1], coin[2]);
	}
	


}

int main()
{
	FILE *input = fopen("coin.inp", "rt");
	FILE *output = fopen("coin.out", "wt");
	int T;//test case
	fscanf(input, "%d\n", &T);
	int i, j;
	for (i = 0; i < T; i++) {
		fscanf(input, "%d %d %d", &coin[0], &coin[1], &coin[2]);
		co(output);
	}




	return (0);
}
