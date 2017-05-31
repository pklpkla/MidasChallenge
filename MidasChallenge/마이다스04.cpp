#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<string>
#include<queue>
using namespace std;

string x,y;
int d;

int main()
{
	cin >> x;
	cin >> y;

	int xl = x.length();
	int yl = y.length();

	int l = yl;-xl;

	if (l == 0)
	{
		for (int i = 0; i < yl; i++)
		{
			if (y[i] - x[i] == 0)
				d++;
		}
	}
	
	cout << d << endl;

	return 0;
}