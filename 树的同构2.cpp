//�����ܵĴ
/*int main() {
	��������1
		��������2
		�б��Ƿ�ͬ�������
		return 0;
}
��Ҫ��Ƶĺ����������ݽ�������
������ͬ���б�
*/
#include <stdio.h>
int main() {
	Tree R1, R2;

	R1 = BuildTree(T1);
	R2 = BuildTree(T2);			
	if (Isomorphic(R1, R2)) printf("Yes\n");
	else printf("No\n");

	return 0;
}

//��ν�������
Tree BuildTree(struct TreeNode T[]) {

	scanf_s("%d\n", &N);//�ѽڵ�������
	if (N) {//N������0��ʱ�򣬾Ͱ���N��������Ϣһ��һ��������
		for (i = 0; i < N; i++)check[i] = 0;//ÿ�����һ��ʼ��Ӧ��check������0
		for (i = 0; i < N; i++) {//ÿ��ѭ����һ�����ݣ�ÿһ����������Ϣ��Ԫ�أ���ڵ㣬�нڵ�
			scanf_s("%c %c %c\n", &T[i].Element, &cl, &cr);
			//cl��Ϊ��-��ʱ���������
			if (cl != '-') {
				T[i].Left = cl - '0';//�ַ�2��ȥ�ַ�0��������
				check[T[i].Left] = 1;//���ĳһ������Leftָ����ĳ��λ�ã�����Ǹ�λ�õ�check��Ϊ1

			}
			else  T[i].Left = NULL;//clΪ��-��ʱ��û�������
			//��cr�Ķ�Ӧ����

		}
		for (i = 0; i < N; i++) {
			if (!check[i]) break;//������û�б���Ϊ1�Ľ�㣬�Ǹ������Ǹ��ڵ�
		}
		//T[i]��û���κν���left(cl)��right(cr)ָ������ֻ��һ��
		Root = i;
	}
	return Root;//��������

}

//����б������������Ƿ�ͬ��
int Isomorphic(Tree R1, Tree R2) {
	if ((R1 == NULL) && (R2 == NULL))//���ǿյ�
		return 1;
	if (((R1 == NULL) && (R2 != NULL)) || ((R1 != NULL) && (R2 == NULL)))
		return 0;
	if (T1[R1].Element != T2[R2].Element)
		return 0;//roots��ͬ,��������ֵ��ͬ�����Բ�ͬ��
	if ((T1[R1].Left == NULL && T2[R2].Left == NULL))//��û�������������ұߵ�ͬ��ͬ��
		return Isomorphic(T1[R1].Right, T2[R2].Right);
	//���ͬʱ��Ϊ��
	if ((T1[R1] != NULL && T2[R2] != NULL) && (T1[T1[R1].Left].Element == T2[T2[R2].Left].Element))
		return (Isomorphic(T1[R1].Left, T2[R2].Left) && Isomorphic(T1[R1].Right, T2[R2].Right));
	else {//��������������Element��һ��
		return (Isomorphic(T1[R1].Left, T2[R2].Right) && Isomorphic(T1[R1].Right, T2[R2].Left));
	}


}
