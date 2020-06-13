#include <stdio.h>
#include <stdlib.h>
#define MAX 1000000
#define fin -233444
int arr[MAX];

void Insert(int num,int location) {
	int parentnode;
	while (location > 1)
	{
		parentnode = (location) / 2;
		if (num <= arr[parentnode])
		{
			arr[location] = num;
			return;
		}
		arr[location] = arr[parentnode];
		location = parentnode;
	}
	arr[1] = num; 
}
void Delete(int n) {
	int j, temp,flag = 1;
	int i = 1;
	while (2 * i <= n && flag == 1)
	{
		j = 2 * i;    //j points to left child
		if (j + 1 <= n && arr[j + 1] > arr[j])
			j = j + 1;
		if (arr[i] > arr[j])
			flag = 0;
		else
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i = j;
		}
	}
}
void report(FILE *output,int n) {
	int i;
	for (i = 1; i < n; i = (i * 2)) {
		fprintf(output,"%d ", arr[i]);
		
	}
	fprintf(output,"\n");
}

int main() {
	FILE *input = fopen("queue.inp", "rt");
	FILE *output = fopen("queue.out", "wt");

	char temp[10000];
	char charTemp;
	int n = 1;
	while (1) {
		fscanf(input, "%s", &temp);
		if (temp[0] == 'q') break;
		else if (temp[0] == 'r') {//report
			report(output, n);
		}
		else if (temp[0] == 'd') {//delete
			arr[1] = arr[n - 1];
			n--;
			Delete(n);
		}
		else {//insert
			Insert(atoi(temp), n);
			n++;
			
		}
	}

	fclose(input);
	fclose(output);
	return 0;
}