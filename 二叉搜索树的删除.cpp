BigTree Delete(ElementType X, BigTree BST) {
	Position Tmp;
	if (!BST) printf("Ҫɾ����Ԫ��δ�ҵ�");
	else if (X < BST->Data)
		BST->Left = Delete(ElementType X, BT->Left);//�������ݹ�ɾ��
	else if (X > BST->Data)
		BST->Right = Delete(ElementType X, BT->Right);//�������ݹ�ɾ��
	else //�ҵ�Ҫɾ���Ľ��
		if (BST->Left && BST->Right) {//��ɾ��Ԫ�������������ӽڵ�
			Tmp = FindMin(BST->Right);//��������������С��Ԫ�����ɾ�����
			BST->Data = Tmp->Data;
			//��ɾ��������������ɾ����СԪ��
			BST->Right = Delete(BST->Data, BST->Right);
		}
		else {//��ɾ�������һ�������ӽڵ�
			Tmp = BST;
			if (!BST->Left)//���Һ��ӻ����ӽڵ�
				BST = BST->Right;
			if (!BST->Right)//�����ӻ����ӽڵ�
				BST = BST->Left;
			free(Tmp);


		}
	return BST;


}