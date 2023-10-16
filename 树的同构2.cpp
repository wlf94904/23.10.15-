//程序框架的搭建
/*int main() {
	建二叉树1
		建二叉树2
		判别是否同构并输出
		return 0;
}
需要设计的函数：读数据建二叉树
二叉树同构判别
*/
#include <stdio.h>
int main() {
	Tree R1, R2;

	R1 = BuildTree(T1);
	R2 = BuildTree(T2);			
	if (Isomorphic(R1, R2)) printf("Yes\n");
	else printf("No\n");

	return 0;
}

//如何建二叉树
Tree BuildTree(struct TreeNode T[]) {

	scanf_s("%d\n", &N);//把节点数读入
	if (N) {//N不等于0的时候，就把这N个结点的信息一个一个读进来
		for (i = 0; i < N; i++)check[i] = 0;//每个结点一开始对应的check都等于0
		for (i = 0; i < N; i++) {//每轮循环读一行数据，每一行有三个信息，元素，左节点，有节点
			scanf_s("%c %c %c\n", &T[i].Element, &cl, &cr);
			//cl不为‘-’时，有左儿子
			if (cl != '-') {
				T[i].Left = cl - '0';//字符2减去字符0就是整数
				check[T[i].Left] = 1;//如果某一个结点的Left指向了某个位置，则把那个位置的check设为1

			}
			else  T[i].Left = NULL;//cl为‘-’时，没有左儿子
			//对cr的对应处理

		}
		for (i = 0; i < N; i++) {
			if (!check[i]) break;//即上面没有被改为1的结点，那个结点就是根节点
		}
		//T[i]中没有任何结点的left(cl)和right(cr)指向它。只有一个
		Root = i;
	}
	return Root;//返回树根

}

//如何判别两个二叉树是否同构
int Isomorphic(Tree R1, Tree R2) {
	if ((R1 == NULL) && (R2 == NULL))//都是空的
		return 1;
	if (((R1 == NULL) && (R2 != NULL)) || ((R1 != NULL) && (R2 == NULL)))
		return 0;
	if (T1[R1].Element != T2[R2].Element)
		return 0;//roots不同,即树根的值不同，所以不同构
	if ((T1[R1].Left == NULL && T2[R2].Left == NULL))//都没有左子树，则看右边的同不同构
		return Isomorphic(T1[R1].Right, T2[R2].Right);
	//左边同时不为空
	if ((T1[R1] != NULL && T2[R2] != NULL) && (T1[T1[R1].Left].Element == T2[T2[R2].Left].Element))
		return (Isomorphic(T1[R1].Left, T2[R2].Left) && Isomorphic(T1[R1].Right, T2[R2].Right));
	else {//两个的左子树的Element不一样
		return (Isomorphic(T1[R1].Left, T2[R2].Right) && Isomorphic(T1[R1].Right, T2[R2].Left));
	}


}
