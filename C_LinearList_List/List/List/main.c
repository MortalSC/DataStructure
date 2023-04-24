#include"List.h"

/* ���Ա��п� */
void test_IsEmpty();

/* ����β�巨 */
void test_PushBack();

/* ����������� */
void test_Print();

/* ����ͷ�巨 */
void test_PushFront();

/* ����βɾ�� */
void test_PopBack();

/* ����ͷɾ�� */
void test_PopFront();

/* ���԰�ֵ���� */
void test_FindByValue();

int main() {
	printf("\n================================================\n");
	test_IsEmpty();

	printf("\n================================================\n");
	test_PushBack();

	printf("\n================================================\n");
	test_Print();

	printf("\n================================================\n");
	test_PushFront();

	printf("\n================================================\n");
	test_PopBack();

	printf("\n================================================\n");
	test_PopFront();

	printf("\n================================================\n");
	test_FindByValue();
	return 0;
}


/* ���Ա��п� */
void test_IsEmpty() {
	printf("���Ա��п�\n");
	List* plist = InitList();

	if (IsEmpty(plist)) {
		printf("����Ϊ�գ�\n");
	}
	else {
		printf("����ǿգ�\n");
	}
}


/* ����β�巨 */
void test_PushBack() {
	printf("����β�巨\n");

	List* plist = InitList();

	for (int i = 1; i <= 10; i++) {
		PushBack(plist, 10 * i);
	}

	if (IsEmpty(plist)) {
		printf("����Ϊ�գ�\n");
	}
	else {
		Print(plist);
	}
}


/* ����������� */
void test_Print() {
	printf("�����������\n");

	List* plist = InitList();

	for (int i = 1; i <= 10; i++) {
		PushBack(plist, 10 * i);
	}

	if (IsEmpty(plist)) {
		printf("����Ϊ�գ�\n");
	}
	else {
		Print(plist);
	}
}

/* ����ͷ�巨 */
void test_PushFront() {
	printf("����ͷ�巨\n");

	List* plist = InitList();

	for (int i = 1; i <= 10; i++) {
		PushBack(plist, 10 * i);
	}

	for (int i = 1; i <= 5; i++) {
		PushFront(plist,  i);
	}

	if (IsEmpty(plist)) {
		printf("����Ϊ�գ�\n");
	}
	else {
		Print(plist);
	}
}

/* ����βɾ�� */
void test_PopBack() {
	printf("����βɾ����1��\n");

	List* plist = InitList();

	for (int i = 1; i <= 10; i++) {
		PushBack(plist, 10 * i);
	}

	for (int i = 1; i <= 5; i++) {
		PushFront(plist, i);
	}

	if (IsEmpty(plist)) {
		printf("����Ϊ�գ�\n");
	}
	else {
		Print(plist);
	}

	PopBack(plist);
	Print(plist);

	printf("����βɾ����2��\n");

	List* pplist = InitList();

	PushBack(pplist, 10);
	if (IsEmpty(pplist)) {
		printf("����Ϊ�գ�\n");
	}
	else {
		Print(pplist);
	}
	PopBack(pplist);
	if (IsEmpty(pplist)) {
		printf("����Ϊ�գ�\n");
	}
	else {
		Print(pplist);
	}
}

/* ����ͷɾ�� */
void test_PopFront() {
	printf("����ͷɾ����1��\n");

	List* plist = InitList();

	for (int i = 1; i <= 10; i++) {
		PushBack(plist, 10 * i);
	}

	for (int i = 1; i <= 5; i++) {
		PushFront(plist, i);
	}

	if (IsEmpty(plist)) {
		printf("����Ϊ�գ�\n");
	}
	else {
		Print(plist);
	}

	PopFront(plist);
	Print(plist);

	printf("����ͷɾ����2��\n");

	List* pplist = InitList();

	PushBack(pplist, 10);
	if (IsEmpty(pplist)) {
		printf("����Ϊ�գ�\n");
	}
	else {
		Print(pplist);
	}
	PopFront(pplist);
	if (IsEmpty(pplist)) {
		printf("����Ϊ�գ�\n");
	}
	else {
		Print(pplist);
	}
}


/* ���԰�ֵ���� */
void test_FindByValue() {
	printf("���԰�ֵ����\n");

	List* plist = InitList();

	for (int i = 1; i <= 10; i++) {
		PushBack(plist, 10 * i);
	}

	if (IsEmpty(plist)) {
		printf("����Ϊ�գ�\n");
	}
	else {
		Print(plist);
	}

	printf("����Ŀ�꣺10����Ԫ�أ�\n");

	printf("��ѯ�����%d\n" ,FindByValue(plist, 10)->data);

	printf("����Ŀ�꣺100��βԪ�أ�\n");
	printf("��ѯ�����%d\n", FindByValue(plist, 100)->data);


	printf("����Ŀ�꣺60������Ԫ�أ�\n");
	printf("��ѯ�����%d\n", FindByValue(plist, 60)->data);



}