#pragma warning(disable:4996)
#include <stdio.h>

int recursion(int n, int k);

int main()
{
	int n, k;
	printf("n개 중이에서 k개를 뽑는 서로 다른 방법의 가지수를 구하는 프로그램입니다.\n");
	printf("n과 k를 입력하여 주세요.\n");
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
