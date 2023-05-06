#include"link_queue.h"

/* ��ʼ��һ������ */
void QueueInit(Queue* queue) {
	queue->head = NULL;
	queue->tail = NULL;
}

/* �Ӵ�С */
int Size(Queue* queue) {
	assert(queue);
	if (IsEmpty(queue)) return 0;
	int count = 1;
	Node* current = queue->head;
	while (current != queue->tail) ++count,current = current->next;
	return count;
}

/* �Ӵ�С */
bool IsEmpty(Queue* queue) {
	return queue->head == NULL;
}

/* ��� */
void Push(Queue* queue, DataType data) {
	assert(queue);			// ���ж�����
	// �����½��
	Node* node = (Node*)malloc(sizeof(Node));
	if (node==NULL) perror("malloc fail��\n"),exit(-1);
	node->data = data;
	node->next = NULL;
	// �½��ֱ��β�巨��ע�⣺����Ϊ�յ����������
	if (IsEmpty(queue)) {
		queue->head = queue->tail = node;
	}
	else {
		queue->tail->next = node;			// β���½��
		queue->tail = node;					// ����¶�β
	}
}

/* ���� */
void Pop(Queue* queue) {
	assert(queue);
	// ע���пգ�
	if (IsEmpty(queue)) perror("Queue is empty��\n");
	// ��ǵڶ������
	// ע���������Σ�ԭ��ֻ��һ�����
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

/* ��ͷԪ�� */
DataType ElemFront(Queue* queue) {
	assert(queue);
	if (IsEmpty(queue)) perror("Queue is empty��\n");
	return queue->head->data;
}

/* ��βԪ�� */
DataType ElemBack(Queue* queue) {
	assert(queue);
	if (IsEmpty(queue)) perror("Queue is empty��\n");
	return queue->tail->data;
}

/* ���ٶ��� */
void Destory(Queue* queue) {
	assert(queue);
	if (IsEmpty(queue)) perror("Queue is empty��\n");
	Node* current = queue->head;
	while (current) {
		Node* next = current->next;
		free(current);
		current = next;
	}
	queue->head = queue->tail = NULL;
}