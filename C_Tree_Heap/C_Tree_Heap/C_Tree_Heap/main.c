#include"CTreeHeap.h"

/* ���Դ����Ѽ���� */
void test_create_push() {
	HP hp;
	HeapInit(&hp);
	DataType array[] = { 27,15,19,18,28,34,65,49,25,37 };
	for (int i = 0; i < sizeof(array) / sizeof(DataType); i++) {
		PushHeap(&hp, array[i]);
	}
	PrintHeap(&hp);
}

/* ���Գ��� */
void test_pop() {
	HP hp;
	HeapInit(&hp);

	PrintHeap(&hp);
	PopHeap(&hp);

	DataType array[] = { 27,15,19,18,28,34,65,49,25,37 };
	for (int i = 0; i < sizeof(array) / sizeof(DataType); i++) {
		PushHeap(&hp, array[i]);
	}
	PrintHeap(&hp);
	PopHeap(&hp);
	PrintHeap(&hp);

}

/* ���Ի�ȡ�Ѷ�Ԫ�� / �Ѵ�С */
void test_gettop_getsize() {
	HP hp;
	HeapInit(&hp);

	DataType array[] = { 27,15,19,18,28,34,65,49,25,37 };
	for (int i = 0; i < sizeof(array) / sizeof(DataType); i++) {
		PushHeap(&hp, array[i]);
	}
	PrintHeap(&hp);
	printf("�Ѷ�Ԫ�أ�%d\n", HeapTop(&hp));

	printf("�Ѷ���С��%d\n", GetSize(&hp));
}

/* ��������ԣ�ʹ���ֳɵĴ������ */
void test_HeadSort() {
	// ���׶ˣ��ռ临�Ӷȸߡ�δ������ø������飬�����½��ѣ�ͨ�������Ը���ԭ���顿��

	HP hp;
	HeapInit(&hp);

	DataType array[] = { 27,15,19,18,28,34,65,49,25,37 };
	for (int i = 0; i < sizeof(array) / sizeof(DataType); i++) {
		PushHeap(&hp, array[i]);
	}
	int i = 0;
	while (!IsEmpty(&hp)) {
		array[i++] = HeapTop(&hp);
		PopHeap(&hp);
	}
	for ( i = 0; i < sizeof(array) / sizeof(DataType); i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
}

/* �����������ʵ�֣����ѣ����¶��� / ���϶��£� */
void HeapSort(int* arr, int n) {

/* ���� */
#if 0
	// ���ϵ���ʵ�֣��ӵڶ���Ԫ�ؿ�ʼ
	// ʱ�临�Ӷȣ�O��N*logN��
	for (int i = 1; i < n; i++) {
		AjustUp(arr, i);
	}
#else
	// ���µ���ʵ�֣��ӵ�����һ����Ҷ�ӽڵ㿪ʼ
	// ʱ�临�Ӷȣ�O��N���� Ч�ʸ��� ��
	for (int i = (n-1-1)/2; i >= 0; i--) {
		AjustDown(arr, n, i);
	}
#endif

/* �����ô�ѣ�������С�� */
	// ʱ�临�Ӷȣ�O��N*logN��
	// ����
	int end = n - 1;
	while (end > 0) {
		Swap(&arr[0], &arr[end]);
		AjustDown(arr, end, 0);			// ע����ʱ�������ֵ����㷨Ĭ��ΪС����
		--end;
	}

}

int main() {
	printf("=====================================================\n");
	printf("���Դ����Ѽ���ѣ�\n");
	test_create_push();

	printf("=====================================================\n");
	printf("���Գ��ѣ�\n");
	test_pop();

	printf("=====================================================\n");
	printf("���Ի�ȡ�Ѷ�Ԫ�� / �Ѵ�С��\n");
	test_gettop_getsize();
	
	printf("=====================================================\n");
	printf("��������ԣ�ʹ���ֳɵĴ�����ԣ�\n");
	test_HeadSort();

	DataType array[] = { 27,15,19,18,28,34,65,49,25,37 };
	printf("=====================================================\n");
	printf("�����������ʵ�֣����� + ������\n");
	HeapSort(array, 10);
	for (int i = 0; i < 10; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
	return 0;
}