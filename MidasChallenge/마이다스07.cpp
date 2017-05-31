#pragma warning (disable : 4996)

#include <stdio.h>
#include <vector>
#include <malloc.h>
#include <algorithm>

using namespace std;

vector<int> v[1001];

typedef struct edge {
	int v1, v2;
	int cost;
}Edge;

bool compare(Edge e1, Edge e2) { return e1.cost < e2.cost; }

void _sort(Edge E[], int m);

int u[1001];

int kruskal(int n, int m, Edge e[])
{
	for (int i = 0; i < n; i++) {
		u[i] = i;
	}
	Edge p;
	int num = 0;
	int k = 0;
	int a, b, c;//a,b는 점 c는 cost
	int result = 0;

	while (num < n - 1) {
		p = e[k];
		a = p.v1;
		b = p.v2;

		if (u[a] != u[b]) {
			u[b] = a;
			num++;
			result += p.cost;
		}
		k++;
	}

	return result;
}

int main()
{
	int n, m;

	scanf("%d %d", &n, &m);

	//Edge** arr = (Edge **)malloc(sizeof(Edge)*n);
	Edge* e = (Edge *)malloc(sizeof(Edge)*n);
	int t = m;
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &e[i].v1, &e[i].v2, &e[i].cost);
	}

	_sort(e, m); // edge들을 정렬

	int result = kruskal(n, m, e);

	printf("%d", result);

	return 0;
}

void _sort(Edge E[], int m)  // E 엣지 집합의 가중치를 정렬하기 위한 함수
{
	int i, Sorted = 0;
	Edge tmp;
	while (!Sorted) { // 정렬이 완료되지 않았으면..
		Sorted = 1;
		for (i = 1; i < m; i++) {
			if (E[i - 1].cost > E[i].cost) {
				tmp = E[i - 1];
				E[i - 1] = E[i];
				E[i] = tmp;
				Sorted = 0;
			}
		}
	}
}