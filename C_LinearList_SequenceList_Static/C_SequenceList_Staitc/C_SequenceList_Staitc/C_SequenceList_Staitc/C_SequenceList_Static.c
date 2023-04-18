#include "C_SequenceList_Static.h"

/* 初始化一个顺序表 */
void InitSeList(SeList* sl) {
	sl->arr = NULL;						/* 初始化指针为空 */
	sl->capacity = sl->CSize = 0;		/* 初始化容量和数组中元素个数为 0 */
}

/* 获取当前数组的容量大小 */
int GetCapacity(SeList sl) {
	return sl.capacity;
}

/* 获取当前数组中元素个数 */
int GetSize(SeList sl) {
	return sl.CSize;
}

/* 容量检查与扩容 */
void CheckCapacity(SeList* sl) {
	if (sl->CSize == sl->capacity) {
		int newCapacity = sl->capacity == 0 ? 4 : sl->capacity * 2;
		DataType* temp = (DataType*)realloc(sl->arr, newCapacity * sizeof(DataType));
		assert(temp);

		sl->arr = temp;
		sl->capacity = newCapacity;
	}
}

/* 遍历数组元素 */
void TravelSeList(SeList sl) {
	for (int j = 0; j < GetSize(sl); j++)
		printf("%d ", sl.arr[j]);
	printf("\n");
}

/* 尾插法 */
/*
	注意点：
		1. 检查空间容量是否满；
*/
void PushBack(SeList* sl, DataType data) {
	/* 容量判断 */
	CheckCapacity(sl);

	sl->arr[sl->CSize++] = data;
}

/* 头插法 */
/*
	注意点：
		1. 检查空间容量是否满；
	思路：从尾部元素开始，将所有元素后移一位；再将新元素放在首位
*/
void PushFront(SeList* sl, DataType data) {
	/* 容量判断 */
	CheckCapacity(sl);

	int curend = sl->CSize - 1;			/* 尾部元素标识 */
	while (curend >= 0) {
		sl->arr[curend + 1] = sl->arr[curend];
		--curend;
	}
	sl->arr[0] = data;
	sl->CSize++;
}

/* 尾删法 */
/*
	注意点：有值才可删！
*/
void PopBack(SeList* sl) {
	assert(sl->CSize != 0);
	sl->CSize--;
}

/* 头删法 */
/*
	注意点：有值才可删！
*/
void PopFront(SeList* sl) {
	assert(sl->CSize != 0);
	for (int i = 1; i < sl->CSize; i++) {
		sl->arr[i - 1] = sl->arr[i];
	}
	sl->CSize--;
}


/* 指定位次插入 */
/*
	注意点：位次与索引关系
*/
void InsertPos(SeList* sl, int pos, DataType data) {
	/* 容量检验 */
	CheckCapacity(sl);
	int curend = sl->CSize - 1;			/* 标识尾部 */
	while (curend >= pos - 1) {
		sl->arr[curend + 1] = sl->arr[curend];
		--curend;
	}
	sl->arr[pos - 1] = data;
	sl->CSize++;
}

/* 指定位次删除 */
/*
	注意点：位次与索引关系
*/
void DelPos(SeList* sl, int pos) {
	assert(sl->CSize != 0);
	assert(pos >= 1 && pos <= sl->CSize);
	for (int i = pos; i < sl->CSize; i++) {
		sl->arr[i - 1] = sl->arr[i];
	}
	sl->CSize--;
}