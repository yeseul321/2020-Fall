#include<stdio.h>
#include<stdlib.h>

#define _CRT_SECURE_NO_WARNINGS

#define table_size 13

typedef struct HashNode {
	int key;
	int value;
}hashnode;

void hashing(hashnode*hash_i, int value_i) { //기본삽입함수
	int key_i = value_i % table_size;

	if (hash_i[key_i].value == NULL) { //mod의 값에 해당하는 배열이 NULL값이면
		hash_i[key_i].key = key_i;		//그 공간에 나머지값 삽입
		hash_i[key_i].value = value_i; //그 공간에 입력값 삽입
	}
	else {
		quadratic_probing(hash_i, key_i, value_i); //NULL이 아니면 이차원조사함수 호출
	}
}

int quadratic_probing(hashnode*hash_p, int key_p, int value_p) { //이차원조사
	int j = 1; //j번째엔 ((value + j*j) % 13)번째의 index로 가서 시행
	int value = value_p + j*j;
	int index = value % 13;

	while (1) { //NULL값이 아닌 현재 인덱스의 j*j번 후의 인덱스부터
		if (hash_p[index].value == NULL) {
			hash_p[index].key = key_p;
			hash_p[index].value = value_p; //그 공간에 입력값 삽입

			return 0;
		}
		j++; 
		value = value_p + j * j; //value값에 j^2를 더해주고
		index = value % 13; //그만큼 index의 값도 갱신시켜줌.

		if (index >= table_size)
			index = index % table_size; //index가 테이블의 마지막을 만나도 순환적으로 조사할 수 있는 조건
	}

	return -1;
}


void printHash(hashnode*hash_i) { //해시테이블의 삽입결과를 출력하는 함수
	printf_s("--------------------------------\n");
	for (int i = 0; i < table_size; i++) {
		printf_s("[%d]번 \t %d \n", i, hash_i[i].value);

	}
}

int main(void) {
	int input = 0; //입력값
	int i = 0; //삽입횟수
	hashnode hash[table_size];
	for (int a = 0; a < table_size; a++) { //배열 초기화
		hash[a].key = NULL;
		hash[a].value = NULL;
	}

	printf_s("삽입할 숫자 입력 후 엔터를 눌러주세요 : \n");

	while (i < 8) {
		scanf_s("%d", &input); //삽입할 값 입력받기

		//hash구조체에 input이라는 삽입값으로 삽입함수 시행
		hashing(hash, input);

		if (i >= 4)
			printHash(hash);

		i++; //삽입횟수를 1 늘리고 같은 과정 입력받은 개수만큼 반복
	}


	printf("함수가 종료되었습니다.");

}