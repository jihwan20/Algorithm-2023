#include <stdio.h>
#include "tree.h"

int testCode()
{
	int num;
    Node* root = makeTree(); // 트리 생성

	// preorder inorder postorder 노드 출력
	printNode(root);

	// 특정 값 찾기 함수 호출
	printf("노드값 입력 >> ");
	scanf("%d", &num);

	Node* foundNode = findNode(num, root);

	if (foundNode != NULL) {
		printf("노드값 %d을 찾았습니다.\n", num);
	}
	else {
		printf("노드값 %d을 찾지 못했습니다.\n", num);
	}

	// 노드 삽입 함수 호출
	printf("노드값 입력 >> ");
	scanf("%d", &num);

	Node* newNode = createNode(num);

	Node* insertedNode = insertLeftNode(root->right, newNode);
	if (insertedNode != NULL) {
		printf("노드값 %d를 삽입했습니다. \n", num);
	}
	else {
		printf("노드값 %d를 삽입하지 못했습니다.\n", num);
	}
}

