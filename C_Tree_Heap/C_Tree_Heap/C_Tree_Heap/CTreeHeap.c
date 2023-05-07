#include"CTreeHeap.h"

/* 创建堆 */
void HeapInit(HP* hp) {
	assert(hp);
	hp->data = NULL;
	hp->capacity = hp->size = 0;
}

/* 判空 */
bool IsEmpty(HP* hp) {
	assert(hp);
	return hp->size == 0;
}

/* 获取堆中元素个数 */
int GetSize(HP* hp) {
	assert(hp);
	return hp->size;
}

/* 交换函数 */
void Swap(DataType* a, DataType* b) {
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

/* 向上调整堆算法：入堆数据调整：生成大根堆 / 小根堆 */
void AjustUp(DataType* arr, int child) {
	int parent = (child-1) / 2;
	while (child > 0) {
		if (arr[child] < arr[parent]) {				// 默认生成小根堆	 大根堆 >；小根堆：<
			Swap(&arr[child], &arr[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else break;
	}
}

/* 入堆：数据插入 + 堆调整 */
void PushHeap(HP* hp, DataType data) {
	assert(hp);
	// 注意空间问题！
	if (hp->size == hp->capacity) {
		int newcapacity = hp->capacity == 0 ? 4 : hp->capacity * 2;
		DataType* heap = (DataType*)realloc(hp->data, sizeof(DataType) * newcapacity);
		assert(heap);				// 防内存申请失败！
		hp->data = heap;
		hp->capacity = newcapacity;
	}

	// 数据插入
	hp->data[hp->size++] = data;
	AjustUp(hp->data, hp->size - 1);
}

/* 向下调整堆算法：出堆数据调整（获取最值至于堆顶） */
/* 向下调整算法有一个前提：左右子树必须是一个堆，才能调整。 */
void AjustDown(DataType* arr, int size, int parent){
	// 左子节点：parent*2 + 1
	// 右子节点：parent*2 + 2
	int child = parent * 2 + 1;											// 默认选左孩子
	while ( child < size ) {
		if (child+1 < size && arr[child + 1] < arr[child])				// 此处默认小根堆（<）；大根堆（>）
		{			// 总是找较小孩子结点
			++child;
		}
		if (arr[child] < arr[parent])									// 此处默认小根堆（<）；大根堆（>）
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

/* 出堆：删除思路：出堆必在堆顶！必定是最值！高效删除方式：交换数组首尾元素 + 向下调整算法（获取最值至于堆顶） */
void PopHeap(HP* hp) {
	assert(hp);
	if (IsEmpty(hp)) return;
	
	Swap(&(hp->data[0]), &(hp->data[hp->size - 1]));		// 首尾元素交换
	hp->size--;
	AjustDown(hp->data, hp->size, 0);
}

/* 获取堆顶元素 */
DataType HeapTop(HP* hp) {
	assert(hp);
	if (IsEmpty(hp)) {
		return -1;
	}
	return hp->data[0];
}

/* 销毁堆 */
void Destroy(HP* hp) {
	assert(hp);
	free(hp);
}

/* 打印堆 */
void PrintHeap(HP* hp) {
	assert(hp);
	if (IsEmpty(hp)) {
		printf("Heap is empty！\n");
		return;
	}
	for (int i = 0; i < hp->size; i++) {
		printf("%d ", hp->data[i]);
	}
	printf("\n");
}