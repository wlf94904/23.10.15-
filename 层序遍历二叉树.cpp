//层序基本过程：先根节点入队，然后：
//1.从队列中取出一个元素
//2.访问该元素所指结点
//3.若该元素所指结点的左、右孩子结点非空
//则将其左、右孩子的指针顺序入队
void LevelOrderTraversal(BinTree BT) {
	Queue Q; BinTree T;
	if (!BT) return;//若是空树则直接返回
	Q = CreatQueue(MaxSize);//创建并初始化队列Q
	AddQ(Q, BT);//把根节点放到队列里
	while (!IsEmptyQ(Q)) {
		//循环做三件事
		//1.从队列里抛出（移出）一个元素
		//2.把这个元素printf出来
		//3.把左、右儿子放到队列里
		T = DeleteQ(Q);
		printf("%d\n", T->Data);//访问取出队列的结点
		if (T->Left) AddQ(Q, T->Left);
		if (T->Right) AddQ(Q, T->left);
	}
}