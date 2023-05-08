#pragma

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

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

typedef int DataType;					// �Զ�����������
	
typedef struct BinaryTreeNode {
	DataType data;
	struct BinaryTreeNode* leftChild;			// ���ӽ��
	struct BinaryTreeNode* rightChild;		// �Һ��ӽ��
}BTNode;

/* ������������� */
BTNode* CreateNode(DataType data);

/* ǰ������������� */
void PreOrder(BTNode* root);

/* ��������������� */
void InOrder(BTNode* root);

/* ��������������� */
void PostOrder(BTNode* root);