#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX 100000

int N, n, pole[MAX], dist[MAX], gcd[MAX];;

int GCD(int x, int y)
{
	while (y != 0) {
		int r = x%y;
		x = y;
		y = r;
	}
	return x;
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &pole[i]);
		if (i > 0)
		{
			dist[i - 1] = pole[i] - pole[i - 1];
		}
	}

	gcd[0] = dist[0];
	for (int i = 1; i < N - 1; i++)
	{
		gcd[i] = GCD(dist[i], gcd[i - 1]);
	}
	for (int i = 0; i < N - 1; i++)
	{
		n += dist[i] / gcd[N - 2] - 1;
	}
	printf("%d", n);

	return 0;
}