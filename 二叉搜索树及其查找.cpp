Position Find(ElementType X, BigTree BST) {
	if (!BST)return NULL;//查找失败
	if (X > BST->Data)
		return Find(X, BST->Right);//在右子树中继续查找
	else if (X < BST->Data)
		return Find(X, BST->Left);//在左子树中继续查找
	else//X==BST->Data
		return BST;//查找成功，返回结点的找到结点的地址

}
//递归：指函数/过程/子程序在运行过程中直接或间接调用自身而产生的重入现象
//由于非递归函数的执行效率高，可将上面的“尾递归”函数改成迭代函数
Position IterFind(ElementType X, BigTree BST) {
	while (BST) {//如果树不空
		if (X > BST -> Data)
			BST = BST->Right;//向右子树移动，继续查找
		else if (X < BST->Data)
			BST = BST->Left;//向左子树移动，继续查找
		else//X==BST->Data
			return BST;//查找成功，返回结点的找到结点的地址
	}
	return NULL;
}
//查找的效率取决于树的高度

//查找最小元素的递归函数
Position FindMin(BigTree BST) {
	if (!BST)return NULL;//空的二叉搜索树，返回NULL
	else if (!BST->Left)//左边是空的
		return BST;//找到最左叶结点并返回
	else
		return FindMin(BST->Left);//沿左分支继续查找，往左边递归
}

//查找最大元素的迭代函数
Position FindMax(BinTree BST) {
	if (BST)
		//沿右分支继续查找，直到最右叶结点
		while (BST->Right) BST = BST->Right;
	return BST;

}