//栈的顺序存储结构通常由一个一维数组和一个记录栈顶元素位置的变量组成
//可以用这么一个结构表示堆栈
#define MaxSize<储存数据元素的最大个数>
typedef struct SNode* Stack;
struct SNode {
	ElementType Data[MaxSize];//数组的分量
	int Top;//用Top来指示栈顶在哪个位置，Top不是一个地址，而是一个整型变量
	//代表了栈顶元素位置的数组下标
};

//入栈操作
void Push(Stack PtrS, ElementType item) {//一个参数是堆栈本身，用指针表示PtrS，是
	//Stack这种类型的指针，是结构指针。
	//先判断堆栈满不满，因为是用数组表示的，最多放MaxSize这些个元素
	//因为数组的分量下标是从0开始的，所以下标是从0到MaxSize-1
	if (PtrS->Top == MaxSize - 1) {//Top[-1]表示堆栈空
		printf("堆栈满"); return;
	}
	else {//栈没满就把item放进去，放在Top上面的一个位置
		//做了两件事
		//1.把item放到top+1这个位置
		//2.同时把Top值加一
		PtrS->Data[++(PtrS->Top)] = item;
		return;
	}
}

//出栈
ElementType Pop(Stack PtrS) {
	if (PtrS->Top == -1) {
		printf("堆栈空");
		return ERROR;//ERROR是ElementType的特殊值，标志错误
	}
	else {//出栈要做两件事
		//1.return 下标为Top的这个值
		//2.Top-1
		return (PtrS->Data[(PtrS->Top)--]);
	}
}

//请用一个数组实现两个堆栈，要求最大地利用数组空间，
//使数组只要有空间，入栈操作就可以成功
//分析：使这两个栈分别从数组的两头开始向中间生长，当两个栈的栈顶指针相遇时，表明两个栈都满了

#define MaxSize<存储数据元素空间的最大>
struct DStack {
	ElementType Data[MaxSize];
	int Top1;//堆栈1的栈顶指针，Data[]数组的下标
	int Top2;//堆栈2的栈顶指针,Data[]数组的下标

}S;
//堆栈是空的时候
S.Top1 = -1;
S.Top2 = MaxSize;//因为最后一个位置是MaxSize-1，所以空的时候是过去一个，即MaxSize

void Push(struct DStack* PtrS, ElementType item, int Tag) {
	//Tag作为区别两个堆栈的标志，取值为1和2
	if (PtrS->Top2 - PtrS->Top1 == 1) {//堆栈满

		printf("堆栈满");
	}
	if (Tag == 1) {//对第一个堆栈进行操作
		PtrS->Data[++PtrS->Top1] = item;//放到Top1后面的一个位置
	}
	else
		PtrS->Data[--PtrS->Top2] = item;//放到Top2前面的一个位置
}

ElementType Pop(struct DStack* PtrS, int Tag) {
	//Tag作为区别两个堆栈的标志，取值为1和2
	if (Tag == 1) {//对第一个堆栈操作
		if (PtrS->Top1 == -1) {//堆栈1空
			printf("堆栈1空"); return NULL;
		}
		else return PtrS->Data[(PtrS->Top1)--];

	}
	else {//对第二个堆栈操作
		if (PtrS->Top2 == MaxSize) {//堆栈2空
			printf("堆栈2空"); return NULL;
		}
		else return PtrS->Data[(Ptrs->Top2)++];

	}
}
