#pragma warning(disable:4996)
#include <stdio.h>

int recursion(int n, int k);

int main()
{
	int n, k;
	printf("n�� ���̿��� k���� �̴� ���� �ٸ� ����� �������� ���ϴ� ���α׷��Դϴ�.\n");
	printf("n�� k�� �Է��Ͽ� �ּ���.\n");
	printf("n : ");
	scanf("%d", &n);
	printf("k : ");
	scanf("%d", &k);

	printf("%d C %d = %d", n, k, recursion(n, k));
	return 0;
}

int recursion(int n, int k)
{
	if (k == 0 || n == k)
		return 1;
	return recursion(n - 1, k - 1) + recursion(n - 1, k);
}
