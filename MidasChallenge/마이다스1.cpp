#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;


int d[10][10];

int number[10];
int jjak, hol;
int dp(int n, int m);
int main()
{
	int n, m;
	cin >> n;
	cin >> m;

	for (int i = 0; i < m; i++) {
		cin >> number[i];
		if (number[i] == 0 || number[i] % 2 == 0)
			jjak++;
		else
			hol++;
	}
	sort(number, number + m);

	int result = dp(n, m) - dp(n, hol) - dp(n, jjak);

	cout << result << endl;

	return 0;
}

int dp(int n, int m)
{
	for (int i = 0; i <= m; i++) {
		d[1][i] = 1;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = i - 1; j <= m; j++) {
			for (int k = j - 1; k >= 0; k--) {
				d[i][j] += d[i - 1][k];
			}
		}
	}
	int result = 0;
	for (int i = 0; i < m; i++) {
		result += d[n][i];
	}

	return result;
}