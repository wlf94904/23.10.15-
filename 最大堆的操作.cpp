//最大堆的创建
typedef struct HeapStruct* MaxHeap;
struct HeapStruct {
	ElementType* Elements;//存储堆元素的数组
	int Size;//堆的当前元素个数
	int Capacity;//堆的最大容量
};

MaxHeap Create(int MaxSize) {
	//创建容量为MaxSize的空的最大堆
	MaxHeap H = malloc(sizeof(struct HeapStruct));//申请一块空间赋给H
	//空间的大小是MaxSize+1，因为堆存放是从下标为1的地方存放的，下标为0的是不存放堆的正式的元素的
	H->Elements = malloc((MaxSize + 1) * sizeof(ElementType));//指向一个数组
	H->Size = 0;
	H->Capacity = MaxSize;
	H->Elements[0] = MaxData;
	//定义"哨兵“为大于堆中所有可能元素的值，便于以后更快操作
	return H;
}

//算法：将新增结点插入到从其父节点到根节点的有序序列中
void Insert(MaxHeap H, ElementType item) {
	//将元素item插入最大堆H，其中H->Elements[0]已经定义为哨兵
	int i;
	if (IsFull(H)) {
		printf("最大堆已满");
		return;
	}
	i = ++H->Size;//i指向插入后堆中的最后一个元素的位置
	for (; H->Elements[i] = H->Elements[i / 2];i/=2)//到父节点这个位置
		H->Elements[i] = H->Elements[i / 2];//向下过滤结点
	H->Elements[i] = item;//将item插入
	//H->Elements[0]是哨兵元素，它不小于堆中的最大元素，控制顺环结束
}

//最大堆的删除
//取出根节点（最大值）元素，同时删除堆的一个结点
ElementType DeleteMax(MaxHeap H) {
	//从最大堆H中取出键值为最大的元素，并删除一个结点
	int Parent, Child;
	ElementType MaxItem, temp;
	if (IsEmpty(H)) {
		printf("最大堆已为空");
		return;
	}
	MaxItem = H->Elements[1];//取出根节点最大值
	//用最大堆中最后一个元素从根节点开始向上过滤下层结点
	temp = H->Elements[H->Size--];
	//下面这个for循环就是为了给temp找一个位置
	for (Parent = 1; Parent * 2 <= H->Size; Parent = Child) {
		Child = Parent * 2;//先假定左儿子大
		//if的前半部分是意味着一定有右儿子
		//if里面后半部分是左右儿子的比较
		if ((Child != H->Size) && (H->Elements[Child] < H->Elements[Child + 1]))
			Child++;//Child指向左右子结点的较大者
		if (temp >= H->Elements[Child])break;
		else//移动temp元素到下一层
			H->Elements[Parent] = H->Elements[Child];
	}
	H->Elements[Parent] = temp;
	return MaxItem;
}

//最大堆的建立
//堆的一个应用：堆排序，需要先建堆
//建立最大堆：将已经存在的N个元素按最大堆的要求存放在一个一维数组中
//在线性时间复杂度下建立最大堆：
//(1)将N个元素按输入顺序存入，先满足完全二叉树的结构特性
//（2）调整各结点的位置，以满足最大堆的有序特性

