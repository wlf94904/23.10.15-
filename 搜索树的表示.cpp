#include <stdio.h>
typedef struct TreeNode* Tree;
struct TreeNode {//用链表的形式表示树
	int v;//用v表示结点的基本信息
	Tree Left, Right;
	int flag;//用来判别一个序列是不是和树一致，作为有没有被访问过的标记
};
//程序框架
//int main() {
//	//对每组数据
//	//读入N和L,N是序列的元素的个数，即搜索树的结点个数，L是代表有多少个序列需要比较
//	//根据第一行序列（即N和L）建树
//	//根据树T分别判别后面的L个序列是否能与T形成同一搜索树并输出结果
//
//	return 0;
//}
//需要设计的主要函数
//读数据，建搜索树T
//判别一序列是否与T构成一样的搜索树

int main() {
	int N, L, i;
	Tree T;

	scanf_s("%d", &N);
	while (N) {
		scanf_s("%d", &L);
		T = MakeTree(N);//读入N个数，建立树T
		for (i = 0; i < N; i++) {
			if (Judge(T, N)printf("Yes\n"));
			else printf("No\n");
			ResetT(T);//清除T中的标记flag

		}
		FreeTree(T);
		scanf_s("%d", &N);
	}
	return 0;
}

Tree MakeTree(int N) {
	Tree T;
	int i, V;

	scanf_s("%d", &V);
	T = NewNode(V);//申请一个树的结点的空间
	for (i = 1; i < N; i++){
		scanf_s("%d", &V);
		T = Insert(T, V);
	}
	return T;
}

Tree NewNode(int V)
{
	Tree T = (Tree)malloc(sizeof(struct Tree Node));
	T->v = V;
	T->Left = T->Right = NULL;
	T->flag = 0;//没被访问过就设为0
	return T;
}

Tree Insert(Tree T, int V) {
	//T如果是空的，意味着在一个空的搜索树上插入第一个结点
	if (!T) T = NewNode(V);
	else {//树T不空，则把这个V和根节点的V做比较
		if (V > T->v)
			T->Right = Insert(T->Right, V);
		else
			T->Left = Insert(T->Left, V);
	}
	return T;
}

//如何判别
int check(Tree T, int V) {//在T这个树里查找V这个整数 
	if (T->flag) {
		if (V < T->v)return check(T->Left, V);
		else if (V > T->v)return check(T->Right, V);
		else return 0;
	}
	else {
		if (V == T->v) {
			T->flag = 1;
			return 1;
		}
		else return 0;
	}
}

int Judge(Tree T, int N) {
	int i, V, flag = 0;
	//flag:0代表目前还一致，1代表已经不一致
	scanf_s("%d", &V);
	if (V != T->v) flag = 1;
	else T->flag = 1;
	for (i = 1; i < N; i++) {
		scanf_s("%d", &V);
		if ((!flag) && (!check(T, V)) flag=1;
	}
	if(flag)return 0;
	else return 1;
}

void ResetT(Tree T) {//清除T中各结点的flag标记
	if(T->Left) ResetT(T->Left);
		if(T->Right) ResetT(T->Right);
		T->flag=0;
}

void FreeTree(Tree T)//释放T的空间
{//把左子树的空间释放，把右子树的空间释放，然后把当前根节点的空间释放
	if (T->Left) FreeTree(T->Left);
	if (T->Right) FreeTree(T->Right);
	free(T);
}

