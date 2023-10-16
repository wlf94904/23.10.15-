BigTree Delete(ElementType X, BigTree BST) {
	Position Tmp;
	if (!BST) printf("要删除的元素未找到");
	else if (X < BST->Data)
		BST->Left = Delete(ElementType X, BT->Left);//左子树递归删除
	else if (X > BST->Data)
		BST->Right = Delete(ElementType X, BT->Right);//右子树递归删除
	else //找到要删除的结点
		if (BST->Left && BST->Right) {//被删除元素有左右两个子节点
			Tmp = FindMin(BST->Right);//在右子树中找最小的元素填充删除结点
			BST->Data = Tmp->Data;
			//在删除结点的左子树中删除最小元素
			BST->Right = Delete(BST->Data, BST->Right);
		}
		else {//被删除结点有一个或无子节点
			Tmp = BST;
			if (!BST->Left)//有右孩子或无子节点
				BST = BST->Right;
			if (!BST->Right)//有左孩子或无子节点
				BST = BST->Left;
			free(Tmp);


		}
	return BST;


}