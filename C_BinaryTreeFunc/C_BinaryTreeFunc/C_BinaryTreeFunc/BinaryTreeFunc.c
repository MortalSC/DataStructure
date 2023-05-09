#include"BinaryTreeFunc.h"

/*
	��ƪ���ݽ�ʵ�ֶ������е�һЩ�����Է�����
		�磺�����������Ҷ�ӽ�����������ָ��ֵ�� ��� K �� ����������ȡ���ĸ߶� / ���
		ָ��ֵ���ҡ��������Ƿ���ȡ��Ƿ�Ϊ�Գ��� / �������������ж�

	��ƪ�еĲ���ʾ��ֱ���ִ깹�죡
*/

/* ������� */
BTNode* CreateNode(DataType data)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	assert(node);
	node->leftChild = NULL;
	node->rightChild = NULL;
	node->data = data;
	return node;
}

/* ��ȡ���Ĵ�С����������������˼· */
int GetTreeSize(BTNode* root) {
	return root == NULL ? 
		0 : GetTreeSize(root->leftChild) + GetTreeSize(root->rightChild) + 1;
}

/* ��ȡҶ�ӽ��ĸ��� */
/* Ҷ�ӽ�㣺�����������ǿգ� */
int GetTreeLeafSize(BTNode* root) {
	if (root == NULL) return 0;
	if (root->leftChild == NULL && root->rightChild == NULL) return 1;
	return GetTreeLeafSize(root->leftChild) + GetTreeLeafSize(root->rightChild);
}

/* ��� K �� ������ */
int GetLevelKSize(BTNode* root, int k) {
	assert(k >= 1);
	if (root == NULL) return 0;
	if (k == 1) return 1;
	return GetLevelKSize(root->leftChild, k - 1) + GetLevelKSize(root->rightChild, k - 1);
}

/* ����ָ��ֵ��� */
BTNode* TreeFind(BTNode* root, int target) {
	if (root == NULL) return NULL;			// ��Ϊ����ֱ�ӷ���
	if (root->data == target) {
		return root;
	}

	BTNode* ret1 = TreeFind(root->leftChild, target);
	if(ret1) return ret1;

	BTNode* ret2 = TreeFind(root->rightChild, target);
	if (ret2) return ret2;

	return NULL;
}

/* ��ȡ���ĸ߶� / ��� */
/*
	����ת�����������ĸ߶ȣ����ո߶� = �����߶� + 1������
	��ʾ��ʹ�ú�������
*/
int GetTreeDepth(BTNode* root) {
	if (root == NULL) return 0;
	int leftDepth = GetTreeDepth(root->leftChild);
	int rightDepth = GetTreeDepth(root->rightChild);

	return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
}

/* �������Ƿ���� */
bool IsEqual(BTNode* p, BTNode* q) {
	// ע�������Ϊ�գ�����
	if (p == NULL && q == NULL) return true;
	if (p == NULL || q == NULL) return false;
	if (p->data != q->data) return false;
	return IsEqual(q->leftChild, p->leftChild) && IsEqual(q->rightChild, p->rightChild);
}


/* �Ƿ�Ϊ�Գ��� / ������ */
bool _IsEqual(BTNode* q, BTNode* p) {
	if (q == NULL && p == NULL) return true;
	if (q == NULL || p == NULL) return false;
	if (q->data != p->data) return false;
	return _IsEqual(q->leftChild, p->rightChild) && _IsEqual(q->rightChild, p->leftChild);
}
bool isSymmetric(BTNode* root) {
	if (root == NULL) return true;
	return _IsEqual(root->leftChild, root->rightChild);
}


/* �����ж� */
bool ChildTree(BTNode* root, BTNode* subRoot) {
	if (root == NULL) return false;
	return IsEqual(root, subRoot) || IsEqual(root->leftChild, subRoot) || IsEqual(root->rightChild, subRoot);
}