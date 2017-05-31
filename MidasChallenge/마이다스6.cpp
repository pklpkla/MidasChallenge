#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;


int n;
int p[2000];
int D[2000];

int min(int a, int b, int c)
{
	return (a < b) ? ((a < c) ? a : c) : ((b < c) ? b : c);
}

int discount(int i)
{
	return p[i-2] + p[i - 1] + p[i] - min(p[i-2], p[i-1], p[i]);
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> p[i];
	D[0] = p[0];
	D[1] = p[0]+p[1];
	D[2] = discount(2);

	for (int i = 3; i < n; i++)
	{
		if (D[i - 3] + discount(i) < D[i - 1] + p[i])
			D[i] = D[i - 3] + discount(i);
		else
			D[i] = D[i - 1] + p[i];
	}

	cout << D[n-1];
	return 0;
}