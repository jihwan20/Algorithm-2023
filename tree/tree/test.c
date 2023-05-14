#include <stdio.h>
#include "tree.h"

int testCode()
{
	int num;
    Node* root = makeTree(); // Ʈ�� ����

	// preorder inorder postorder ��� ���
	printNode(root);

	// Ư�� �� ã�� �Լ� ȣ��
	printf("��尪 �Է� >> ");
	scanf("%d", &num);

	Node* foundNode = findNode(num, root);

	if (foundNode != NULL) {
		printf("��尪 %d�� ã�ҽ��ϴ�.\n", num);
	}
	else {
		printf("��尪 %d�� ã�� ���߽��ϴ�.\n", num);
	}

	// ��� ���� �Լ� ȣ��
	printf("��尪 �Է� >> ");
	scanf("%d", &num);

	Node* newNode = createNode(num);

	Node* insertedNode = insertLeftNode(root->right, newNode);
	if (insertedNode != NULL) {
		printf("��尪 %d�� �����߽��ϴ�. \n", num);
	}
	else {
		printf("��尪 %d�� �������� ���߽��ϴ�.\n", num);
	}
}

