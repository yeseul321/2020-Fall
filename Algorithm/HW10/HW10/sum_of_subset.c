#include<stdio.h>
#include<time.h>

int w[6] = { 2, 10, 13, 17, 22, 42 }; //Input
int W = 0; //구하고자 하는 값
int x[6] = { 0, }; //지나간 노드들의 값을 저장하는 배열

int promising(int i, int weight, int total) { //유망한 노드인지 판별
	if (weight + total >= W && (weight == W || weight + w[i + 1] <= W)) {
		return 1; //유망
	}
	return 0; //유망하지 않다
}

void print() { //W값에 해당하는 경로에 대한 x배열 출력
	for (int i = 0; i < 6; i++) {
		if (x[i] != 0) {
			printf("-> %d ", x[i]);
		}
	}
	printf("\n");
}

void sum_of_subset(int i, int weight, int total) {
	if (promising(i, weight, total)) {
		if (W == weight) { //구하고자 하는 값과 동일할 때
			printf("답에 포함 : ");
			print();
		}
		else {
			x[i + 1] = w[i + 1];
			sum_of_subset(i + 1, weight + w[i + 1], total - w[i + 1]);
			x[i + 1] = 0;
			sum_of_subset(i + 1, weight, total - w[i + 1]);
		}
	} 
}

int estimate() { //몬테카를로 함수

	int m = 2; //노드의 유망한 자식의 개수
	int mprod = 1; //유망한 자식의 개수의 곱을 갖는 변수
	int numnodes = 1; //총 노드의 개수
	int index = 1;
	int weight = 0;
	int n;
	int total = 106;
	int chk = 1;
	
	srand((unsigned int)time(NULL));

	while (m != 0) {
		m = 0;
		chk = 1;

		weight = weight + w[index + 1];
		total = total - w[index + 1];

		if (promising(index + 1, weight, total)) {
			m++;
			chk = chk * (-1);
		}

		weight = weight - w[index + 1];
		if (promising(index + 1, weight, total)) {
			m++;
			chk = chk * 2;
		}
		mprod = mprod * m;
		numnodes = numnodes + mprod * 2;
		n = (int)rand() % 2;
		if (chk == -2) { //양쪽 다 유망한 노드일 때
			if (n) { //왼쪽노드
				index++;
				weight = weight + w[index];
			}
			else { //오른쪽 노드
				index++;
			}
		}
		else if (chk == -1) {
			index++;
			weight = weight + w[index];
		}
		else if (chk == 2) {
			index++;
		}
	}
	return numnodes;
}

void main() {
	int num, total = 0;
	int es = 0;
	double sum = 0;

	for (int i = 0; i < 6; i++) {
		total += w[i];
	}

	printf("검색할 숫자 입력 : ");
	scanf_s("%d", &W);

	sum_of_subset(-1, 0, total);

	es = estimate();
	printf("\n효율성 : %d\n", es);
}
	