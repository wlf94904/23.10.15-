//ջ��˳��洢�ṹͨ����һ��һά�����һ����¼ջ��Ԫ��λ�õı������
//��������ôһ���ṹ��ʾ��ջ
#define MaxSize<��������Ԫ�ص�������>
typedef struct SNode* Stack;
struct SNode {
	ElementType Data[MaxSize];//����ķ���
	int Top;//��Top��ָʾջ�����ĸ�λ�ã�Top����һ����ַ������һ�����ͱ���
	//������ջ��Ԫ��λ�õ������±�
};

//��ջ����
void Push(Stack PtrS, ElementType item) {//һ�������Ƕ�ջ������ָ���ʾPtrS����
	//Stack�������͵�ָ�룬�ǽṹָ�롣
	//���ж϶�ջ����������Ϊ���������ʾ�ģ�����MaxSize��Щ��Ԫ��
	//��Ϊ����ķ����±��Ǵ�0��ʼ�ģ������±��Ǵ�0��MaxSize-1
	if (PtrS->Top == MaxSize - 1) {//Top[-1]��ʾ��ջ��
		printf("��ջ��"); return;
	}
	else {//ջû���Ͱ�item�Ž�ȥ������Top�����һ��λ��
		//����������
		//1.��item�ŵ�top+1���λ��
		//2.ͬʱ��Topֵ��һ
		PtrS->Data[++(PtrS->Top)] = item;
		return;
	}
}

//��ջ
ElementType Pop(Stack PtrS) {
	if (PtrS->Top == -1) {
		printf("��ջ��");
		return ERROR;//ERROR��ElementType������ֵ����־����
	}
	else {//��ջҪ��������
		//1.return �±�ΪTop�����ֵ
		//2.Top-1
		return (PtrS->Data[(PtrS->Top)--]);
	}
}

//����һ������ʵ��������ջ��Ҫ��������������ռ䣬
//ʹ����ֻҪ�пռ䣬��ջ�����Ϳ��Գɹ�
//������ʹ������ջ�ֱ���������ͷ��ʼ���м�������������ջ��ջ��ָ������ʱ����������ջ������

#define MaxSize<�洢����Ԫ�ؿռ�����>
struct DStack {
	ElementType Data[MaxSize];
	int Top1;//��ջ1��ջ��ָ�룬Data[]������±�
	int Top2;//��ջ2��ջ��ָ��,Data[]������±�

}S;
//��ջ�ǿյ�ʱ��
S.Top1 = -1;
S.Top2 = MaxSize;//��Ϊ���һ��λ����MaxSize-1�����Կյ�ʱ���ǹ�ȥһ������MaxSize

void Push(struct DStack* PtrS, ElementType item, int Tag) {
	//Tag��Ϊ����������ջ�ı�־��ȡֵΪ1��2
	if (PtrS->Top2 - PtrS->Top1 == 1) {//��ջ��

		printf("��ջ��");
	}
	if (Tag == 1) {//�Ե�һ����ջ���в���
		PtrS->Data[++PtrS->Top1] = item;//�ŵ�Top1�����һ��λ��
	}
	else
		PtrS->Data[--PtrS->Top2] = item;//�ŵ�Top2ǰ���һ��λ��
}

ElementType Pop(struct DStack* PtrS, int Tag) {
	//Tag��Ϊ����������ջ�ı�־��ȡֵΪ1��2
	if (Tag == 1) {//�Ե�һ����ջ����
		if (PtrS->Top1 == -1) {//��ջ1��
			printf("��ջ1��"); return NULL;
		}
		else return PtrS->Data[(PtrS->Top1)--];

	}
	else {//�Եڶ�����ջ����
		if (PtrS->Top2 == MaxSize) {//��ջ2��
			printf("��ջ2��"); return NULL;
		}
		else return PtrS->Data[(Ptrs->Top2)++];

	}
}
