#pragma

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

/* 
	堆：
	基本性质：
	·	一定是一个：完全二叉树！！！
	·	小根堆（父节点数据总是小于等于子节点）、大根堆（父节点数据总是大于等子节点）

	使用顺序存储方式！逻辑上的二叉树！

	·	小根堆：根节点元素一定是堆中最小元素；大根堆：根节点元素一定是堆中最大元素；
	·	出堆：指定从堆顶出堆；
*/

typedef int DataType;

typedef struct Heap {
	DataType* data;
	int capacity;					// 数组容量
	int size;						// 当前元素个数
}HP;

/*	方法合集：
		1. 创建堆；
		2. 销毁堆；
		3. 入堆、出堆；
		4. 获取堆顶元素；
		5. 判空；
		6. 获取元素个数；
		7. 打印堆（非必要接口）

	注意：堆可用于排序！
*/

/* 创建堆 */
void HeapInit(HP* hp);

/* 判空 */
bool IsEmpty(HP* hp);

/* 获取堆中元素个数 */
int GetSize(HP* hp);

/* 交换函数 */
void Swap(DataType* a, DataType* b);

/* 向上调整堆算法：入堆数据调整：生成大根堆 / 小根堆 */
void AjustUp(DataType* arr, int child);

/* 向下调整堆算法：出堆数据调整（获取最值至于堆顶） */
/* 向下调整算法有一个前提：左右子树必须是一个堆，才能调整。 */
void AjustDown(DataType* arr, int size, int parent);


/* 入堆 */
void PushHeap(HP* hp, DataType data);

/* 出堆 */
void PopHeap(HP* hp);

/* 获取堆顶元素 */
DataType HeapTop(HP* hp);

/* 销毁堆 */
void Destroy(HP* hp);


/* 打印堆 */
void PrintHeap(HP* hp);