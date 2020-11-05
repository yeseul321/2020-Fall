#include<stdio.h.>
#include<stdlib.h>

#define NUM 7
#define INF 999

int D[NUM][NUM];

int W[NUM][NUM] = {

	{0,4,INF,INF,INF,10,INF},
	{3,0,INF,18,INF,INF,INF},
	{INF,6,0,INF,INF,INF,INF},
	{INF,5,15,0,2,19,5},
	{INF, INF,12,1,0,INF,INF},
	{INF,INF,INF,INF,INF,0,10},
	{INF,INF,INF,8,INF,INF,0}

};

void simpleShortestPath(int num, int W[NUM][NUM]) {

	int i, j, m = 0;

	for (i = 0; i < num; i++) {
		for (j = 0; j < num; j++) {
			D[i][j] = W[i][j];
		}
	} 

	printf("-----------������ 1���� ��-----------\n");

	for (i = 0; i < num; i++) { //������ ������ 1���� ���� ������ D��İ� �����Ƿ� �״�� ���
		for (j = 0; j < num; j++) {
			printf("%4d", D[i][j]);
		}
		printf("\n");
	}


	for (m = 2; m <= num; m++) { //m�� ������ ���� 
		for (i = 0; i < num; i++) { //i�� ���� ���
			for (j = 0; j < num; j++) { //j�� ������ ���
				for (int k = 0; k < num; k++){ //k�� ���İ��� ���
					D[i][j] = min(D[i][j], D[i][k] + W[k][j]);
				}
			}
		}
		printf("-----------������ %d���� ��-----------\n", m);
		for (int a = 0; a < num; a++) { //������ ������ 2�̻��� �� D��� ���
			for (int b = 0; b < num; b++) {
				printf("%4d", D[a][b]);
			}
			printf("\n");
		}
		printf("\n\n");
	}
	
}

int main(void) {

	simpleShortestPath(NUM, W);
	return 0;
}