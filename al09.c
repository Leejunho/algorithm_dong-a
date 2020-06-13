#include <stdio.h>
#include <stdlib.h>
#define MAX 100000

long long arr[MAX];
long long _sort(long long arr[], long long N);
long long sort(long long arr[], long long temp[], long long left, long long mid, long long right);
long long Count(long long arr[], long long temp[], long long left, long long right);



int main() {
	FILE *input = fopen("inv.inp", "rt");
	FILE *output = fopen("inv.out", "wt");

	int T; // Test Case
	int N; // Integer Number
	int i, j;

	fscanf(input, "%d", &T);

	for (i = 0; i < T; i++) {
		fscanf(input, "%d", &N);
		for (j = 0; j < N; j++) {
			fscanf(input, "%d", &arr[j]);
		}

		long long a = _sort(arr, N);
		fprintf(output, "%ld\n", a);

	}

	fclose(input);
	fclose(output);
	return 0;
}


long long sort(long long arr[], long long temp[], long long left, long long mid, long long right) {
	long long i, j, k;
	i = left;
	j = mid;
	k = left;
	long long check = 0;
	while ((i <= mid - 1) && (j <= right)) {
		if (arr[i] <= arr[j])
			temp[k++] = arr[i++];
		else {
			temp[k++] = arr[j++];
			check = check + (mid - i);
		}
	}
	while (i <= mid - 1) {
		temp[k++] = arr[i++];
	}
	while (j <= right) {
		temp[k++] = arr[j++];
	}
	for (i = left; i <= right; i++) {
		arr[i] = temp[i];
	}

	return check;
}

long long Count(long long arr[], long long temp[], long long left, long long right)
{
	long long mid, count = 0;


	if (right>left) {
		mid = (left + right) / 2;

		count = Count(arr, temp, left, mid);
		count += Count(arr, temp, mid + 1, right);

		count += sort(arr, temp, left, mid + 1, right);
	}
	return count;
}

long long _sort(long long arr[], long long N) {
	long long *temp = (long long *)malloc(sizeof(long long)*N);
	return Count(arr, temp, 0, N - 1);
}
