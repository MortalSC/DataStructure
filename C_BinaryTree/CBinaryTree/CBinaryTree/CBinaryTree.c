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

/* ������������� */
BTNode* CreateNode(DataType data) {
	// �ڴ�����
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	assert(node);

	node->data = data;
	node->leftChild = NULL;
	node->rightChild = NULL;

	return node;
}



/* ǰ������������� */
void PreOrder(BTNode* root) {
	if (root == NULL) {		// ��Ϊ�գ�
		printf("# ");
		return;
	}
	printf("%d ", root->data);
	PreOrder(root->leftChild);
	PreOrder(root->rightChild);
}

/* ��������������� */
void InOrder(BTNode* root) {
	if (root == NULL) {
		printf("# ");
		return;
	}
	InOrder(root->leftChild);
	printf("%d ", root->data);
	InOrder(root->rightChild);
}

/* ��������������� */
void PostOrder(BTNode* root) {
	if (root == NULL) {
		printf("# ");
		return;
	}
	PostOrder(root->leftChild);
	PostOrder(root->rightChild);
	printf("%d ", root->data);

}