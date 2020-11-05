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

	printf("-----------간선이 1개일 때-----------\n");

	for (i = 0; i < num; i++) { //간선의 갯수가 1개일 때는 최초의 D행렬과 같으므로 그대로 출력
		for (j = 0; j < num; j++) {
			printf("%4d", D[i][j]);
		}
		printf("\n");
	}


	for (m = 2; m <= num; m++) { //m은 간선의 갯수 
		for (i = 0; i < num; i++) { //i는 시작 노드
			for (j = 0; j < num; j++) { //j는 마지막 노드
				for (int k = 0; k < num; k++){ //k는 거쳐가는 노드
					D[i][j] = min(D[i][j], D[i][k] + W[k][j]);
				}
			}
		}
		printf("-----------간선이 %d개일 때-----------\n", m);
		for (int a = 0; a < num; a++) { //간선의 개수가 2이상일 때 D행렬 출력
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