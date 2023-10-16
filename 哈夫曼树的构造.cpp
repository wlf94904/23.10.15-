//ÿ�ΰ�Ȩֵ��С�����ö������ϲ�,�γ�һ���µĶ�����
//˼·�����ѡȡ������С�ģ����ö�
typedef struct TreeNode* HuffmanTree;
struct TreeNode {
	int Weight;
	HuffmanTree Left, Right;
};
HuffmanTree Huffman(MinHeap H) {
	//����H->Size��Ȩֵ�Ѿ�����H->Elements[]->Weight��
	int i;
	HuffmanTree T;
	BuileMinHeap(H);//��H->Elements[]��Ȩֵ����Ϊ��С��
	//��H->Size-1�κϲ�
	for (i = 1; i < H->Size; i++) {
		T = malloc(sizeof(struct TreeNode));//�����½��
		//����С����ɾ��һ����㣬��Ϊ��T�����ӽ��
		T->Left = DeleteMin(H);
		//����С����ɾ��һ����㣬��Ϊ��T�����ӽ��
		T->Right = DeleteMin(H);
		//������Ȩֵ����Ȩֵ����ԭ������������Ȩֵ�ĺ�
		T->Weight = T->Left->Weight + T->Right->Weight;
		Insert(H, T);//����T������С��
		
	}
	T = DeleteMin(H);
	return T;
}