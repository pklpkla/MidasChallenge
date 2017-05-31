#include <stdio.h>
#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main()
{
	int n;
	int coin[1001];
	int dp[1001];
	bool d[1001] = { 0 };
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> coin[i];
	}
	dp[0] = coin[0];

	for (int i = 1; i < n; i++)
	{
		if (i == 1)
		{
			dp[1] = coin[1] + dp[0];
			d[1] = true;
			continue;
		}
		if (d[i - 1] == true)
		{
			if (coin[i] + coin[i - 1] > coin[i] + dp[i - 2])
			{
				dp[i] = coin[i] + coin[i - 1];
				d[i] = true;
			}
			else if (coin[i] + coin[i - 1] == coin[i] + dp[i - 2])
			{
				dp[i] = coin[i] + coin[i - 1] + dp[i - 3];
				d[i] = true;
			}
			else if (coin[i] + coin[i - 1] + dp[i - 3] > coin[i] + dp[i - 2])
			{
				dp[i] = coin[i] + coin[i - 1] + dp[i - 3];
				d[i] = true;
			}
			else
				dp[i] = coin[i] + dp[i - 2];

		}
		else
		{
			if (coin[i] + dp[i - 1] > coin[i] + dp[i - 2])
			{
				dp[i] = coin[i] + dp[i - 1];
				d[i] = true;
			}
			else
				dp[i] = coin[i] + dp[i - 2];

		}
	}
	cout << dp[n - 1];

	return 0;
}