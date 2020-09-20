#include<stdio.h>
#include<stdlib.h>




typedef struct _TreeNode { //_TreeNode 구조체 생성
	char value; //입력받은 알파벳을 저장하는 변수
	//이하는 자기참조구조체
	struct _TreeNode *LeftChild;
	struct _TreeNode *RightChild; 

}TreeNode;



int searchNode(char v, TreeNode* t) { //노드를 탐색하는 함수
	for (int i = 0; i < 26; i++) {
		if (v == t[i].value) //입력받은 알파벳을 value로 갖고있는 노드가 있는지 검색
			return i; // 존재한다면 노드의 순번을 return
	}
	return -1; //존재하지 않는다면 -1 return
}

void treeInOrder(TreeNode* t) { //트리를 중위 순회 방식으로 출력하는 함수
	if (t->LeftChild != NULL) {
		treeInOrder(t->LeftChild);   //input된 노드의 왼쪽 자식노드가 NULL값이 아니라면 왼쪽 자식노드로 재귀함수.
	}
	printf("%c", t->value); //입력받은 노드의 value값 출력.
	if (t->RightChild != NULL) {
		treeInOrder(t->RightChild);   //input된 노드의 오른쪽 자식노드가 NULL값이 아니라면 오른쪽 자식노드로 재귀함수.
	}
}

int main() {
	TreeNode trees[26]; //TreeNode형태의 구조체배열 trees 선언
	int num; //Node의 개수를 입력받을 변수

	for (int i = 0; i < 26; i++) { //구조체 배열 초기화
		trees[i].value = NULL;
	} 

	scanf("%d", &num); //앞으로 입력받을 node의 전체 개수를 입력받는다
	getchar();
	
	for (int i = 0; i < num; i++)
	{
		char parent, leftChild, rightChild;
		scanf("%c %c %c", &parent, &leftChild, &rightChild);
		getchar(); //명세에 나와있던대로. 

		int p_index, l_index, r_index; //searchNode함수를 실행시킨 뒤 return값을 임시저장할 변수


		p_index = searchNode(parent, trees); //parent 값으로 searchNode를 실행시킨 뒤 받은 return값을 p_index에 저장
		
		
		
		if (p_index == -1) { //parent 값이 기존 노드들의 value값 중 같은 게 없다면
			p_index = searchNode(NULL, trees); //value값이 NULL값인 노드가 몇번째에 존재하는지 return받은 값을 p_index에 저장
			trees[p_index].value = parent; //parent값을 위에서 알려준 'p_index'번째의 노드의 value값에 저장
		}

		if (leftChild == '.') {   //leftChild값으로 '.'이 들어오면 p_index번째의 노드의 왼쪽 자식노드엔 NULL.
			trees[p_index].LeftChild = NULL;
		}
		else {  //'.'이 아닌 값이 들어오면 이 값은 다른 노드의 value로 존재했던 값인지 탐색.
			l_index = searchNode(leftChild, trees);

			if (l_index == -1) { //존재하지 않는다면 parent와 같이 빈 노드에 추가.
				l_index = searchNode(NULL, trees);
				trees[l_index].value = leftChild;
			}
			trees[p_index].LeftChild = &trees[l_index]; //lefrChild의 값이 들어간 노드의 주소를 parent값이 들어갔던 노드의 LeftChild 자기참조구조체에 대입.
		}

		//이하 reightChild에 관한건 leftChild와 같다

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

	treeInOrder(&trees[0]); //중위순회방식의 출력함수 실행

	printf("\n");


	return 0;
}