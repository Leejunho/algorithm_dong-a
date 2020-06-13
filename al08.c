#include <stdio.h>
#include <string.h>
#define MAX 50000

void Preorder(char arr[], FILE *output) {
	int r = 0;
	int i = 0;
	while (i < strlen(arr)) {
		if (arr[i] == '(') {
			fprintf(output, "r%d\n", r);
			r++;
		}
		if (arr[i] != '('&& arr[i] != ')' && arr[i] != ' ') {
			while (arr[i] != ' ') fprintf(output, "%c", arr[i++]);
			fprintf(output, "\n");
		}
		i++;
	}
}
void Inorder(char arr[], FILE *output) { 
	int r[50000];
	int rN = 0;//r배열 index
	int rTemp = -1;//집어 넣어야 하는 r 값
	int rCheck = 0, rPrint = 0;
	int i = 0;
	while (i < strlen(arr)) {
		if (arr[i] == '(') {
			rTemp++;
			r[rN++] = rTemp;
			rCheck++;
		}
		if (arr[i] != '('&& arr[i] != ')' && arr[i] != ' ') {
			while (arr[i] != ' ') fprintf(output,"%c", arr[i++]);
			fprintf(output, "\n");
			if (rCheck != rPrint) {
				fprintf(output, "r%d\n", r[rN-1]);
				rN--;
				rPrint++;
			}
		}
		i++;
		
	}
}
int main() {
	FILE *input = fopen("tree.inp", "rt");
	FILE *output = fopen("tree.out", "wt");

	int T;//Test Case
	fscanf(input, "%d\n", &T);

	int i, j=0;
	char charTemp;
	for (i = 0; i < T; i++) {
		char arr[MAX];
		fgets(arr, MAX, input);
		
		arr[strlen(arr) - 1] = '\0';
		
		
		fprintf(output, "%s\n", arr);
		fprintf(output, "Preorder\n");
		Preorder(arr, output);
		fprintf(output, "Inorder\n");
		Inorder(arr, output);
	}

	fclose(input);
	fclose(output);
	return 0;
}
