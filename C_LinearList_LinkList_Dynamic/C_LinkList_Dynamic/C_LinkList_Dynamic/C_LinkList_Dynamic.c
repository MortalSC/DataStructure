#include"C_LinkList_Dynamic.h"

/* 初始化一个空链表：不含哨兵结点的空链表 */
/*
	无参数；
	返回值：结点类型（初始化一个空表）
*/
LstNode* InitLinkList() {
	LstNode* plist = NULL;
	return plist;
}

/* 新建结点：此处单独使用一个函数新建结点 */
/* 
	参数：即指针与存储的值
	返回值：结点类型
*/
LstNode* CreateNode(DataType data) {
	/* 1. 动态申请空间 */
	LstNode* pnode = (LstNode*)malloc(sizeof(LstNode));
	assert(pnode);			/* 检查内存申请是否成功 */

	/* 2. 初始化数据域与指针域 */
	pnode->data = data;
	pnode->next = NULL;		/* 一定要指针域置空 */

	/* 3. 返回结点 */
	return pnode;
}

/* 链表判空：此处注意：C 语言中使用 bool 类型，需要 stdbool.h 头文件 */
/*
	参数：结点类型（明确判断对象）；
	返回值：bool 类型
*/
bool IsEmpty(LstNode* pHead) {
	return pHead == NULL;	/* 直接判断头结点是否为空即可 */
}


/* 输出表 */
/*
	参数：结点类型（明确操作对象）；
	无返回值；
*/
void ListPrint(LstNode* pHead) {
	/* 1. 判断被打印链表是否为空！ */
	if (IsEmpty(pHead)) {
		printf("链表为空\n");
		return;
	}
	/* 2. 遍历是访问结点并输出值 */
	/* 定义一个游标指针访问结点 */
	LstNode* current = pHead;
	printf("List: ");
	while (current) {
		printf("%d -> ", current->data);
		current = current->next;	/* 结点访问更迭 */
	}
	printf("NULL\n");
}

/* 尾插法 */
/*
	参数：结点类型（明确操作对象）；
	无返回值；

	难点：空表的尾插！涉及二级指针！
	原因：直接传入 LstNode* pHead 涉及的问题是实参和形参的问题
*/
void LinkListPushBack(LstNode** pHead, DataType data) {
	/* 1. 新建一个结点 */
	LstNode* pnode = CreateNode(data);
	/* 2. 判断原表是否为空 */
	if (IsEmpty(*pHead)) {
		/* 注意点：
			void LinkListPushBack(LstNode* pHead, DataType data)
			若直接使用一级指针，会出现实参和形参的问题；
			pHead 是形参，函数结束后就销毁了，
			pHead = pnode; 只是对形参赋值，不会影响外部实参 plist
			故此使用二级指针解决该问题！
		*/
		*pHead = pnode;
	}
	else {
		/* 原表非空：建立游标指针辅助插入 */
		LstNode* current = *pHead;
		while (current->next) {	/* 寻找尾结点 */
			current = current->next;
		}
		current->next = pnode;	/* 结点插入 */
	}
}

/* 头插法 */
/*
	参数：结点类型（明确操作对象）；
	无返回值；

	难点：空表的尾插！涉及二级指针！
	原因：直接传入 LstNode* pHead 涉及的问题是实参和形参的问题
*/
void LinkListPushFront(LstNode** pHead, DataType data) {
	/* 1. 新建结点 */
	LstNode* pnode = CreateNode(data);

	/* 2. 头部插入 */
	pnode->next = *pHead;		/* 新结点指向原表的头节点 */
	*pHead = pnode;		/* 设置新结点为链表头结点 */
	/*
		说明：为什么不需要进行原表判空？
		因为无论原表是否为空，头插都执行 pnode->next = *pHead; 即：新节点指向原表头结点；
		此时无需知道原表头结点是否为空，该步骤都是安全的。

		注意理解：*pHead 的意义：是标识链表头结点的指针。
	*/
}

/* 尾删法 */
void LinkListPopBack(LstNode** pHead) {
	/* 1. 判断操作对象的合法性：空表 */
	assert(*pHead);	/* 是空则报错！ */
	/*
		注意：
			1. assert(); 是使用强制型错误检验（空表）；
			2. 可以使用 if() 语句简单错误检验（空表）+“人性化”提示；
	*/

	/* 2. 尾删法 */
	/* 注意：需要维护两个游标指针：找到倒数第二个结点 */
	LstNode* del = *pHead;
	if (del->next) {					/* 链表结点个数 大于等于 2 */
		del = del->next;
		LstNode* delPrev = *pHead;
		while (del->next) {				/* 寻找最后两个结点 */
			del = del->next;
			delPrev = delPrev->next;
		}
		delPrev->next = NULL;
		free(del);
	}
	else {								/* 链表结点个数为：1 */
		*pHead = NULL;
	}

}

/* 头删法 */
void LinkListPopFront(LstNode** pHead) {
	/* 1. 判断操作对象的合法性：空表 */
	assert(*pHead);	/* 是空则报错！ */
	/*
		注意：
			1. assert(); 是使用强制型错误检验（空表）；
			2. 可以使用 if() 语句简单错误检验（空表）+“人性化”提示；
	*/

	/* 2. 头删法 */
	LstNode* current = (*pHead)->next;
	free(*pHead);		/* 释放空间 */
	*pHead = current;
}


/* 求表长 */
int GetLength(LstNode* pHead) {
	if (IsEmpty(pHead)) return 0;
	int res = 0;
	LstNode* current = pHead;
	while (current) {
		res++;
		current = current->next;
	}
	return res;
}

/* 按值查找：返回结点 */
/*
	参数：操作对象、目标值
	返回值：目标结点 / NULL
*/
LstNode* FindByValue(LstNode* pHead, DataType data) {
	/* 1. 判断操作对象的合法性：空表 */
	if (IsEmpty(pHead)) return NULL;

	/* 2. 借助游标进行查找 */
	LstNode* current = pHead;
	while (current) {
		if (current->data == data) return current;
		current = current->next;
	}
	return NULL;
}


/* 查找指定位置：返回结点 */
/*
	参数：操作对象、指定位置【位次】
	返回值：目标结点 / NULL

	说明：注意 指定位置的合法性
*/
LstNode* FindByPos(LstNode* pHead, int pos) {
	/* 1. 判断操作对象的合法性：空表 */
	if (IsEmpty(pHead)) return NULL;
	
	if (pos < 0 || pos > GetLength(pHead)) {
		printf("指定位置不合法！\n");
		return NULL;
	}
	LstNode* current = pHead;
	for (int i = 0; i < pos-1; i++) {
		current = current->next;
	}
	return current;
}

/* 测试指定位置之后插入：注意实际使用中，该方式效益低 */
/*
	参数：操作对象、指定位置【位次】、插入值
	返回值：无
	说明：
		注意:	1. 指定位置的合法性
				2. 指定位置插入的两种写法：
				2.1 当插入位次在[1,GetLength(plist)]之外时，设置头插或尾插；
				2.2 限定只能在合法位次内插入；【以下仅实现该情况】
*/
void InsertPos(LstNode** pHead, int pos, DataType data) {
	/* 1. 合法性检验 */
	assert(*pHead);
	assert(pos > 0 && pos <= GetLength(*pHead));

	/* 2. 插入：借助游标指针实现 */
	/* 新建结点 */
	LstNode* pnode = CreateNode(data);

	/* 使用循环找到指定插入的位置 */
	LstNode* current = *pHead;
	for (int i = 0; i < pos - 1; i++) {
		current = current->next;
	}
	pnode->next = current->next;
	current->next = pnode;
}

/* 删除指定位次上的值 */
/*
	参数：操作对象、指定位置【位次】
	返回值：结点
	说明：
		注意:	1. 指定位置的合法性
				2. 指定位置插入的两种写法：
				2.1 当删除位次在[1,GetLength(plist)]之外时，设置头删或尾删；
				2.2 限定只能在合法位次内删除；【以下仅实现该情况】
*/
LstNode* DelPos(LstNode** pHead, int pos) {
	/* 1. 合法性检验 */
	assert(*pHead);
	assert(pos > 0 && pos <= GetLength(*pHead));

	/* 使用循环找到指定删除的位置 */
	LstNode* current = *pHead;
	if (GetLength(*pHead) == 1) {
		free(*pHead);
		*pHead = NULL;
		return current;
	}
	else {
		LstNode* prev = *pHead;
		if (pos == 1) {
			*pHead = (*pHead)->next;
			return prev;
		}
		else {
			for (int i = 0; i < pos - 1; i++) {
				current = current->next;
			}

			while (prev->next != current) {
				prev = prev->next;
			}
			prev->next = current->next;
			return current;
		}
	}
}