#include <stdio.h>
#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;
int n, m;
int num[10], even[10], odd[10];
int e_num, o_num;

int get_ascending(int n, int m)
{
	int D[10][10] = { 0, };

	for (int i = 0; i <= m; i++) {
		D[1][i] = 1;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = i - 1; j <= m; j++) {
			for (int k = j - 1; k >= 0; k--) {
				D[i][j] += (D[i - 1][k]);
			}
		}
	}
	int sum = 0;
	for (int i = 0; i < m; i++) {
		sum += (D[n][i]);
	}
	cout << sum << endl;

	return sum;
}

int main() {

	cin >> n;
	cin >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> num[i];
		if (num[i]==0 || num[i] % 2 == 0)
		{
			e_num++;
		}
		else
		{
			o_num++;
		}
	}
	sort(num, num + m);

	int result = get_ascending(n, m) - get_ascending(n, e_num) -get_ascending(n, o_num);
	
	cout << result;

	return 0;
}