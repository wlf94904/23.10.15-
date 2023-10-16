#include <stdio.h>
typedef struct TreeNode* Tree;
struct TreeNode {//���������ʽ��ʾ��
	int v;//��v��ʾ���Ļ�����Ϣ
	Tree Left, Right;
	int flag;//�����б�һ�������ǲ��Ǻ���һ�£���Ϊ��û�б����ʹ��ı��
};
//������
//int main() {
//	//��ÿ������
//	//����N��L,N�����е�Ԫ�صĸ��������������Ľ�������L�Ǵ����ж��ٸ�������Ҫ�Ƚ�
//	//���ݵ�һ�����У���N��L������
//	//������T�ֱ��б�����L�������Ƿ�����T�γ�ͬһ��������������
//
//	return 0;
//}
//��Ҫ��Ƶ���Ҫ����
//�����ݣ���������T
//�б�һ�����Ƿ���T����һ����������

int main() {
	int N, L, i;
	Tree T;

	scanf_s("%d", &N);
	while (N) {
		scanf_s("%d", &L);
		T = MakeTree(N);//����N������������T
		for (i = 0; i < N; i++) {
			if (Judge(T, N)printf("Yes\n"));
			else printf("No\n");
			ResetT(T);//���T�еı��flag

		}
		FreeTree(T);
		scanf_s("%d", &N);
	}
	return 0;
}

Tree MakeTree(int N) {
	Tree T;
	int i, V;

	scanf_s("%d", &V);
	T = NewNode(V);//����һ�����Ľ��Ŀռ�
	for (i = 1; i < N; i++){
		scanf_s("%d", &V);
		T = Insert(T, V);
	}
	return T;
}

Tree NewNode(int V)
{
	Tree T = (Tree)malloc(sizeof(struct Tree Node));
	T->v = V;
	T->Left = T->Right = NULL;
	T->flag = 0;//û�����ʹ�����Ϊ0
	return T;
}

Tree Insert(Tree T, int V) {
	//T����ǿյģ���ζ����һ���յ��������ϲ����һ�����
	if (!T) T = NewNode(V);
	else {//��T���գ�������V�͸��ڵ��V���Ƚ�
		if (V > T->v)
			T->Right = Insert(T->Right, V);
		else
			T->Left = Insert(T->Left, V);
	}
	return T;
}

//����б�
int check(Tree T, int V) {//��T����������V������� 
	if (T->flag) {
		if (V < T->v)return check(T->Left, V);
		else if (V > T->v)return check(T->Right, V);
		else return 0;
	}
	else {
		if (V == T->v) {
			T->flag = 1;
			return 1;
		}
		else return 0;
	}
}

int Judge(Tree T, int N) {
	int i, V, flag = 0;
	//flag:0����Ŀǰ��һ�£�1�����Ѿ���һ��
	scanf_s("%d", &V);
	if (V != T->v) flag = 1;
	else T->flag = 1;
	for (i = 1; i < N; i++) {
		scanf_s("%d", &V);
		if ((!flag) && (!check(T, V)) flag=1;
	}
	if(flag)return 0;
	else return 1;
}

void ResetT(Tree T) {//���T�и�����flag���
	if(T->Left) ResetT(T->Left);
		if(T->Right) ResetT(T->Right);
		T->flag=0;
}

void FreeTree(Tree T)//�ͷ�T�Ŀռ�
{//���������Ŀռ��ͷţ����������Ŀռ��ͷţ�Ȼ��ѵ�ǰ���ڵ�Ŀռ��ͷ�
	if (T->Left) FreeTree(T->Left);
	if (T->Right) FreeTree(T->Right);
	free(T);
}

