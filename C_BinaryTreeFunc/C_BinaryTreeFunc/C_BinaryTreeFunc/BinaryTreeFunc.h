#pragma

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>

/* 
	��ƪ���ݽ�ʵ�ֶ������е�һЩ�����Է�����
		�磺�����������Ҷ�ӽ�����������ָ��ֵ�� ��� K �� ����������ȡ���ĸ߶� / ���
		ָ��ֵ���ҡ��������Ƿ���ȡ��Ƿ�Ϊ�Գ��� / �������������ж�

	��ƪ�еĲ���ʾ��ֱ���ִ깹�죡
*/

typedef int DataType;

typedef struct BinaryTreeNode {
	struct BinaryTreeNode* leftChild;
	struct BinaryTreeNode* rightChild;
	DataType data;
}BTNode;

/* ������� */
BTNode* CreateNode(DataType data);

/* ��ȡ���Ĵ�С����������������˼· */
int GetTreeSize(BTNode* root);

/* ��ȡҶ�ӽ��ĸ��� */
int GetTreeLeafSize(BTNode* root);

/* ��� K �� ������ */
int GetLevelKSize(BTNode* root, int k);

/* ��ȡ���ĸ߶� / ��� */
int GetTreeDepth(BTNode* root);

/* ����ָ��ֵ��� */
BTNode* TreeFind(BTNode* root, int target);

/* �������Ƿ���� */
bool IsEqual(BTNode* p, BTNode* q);

/* �Ƿ�Ϊ�Գ��� / ������ */
bool _IsEqual(BTNode* q, BTNode* p);
bool isSymmetric(BTNode* root);

/* �����ж� */
bool ChildTree(BTNode* root, BTNode* subRoot);