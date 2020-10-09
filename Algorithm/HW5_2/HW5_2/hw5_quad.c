#include<stdio.h>
#include<stdlib.h>

#define _CRT_SECURE_NO_WARNINGS

#define table_size 13

typedef struct HashNode {
	int key;
	int value;
}hashnode;

void hashing(hashnode*hash_i, int value_i) { //�⺻�����Լ�
	int key_i = value_i % table_size;

	if (hash_i[key_i].value == NULL) { //mod�� ���� �ش��ϴ� �迭�� NULL���̸�
		hash_i[key_i].key = key_i;		//�� ������ �������� ����
		hash_i[key_i].value = value_i; //�� ������ �Է°� ����
	}
	else {
		quadratic_probing(hash_i, key_i, value_i); //NULL�� �ƴϸ� �����������Լ� ȣ��
	}
}

int quadratic_probing(hashnode*hash_p, int key_p, int value_p) { //����������
	int j = 1; //j��°�� ((value + j*j) % 13)��°�� index�� ���� ����
	int value = value_p + j*j;
	int index = value % 13;

	while (1) { //NULL���� �ƴ� ���� �ε����� j*j�� ���� �ε�������
		if (hash_p[index].value == NULL) {
			hash_p[index].key = key_p;
			hash_p[index].value = value_p; //�� ������ �Է°� ����

			return 0;
		}
		j++; 
		value = value_p + j * j; //value���� j^2�� �����ְ�
		index = value % 13; //�׸�ŭ index�� ���� ���Ž�����.

		if (index >= table_size)
			index = index % table_size; //index�� ���̺��� �������� ������ ��ȯ������ ������ �� �ִ� ����
	}

	return -1;
}


void printHash(hashnode*hash_i) { //�ؽ����̺��� ���԰���� ����ϴ� �Լ�
	printf_s("--------------------------------\n");
	for (int i = 0; i < table_size; i++) {
		printf_s("[%d]�� \t %d \n", i, hash_i[i].value);

	}
}

int main(void) {
	int input = 0; //�Է°�
	int i = 0; //����Ƚ��
	hashnode hash[table_size];
	for (int a = 0; a < table_size; a++) { //�迭 �ʱ�ȭ
		hash[a].key = NULL;
		hash[a].value = NULL;
	}

	printf_s("������ ���� �Է� �� ���͸� �����ּ��� : \n");

	while (i < 8) {
		scanf_s("%d", &input); //������ �� �Է¹ޱ�

		//hash����ü�� input�̶�� ���԰����� �����Լ� ����
		hashing(hash, input);

		if (i >= 4)
			printHash(hash);

		i++; //����Ƚ���� 1 �ø��� ���� ���� �Է¹��� ������ŭ �ݺ�
	}


	printf("�Լ��� ����Ǿ����ϴ�.");

}