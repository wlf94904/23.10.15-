//����������̣��ȸ��ڵ���ӣ�Ȼ��
//1.�Ӷ�����ȡ��һ��Ԫ��
//2.���ʸ�Ԫ����ָ���
//3.����Ԫ����ָ�������Һ��ӽ��ǿ�
//�������Һ��ӵ�ָ��˳�����
void LevelOrderTraversal(BinTree BT) {
	Queue Q; BinTree T;
	if (!BT) return;//���ǿ�����ֱ�ӷ���
	Q = CreatQueue(MaxSize);//��������ʼ������Q
	AddQ(Q, BT);//�Ѹ��ڵ�ŵ�������
	while (!IsEmptyQ(Q)) {
		//ѭ����������
		//1.�Ӷ������׳����Ƴ���һ��Ԫ��
		//2.�����Ԫ��printf����
		//3.�����Ҷ��ӷŵ�������
		T = DeleteQ(Q);
		printf("%d\n", T->Data);//����ȡ�����еĽ��
		if (T->Left) AddQ(Q, T->Left);
		if (T->Right) AddQ(Q, T->left);
	}
}