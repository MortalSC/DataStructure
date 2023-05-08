#include"CBinaryTree.h"

/*
	ע������������ʹ��˳��洢��ʽ��ʾ����һ������ڱ�ʾ��ȫ������������
	���㷨������һ���ʹ��˳��洢��ʽ���ռ任ʱ�䣨����ʹ���±���ʽ�㣬��ѯЧ�ʸߣ���

	��ƪʹ�� C ����ʵ����ʽ��������һ��ʵ�ַ�ʽ��
	ע����ͨ����������ɾ���û�ж�����壡����

	��ƪ��ʵ�ֶ�������ǰ�к������������ �� ע�����������У��ս���ӡ��# ��ʶ ��
	��������ֱ�ӡ��ִꡱ��

	��������ǰ�к�����������䷽ʽ��ǰ�к��������� root ���Ĵ�ӡ���������ӽڵ�ʼ������
	ǰ������������ң�
	��������������ң�
	��������������У�
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
	BTNode* root = create_BTree();

	PreOrder(root);
	printf("\n");

	InOrder(root);
	printf("\n");

	PostOrder(root);
	printf("\n");

	return 0;
}