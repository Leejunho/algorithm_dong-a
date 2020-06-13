#include <stdio.h>
#define MAX 100000
#define max(a, b) (((a) > (b)) ? (a) : (b))
FILE *input = fopen("light.inp", "rt");
FILE *output = fopen("light.out", "wt");

int N;//가로등 구간
int K;// 밝히고자 하는 구간
struct node {
	int L_light;
	int R_light;
}node;
void swap(struct node *a, struct node *b) {
	struct node temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
void quickSort(struct node *nodes, int low, int high) {
	int pivot, temp;
	int i, j;
	if (low < high) {
		pivot = low;
		i = low;
		j = high;
		while (i < j) {
			while (nodes[i].L_light <= nodes[pivot].L_light && i <= high) i++;
			while (nodes[j].L_light > nodes[pivot].L_light && j >= low) j--;

			if (i < j) swap(&nodes[i], &nodes[j]);
		}

		swap(&nodes[j], &nodes[pivot]);
		quickSort(nodes, low, j - 1);
		quickSort(nodes, j + 1, high);
	}
}

int process(struct node *lights,int L,int R) {
	int i, j=0;
	int ti=0;
	int l = L, r = R;
	int temp=L;
	int result = 0;


	int flag = -1;
	for (i = j; i < N; i++) {
		if (lights[i].L_light <= L) {
			if (lights[i].R_light >= R) {
				flag = 1;
				result++;
				break;
			}
			else {
				if (lights[i].R_light >= L)
					temp = max(temp, lights[i].R_light);
			}
		}
		else if (lights[i].L_light > L) {
			if (temp != L) {
				result++;
				L = temp;
				i--;
			}
			else
				break;
		}
	}
	
	if (flag == 1) return result;
	else return -1;
}

int main() {
	int i, j;
	struct node lights[MAX];

	fscanf(input, "%d", &N);
	for (i = 0; i < N; i++) {
		fscanf(input, "%d %d", &lights[i].L_light, &lights[i].R_light);
	}
	quickSort(lights, 0, N - 1);
	fscanf(input, "%d", &K);
	int L, R;
	for (i = 0; i < K; i++) {
		fscanf(input, "%d %d", &L, &R);
		fprintf(output,"%d\n",process(lights,L,R));
	}

	fclose(input);
	fclose(output);
	return 0;
}