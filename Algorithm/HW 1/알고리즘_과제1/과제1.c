#include<stdio.h>
#include<stdlib.h>




typedef struct _TreeNode { //_TreeNode ����ü ����
	char value; //�Է¹��� ���ĺ��� �����ϴ� ����
	//���ϴ� �ڱ���������ü
	struct _TreeNode *LeftChild;
	struct _TreeNode *RightChild; 

}TreeNode;



int searchNode(char v, TreeNode* t) { //��带 Ž���ϴ� �Լ�
	for (int i = 0; i < 26; i++) {
		if (v == t[i].value) //�Է¹��� ���ĺ��� value�� �����ִ� ��尡 �ִ��� �˻�
			return i; // �����Ѵٸ� ����� ������ return
	}
	return -1; //�������� �ʴ´ٸ� -1 return
}

void treeInOrder(TreeNode* t) { //Ʈ���� ���� ��ȸ ������� ����ϴ� �Լ�
	if (t->LeftChild != NULL) {
		treeInOrder(t->LeftChild);   //input�� ����� ���� �ڽĳ�尡 NULL���� �ƴ϶�� ���� �ڽĳ��� ����Լ�.
	}
	printf("%c", t->value); //�Է¹��� ����� value�� ���.
	if (t->RightChild != NULL) {
		treeInOrder(t->RightChild);   //input�� ����� ������ �ڽĳ�尡 NULL���� �ƴ϶�� ������ �ڽĳ��� ����Լ�.
	}
}

int main() {
	TreeNode trees[26]; //TreeNode������ ����ü�迭 trees ����
	int num; //Node�� ������ �Է¹��� ����

	for (int i = 0; i < 26; i++) { //����ü �迭 �ʱ�ȭ
		trees[i].value = NULL;
	} 

	scanf("%d", &num); //������ �Է¹��� node�� ��ü ������ �Է¹޴´�
	getchar();
	
	for (int i = 0; i < num; i++)
	{
		char parent, leftChild, rightChild;
		scanf("%c %c %c", &parent, &leftChild, &rightChild);
		getchar(); //���� �����ִ����. 

		int p_index, l_index, r_index; //searchNode�Լ��� �����Ų �� return���� �ӽ������� ����


		p_index = searchNode(parent, trees); //parent ������ searchNode�� �����Ų �� ���� return���� p_index�� ����
		
		
		
		if (p_index == -1) { //parent ���� ���� ������ value�� �� ���� �� ���ٸ�
			p_index = searchNode(NULL, trees); //value���� NULL���� ��尡 ���°�� �����ϴ��� return���� ���� p_index�� ����
			trees[p_index].value = parent; //parent���� ������ �˷��� 'p_index'��°�� ����� value���� ����
		}

		if (leftChild == '.') {   //leftChild������ '.'�� ������ p_index��°�� ����� ���� �ڽĳ�忣 NULL.
			trees[p_index].LeftChild = NULL;
		}
		else {  //'.'�� �ƴ� ���� ������ �� ���� �ٸ� ����� value�� �����ߴ� ������ Ž��.
			l_index = searchNode(leftChild, trees);

			if (l_index == -1) { //�������� �ʴ´ٸ� parent�� ���� �� ��忡 �߰�.
				l_index = searchNode(NULL, trees);
				trees[l_index].value = leftChild;
			}
			trees[p_index].LeftChild = &trees[l_index]; //lefrChild�� ���� �� ����� �ּҸ� parent���� ���� ����� LeftChild �ڱ���������ü�� ����.
		}

		//���� reightChild�� ���Ѱ� leftChild�� ����

		if (rightChild == '.') { 
			trees[p_index].RightChild = NULL;
		}
		else {
			r_index = searchNode(rightChild, trees);

			if (r_index == -1) {
				r_index = searchNode(NULL, trees);
				trees[r_index].value = rightChild;
			}
			trees[p_index].RightChild = &trees[r_index];
		}
		
	}

	printf("\n");

	treeInOrder(&trees[0]); //������ȸ����� ����Լ� ����

	printf("\n");


	return 0;
}