//每次把权值最小的两棵二叉树合并,形成一个新的二叉树
//思路：如何选取两个最小的？利用堆
typedef struct TreeNode* HuffmanTree;
struct TreeNode {
	int Weight;
	HuffmanTree Left, Right;
};
HuffmanTree Huffman(MinHeap H) {
	//假设H->Size个权值已经存在H->Elements[]->Weight里
	int i;
	HuffmanTree T;
	BuileMinHeap(H);//将H->Elements[]按权值调整为最小堆
	//做H->Size-1次合并
	for (i = 1; i < H->Size; i++) {
		T = malloc(sizeof(struct TreeNode));//建立新结点
		//从最小堆中删除一个结点，作为新T的左子结点
		T->Left = DeleteMin(H);
		//从最小堆中删除一个结点，作为新T的右子结点
		T->Right = DeleteMin(H);
		//计算新权值，新权值等于原来两个二叉树权值的和
		T->Weight = T->Left->Weight + T->Right->Weight;
		Insert(H, T);//将新T插入最小堆
		
	}
	T = DeleteMin(H);
	return T;
}