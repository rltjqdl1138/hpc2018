#include <stdio.h>
#include <stdlib.h>


int sort(const void * a,const void * b) 
{
	if (*(int*)a >*(int*) b)
		return -1;
	else if (*(int*)a < *(int*)b)
		return 1;
	else
		return 0;
}

int main() 
{
	int N, M;
	scanf("%d %d", &M, &N);
	int *L = (int*)malloc(sizeof(int)*N);
	for (int i = 0; i < N; i++)
		scanf("%d", &L[i]);

	qsort(L, N, sizeof(int), sort);
	
	int size=0;
	int num;
	int top = L[0], btm = 1;
	int mid;
	
	while (top>=btm)
	{
		mid = (top + btm) / 2;
		num = 0;
		for (int i = 0; i < N; i++)
		{
			num += L[i] / mid;
			if (num >= M)
			{
				btm = mid + 1;
				size = mid;
				break;
			}
		}
		if (num < M)
			top = mid - 1;
	}
	
	printf("%d", size);
}