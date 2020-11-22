#include <stdio.h>


#define MAX 8 //����� ����
#define INF 999 //������ ����ġ�� ���� ��� ���Ѵ� ǥ��

void kruskal();

int w[MAX][MAX] = { //����ġ ���. �� ���� �� ��忡�� ���� ���� ���� ����ġ�� ��Ÿ��
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
	int v[MAX]; //�ش� ������ �������� ���������� ǥ��

	sum = 0;

	printf("�˰��� ���� �� ��� : \n");

	for (int i = 0; i < MAX; i++)
		v[i] = 1; //������ ���� ������ 1�� ǥ���Ѵ�
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
		} //���� �����鰣�� ����ġ �� ���� �ּҰ��� ���Ѵ�.

		for (int i = 0; i < MAX; i++)
		{
			if (w[a][i] == -1 && w[i][b] == -1)
			{
				w[a][b] = -1;
				w[b][a] = -1;
			} //������ ������ ����ġ�� -1�� �ٲ��ش�.
		}
		if (v[a] == -1 && v[b] == -1)
			for (int i = 0; i < MAX; i++)
			{
				if (w[a][i] == -1 && w[i][b] == -1)
				{
					cycle = 1;
					break;
				} //���� ����Ŭ�� �����Ǿ��ٸ� break
			}

		if (cycle == 0) //����Ŭ�� �ƴ϶�� ������ ������ -1�� ǥ���ϰ� ����ġ�� -1�� ǥ���Ѵ�.
		{
			v[a] = -1;
			v[b] = -1;
			w[a][b] = -1;
			w[b][a] = -1;
			sum = sum + min; //����ġ ���� �տ� �ش� ����ġ�� min���� �����ش�.
			printf("(%c, %c) ����ġ ������ : %d\n", alph[a], alph[b], sum);
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