Position Find(ElementType X, BigTree BST) {
	if (!BST)return NULL;//����ʧ��
	if (X > BST->Data)
		return Find(X, BST->Right);//���������м�������
	else if (X < BST->Data)
		return Find(X, BST->Left);//���������м�������
	else//X==BST->Data
		return BST;//���ҳɹ������ؽ����ҵ����ĵ�ַ

}
//�ݹ飺ָ����/����/�ӳ��������й�����ֱ�ӻ��ӵ����������������������
//���ڷǵݹ麯����ִ��Ч�ʸߣ��ɽ�����ġ�β�ݹ顱�����ĳɵ�������
Position IterFind(ElementType X, BigTree BST) {
	while (BST) {//���������
		if (X > BST -> Data)
			BST = BST->Right;//���������ƶ�����������
		else if (X < BST->Data)
			BST = BST->Left;//���������ƶ�����������
		else//X==BST->Data
			return BST;//���ҳɹ������ؽ����ҵ����ĵ�ַ
	}
	return NULL;
}
//���ҵ�Ч��ȡ�������ĸ߶�

//������СԪ�صĵݹ麯��
Position FindMin(BigTree BST) {
	if (!BST)return NULL;//�յĶ���������������NULL
	else if (!BST->Left)//����ǿյ�
		return BST;//�ҵ�����Ҷ��㲢����
	else
		return FindMin(BST->Left);//�����֧�������ң�����ߵݹ�
}

//�������Ԫ�صĵ�������
Position FindMax(BinTree BST) {
	if (BST)
		//���ҷ�֧�������ң�ֱ������Ҷ���
		while (BST->Right) BST = BST->Right;
	return BST;

}