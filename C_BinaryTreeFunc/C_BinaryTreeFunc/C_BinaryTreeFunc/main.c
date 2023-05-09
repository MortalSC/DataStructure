#include"BinaryTreeFunc.h"

/*
	��ƪ���ݽ�ʵ�ֶ������е�һЩ�����Է�����
		�磺�����������Ҷ�ӽ�����������ָ��ֵ�� ��� K �� ����������ȡ���ĸ߶� / ���
		ָ��ֵ���ҡ��������Ƿ���ȡ��Ƿ�Ϊ�Գ��� / �������������ж�

	��ƪ�еĲ���ʾ��ֱ���ִ깹�죡
*/

/* �����ִ����ʵ�� */
BTNode* create_BTree() {
	BTNode* root = CreateNode(0);
	BTNode* node1 = CreateNode(1);
	BTNode* node2 = CreateNode(2);
	BTNode* node3 = CreateNode(4);
	BTNode* node4 = CreateNode(3);
	BTNode* node5 = CreateNode(5);
	BTNode* node6 = CreateNode(6);

	/*	ʵ���ṹ��
						1
				2				4
			3		��		5		6
		��	��			��	��		��	��
	*/

	root = node1;
	node1->leftChild = node2;
	node2->leftChild = node4;
	node1->rightChild = node3;
	node3->leftChild = node5;
	node3->rightChild = node6;
	return root;
}

int main() {

	// �������Զ�����
	BTNode* root = create_BTree();

	printf("�����Ľ�����Ϊ��%d\n\n", GetTreeSize(root));
	printf("������Ҷ�ӽ�����Ϊ��%d\n\n", GetTreeLeafSize(root));

	printf("�����ĵ�һ�������Ϊ��%d\n\n", GetLevelKSize(root, 1));
	printf("�����ĵڶ��������Ϊ��%d\n\n", GetLevelKSize(root, 2));
	printf("�����ĵ����������Ϊ��%d\n\n", GetLevelKSize(root, 3));
	printf("�����ĵ��Ĳ������Ϊ��%d\n\n", GetLevelKSize(root, 4));


	BTNode* node1 = TreeFind(root, 3);
	if (node1)
		printf("���ң�3�������%p\n", &node1);
	else
		printf("���ң�3�������NULL\n");


	BTNode* node2 = TreeFind(root, 10);
	if (node2)
		printf("���ң�10�������%p\n", &node2);
	else
		printf("���ң�10�������NULL\n");


	printf("���ĸ߶�Ϊ��%d\n\n", GetTreeDepth(root));

	return 0;
}