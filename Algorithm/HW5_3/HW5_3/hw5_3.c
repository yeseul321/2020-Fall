#include<stdio.h>
#include<stdlib.h>

#define _CRT_SECURE_NO_WARNINGS
#define table_size 13
#define INPUT_SIZE 8

typedef struct HashNode {
	int key;
	int value;
	struct HashNode* next; //다음 노드를 가리키는 포인터
} hashnode;

void hashing(hashnode * hash_i, int value_i, hashnode * node) { //기본삽입함수
	int key_i = value_i % table_size;
	
	(*node).key = key_i;
	(*node).value = value_i;
	(*node).next = hash_i[key_i].next; //next포인터에 NULL값
	hash_i[key_i].next = node; //기존 구조체배열의 next는 새로 생겨난 node를 포인터
	//새로 입력받은 node가 앞쪽으로 올 수 있도록 만든 구조
}

void printHash(hashnode * hash_i) { //해시테이블의 삽입결과를 출력하는 함수
	
	printf_s("--------------------------------\n");
	for (int i = 0; i < table_size; i++) {
		hashnode current = hash_i[i];
		printf("[%d]번째 줄: ", i);
		while (1) {
			printf("%d", current.value);
			if (current.next == NULL)
				break;
			current = *(current.next); //꼬리에 꼬리를 무는 형식
			printf(" -> ");
		}
		printf("\n");
	}
}

int main(void) {
	int input = 0; //입력값
	int i = 0; //삽입횟수
	
	hashnode * inputnode = (hashnode *)malloc(sizeof(hashnode)*INPUT_SIZE); //입력받을 크기만큼 동적할당해준 구조체 포인터

	hashnode hash[table_size];
	for (int a = 0; a < table_size; a++) { //배열 초기화
		hash[a].key = a;
		hash[a].value = NULL;
		hash[a].next = NULL;
	}


	printf_s("삽입할 숫자 입력 후 엔터를 눌러주세요 : \n");

	while (i < INPUT_SIZE) {
		scanf_s("%d", &input); //삽입할 값 입력받기

		//hash구조체에 input이라는 삽입값으로 삽입함수 시행
		hashing(hash, input, &inputnode[i]);

		if (i >= 4)
			printHash(hash);

		i++; //삽입횟수를 1 늘리고 같은 과정 구조체 크기만큼 반복
	}

	free(inputnode);

	printf("함수가 종료되었습니다.");

}