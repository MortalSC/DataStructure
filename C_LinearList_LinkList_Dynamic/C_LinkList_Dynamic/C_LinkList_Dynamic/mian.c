#include"C_LinkList_Dynamic.h"

/* ���Գ�ʼ��һ������ */
void test_InitLinkList();

/* ����β�巨 */
void test_LinkListPushBack();

/* ����ͷ�巨 */
void test_LinkListPushFront();

/* ����βɾ�� */
void test_LinkListPopBack();

/* ����ͷɾ�� */
void test_LinkListPopFront();

/* ���Ի�ȡ�� */
void test_GetLength();

/* ���԰�ֵ���� */
void test_FindByValue();

/* ����ָ��λ�ò��� */
void test_FindByPos();

/* ����ָ��λ��֮����� */
void test_InsertPos();

/* ����ָ��λ��ɾ�� */
void test_DelPos();

int main() {

	printf("====================================\n");
	test_InitLinkList();

	printf("====================================\n");
	test_LinkListPushBack();

	printf("====================================\n");
	test_LinkListPushFront();

	printf("====================================\n");
	test_LinkListPopBack();

	printf("====================================\n");
	test_LinkListPopFront();

	printf("====================================\n");
	test_GetLength();

	printf("====================================\n");
	test_FindByValue();

	printf("====================================\n");
	test_FindByPos();

	printf("====================================\n");
	test_InsertPos();

	printf("====================================\n");
	test_DelPos();

	return 0;
}

/* ���Գ�ʼ��һ������ */
void test_InitLinkList() {
	LstNode* plist = InitLinkList();
	ListPrint(plist);
}

/* ����β�巨 */
void test_LinkListPushBack() {
	LstNode* plist = InitLinkList();

	LinkListPushBack(&plist, 10);

	for (int i = 2; i <= 10; i++) {
		LinkListPushBack(&plist, i * 10);
	}

	ListPrint(plist);
}

/* ����ͷ�巨 */
void test_LinkListPushFront() {
	LstNode* plist = InitLinkList();

	LinkListPushFront(&plist, 1);

	for (int i = 2; i <= 10; i++) {
		LinkListPushFront(&plist, i);
	}

	ListPrint(plist);
}

/* ����βɾ�� */
void test_LinkListPopBack() {

	LstNode* plist = InitLinkList();

#if 0		/* ������������Ϊ��1 */
	LinkListPushBack(&plist, 10);
	ListPrint(plist);
#else		/* ���������������ڣ�1 */
	for (int i = 1; i <= 10; i++) {
		LinkListPushBack(&plist, i * 10);
	}
	ListPrint(plist);
#endif

	LinkListPopBack(&plist);
	ListPrint(plist);

}


/* ����ͷɾ�� */
void test_LinkListPopFront() {
	LstNode* plist = InitLinkList();

#if 0		/* ������������Ϊ��1 */
	LinkListPushBack(&plist, 10);
	ListPrint(plist);
#else		/* ���������������ڣ�1 */
	for (int i = 1; i <= 10; i++) {
		LinkListPushBack(&plist, i * 10);
	}
	ListPrint(plist);
#endif

	LinkListPopFront(&plist);
	ListPrint(plist);
}


/* ���Ի�ȡ�� */
void test_GetLength() {
	LstNode* plist = InitLinkList();
	printf("length: %d\n", GetLength(plist));

	for (int i = 1; i <= 10; i++) {
		LinkListPushBack(&plist, i * 10);
	}
	ListPrint(plist);
	printf("length: %d\n", GetLength(plist));
}

/* ���԰�ֵ���� */
void test_FindByValue() {
	LstNode* plist = InitLinkList();
	for (int i = 1; i <= 10; i++) {
		LinkListPushBack(&plist, i * 10);
	}
	ListPrint(plist);

	printf("Ŀ��ֵΪ��20\n");
	if (FindByValue(plist, 20)) {
		printf("�ҵ�Ŀ�ֵ꣬Ϊ��%d\n", FindByValue(plist, 20)->data);
	}
	else {
		printf("δ�ҵ�Ŀ��ֵ �� ����Ϊ�գ�\n");
	}

	printf("Ŀ��ֵΪ��1\n");
	if (FindByValue(plist, 1)) {
		printf("�ҵ�Ŀ�ֵ꣬Ϊ��%d\n", FindByValue(plist, 20)->data);
	}
	else {
		printf("δ�ҵ�Ŀ��ֵ �� ����Ϊ�գ�\n");
	}
}


/* ����ָ��λ�ò��� */
void test_FindByPos() {
	LstNode* plist = InitLinkList();
	for (int i = 1; i <= 10; i++) {
		LinkListPushBack(&plist, i * 10);
	}
	ListPrint(plist);

	printf("Ŀ��λ��Ϊ��20\n");
	if (FindByPos(plist, 20)) {
		printf("�ҵ�Ŀ�ֵ꣬Ϊ��%d\n", FindByPos(plist, 20)->data);
	}
	else {
		printf("δ�ҵ�Ŀ��ֵ��\n");
	}

	printf("Ŀ��λ��Ϊ��1\n");
	if (FindByPos(plist, 1)) {
		printf("�ҵ�Ŀ�ֵ꣬Ϊ��%d\n", FindByPos(plist, 1)->data);
	}
	else {
		printf("δ�ҵ�Ŀ��ֵ��\n");
	}
}


/* ����ָ��λ��֮����� */
void test_InsertPos() {
	LstNode* plist = InitLinkList();

	if (0) {		/* ���Կձ���� */
		InsertPos(&plist, 1, 111);
	}

	for (int i = 1; i <= 5; i++) {
		LinkListPushBack(&plist, i * 10);
	}
	ListPrint(plist);

	printf("β�����룺\n");
	InsertPos(&plist, 5, 111);
	ListPrint(plist);

	printf("ͷ�����룺\n");
	InsertPos(&plist, 1, 222);
	ListPrint(plist);

	printf("�в����룺\n");
	InsertPos(&plist, 3, 333);
	ListPrint(plist);
}

/* ����ָ��λ��ɾ�� */
void test_DelPos() {
	LstNode* plist = InitLinkList();

	if (0) {		/* ���Կձ���� */
		DelPos(&plist, 1);
	}

	for (int i = 1; i <= 10; i++) {
		LinkListPushBack(&plist, i * 10);
	}
	ListPrint(plist);

	printf("β��ɾ����\n");
	printf("��ɾ���Ľ��ֵΪ��%d\n", DelPos(&plist, 10)->data);
	ListPrint(plist);

	printf("�в�ɾ����\n");
	printf("��ɾ���Ľ��ֵΪ��%d\n", DelPos(&plist, 4)->data);
	ListPrint(plist);

	printf("ͷ��ɾ����\n");
	printf("��ɾ���Ľ��ֵΪ��%d\n", DelPos(&plist, 1)->data);
	ListPrint(plist);

}