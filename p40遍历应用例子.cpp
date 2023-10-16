//遍历二叉树的应用：输出二叉树中的叶子结点
//在二叉树的遍历算法中增加检测结点的“左右子树是否都为空“
void PreOrderPrintLeaves(BinTree BT) {
	if (BT) {
		if (!BT->Left && !BT->Right)//左右两边都没有儿子了
			printf("%d", BT->Data);
		PreOrderPrintLeaves(BT->Left);
		PreOrderPrintLeaves(BT->Right);
	}
}
//求二叉树的高度
//思路：二叉树的高度等于左右两个子树中最高的高度然后加上一
//前提是左右两个子树的高度都知道
int PostOrderGetHeight(BinTree BT) {
	int HL, HR, MaxH;
	if (BT) {
		HL = PostOrderGetHeight(BT->Left);//求左子树的深度
		HR = PostOrderGetHeight(BT->Right);//求右子树的深度
		MaxH = (HL > HR) ? HL : HR;//取左右子树较大的深度
		return (MaxH + 1);//返回树的深度
	}
	else return 0;//空树深度为0
}
//暂停p40的2:14