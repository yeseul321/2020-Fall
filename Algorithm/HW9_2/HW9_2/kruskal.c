#include <stdio.h>


#define MAX 8 //노드의 개수
#define INF 999 //간선의 가중치가 없는 경우 무한대 표시

void kruskal();

int w[MAX][MAX] = { //가중치 행렬. 각 행은 각 노드에서 인접 노드로 가는 가중치를 나타냄
	{ 0, 11, 9, 8, INF, INF, INF, INF },
	{ 11, 0, 3, INF, 8, 8, INF, INF },
	{ 9, 3, 0, 15, INF, 12, 1, INF },
	{ 8, INF, 15, 0, INF, INF, 10, INF },
	{ INF, 8, INF, INF, 0, 7, INF, 4 },
	{ INF, 8, 12, INF, 7, 0, INF, 5 },
	{ INF, INF, 1, 10, INF, INF, 0, 2 },
	{ INF, INF, INF, INF, 4, 5, 2, 0 }
};

char alph[MAX] = { 'V1', 'V2', 'V3', 'V4', 'V5', 'V6', 'V7', 'V8' };

int main()
{
	kruskal();
}

void kruskal() {

	int min, a, b, cycle, sum;
	int v[MAX]; //해당 정점을 지났는지 안지났는지 표시

	sum = 0;

	printf("알고리즘 실행 후 결과 : \n");

	for (int i = 0; i < MAX; i++)
		v[i] = 1; //지나지 않은 정점은 1로 표시한다
	for (int tmp = 0; tmp < MAX - 1;)
	{
		min = INF; 
		cycle = 0;

		for (int i = 0; i < MAX; i++)
		{
			for (int j = 0; j < MAX; j++)
			{
				if (w[i][j] != 0 && w[i][j] != -1 && w[i][j] != INF)
				{
					if (min > w[i][j])
					{
						min = w[i][j];
						a = i;
						b = j;
					}
				}
			}
		} //남은 정점들간의 가중치 중 제일 최소값은 구한다.

		for (int i = 0; i < MAX; i++)
		{
			if (w[a][i] == -1 && w[i][b] == -1)
			{
				w[a][b] = -1;
				w[b][a] = -1;
			} //지나간 정점의 가중치도 -1로 바꿔준다.
		}
		if (v[a] == -1 && v[b] == -1)
			for (int i = 0; i < MAX; i++)
			{
				if (w[a][i] == -1 && w[i][b] == -1)
				{
					cycle = 1;
					break;
				} //만약 사이클이 생성되었다면 break
			}

		if (cycle == 0) //사이클이 아니라면 지나간 정점을 -1로 표시하고 가중치도 -1로 표시한다.
		{
			v[a] = -1;
			v[b] = -1;
			w[a][b] = -1;
			w[b][a] = -1;
			sum = sum + min; //가중치 누적 합에 해당 가중치인 min값을 더해준다.
			printf("(%c, %c) 가중치 누적합 : %d\n", alph[a], alph[b], sum);
			tmp++;
		}

		for (int i = 0; i < MAX; i++)
		{
			for (int j = 0; j < MAX; j++)
			{
				for (int tmp2 = 0; tmp2 < MAX; tmp2++)
				{
					if (w[i][tmp2] == -1 && w[tmp2][j] == -1)
					{
						w[i][j] = -1;
						w[j][i] = -1;
					}
				}
			}
		}
	}
	printf("\nSum = %d", sum);}