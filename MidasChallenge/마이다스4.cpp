#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
using namespace std;
#define max(x,y) x>y?x:y

int c[14][14];
string x[14], y[14];

int lcs(int m, int n) 
{
	for (int i = 0; i <= m; i++)
		c[i][0] = 0;
	for (int j = 0; j <= n; j++)
		c[0][j] = 0;

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (x[i] == y[j])
				c[i][j] = c[i - 1][j - 1] + 1;
			else
				c[i][j] = max(c[i - 1][j], c[i][j - 1]);
		}
	}
	return c[m][n];
}

int main()
{
	for (int i = 1; i < 14; i++)
		cin >> x[i];
	for (int i = 1; i < 14; i++)
		cin >> y[i];

	cout << lcs(13, 13);

	return 0;
}