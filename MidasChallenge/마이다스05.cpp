#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX(a,b) a>b?a:b

int N, M, n, r, check[100], d[100][100];

int recursion(int n, int k)
{

}

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &n);
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &r);
			d[i][r-1] = 1;
		}
	}

	for (int i = 0; i < N; i++)
	{
		
	}


	return 0;
}