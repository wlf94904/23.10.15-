//������������Ӧ�ã�����������е�Ҷ�ӽ��
//�ڶ������ı����㷨�����Ӽ����ġ����������Ƿ�Ϊ�ա�
void PreOrderPrintLeaves(BinTree BT) {
	if (BT) {
		if (!BT->Left && !BT->Right)//�������߶�û�ж�����
			printf("%d", BT->Data);
		PreOrderPrintLeaves(BT->Left);
		PreOrderPrintLeaves(BT->Right);
	}
}
//��������ĸ߶�
//˼·���������ĸ߶ȵ�������������������ߵĸ߶�Ȼ�����һ
//ǰ�����������������ĸ߶ȶ�֪��
int PostOrderGetHeight(BinTree BT) {
	int HL, HR, MaxH;
	if (BT) {
		HL = PostOrderGetHeight(BT->Left);//�������������
		HR = PostOrderGetHeight(BT->Right);//�������������
		MaxH = (HL > HR) ? HL : HR;//ȡ���������ϴ�����
		return (MaxH + 1);//�����������
	}
	else return 0;//�������Ϊ0
}
//��ͣp40��2:14