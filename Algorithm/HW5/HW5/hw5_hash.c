#include<stdio.h>
#include<stdlib.h>

#define _CRT_SECURE_NO_WARNINGS

#define table_size 13 //hashtable�� ����� �̸� �����ش�.

typedef struct HashNode {
	int key; //���������� �� ��ġ
	int value; //�Է°��� �� ��ġ
}hashnode;

void hashing(hashnode*hash_i,int value_i) { //�⺻�����Լ�
	int key_i = value_i % table_size;

	if (hash_i[key_i].value == NULL) { //mod�� ���� �ش��ϴ� �迭�� NULL���̸�
		hash_i[key_i].key = key_i;		//�� ������ �������� ����
		hash_i[key_i].value = value_i; //�� ������ �Է°� ����
	}
	else {
		linear_probing(hash_i, key_i, value_i); //NULL���� �ƴ϶�� ���������Լ� ȣ��
	}
}

int linear_probing(hashnode*hash_p, int key_p, int value_p) { //��������

	int i = 0;
	int index = key_p + 1; //�����ε�������

	while (index != key_p) { 
		if (hash_p[index].value == NULL) {
			hash_p[index].key = key_p;
			hash_p[index].value = value_p;//�����Լ������� ���� ���.
			return 0;
		}

		index++;

		if (index == table_size)
			index = 0; //index�� ���̺��� ������� 0���� �ٲپ��־ �ٽ� ���縦 �̾����.
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
	hashnode hash[table_size]; //����ü�迭 ����

	for (int a = 0; a < table_size; a++) { //�迭 �ʱ�ȭ
		hash[a].key = NULL;
		hash[a].value = NULL;
	}

	printf_s("������ ���� �Է� �� ���͸� �����ּ��� : \n");

	while (i < 8) {
		scanf_s("%d", &input); //������ �� �Է¹ޱ�

		hashing(hash, input); //hash����ü�� input�̶�� ���԰����� �����Լ� ����

		if(i>=4)
			printHash(hash); //33�� �Է����������� �ؽ����̺� ���.(���� �䱸����)

		i++; //����Ƚ���� 1 �ø��� ���� ���� �Է¹��� ������ ������ŭ �ݺ�
	}


	printf("�Լ��� ����Ǿ����ϴ�.");

}