#include<stdio.h.>
#include<stdlib.h>

#define NUM 7
#define INF 999

int D[NUM][NUM];
int P[NUM][NUM];

int W[NUM][NUM] = {

	{0,4,INF,INF,INF,10,INF},
	{3,0,INF,18,INF,INF,INF},
	{INF,6,0,INF,INF,INF,INF},
	{INF,5,15,0,2,19,5},
	{INF, INF,12,1,0,INF,INF},
	{INF,INF,INF,INF,INF,0,10},
	{INF,INF,INF,8,INF,INF,0}

};

int M[NUM][NUM] = { //문제 3번을 위한 행렬
	{0,INF,INF,8,INF,INF,INF},
	{10,0,INF,INF,INF,INF,INF},
	{INF,INF,0,1,12,INF,INF},
	{5,19,2,0,15,5,INF},
	{INF,INF,INF,INF,0,6,INF},
	{INF,INF,INF,18,INF,0,3},
	{INF,10,INF,INF,INF,4}
};


void path(int q, int r) { 
	if (P[q][r] != 0) {
		path(q, P[q][r] - 1);
		printf("\n-----------\n");
		printf(" 결과 : v%d", P[q][r]);
		//printf(" 결과 : a%d", P[q][r]);  //문제 3번을 위한 코드
		printf("\n-----------\n");
		path(P[q][r] - 1, r);
	}
}

void floyd(int num, int W[][NUM]) {

	int i, j, k = 0;
	for (i = 0; i < num; i++) {
		for (j = 0; j < num; j++) {
			P[i][j] = 0;
			D[i][j] = W[i][j];
		}
	} 

	for (k = 0; k < num; k++) {	// k는 거쳐가는 노드
		for (i = 0; i < num; i++) {	// i는 출발노드
			for (j = 0; j < num; j++) { // j는 도착노드
				if (D[i][k] + D[k][j] < D[i][j]) {
					P[i][j] = k + 1;
					D[i][j] = D[i][k] + D[k][j];
				}
			}
		}
	}
	

	printf("-----------행렬 D------------\n");
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			printf("%4d", D[i][j]);
		}
		printf("\n");
	}
	printf("\n-----------행렬 P------------\n");
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			printf("%4d", P[i][j]);
		}
		printf("\n");
	}

	path(2, 5);
	//path(4, 1); //문제 3번을 위한 명령어
}


int main(void) {

	floyd(NUM, W);
	//floyd(NUM,M); //문제 3번을 위한 명령어
	return 0;
}