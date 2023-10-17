#define MAXN 1001
#define MINH -10001

//堆用数组来表示
int H[MAXN], size;//堆的大小用size表示

//堆的初始化，建立一个空堆
void Create() {
	size = 0;
	//根节点是从1开始放的，所以下标为0的位置是空缺的
	H[0] = MINH;//设置“岗哨”
}

void Insert(int X) {
	//将X插入H，这里省略检查堆是否已满的代码
	int i;

	//在插入的过程中，要把准备插入的元素从底往上一个个比较
	//一直比较到根节点为止，有了岗哨以后，就不用看下标有没有越界
	for (i = ++size; H[i / 2] > X; i /= 2)
		H[i] = H[i / 2];//如果父节点大，就把它挪下来
	H[i] = X;
}

//主程序
//int main() {
//	//读入n和m,n是这堆元素的个数，m是要查询的次数
//	//根据输入序列建堆
//	//对m个要求：打印到根的路径
//
//	return 0;
//}

int main() {
	int n, m, x, i, j;

	scanf_s("%d%d", &n, &m);
	Create();//堆初始化
	for (i = 0; i < n; i++) {
		//以逐个插入方式建堆
		scanf_s("%d", &x);
		Insert(x);//把每个读进来的数插到堆里面
	}
	for (i = 0; i < m; i++) {
		scanf_s("%d", &j);
		printf("%d", H[j]);
		while (j > 1) {
			//沿根方向输出各结点
			j /= 2;
			printf("%d", H[j]);
		}
		printf("\n");
	}
	return 0;
}