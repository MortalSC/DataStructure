#include"CTreeHeap.h"

/* ������ */
void HeapInit(HP* hp) {
	assert(hp);
	hp->data = NULL;
	hp->capacity = hp->size = 0;
}

/* �п� */
bool IsEmpty(HP* hp) {
	assert(hp);
	return hp->size == 0;
}

/* ��ȡ����Ԫ�ظ��� */
int GetSize(HP* hp) {
	assert(hp);
	return hp->size;
}

/* �������� */
void Swap(DataType* a, DataType* b) {
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

/* ���ϵ������㷨��������ݵ��������ɴ���� / С���� */
void AjustUp(DataType* arr, int child) {
	int parent = (child-1) / 2;
	while (child > 0) {
		if (arr[child] < arr[parent]) {				// Ĭ������С����	 ����� >��С���ѣ�<
			Swap(&arr[child], &arr[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else break;
	}
}

/* ��ѣ����ݲ��� + �ѵ��� */
void PushHeap(HP* hp, DataType data) {
	assert(hp);
	// ע��ռ����⣡
	if (hp->size == hp->capacity) {
		int newcapacity = hp->capacity == 0 ? 4 : hp->capacity * 2;
		DataType* heap = (DataType*)realloc(hp->data, sizeof(DataType) * newcapacity);
		assert(heap);				// ���ڴ�����ʧ�ܣ�
		hp->data = heap;
		hp->capacity = newcapacity;
	}

	// ���ݲ���
	hp->data[hp->size++] = data;
	AjustUp(hp->data, hp->size - 1);
}

/* ���µ������㷨���������ݵ�������ȡ��ֵ���ڶѶ��� */
/* ���µ����㷨��һ��ǰ�᣺��������������һ���ѣ����ܵ����� */
void AjustDown(DataType* arr, int size, int parent){
	// ���ӽڵ㣺parent*2 + 1
	// ���ӽڵ㣺parent*2 + 2
	int child = parent * 2 + 1;											// Ĭ��ѡ����
	while ( child < size ) {
		if (child+1 < size && arr[child + 1] < arr[child])				// �˴�Ĭ��С���ѣ�<��������ѣ�>��
		{			// �����ҽ�С���ӽ��
			++child;
		}
		if (arr[child] < arr[parent])									// �˴�Ĭ��С���ѣ�<��������ѣ�>��
		{
			Swap(&arr[child], &arr[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else {
			break;
		}
	}

}

/* ���ѣ�ɾ��˼·�����ѱ��ڶѶ����ض�����ֵ����Чɾ����ʽ������������βԪ�� + ���µ����㷨����ȡ��ֵ���ڶѶ��� */
void PopHeap(HP* hp) {
	assert(hp);
	if (IsEmpty(hp)) return;
	
	Swap(&(hp->data[0]), &(hp->data[hp->size - 1]));		// ��βԪ�ؽ���
	hp->size--;
	AjustDown(hp->data, hp->size, 0);
}

/* ��ȡ�Ѷ�Ԫ�� */
DataType HeapTop(HP* hp) {
	assert(hp);
	if (IsEmpty(hp)) {
		return -1;
	}
	return hp->data[0];
}

/* ���ٶ� */
void Destroy(HP* hp) {
	assert(hp);
	free(hp);
}

/* ��ӡ�� */
void PrintHeap(HP* hp) {
	assert(hp);
	if (IsEmpty(hp)) {
		printf("Heap is empty��\n");
		return;
	}
	for (int i = 0; i < hp->size; i++) {
		printf("%d ", hp->data[i]);
	}
	printf("\n");
}