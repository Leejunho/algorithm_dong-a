#include <stdio.h>

FILE *input = fopen("mst.inp", "rt");
FILE *output = fopen("mst.out", "wt");
int n, m;
int sum;
int edge[100001][3];
int prim[10001][10001][2];
int kruscal[100001][2];
int heap[10001][2]; 
int check[10001];
int head[10001];
int head_temp[10001][10001];
int floor[10001];
int floor_max[10001];
int select[10001]; 
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
int partition(int p, int q) // 가중치에 대한 정렬
{
	int L = p + 1;
	int R = q;
	while (1)
	{
		while (L < R && kruscal[L][0] < kruscal[p][0]) L++;
		while (L <= R && kruscal[R][0] >= kruscal[p][0]) R--;

		if (L < R)
		{
			swap(&kruscal[L][0], &kruscal[R][0]);
			swap(&kruscal[L][1], &kruscal[R][1]);
		}
		else
		{
			swap(&kruscal[p][0], &kruscal[R][0]);
			swap(&kruscal[p][1], &kruscal[R][1]);
			return R;
		}

	}
}
int sub_partition(int p, int q)
{
	int L = p + 1;
	int R = q;
	while (1)
	{
		while (L < R && kruscal[L][1] < kruscal[p][1]) L++;
		while (L <= R && kruscal[R][1] >= kruscal[p][1]) R--;

		if (L < R)
		{
			swap(&kruscal[L][1], &kruscal[R][1]);
		}
		else
		{
			swap(&kruscal[p][1], &kruscal[R][1]);
			return R;
		}

	}
}
void quicksort(int p, int q)
{
	if (p < q)
	{
		int position = partition(p, q);
		quicksort(p, position - 1);
		quicksort(position + 1, q);
	}
}
void sub_quicksort(int p, int q)
{
	if (p < q)
	{
		int position = sub_partition(p, q);
		sub_quicksort(p, position - 1);
		sub_quicksort(position + 1, q);
	}
}
void duplicate_process(int p, int q)
{
	int i = 0;
	while (p <= q)
	{

		for (i = p; i <= q; i++)
		{
			if (kruscal[i][0] != kruscal[p][0])break;
		}
		if (i != p)
		{
			sub_quicksort(p, i - 1);
		}
		p = i;
	}
}
int minDistance(int dist[],
	bool sptSet[])
{

	// Initialize min value 
	int min = 9999, min_index;

	for (int v = 0; v < 99; v++)
		if (sptSet[v] == false &&
			dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}
void print_path(const int *parent, int v, FILE *output)
{
	if (parent[v] == -1) {
		fprintf(output, "%d ", v);
		return;
	}
	print_path(parent, parent[v], output);
}

void simul() {
	int i, j;

	int ca[100];
	int ent = 0;
	for (i = 0; i < 10; i++) {
		ca[i] = ent++;
	}
	printf("function ok\n");
}
void merge(int f_u1, int f_u2, int u1, int u2, int target)
{
	int i = 0;
	for (i = f_u1; i < f_u1 + f_u2; i++)
	{
		head_temp[u1][i] = head_temp[u2][i - f_u1];
		head[head_temp[u1][i]] = head[target];
		floor_max[u1]++;
	}
}
int is_union(int x, int y)
{
	int u1, u2, i, j, f_u1, f_u2;
	if (head[x] >= 0 && head[y] >= 0) 
	{
		if (head[x] == head[y])
			return 0;
		else 
		{
			u1 = head[x], u2 = head[y]; 
			f_u1 = floor_max[u1], f_u2 = floor_max[u2];
			if (f_u1 > f_u2) // u1에 u2를 병합
			{
				merge(f_u1, f_u2, u1, u2, head[x]);
			}
			else
			{
				merge(f_u2, f_u1, u2, u1, head[y]);
			}
		}
	}
	else
	{
		if (head[x] >= 0)// head[y] == -1
		{
			u1 = head[x];
			head_temp[u1][floor_max[u1]++] = y;
			head[y] = head[x];
		}
		else if (head[y] >= 0) 
		{
			u1 = head[y];
			head_temp[u1][floor_max[u1]++] = x;
			head[x] = head[y];
		}
		else
		{
			head[x] = x, head[y] = x;
			floor_max[x] = 2;
			head_temp[x][0] = x;
			head_temp[x][1] = y;
		}
	}
	return 1;
}


void findPosition(int p) 
{
	int parent = 0;
	while (p>1)
	{
		parent = p / 2;
		if (heap[p][0] < heap[parent][0])
		{
			swap(&heap[p][0], &heap[parent][0]);
			swap(&heap[p][1], &heap[parent][1]);
		}
		else if (heap[p][0] == heap[parent][0] && heap[p][1] < heap[parent][1])
		{
			swap(&heap[p][1], &heap[parent][1]);
		}

		p = parent;
	}
}
int adjust(int a, int b, int target) 
{
	if (a && b)
	{
		if (a < target && b < target)
			return a < b ? 0 : 1;
		else if (a < target)
			return 0;
		else if (b < target)
			return 1;
		else
			return -1;
	}
	else if (a)
		return a < target ? 0 : -1;
	else if (b)
		return b < target ? 1 : -1;
	else
		return -1;
}
int getMinHeap(int n) 
{
	int p, temp = 0;
	swap(&heap[1][0], &heap[n][0]);
	swap(&heap[1][1], &heap[n][1]);
	p = 1;
	while (p < n)
	{
		if ((2 * p) + 1 < n) 
		{
			temp = adjust(heap[2 * p][0], heap[2 * p + 1][0], heap[p][0]);
			if (temp < 0)
			{
				if (heap[2 * p][0] == heap[p][0] && heap[2 * p + 1][0] == heap[p][0]) 
				{
					temp = adjust(heap[2 * p][1], heap[2 * p + 1][1], heap[p][1]);
					if (temp<0)
						break;
					else
						swap(&heap[2 * p + temp][1], &heap[p][1]);
				}
				else if (heap[2 * p][0] == heap[p][0])
				{
					if (heap[2 * p][1] < heap[p][1])
					{
						swap(&heap[2 * p][0], &heap[p][0]);
						swap(&heap[2 * p][1], &heap[p][1]);
						temp = 0;
					}
					else
						break;
				}
				else if (heap[2 * p + 1][0] == heap[p][0])
				{
					if (heap[2 * p + 1][1] < heap[p][1])
					{
						swap(&heap[2 * p + 1][0], &heap[p][0]);
						swap(&heap[2 * p + 1][1], &heap[p][1]);
						temp = 1;
					}
					else
						break;
				}
				else 
					break;
			}
			else
			{
				if (heap[2 * p][0] == heap[2 * p + 1][0]) 
				{
					if (heap[2 * p][1] < heap[2 * p + 1][1]) 
					{
						temp = 0;
					}
					else
					{
						temp = 1;
					}
				}
				swap(&heap[2 * p + temp][0], &heap[p][0]);
				swap(&heap[2 * p + temp][1], &heap[p][1]);
				
			}
		}
		else if (2 * p < n) 
		{
			if (heap[2 * p][0] < heap[p][0])
			{
				swap(&heap[2 * p][0], &heap[p][0]);
				swap(&heap[2 * p][1], &heap[p][1]);
				temp = 0;
			}
			else if (heap[2 * p][0] == heap[p][0] && heap[2 * p][1] < heap[p][1])
			{
				swap(&heap[2 * p][1], &heap[p][1]);
				temp = 0;
			}
			else
				break;
		}

		p = (2 * p) + temp;
	}
	return heap[n][0];
}
void Prim(int num, int type)
{
	
	int EdgeCount = 0, EdgeNumber = 0; simul();
	int index = 1, i = 0;
	while (EdgeCount < n - 1)
	{
		if (check[num] != type)
		{
			check[num] = type;
			for (i = 0; i < floor[num]; i++)
			{
				if (check[edge[prim[num][i][1]][1]] != type || check[edge[prim[num][i][1]][2]] != type)
				{
					heap[index][0] = prim[num][i][0];
					heap[index][1] = prim[num][i][1];
					findPosition(index++);
				}
			}
		}
		while (index>0)
		{
			getMinHeap(index - 1);
			EdgeNumber = heap[index - 1][1];
			num = check[edge[EdgeNumber][1]] != type ? edge[EdgeNumber][1] : edge[EdgeNumber][2];
			index--;
			if (check[num] != type)
			{
				select[EdgeCount++] = EdgeNumber;
				break;
			}
		}
	}
	
}
void Kruscal()
{
	int EdgeCount = 0;
	int EdgeNumber = 0;
	int vertex;
	int sP, eP; simul();
	while (EdgeCount < n - 1)
	{
		vertex = kruscal[EdgeNumber][1];
		sP = edge[vertex][1], eP = edge[vertex][2];
		if (is_union(sP, eP))
		{
			select[EdgeCount++] = vertex;
			sum += edge[vertex][0];
		}
		EdgeNumber++;
	}
}

int main() {

	fscanf(input, "%d %d", &n, &m);

	int i, j;
	int x, y, w;
	for (i = 0; i < n; i++)
	{
		head[i] = -1;
	}
	simul();
	for (i = 0; i < m; i++) {
		fscanf(input, "%d %d %d", &x, &y, &w);
		edge[i][0] = w;
		edge[i][1] = x, edge[i][2] = y;
		kruscal[i][0] = w;
		kruscal[i][1] = i;
		prim[x][floor[x]][0] = w;
		prim[x][floor[x]++][1] = i;
		prim[y][floor[y]][0] = w;
		prim[y][floor[y]++][1] = i;
	}
	quicksort(0, m - 1); 
	duplicate_process(0, m - 1); 
	Kruscal();
	fprintf(output, "Tree edges by Kruskal algorithm: %d\n", sum);
	for (i = 0; i < n - 1; i++)
	{
		fprintf(output, "%d\n", select[i]);
	}
	fprintf(output, "Tree edges by Prim algorithm with starting vertex %d: %d\n", 0, sum);
	Prim(0, 1);
	for (i = 0; i < n - 1; i++)
	{
		fprintf(output, "%d\n", select[i]);
	}
	fprintf(output, "Tree edges by Prim algorithm with starting vertex %d: %d\n", n / 2, sum);
	Prim(n / 2, 2);
	for (i = 0; i < n - 1; i++)
	{
		fprintf(output, "%d\n", select[i]);
	}
	fprintf(output, "Tree edges by Prim algorithm with starting vertex %d: %d\n", n - 1, sum);
	Prim(n - 1, 3);
	for (i = 0; i < n - 1; i++)
	{
		fprintf(output, "%d\n", select[i]);
	}

	fclose(input);
	fclose(output);
	return 0;
}