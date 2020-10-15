#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode { //집합의 각 숫자를 포함할 노드를 구조체로 생성
	char value;
	int rank;
	struct TreeNode *parent;
}treenode;

int Union(treenode *tnode_i,treenode *tnode_j) { //노드끼리 연결시키는 함수
	int rank_i = tnode_i->rank;
	int rank_j = tnode_j->rank;

	if (rank_i < rank_j) { //rank가 다를경우의 상황
		tnode_i->parent = tnode_j;
		return 0; //함수종료
	}

	if (rank_i == rank_j) { //랭크가 같다면 둘 중 어느 노드가 부모가 되어도 상관없지만 왼쪽에 입력한 노드가 부모가 되도록 실행
		tnode_i->rank=tnode_j->rank+1; //부모가 되는 노드의 랭크가 하나 올라간다.
	}
	tnode_j->parent = tnode_i; //랭크가 같을때와 tnode_j의 랭크가 더 높을때 이와같이 실행

	return 0;
}

treenode * Find(treenode tnode[9], char alphabet) { //알파벳을 통해 노드의 인덱스로 접근할 수 있도록 설계
	for (int i = 0; i < 9; i++) {
		if (tnode[i].value == alphabet) {
			return &tnode[i];
		}
	}
}

int main(void) {
	treenode tnode[9] = { {'a', 0}, {'b', 0},
							{'c', 0},
							{'d', 0},{'e', 0},
							{'f', 0},{'g', 0},{'h', 0},{'i', 0} };

	for (int i = 0; i < 9; i++) {
		tnode[i].parent = &tnode[i]; //treenode에 대해 먼저 선언해준 후 각 노드의 포인터들을 자기자신을 가리키도록 초기화
	}

	Union(Find(tnode, 'a'), Find(tnode, 'b'));
	Union(Find(tnode, 'd'), Find(tnode, 'e'));
	Union(Find(tnode, 'f'), Find(tnode, 'g'));
	Union(Find(tnode, 'f'), Find(tnode, 'h'));
	Union(Find(tnode, 'f'), Find(tnode, 'i')); //문제에서 제시된 그림대로 초기집합 union

	// (a) solution
	printf("<(a) Before Union>\n");
	for (int j = 0; j < 3; j++) {
		printf("value : %c   rank : %d   parent : %c\n", tnode[j].value, tnode[j].rank, tnode[j].parent->value);
	}

	Union(Find(tnode, 'a'), Find(tnode, 'c')); //문제의 (a)부분 union

	printf("<(a) After Union>\n");
	for (int j = 0; j < 3; j++) {
		printf("value : %c   rank : %d   parent : %c\n", tnode[j].value, tnode[j].rank, tnode[j].parent->value);
	}
	printf("\n---------------------------------\n\n");

	// (b) solution
	printf("<(b) Before Union>\n");
	for (int j = 3; j < 9; j++) {
		printf("value : %c   rank : %d   parent : %c\n", tnode[j].value, tnode[j].rank, tnode[j].parent->value);
	}

	Union(Find(tnode, 'd'), Find(tnode, 'f'));

	printf("<(b) After Union>\n");
	for (int j = 3; j < 9; j++) {
		printf("value : %c   rank : %d   parent : %c\n", tnode[j].value, tnode[j].rank, tnode[j].parent->value);
	}
	printf("\n---------------------------------\n\n");


	// (a), (b) Union solution
	printf("<(a)+(b) Before Union>\n");
	for (int j = 0; j < 9; j++) {
		printf("value : %c   rank : %d   parent : %c\n", tnode[j].value, tnode[j].rank, tnode[j].parent->value);
	}
	Union(Find(tnode, 'a'), Find(tnode, 'd'));
	printf("<(a)+(b) After Union>\n");
	for (int j = 0; j < 9; j++) {
		printf("value : %c   rank : %d   parent : %c\n", tnode[j].value, tnode[j].rank, tnode[j].parent->value);
	}
	printf("\n---------------------------------\n\n");


}