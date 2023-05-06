#include"link_queue.h"

void test() {
	Queue queue;
	QueueInit(&queue);

	printf("队列判空测试：");
	if (IsEmpty(&queue)) printf("队列为空\n");
	else printf("队列非空\n\n");
	printf("当前队列元素个数：%d\n\n", Size(&queue));


	printf("入队测试：\n");
	for (int i = 0; i < 10; i++) Push(&queue, i * 10);

	printf("当前队列元素个数：%d\n\n", Size(&queue));


	printf("获取队头元素：%d\n\n", ElemBack(&queue));
	printf("获取队尾元素：%d\n\n", ElemFront(&queue));

	printf("测试删除元素（删除三个）：\n");
	for (int i = 0; i < 3; i++) {
		printf("删除元素：%d\n", ElemFront(&queue));
		Pop(&queue);
	}
	printf("当前队列元素个数：%d\n\n", Size(&queue));


	printf("测试销毁队列：\n");
	Destory(&queue);
	printf("当前队列元素个数：%d\n\n", Size(&queue));




}

int main() {
	test();

	return 0;
}