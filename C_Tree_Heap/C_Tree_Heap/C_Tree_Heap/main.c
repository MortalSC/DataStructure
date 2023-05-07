#include"CTreeHeap.h"

/* 测试创建堆及入堆 */
void test_create_push() {
	HP hp;
	HeapInit(&hp);
	DataType array[] = { 27,15,19,18,28,34,65,49,25,37 };
	for (int i = 0; i < sizeof(array) / sizeof(DataType); i++) {
		PushHeap(&hp, array[i]);
	}
	PrintHeap(&hp);
}

/* 测试出堆 */
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

/* 测试获取堆顶元素 / 堆大小 */
void test_gettop_getsize() {
	HP hp;
	HeapInit(&hp);

	DataType array[] = { 27,15,19,18,28,34,65,49,25,37 };
	for (int i = 0; i < sizeof(array) / sizeof(DataType); i++) {
		PushHeap(&hp, array[i]);
	}
	PrintHeap(&hp);
	printf("堆顶元素：%d\n", HeapTop(&hp));

	printf("堆顶大小：%d\n", GetSize(&hp));
}

/* 堆排序测试：使用现成的代码测试 */
void test_HeadSort() {
	// （弊端：空间复杂度高【未充分利用给的数组，而是新建堆，通过堆特性更新原数组】）

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

/* 堆排序设计与实现：建堆（自下而上 / 自上而下） */
void HeapSort(int* arr, int n) {

/* 建堆 */
#if 0
	// 向上调整实现：从第二个元素开始
	// 时间复杂度：O（N*logN）
	for (int i = 1; i < n; i++) {
		AjustUp(arr, i);
	}
#else
	// 向下调整实现：从倒数第一个非叶子节点开始
	// 时间复杂度：O（N）【 效率更高 】
	for (int i = (n-1-1)/2; i >= 0; i--) {
		AjustDown(arr, n, i);
	}
#endif

/* 升序用大堆，降序用小堆 */
	// 时间复杂度：O（N*logN）
	// 降序
	int end = n - 1;
	while (end > 0) {
		Swap(&arr[0], &arr[end]);
		AjustDown(arr, end, 0);			// 注：此时代码两种调整算法默认为小根堆
		--end;
	}

}

int main() {
	printf("=====================================================\n");
	printf("测试创建堆及入堆：\n");
	test_create_push();

	printf("=====================================================\n");
	printf("测试出堆：\n");
	test_pop();

	printf("=====================================================\n");
	printf("测试获取堆顶元素 / 堆大小：\n");
	test_gettop_getsize();
	
	printf("=====================================================\n");
	printf("堆排序测试：使用现成的代码测试：\n");
	test_HeadSort();

	DataType array[] = { 27,15,19,18,28,34,65,49,25,37 };
	printf("=====================================================\n");
	printf("堆排序设计与实现：建堆 + 调整：\n");
	HeapSort(array, 10);
	for (int i = 0; i < 10; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
	return 0;
}