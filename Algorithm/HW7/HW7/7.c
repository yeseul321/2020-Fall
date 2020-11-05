#include <stdio.h>
#include <stdlib.h>


int n;

int cache[5][32]; //다녀간 곳을 표시하는 배열
int(*cacheptr)[32] = cache;
int dist[5][5]; //입력값이 들어올 배열

void result_show(int last, int visited, int result) { //각 결과에서 방문할 곳을 V0 등으로 변경하여 출력할 함수
	printf("D[v%d][ ", last);

	// visited union
	visited = 31 - visited;//visited는 다녀온곳을 2진수로 표현하여 그 수를 10진수를 보여준것이므로 '가야할 곳'을 보여주려면 31에서 빼줘야한다.
	int j = 4;
	for (int i = 16; i >= 1; i = i / 2) { 
		if ((visited) / i > 0) {
			printf("v%d ", j);
			visited = visited % i;
			j--;
		}
	}


	printf("] = %d\n", result);
}

int TSP(int last, int visited) {  //최적 경로 구하는 함수
	int * result = cache[last][visited];
	if (result != 0) {
		//printf("cache: D[v%d][%d] = %d\n", last, visited, result);
		return result;
	}
		
	result = 65536;

	if (visited == (1 << n) - 1) { //모든곳을 다 방문했을 경우
		result = dist[last][0];
	}
	else { 
		for (int next = 0; next < n; next++) {
			if (visited&(1 << next))
				continue;
			if (dist[last][next] == 0)
				continue;
			//위의 두 조건을 모두 만족해야 아래 문장 실행
			result = min(result, TSP(next, visited | (1 << next)) + dist[last][next]); //최솟값 구하기
		}
	}
	cache[last][visited] = result;
	result_show(last, visited, result);
		return result;
}



int main() {
	for (int i = 0; i < n; i++) { //cache배열 초기화
		for (int j = 0; j < 32; j++) {
			cache[i][j] = 0;
		}
	}
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf_s("%d", &dist[i][j]);
		}
	} //입력값을 받아서 dist 2차원 배열에 넣어준다.
	printf("%d", TSP(0, 1));

		return 0;
}