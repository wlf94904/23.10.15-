//二叉搜索树的插入算法
//往一个树BST里插入一个元素X
BigTree Insert(ElementType X, BigTree BST) {
	if (!BST) {
		//若原树为空，则生成一个二叉树且返回一个结点
		BST = malloc(sizeof(struct TreeNode));
		BST->Data = X;
		BST->Right =BST->Left = NULL;
	}
	else {//开始查找要插入元素的位置
		if (X < BST->Data) {
			//递归插入左子树
			BST->Left = Insert(X, BST->Left);
			
		}
		else if(X>BST->Data){
			//递归插入右子树
			BST->Right = Insert(X, BST->Right);

		}

		//
	


	}
	//X已存在，则什么都不做
	return BST;

}