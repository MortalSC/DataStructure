#include"BinaryTreeFunc.h"

/*
	本篇内容将实现二叉树中的一些功能性方法：
		如：求结点个数、求叶子结点个数、查找指定值、 求第 K 层 结点个数、获取树的高度 / 深度
		指定值查找、两棵树是否相等、是否为对称树 / 镜像树、子树判断

	本篇中的测试示例直接手搓构造！
*/

/* 测试手搓测试实例 */
BTNode* create_BTree() {
	BTNode* root = CreateNode(0);
	BTNode* node1 = CreateNode(1);
	BTNode* node2 = CreateNode(2);
	BTNode* node3 = CreateNode(4);
	BTNode* node4 = CreateNode(3);
	BTNode* node5 = CreateNode(5);
	BTNode* node6 = CreateNode(6);

	/*	实例结构：
						1
				2				4
			3		空		5		6
		空	空			空	空		空	空
	*/

	root = node1;
	node1->leftChild = node2;
	node2->leftChild = node4;
	node1->rightChild = node3;
	node3->leftChild = node5;
	node3->rightChild = node6;
	return root;
}

int main() {

	// 构建测试二叉树
	BTNode* root = create_BTree();

	printf("该树的结点个数为：%d\n\n", GetTreeSize(root));
	printf("该树的叶子结点个数为：%d\n\n", GetTreeLeafSize(root));

	printf("该树的第一层结点个数为：%d\n\n", GetLevelKSize(root, 1));
	printf("该树的第二层结点个数为：%d\n\n", GetLevelKSize(root, 2));
	printf("该树的第三层结点个数为：%d\n\n", GetLevelKSize(root, 3));
	printf("该树的第四层结点个数为：%d\n\n", GetLevelKSize(root, 4));


	BTNode* node1 = TreeFind(root, 3);
	if (node1)
		printf("查找：3；结果：%p\n", &node1);
	else
		printf("查找：3；结果：NULL\n");


	BTNode* node2 = TreeFind(root, 10);
	if (node2)
		printf("查找：10；结果：%p\n", &node2);
	else
		printf("查找：10；结果：NULL\n");


	printf("树的高度为：%d\n\n", GetTreeDepth(root));

	return 0;
}