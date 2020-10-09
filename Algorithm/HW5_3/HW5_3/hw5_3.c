#include<stdio.h>
#include<stdlib.h>

#define _CRT_SECURE_NO_WARNINGS
#define table_size 13
#define INPUT_SIZE 8

typedef struct HashNode {
	int key;
	int value;
	struct HashNode* next; //���� ��带 ����Ű�� ������
} hashnode;

void hashing(hashnode * hash_i, int value_i, hashnode * node) { //�⺻�����Լ�
	int key_i = value_i % table_size;
	
	(*node).key = key_i;
	(*node).value = value_i;
	(*node).next = hash_i[key_i].next; //next�����Ϳ� NULL��
	hash_i[key_i].next = node; //���� ����ü�迭�� next�� ���� ���ܳ� node�� ������
	//���� �Է¹��� node�� �������� �� �� �ֵ��� ���� ����
}

void printHash(hashnode * hash_i) { //�ؽ����̺��� ���԰���� ����ϴ� �Լ�
	
	printf_s("--------------------------------\n");
	for (int i = 0; i < table_size; i++) {
		hashnode current = hash_i[i];
		printf("[%d]��° ��: ", i);
		while (1) {
			printf("%d", current.value);
			if (current.next == NULL)
				break;
			current = *(current.next); //������ ������ ���� ����
			printf(" -> ");
		}
		printf("\n");
	}
}

int main(void) {
	int input = 0; //�Է°�
	int i = 0; //����Ƚ��
	
	hashnode * inputnode = (hashnode *)malloc(sizeof(hashnode)*INPUT_SIZE); //�Է¹��� ũ�⸸ŭ �����Ҵ����� ����ü ������

	hashnode hash[table_size];
	for (int a = 0; a < table_size; a++) { //�迭 �ʱ�ȭ
		hash[a].key = a;
		hash[a].value = NULL;
		hash[a].next = NULL;
	}


	printf_s("������ ���� �Է� �� ���͸� �����ּ��� : \n");

	while (i < INPUT_SIZE) {
		scanf_s("%d", &input); //������ �� �Է¹ޱ�

		//hash����ü�� input�̶�� ���԰����� �����Լ� ����
		hashing(hash, input, &inputnode[i]);

		if (i >= 4)
			printHash(hash);

		i++; //����Ƚ���� 1 �ø��� ���� ���� ����ü ũ�⸸ŭ �ݺ�
	}

	free(inputnode);

	printf("�Լ��� ����Ǿ����ϴ�.");

}