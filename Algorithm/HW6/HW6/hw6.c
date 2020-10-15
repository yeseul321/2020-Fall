#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode { //������ �� ���ڸ� ������ ��带 ����ü�� ����
	char value;
	int rank;
	struct TreeNode *parent;
}treenode;

int Union(treenode *tnode_i,treenode *tnode_j) { //��峢�� �����Ű�� �Լ�
	int rank_i = tnode_i->rank;
	int rank_j = tnode_j->rank;

	if (rank_i < rank_j) { //rank�� �ٸ������ ��Ȳ
		tnode_i->parent = tnode_j;
		return 0; //�Լ�����
	}

	if (rank_i == rank_j) { //��ũ�� ���ٸ� �� �� ��� ��尡 �θ� �Ǿ ��������� ���ʿ� �Է��� ��尡 �θ� �ǵ��� ����
		tnode_i->rank=tnode_j->rank+1; //�θ� �Ǵ� ����� ��ũ�� �ϳ� �ö󰣴�.
	}
	tnode_j->parent = tnode_i; //��ũ�� �������� tnode_j�� ��ũ�� �� ������ �̿Ͱ��� ����

	return 0;
}

treenode * Find(treenode tnode[9], char alphabet) { //���ĺ��� ���� ����� �ε����� ������ �� �ֵ��� ����
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
		tnode[i].parent = &tnode[i]; //treenode�� ���� ���� �������� �� �� ����� �����͵��� �ڱ��ڽ��� ����Ű���� �ʱ�ȭ
	}

	Union(Find(tnode, 'a'), Find(tnode, 'b'));
	Union(Find(tnode, 'd'), Find(tnode, 'e'));
	Union(Find(tnode, 'f'), Find(tnode, 'g'));
	Union(Find(tnode, 'f'), Find(tnode, 'h'));
	Union(Find(tnode, 'f'), Find(tnode, 'i')); //�������� ���õ� �׸���� �ʱ����� union

	// (a) solution
	printf("<(a) Before Union>\n");
	for (int j = 0; j < 3; j++) {
		printf("value : %c   rank : %d   parent : %c\n", tnode[j].value, tnode[j].rank, tnode[j].parent->value);
	}

	Union(Find(tnode, 'a'), Find(tnode, 'c')); //������ (a)�κ� union

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