#include "C_SequenceList_Static.h"

/* ��ʼ��һ��˳��� */
void InitSeList(SeList* sl) {
	sl->arr = NULL;						/* ��ʼ��ָ��Ϊ�� */
	sl->capacity = sl->CSize = 0;		/* ��ʼ��������������Ԫ�ظ���Ϊ 0 */
}

/* ��ȡ��ǰ�����������С */
int GetCapacity(SeList sl) {
	return sl.capacity;
}

/* ��ȡ��ǰ������Ԫ�ظ��� */
int GetSize(SeList sl) {
	return sl.CSize;
}

/* ������������� */
void CheckCapacity(SeList* sl) {
	if (sl->CSize == sl->capacity) {
		int newCapacity = sl->capacity == 0 ? 4 : sl->capacity * 2;
		DataType* temp = (DataType*)realloc(sl->arr, newCapacity * sizeof(DataType));
		assert(temp);

		sl->arr = temp;
		sl->capacity = newCapacity;
	}
}

/* ��������Ԫ�� */
void TravelSeList(SeList sl) {
	for (int j = 0; j < GetSize(sl); j++)
		printf("%d ", sl.arr[j]);
	printf("\n");
}

/* β�巨 */
/*
	ע��㣺
		1. ���ռ������Ƿ�����
*/
void PushBack(SeList* sl, DataType data) {
	/* �����ж� */
	CheckCapacity(sl);

	sl->arr[sl->CSize++] = data;
}

/* ͷ�巨 */
/*
	ע��㣺
		1. ���ռ������Ƿ�����
	˼·����β��Ԫ�ؿ�ʼ��������Ԫ�غ���һλ���ٽ���Ԫ�ط�����λ
*/
void PushFront(SeList* sl, DataType data) {
	/* �����ж� */
	CheckCapacity(sl);

	int curend = sl->CSize - 1;			/* β��Ԫ�ر�ʶ */
	while (curend >= 0) {
		sl->arr[curend + 1] = sl->arr[curend];
		--curend;
	}
	sl->arr[0] = data;
	sl->CSize++;
}

/* βɾ�� */
/*
	ע��㣺��ֵ�ſ�ɾ��
*/
void PopBack(SeList* sl) {
	assert(sl->CSize != 0);
	sl->CSize--;
}

/* ͷɾ�� */
/*
	ע��㣺��ֵ�ſ�ɾ��
*/
void PopFront(SeList* sl) {
	assert(sl->CSize != 0);
	for (int i = 1; i < sl->CSize; i++) {
		sl->arr[i - 1] = sl->arr[i];
	}
	sl->CSize--;
}


/* ָ��λ�β��� */
/*
	ע��㣺λ����������ϵ
*/
void InsertPos(SeList* sl, int pos, DataType data) {
	/* �������� */
	CheckCapacity(sl);
	int curend = sl->CSize - 1;			/* ��ʶβ�� */
	while (curend >= pos - 1) {
		sl->arr[curend + 1] = sl->arr[curend];
		--curend;
	}
	sl->arr[pos - 1] = data;
	sl->CSize++;
}

/* ָ��λ��ɾ�� */
/*
	ע��㣺λ����������ϵ
*/
void DelPos(SeList* sl, int pos) {
	assert(sl->CSize != 0);
	assert(pos >= 1 && pos <= sl->CSize);
	for (int i = pos; i < sl->CSize; i++) {
		sl->arr[i - 1] = sl->arr[i];
	}
	sl->CSize--;
}