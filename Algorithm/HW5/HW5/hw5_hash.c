#include<stdio.h>
#include<stdlib.h>

#define _CRT_SECURE_NO_WARNINGS

#define table_size 13 //hashtable의 사이즈를 미리 정해준다.

typedef struct HashNode {
	int key; //나머지값이 들어갈 위치
	int value; //입력값이 들어갈 위치
}hashnode;

void hashing(hashnode*hash_i,int value_i) { //기본삽입함수
	int key_i = value_i % table_size;

	if (hash_i[key_i].value == NULL) { //mod의 값에 해당하는 배열이 NULL값이면
		hash_i[key_i].key = key_i;		//그 공간에 나머지값 삽입
		hash_i[key_i].value = value_i; //그 공간에 입력값 삽입
	}
	else {
		linear_probing(hash_i, key_i, value_i); //NULL값이 아니라면 선형조사함수 호출
	}
}

int linear_probing(hashnode*hash_p, int key_p, int value_p) { //선형조사

	int i = 0;
	int index = key_p + 1; //다음인덱스부터

	while (index != key_p) { 
		if (hash_p[index].value == NULL) {
			hash_p[index].key = key_p;
			hash_p[index].value = value_p;//삽입함수에서와 같은 방법.
			return 0;
		}

		index++;

		if (index == table_size)
			index = 0; //index가 테이블을 넘을경우 0으로 바꾸어주어서 다시 조사를 이어나간다.
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
	hashnode hash[table_size]; //구조체배열 선언

	for (int a = 0; a < table_size; a++) { //배열 초기화
		hash[a].key = NULL;
		hash[a].value = NULL;
	}

	printf_s("삽입할 숫자 입력 후 엔터를 눌러주세요 : \n");

	while (i < 8) {
		scanf_s("%d", &input); //삽입할 값 입력받기

		hashing(hash, input); //hash구조체에 input이라는 삽입값으로 삽입함수 시행

		if(i>=4)
			printHash(hash); //33을 입력했을때부터 해시테이블 출력.(과제 요구조건)

		i++; //삽입횟수를 1 늘리고 같은 과정 입력받은 값들의 갯수만큼 반복
	}


	printf("함수가 종료되었습니다.");

}