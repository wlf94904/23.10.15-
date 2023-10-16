//���ѵĴ���
typedef struct HeapStruct* MaxHeap;
struct HeapStruct {
	ElementType* Elements;//�洢��Ԫ�ص�����
	int Size;//�ѵĵ�ǰԪ�ظ���
	int Capacity;//�ѵ��������
};

MaxHeap Create(int MaxSize) {
	//��������ΪMaxSize�Ŀյ�����
	MaxHeap H = malloc(sizeof(struct HeapStruct));//����һ��ռ丳��H
	//�ռ�Ĵ�С��MaxSize+1����Ϊ�Ѵ���Ǵ��±�Ϊ1�ĵط���ŵģ��±�Ϊ0���ǲ���Ŷѵ���ʽ��Ԫ�ص�
	H->Elements = malloc((MaxSize + 1) * sizeof(ElementType));//ָ��һ������
	H->Size = 0;
	H->Capacity = MaxSize;
	H->Elements[0] = MaxData;
	//����"�ڱ���Ϊ���ڶ������п���Ԫ�ص�ֵ�������Ժ�������
	return H;
}

//�㷨�������������뵽���丸�ڵ㵽���ڵ������������
void Insert(MaxHeap H, ElementType item) {
	//��Ԫ��item��������H������H->Elements[0]�Ѿ�����Ϊ�ڱ�
	int i;
	if (IsFull(H)) {
		printf("��������");
		return;
	}
	i = ++H->Size;//iָ��������е����һ��Ԫ�ص�λ��
	for (; H->Elements[i] = H->Elements[i / 2];i/=2)//�����ڵ����λ��
		H->Elements[i] = H->Elements[i / 2];//���¹��˽��
	H->Elements[i] = item;//��item����
	//H->Elements[0]���ڱ�Ԫ�أ�����С�ڶ��е����Ԫ�أ�����˳������
}

//���ѵ�ɾ��
//ȡ�����ڵ㣨���ֵ��Ԫ�أ�ͬʱɾ���ѵ�һ�����
ElementType DeleteMax(MaxHeap H) {
	//������H��ȡ����ֵΪ����Ԫ�أ���ɾ��һ�����
	int Parent, Child;
	ElementType MaxItem, temp;
	if (IsEmpty(H)) {
		printf("������Ϊ��");
		return;
	}
	MaxItem = H->Elements[1];//ȡ�����ڵ����ֵ
	//�����������һ��Ԫ�شӸ��ڵ㿪ʼ���Ϲ����²���
	temp = H->Elements[H->Size--];
	//�������forѭ������Ϊ�˸�temp��һ��λ��
	for (Parent = 1; Parent * 2 <= H->Size; Parent = Child) {
		Child = Parent * 2;//�ȼٶ�����Ӵ�
		//if��ǰ�벿������ζ��һ�����Ҷ���
		//if�����벿�������Ҷ��ӵıȽ�
		if ((Child != H->Size) && (H->Elements[Child] < H->Elements[Child + 1]))
			Child++;//Childָ�������ӽ��Ľϴ���
		if (temp >= H->Elements[Child])break;
		else//�ƶ�tempԪ�ص���һ��
			H->Elements[Parent] = H->Elements[Child];
	}
	H->Elements[Parent] = temp;
	return MaxItem;
}

//���ѵĽ���
//�ѵ�һ��Ӧ�ã���������Ҫ�Ƚ���
//�������ѣ����Ѿ����ڵ�N��Ԫ�ذ����ѵ�Ҫ������һ��һά������
//������ʱ�临�Ӷ��½������ѣ�
//(1)��N��Ԫ�ذ�����˳����룬��������ȫ�������Ľṹ����
//��2������������λ�ã����������ѵ���������

