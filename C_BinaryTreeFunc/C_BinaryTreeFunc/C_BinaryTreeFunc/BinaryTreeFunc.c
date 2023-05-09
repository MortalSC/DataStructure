#include"BinaryTreeFunc.h"

/*
	本篇内容将实现二叉树中的一些功能性方法：
		如：求结点个数、求叶子结点个数、查找指定值、 求第 K 层 结点个数、获取树的高度 / 深度
		指定值查找、两棵树是否相等、是否为对称树 / 镜像树、子树判断

	本篇中的测试示例直接手搓构造！
*/

/* 创建结点 */
BTNode* CreateNode(DataType data)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	assert(node);
	node->leftChild = NULL;
	node->rightChild = NULL;
	node->data = data;
	return node;
}

/* 获取树的大小（结点个数）：分治思路 */
int GetTreeSize(BTNode* root) {
	return root == NULL ? 
		0 : GetTreeSize(root->leftChild) + GetTreeSize(root->rightChild) + 1;
}

/* 获取叶子结点的个数 */
/* 叶子结点：左右子树都是空！ */
int GetTreeLeafSize(BTNode* root) {
	if (root == NULL) return 0;
	if (root->leftChild == NULL && root->rightChild == NULL) return 1;
	return GetTreeLeafSize(root->leftChild) + GetTreeLeafSize(root->rightChild);
}

/* 求第 K 层 结点个数 */
int GetLevelKSize(BTNode* root, int k) {
	assert(k >= 1);
	if (root == NULL) return 0;
	if (k == 1) return 1;
	return GetLevelKSize(root->leftChild, k - 1) + GetLevelKSize(root->rightChild, k - 1);
}

/* 查找指定值结点 */
BTNode* TreeFind(BTNode* root, int target) {
	if (root == NULL) return NULL;			// 树为空则直接返回
	if (root->data == target) {
		return root;
	}

	BTNode* ret1 = TreeFind(root->leftChild, target);
	if(ret1) return ret1;

	BTNode* ret2 = TreeFind(root->rightChild, target);
	if (ret2) return ret2;

	return NULL;
}

/* 获取树的高度 / 深度 */
/*
	分治转化：求子树的高度；最终高度 = 子树高度 + 1（本身）
	提示：使用后续遍历
*/
int GetTreeDepth(BTNode* root) {
	if (root == NULL) return 0;
	int leftDepth = GetTreeDepth(root->leftChild);
	int rightDepth = GetTreeDepth(root->rightChild);

	return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
}

/* 两棵树是否相等 */
bool IsEqual(BTNode* p, BTNode* q) {
	// 注意结点可能为空！！！
	if (p == NULL && q == NULL) return true;
	if (p == NULL || q == NULL) return false;
	if (p->data != q->data) return false;
	return IsEqual(q->leftChild, p->leftChild) && IsEqual(q->rightChild, p->rightChild);
}


/* 是否为对称树 / 镜像树 */
bool _IsEqual(BTNode* q, BTNode* p) {
	if (q == NULL && p == NULL) return true;
	if (q == NULL || p == NULL) return false;
	if (q->data != p->data) return false;
	return _IsEqual(q->leftChild, p->rightChild) && _IsEqual(q->rightChild, p->leftChild);
}
bool isSymmetric(BTNode* root) {
	if (root == NULL) return true;
	return _IsEqual(root->leftChild, root->rightChild);
}


/* 子树判断 */
bool ChildTree(BTNode* root, BTNode* subRoot) {
	if (root == NULL) return false;
	return IsEqual(root, subRoot) || IsEqual(root->leftChild, subRoot) || IsEqual(root->rightChild, subRoot);
}