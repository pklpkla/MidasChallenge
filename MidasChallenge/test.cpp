#include <stdio.h>
#include <iostream>
#include <stack>
#include <string>
using namespace std;
int gcd(int a, int b)
{
	if (a < b)
	{
		int tmp = a;
		a = b;
		b = tmp;
	}
	int mod = a % b;
	while (mod > 0)
	{
		a = b;
		b = mod;
		mod = a % b;
	}
	return b;
}
int main()
{
	int n = 0;
	int junbot[100001] = { 0 };
	int total = 0;
	int gcdd = 0;
	int result = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> junbot[i];
	}
	int a, b;
	a = junbot[1] - junbot[0];
	b = junbot[2] - junbot[1];
	int tmp = gcd(a, b);
	total += a;
	total += b;
	if (gcdd < tmp)
	{
		gcdd = tmp;
	}
	for (int i = 2; i < n - 1; i++)
	{
		int a;
		a = junbot[i + 1] - junbot[i];

		tmp = gcd(a, gcdd);
		total += a;
		if (gcdd > tmp)
		{
			gcdd = tmp;
		}
	}
	result = (total / gcdd) - (n - 1);
	cout << result;

	return 0;
}