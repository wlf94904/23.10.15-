typedef struct {
	ElementType Data;//Data代表这个结点的信息
	int Parent;//Parent是一个下标，指向父亲的位置
}SetType;

//查找某个元素所在的集合（用根节点表示）
int Find(SetType S[], ElementType X) {
	//已知X，求X所在树的树根
	//在数组S中查找值为X的元素所属的集合
	//MaxSize是全局变量，为数组S的最大长度
	int i;
	for (i = 0; i < MaxSize && S[i].Data != X; i++);
	if (i >= MaxSize) return -1;//未找到X，返回-1
	for (; S[i].Parent >= 0; i = S[i].Parent);
	return i;//找到X所属集合，返回树根结点在数组S中的下标
}

//集合的并运算
//分别找到X1和X2两个元素所在集合树的根节点
//如果它们不同根，则将其中一个根节点的父节点指针设置成另一个根结点的数组下标
void Union(SetType S[], ElementType X1, ElementType X2) {
	int Root1, Root2;
	Root1 = Find(S, X1);
	Root2 = Find(S, X2);
	//如果是不同的集合，则进行合并
	if (Root1 != Root2)S[Root2].Parent = Root1;
}