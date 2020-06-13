#include <stdio.h>
#include <stdlib.h>

int ladder[50][10000] = { 0, };
int count[50] = { 0, }; //각 사다리 점 개수
int ind[50][10000]={0,}; // 몇번째 입력되는지
int ind_ladder[10000][4];
int T;//ladder number
int x, y;
int check;
int ind_count;

void Swap(int arr[][10000], int arr2[][10000], int a, int b,int N) // a,b 스왑 함수 
{
    int temp = arr[N][a];
    arr[N][a] = arr[N][b];
    arr[N][b] = temp;
    
    temp = arr2[N][a];
    arr2[N][a] = arr2[N][b];
    arr2[N][b] = temp;
}
int Partition(int arr[][10000], int arr2[][10000], int left, int right,int N)
{
    int pivot = arr[N][left]; // 피벗의 위치는 가장 왼쪽에서 시작
    int low = left + 1;
    int high = right;
 
    while (low <= high) // 교차되기 전까지 반복한다 
    {
        while (pivot >= arr[N][low] && low <= right) // 피벗보다 큰 값을 찾는 과정 
        {
            low++; // low를 오른쪽으로 이동 
        }
        while (pivot <= arr[N][high] && high >= (left+1) ) // 피벗보다 작은 값을 찾는 과정 
        {
            high--; // high를 왼쪽으로 이동
        }
        if (low <= high)// 교차되지 않은 상태이면 스왑 과정 실행 
        {
            Swap(arr,arr2 ,low, high,N); //low와 high를 스왑 
        }
    }
    Swap(arr, arr2,left, high,N); // 피벗과 high가 가리키는 대상을 교환 
    return high;  // 옮겨진 피벗의 위치정보를 반환 
 
}
 
void QuickSort(int arr[][10000], int arr2[][10000],int left, int right,int N)
{
    if (left <= right)
    {
        int pivot = Partition(arr ,arr2 ,left, right,N); // 둘로 나누어서
        QuickSort(arr, arr2 ,left, pivot - 1,N); // 왼쪽 영역을 정렬한다.
        QuickSort(arr, arr2 ,pivot + 1, right, N); // 오른쪽 영역을 정렬한다.
    }
}
void start(FILE *output){
	
	int x,y,z;
	int i,k,j;
	int result[50]={0,};
	for (k = 0; k < T; k++) {
      x = k;
      for (j=count[x]-1;j>=0;j--) {
         z = ind[x][j];
         if (ind_ladder[z][0] == x && ind_ladder[z][1] == ladder[x][j]) {
            x = ind_ladder[z][2];
            for (i = 0; i < count[x]; i++) {
               if (ind_ladder[z][3] == ladder[x][i]) {
                  j = i;
                  break;
               }
            }
            continue;
         }
         else {
            x = ind_ladder[z][0];
            for (i = 0; i < count[x]; i++) {
               if (ind_ladder[z][1] == ladder[x][i]) {
                  j = i;
                  break;
               }
            }
            continue;
         }

      }
      result[x] = k;
   }
   
   for(i=0;i<T;i++){
		fprintf(output,"%d ",result[i]);
	}
}
int main() {
	FILE *input = fopen("ladder.inp", "rt");
	FILE *output = fopen("ladder.out", "wt");

	fscanf(input, "%d", &T);
	int x1, y1, x2, y2;
	check = 1;
	ind_count = 0;
	
	while (1) {
		fscanf(input, "%d %d %d %d", &x1, &y1, &x2, &y2);
		if (x1 == 0 && y1 == 0 && x2 == 0 && y2 == 0) break;

		ladder[x1][count[x1]] = y1;
		ind[x1][count[x1]++] = ind_count;
		ladder[x2][count[x2]] = y2;
		ind[x2][count[x2]++] = ind_count;

		ind_ladder[ind_count][0] = x1;
		ind_ladder[ind_count][1] = y1;
		ind_ladder[ind_count][2] = x2;
		ind_ladder[ind_count][3] = y2;

		ind_count++;

	}

	int i,j,k;
	
	 for (i = 0; i < count[i]; i++) {
      QuickSort(ladder, ind,0, count[i]-1, i);
  
   }
	
	start(output);


	
	fclose(input);
	fclose(output);
	return 0;
}
