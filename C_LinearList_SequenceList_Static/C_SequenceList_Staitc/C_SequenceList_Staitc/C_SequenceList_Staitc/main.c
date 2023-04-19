#include "C_SequenceList_Static.h"


/* ���Գ�ʼ��һ��˳��� */
void test_InitSeList();

/* ���Ի�ȡ���������͵�ǰԪ�ظ��� */
void test_GetInfo();

/* ����β������ */
void test_PushBack();

/* ����ͷ������ */
void test_PushFront();

/* ����βɾ�� */
void test_PopBack();

/* ����ͷɾ�� */
void test_PopFront();

/* ����ָ��λ�β��� */
void test_InsertPos();

/* ����ָ��λ��ɾ�� */
void test_DelPos();

/* ����Ԫ�أ��������� */
void test_GetElemPos();

/* ����ָ������������Ԫ�� */
void test_GetElemByPos();

int main() {

	printf("==============================================\n");
	test_InitSeList();

	printf("==============================================\n");
	test_GetInfo();

	printf("==============================================\n");
	test_PushBack();

	printf("==============================================\n");
	test_PushFront();

	printf("==============================================\n");
	test_PopBack();

	printf("==============================================\n");
	test_PopFront();

	printf("==============================================\n");
	test_InsertPos();

	printf("==============================================\n");
	test_DelPos();

	printf("==============================================\n");
	test_GetElemPos();

	printf("==============================================\n");
	test_GetElemByPos();

	return 0;
}


/* ��ʼ��һ��˳��� */
void test_InitSeList() {
	SeList sl;
	InitSeList(&sl);
}

/* ���Ի�ȡ���������͵�ǰԪ�ظ��� */
void test_GetInfo() {
	SeList sl;
	InitSeList(&sl);
	printf("%d \n", GetCapacity(sl));
	printf("%d \n", GetSize(sl));
}

/* ����β������ */
void test_PushBack() {
	SeList sl;
	InitSeList(&sl);

	for (int i = 0; i < 10; i++) {
		PushBack(&sl, i + 1);
		printf("%d ", GetCapacity(sl));
		printf("%d ��", GetSize(sl));
		TravelSeList(sl);
	}
}

/* ����ͷ������ */
void test_PushFront() {
	SeList sl;
	InitSeList(&sl);

	for (int i = 0; i < 10; i++) {
		PushFront(&sl, i + 1);
		printf("%d ", GetCapacity(sl));
		printf("%d ��", GetSize(sl));
		TravelSeList(sl);
	}
}


/* ����βɾ�� */
void test_PopBack() {
	SeList sl;
	InitSeList(&sl);

	for (int i = 0; i < 10; i++) {
		PushFront(&sl, i + 1);
	}
	TravelSeList(sl);

	PopBack(&sl);
	TravelSeList(sl);
}

/* ����ͷɾ�� */
void test_PopFront() {
	SeList sl;
	InitSeList(&sl);

	for (int i = 0; i < 10; i++) {
		PushFront(&sl, i + 1);
	}
	TravelSeList(sl);

	PopFront(&sl);
	TravelSeList(sl);
}


/* ����ָ��λ�β��� */
void test_InsertPos() {
	SeList sl;
	InitSeList(&sl);

	for (int i = 0; i < 10; i++) {
		PushFront(&sl, i + 1);
	}
	TravelSeList(sl);
	printf("�� 2 ��λ�ò��룺");
	InsertPos(&sl, 2,100);
	TravelSeList(sl);
}

/* ����ָ��λ��ɾ�� */
void test_DelPos() {
	SeList sl;
	InitSeList(&sl);

	for (int i = 0; i < 10; i++) {
		PushFront(&sl, i + 1);
	}
	TravelSeList(sl);
	printf("ɾ������ 2 ����");
	DelPos(&sl,2);
	TravelSeList(sl);
}


/* ����Ԫ�أ��������� */
void test_GetElemPos() {
	SeList sl;
	InitSeList(&sl);

	for (int i = 0; i < 10; i++) {
		PushFront(&sl, i + 1);
	}
	TravelSeList(sl);
	printf("5 ������ֵ��%d\n", GetElemPos(&sl,5));
}

/* ����ָ������������Ԫ�� */
void test_GetElemByPos() {
	SeList sl;
	InitSeList(&sl);

	for (int i = 0; i < 10; i++) {
		PushFront(&sl, i + 1);
	}
	TravelSeList(sl);
	printf("����Ϊ 5 ��Ԫ�أ�%d\n", GetElemByPos(&sl, 5));
}