#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 8
#define INF 999

int weight[MAX_VERTICES][MAX_VERTICES] =
{
	{ 0, 11, 9, 8, INF, INF, INF, INF },
	{ 11, 0, 3, INF, 8, 8, INF, INF },
	{ 9, 3, 0, 15, INF, 12, 1, INF },
	{ 8, INF, 15, 0, INF, INF, 10, INF },
	{ INF, 8, INF, INF, 0, 7, INF, 4 },
	{ INF, 8, 12, INF, 7, 0, INF, 5 },
	{ INF, INF, 1, 10, INF, INF, 0, 2 },
	{ INF, INF, INF, INF, 4, 5, 2, 0 }
};

int selected[MAX_VERTICES]; //������ ���� ǥ�� ���
int dist[MAX_VERTICES]; //����ġ ���� ���

int getMinVertex(int n) //����ġ�� ���� ���� ������ ã�� �Լ�
{
	int v, i;
	for (i = 0; i < n; i++)
	{
		if (!selected[i])
		{
			v = i;
			break;
		}
	}
	for (i = 0; i < n; i++)
	{
		if (!selected[i] && (dist[i] < dist[v]))
			v = i;
	}

	return v;
}

void prim(int s, int n)
{
	int i, u, v, sum=0;
	for (u = 0; u < n; u++)
		dist[u] = INF;

	dist[s] = 0;
	for (i = 0; i < n; i++)
	{
		u = getMinVertex(n);
		selected[u] = 1; //������ ������ 1�� ǥ��

		if (dist[u] == INF)
			return;

		for (v = 0; v < n; v++)
		{
			if (weight[u][v] != INF)
				if (!selected[v] && weight[u][v] < dist[v])
					dist[v] = weight[u][v];
		}

		printf("%d ��° ���� : v%d ---> ", u + 1, u + 1);
		printf("����ġ : %d\n", dist[u]);

		sum = sum + dist[u];

	}

	printf("\n ������� ����ġ : %d", sum);

}

void main()
{
	prim(0, MAX_VERTICES);
}