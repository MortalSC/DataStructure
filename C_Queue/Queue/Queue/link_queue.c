#include"link_queue.h"

/* 初始化一个队列 */
void QueueInit(Queue* queue) {
	queue->head = NULL;
	queue->tail = NULL;
}

/* 队大小 */
int Size(Queue* queue) {
	assert(queue);
	if (IsEmpty(queue)) return 0;
	int count = 1;
	Node* current = queue->head;
	while (current != queue->tail) ++count,current = current->next;
	return count;
}

/* 队大小 */
bool IsEmpty(Queue* queue) {
	return queue->head == NULL;
}

/* 入队 */
void Push(Queue* queue, DataType data) {
	assert(queue);			// 队列对象检查
	// 创建新结点
	Node* node = (Node*)malloc(sizeof(Node));
	if (node==NULL) perror("malloc fail！\n"),exit(-1);
	node->data = data;
	node->next = NULL;
	// 新结点直接尾插法（注意：队列为空的特殊情况）
	if (IsEmpty(queue)) {
		queue->head = queue->tail = node;
	}
	else {
		queue->tail->next = node;			// 尾插新结点
		queue->tail = node;					// 标记新队尾
	}
}

/* 出队 */
void Pop(Queue* queue) {
	assert(queue);
	// 注意判空！
	if (IsEmpty(queue)) perror("Queue is empty！\n");
	// 标记第二个结点
	// 注意特殊情形：原队只含一个结点
	if (Size(queue) == 1) {
		free(queue->head);
		queue->head = queue->tail = NULL;
	}
	else {
		Node* current = queue->head->next;
		free(queue->head);
		queue->head = current;
	}

}

/* 队头元素 */
DataType ElemFront(Queue* queue) {
	assert(queue);
	if (IsEmpty(queue)) perror("Queue is empty！\n");
	return queue->head->data;
}

/* 队尾元素 */
DataType ElemBack(Queue* queue) {
	assert(queue);
	if (IsEmpty(queue)) perror("Queue is empty！\n");
	return queue->tail->data;
}

/* 销毁队列 */
void Destory(Queue* queue) {
	assert(queue);
	if (IsEmpty(queue)) perror("Queue is empty！\n");
	Node* current = queue->head;
	while (current) {
		Node* next = current->next;
		free(current);
		current = next;
	}
	queue->head = queue->tail = NULL;
}