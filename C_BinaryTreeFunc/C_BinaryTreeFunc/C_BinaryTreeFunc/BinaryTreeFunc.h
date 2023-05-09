#pragma

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>

/* 
	本篇内容将实现二叉树中的一些功能性方法：
		如：求结点个数、求叶子结点个数、查找指定值、 求第 K 层 结点个数、获取树的高度 / 深度
		指定值查找、两棵树是否相等、是否为对称树 / 镜像树、子树判断

	本篇中的测试示例直接手搓构造！
*/

typedef int DataType;

typedef struct BinaryTreeNode {
	struct BinaryTreeNode* leftChild;
	struct BinaryTreeNode* rightChild;
	DataType data;
}BTNode;

/* 创建结点 */
BTNode* CreateNode(DataType data);

/* 获取树的大小（结点个数）：分治思路 */
int GetTreeSize(BTNode* root);

/* 获取叶子结点的个数 */
int GetTreeLeafSize(BTNode* root);

/* 求第 K 层 结点个数 */
int GetLevelKSize(BTNode* root, int k);

/* 获取树的高度 / 深度 */
int GetTreeDepth(BTNode* root);

/* 查找指定值结点 */
BTNode* TreeFind(BTNode* root, int target);

/* 两棵树是否相等 */
bool IsEqual(BTNode* p, BTNode* q);

/* 是否为对称树 / 镜像树 */
bool _IsEqual(BTNode* q, BTNode* p);
bool isSymmetric(BTNode* root);

/* 子树判断 */
bool ChildTree(BTNode* root, BTNode* subRoot);