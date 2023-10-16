//结构数组表示二叉树：静态链表
#define MaxTree 10
#define ElementType char
#define Tree int
#define NULL -1//区分传统空指针的NULL

struct TreeNode//二叉树的结点，三个成员变量
{
	ElementType element;
	Tree Left;
	Tree Right;//注意：此处的Left和Right不是指针类型，而是整型

}T1[MaxTree], T2[MaxTree];