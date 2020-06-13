#include <cstdio>
#include <algorithm>
#include <queue>
#define MAX 1010
using namespace std;

FILE *fp_input = fopen("watertank.inp", "rt");
FILE *fp_output = fopen("watertank.out", "wt");

int T;//test case

struct Node {
	int n;
	int up;
	int right;
	int down;
	int left;
} N[MAX + 2][MAX + 2];

struct PQ {
	int x;
	int y;
	int val;
	bool operator<(const PQ& other) const {
		return val > other.val;
	}
};

int n, m, h;
priority_queue<PQ> que;

void input() {
	int i, j;
	fscanf(fp_input, "%d %d %d", &n, &m, &h);

	for (i = 0; i<n + 2; i++) {
		for (j = 0; j<m + 2; j++) {
			N[i][j].up = -1;
			N[i][j].right = -1;
			N[i][j].down = -1;
			N[i][j].left = -1;
			N[i][j].n = h;
		}
	}
	for (i = 0; i<n + 1; i++) {
		for (j = 1; j <= m; j++) {
			int temp;
			fscanf(fp_input, "%d", &temp);
			N[i][j].down = temp;
			N[i + 1][j].up = temp;
		}
	}
	for (i = 1; i <= n; i++) {
		for (j = 0; j<m + 1; j++) {
			int temp;
			fscanf(fp_input, "%d", &temp);
			N[i][j + 1].left = temp;
			N[i][j].right = temp;
		}
	}
}

int result() {
	int i,j;
	int sum = 0;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			sum += N[i][j].n;
		}
	}
	return sum;
}

void bfs() {
	while (!que.empty()) {
		PQ test = que.top();
		que.pop();
		if (test.val >= N[test.x][test.y].n)
			continue;
		N[test.x][test.y].n = test.val;


		if (N[test.x][test.y].up > -1 && N[test.x - 1][test.y].n > N[test.x][test.y].up)
			que.push(PQ{ test.x - 1, test.y, max(test.val, N[test.x][test.y].up) });
		if (N[test.x][test.y].right > -1 && N[test.x][test.y + 1].n > N[test.x][test.y].right)
			que.push(PQ{ test.x, test.y + 1, max(test.val, N[test.x][test.y].right) });
		if (N[test.x][test.y].down > -1 && N[test.x + 1][test.y].n > N[test.x][test.y].down)
			que.push(PQ{ test.x + 1, test.y, max(test.val, N[test.x][test.y].down) });
		if (N[test.x][test.y].left > -1 && N[test.x][test.y - 1].n > N[test.x][test.y].left)
			que.push(PQ{ test.x, test.y - 1, max(test.val, N[test.x][test.y].left) });
		
	}
}



int main() {
	int i, j;
	fscanf(fp_input, "%d", &T);

	for (i = 0; i < T; i++) {
		input();
		for (j = 1; j <= m; j++) {
			que.push(PQ{ 0, j, 0 });
			que.push(PQ{ n + 1, j, 0 });
		}
		for (j = 1; j <= n; j++) {
			que.push(PQ{ j, 0, 0 });
			que.push(PQ{ j, m + 1, 0 });
		}
		bfs();
		fprintf(fp_output, "%d\n", result());
	}

	fclose(fp_input);
	fclose(fp_output);

	return 0;
}