#pragma warning(disable:4996)
#include<stdio.h>
#define MAX 1000

int F[MAX];
int N, C, D;

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%d ", &F[i]);
	
	scanf("%d", &C);
	
	for (int j = 0; j < N; j++)
	{
		D += F[j] / C;
		if (F[j] / C != 0)
			D++;
	}

	printf("%d\n", D*C);
	
	return 0;
}