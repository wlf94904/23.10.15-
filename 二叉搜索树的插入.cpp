//�����������Ĳ����㷨
//��һ����BST�����һ��Ԫ��X
BigTree Insert(ElementType X, BigTree BST) {
	if (!BST) {
		//��ԭ��Ϊ�գ�������һ���������ҷ���һ�����
		BST = malloc(sizeof(struct TreeNode));
		BST->Data = X;
		BST->Right =BST->Left = NULL;
	}
	else {//��ʼ����Ҫ����Ԫ�ص�λ��
		if (X < BST->Data) {
			//�ݹ����������
			BST->Left = Insert(X, BST->Left);
			
		}
		else if(X>BST->Data){
			//�ݹ����������
			BST->Right = Insert(X, BST->Right);

		}

		//
	


	}
	//X�Ѵ��ڣ���ʲô������
	return BST;

}