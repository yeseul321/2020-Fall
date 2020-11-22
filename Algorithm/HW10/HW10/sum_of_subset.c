#include<stdio.h>
#include<time.h>

int w[6] = { 2, 10, 13, 17, 22, 42 }; //Input
int W = 0; //���ϰ��� �ϴ� ��
int x[6] = { 0, }; //������ ������ ���� �����ϴ� �迭

int promising(int i, int weight, int total) { //������ ������� �Ǻ�
	if (weight + total >= W && (weight == W || weight + w[i + 1] <= W)) {
		return 1; //����
	}
	return 0; //�������� �ʴ�
}

void print() { //W���� �ش��ϴ� ��ο� ���� x�迭 ���
	for (int i = 0; i < 6; i++) {
		if (x[i] != 0) {
			printf("-> %d ", x[i]);
		}
	}
	printf("\n");
}

void sum_of_subset(int i, int weight, int total) {
	if (promising(i, weight, total)) {
		if (W == weight) { //���ϰ��� �ϴ� ���� ������ ��
			printf("�信 ���� : ");
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

int estimate() { //����ī���� �Լ�

	int m = 2; //����� ������ �ڽ��� ����
	int mprod = 1; //������ �ڽ��� ������ ���� ���� ����
	int numnodes = 1; //�� ����� ����
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
		if (chk == -2) { //���� �� ������ ����� ��
			if (n) { //���ʳ��
				index++;
				weight = weight + w[index];
			}
			else { //������ ���
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

	printf("�˻��� ���� �Է� : ");
	scanf_s("%d", &W);

	sum_of_subset(-1, 0, total);

	es = estimate();
	printf("\nȿ���� : %d\n", es);
}
	