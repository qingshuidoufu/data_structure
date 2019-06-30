/* 3 ��ջ����ʽջ������ƽ��
������Ҫ��������
1/��ʽ��ջ�ĳ�ʼ��
2/��ȡջ��Ԫ�����ӡջ���ݣ���ջ����ջ�ף�
3/��ʽջ����ջ���ջ
4/ջ�ڷ���ƽ�������ϵ�Ӧ��

ջ�ڷ���ƽ�������ϵ�Ӧ��
��������������﷨���󣬵��ǳ�������ȱ��һ�����ţ�����©һ�������Ż���ע����ʼ�������±������г��ϰ��еĴ��󣬶������Ĵ���ȴ��û���ҳ���
����������£�һ�����õĹ��߾��Ǽ����Ƿ����еĶ������ɶԳ��ֵĳ������ǣ�ÿһ���һ����š��ҷ����ż���Բ���ű�Ȼ��Ӧ����Ӧ����벿�֡�[()]�ǺϷ��ģ�����[(])���Ǵ���ġ���Ȼ����ֵ��Ϊ�˱�дһ�����ͳ��򣬵�����˵���������ļ���ʱ������ʵ�ֵġ�Ϊ����������ǽ���Բ���š������źͻ����Ž��м��鲢���Գ��ֵ��κ������ַ���
����򵥵��㷨�õ�һ��ջ���������£�
����һ����ջ�������ַ�ֱ���ļ�β������ַ���һ�����ŷ��ţ�����ѹ��ջ�С�����ַ���һ����շ��ţ���ô��1����ջΪ�գ��򱨴�2����ջ��Ϊ�գ���ջ��Ԫ�ص�������������ķ��Ų��Ƕ�Ӧ�Ŀ��ŷ��ţ��򱨴�3�����ļ�β�����ջ�ǿ��򱨴�
����ȷ�š�����㷨�ǿ�����ȷ���еġ���������㷨�����Եģ���ʵ����ֻ����������һ�μ��顣��ˣ�����������on-line���Ĳ����൱�졣������һЩ���ӵĹ�������������������ʱ��δ���----�����жϿ��ܵ�ԭ��
α�������£�//���д���������壬����ϵ��ʦ����
������Ŵ�һ�ַ���@�����������ȼ����Ƿ���ƽ��ģ�flag=1��
1���ζ�����ţ�ֱ������������
2����˷���
2.1���Ų�Ϊ��������ת5
2.2�������Ϊ������
2.2.1�������������ջ
2.2.2���Ҳ�����
2.2.2.1����ջ�����ջΪ�գ�����flag=0��break
2.2.2.2����ջ��ջ��Ϊ�գ���ȡջ��Ԫ��
	2.2.2.2.1 ջ��Ԫ��Ϊ��Ӧ�����������ջ
	2.2.2.2.2	ջ��Ԫ�ز�Ϊ��Ӧ�������������flag=0��break
0	ת1
4 ջ����flag==1  �ɹ�
5ջ�ǿ� �� flag==0  ʧ��
������Ƭ�Ρ� */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef char ElemType;
typedef struct linknode
{
	ElemType data;
	struct linknode* next;
}LiStack, * PointStack;
/****************��ʼ����ջ********************/

void InitStack(LiStack** s)//����ᣬ����������ָ��ָ���ָ�룬��������Ӱ��
//����������������ʵ�Σ�ʵ����ָ��linknode���͵�ָ�룩 
{
	//��ע�⡰(*s)�� ��ʹ�ã����� 
	(*s) = (LiStack*)malloc(sizeof(LiStack));
	(*s)->next = NULL;
}

/****************������ջ********************/
void DestroyStack(LiStack* s)
{
	LiStack* p = s->next, * q = s;
	while (p != NULL)
	{
		free(q);
		q = p;
		p = p->next;
	}
	free(p);
}
/****************�ж���ջ�Ƿ�Ϊ��********************/
int StackEmpty(LiStack* s)
{
	return (s->next == NULL);
}
/****************��ջ********************/
void Push(LiStack* s, ElemType e)
{

	LiStack* newNode = (LiStack*)malloc(sizeof(LiStack));
	newNode->data = e;
	newNode->next = s->next;
	s->next = newNode;
	//��1������д���д���
}
/****************��ջ********************/
int Pop(LiStack* s, ElemType* e)
{
	LiStack* p = s->next;
	if (s->next == NULL)
		return 0;
	else
	{
		*e = p->data;
		s->next = p->next;
		free(p);
		// ��2������д���д���

		return 1;
	}
}
/****************�õ�ջ��Ԫ��********************/
int GetTop(LiStack* s, ElemType* e)
{
	LiStack* p = s->next;
	if (s->next == NULL)
		return 0;
	*e = p->data;
	//��3������дһ�д���
	return 1;
}
/****************�����ջԪ��********************/
void PrintStack(LiStack* s)
{
	LiStack* p = s->next;
	while (p != NULL)
	{
		printf("%c ", p->data);
		p = p->next;
	}
	printf("\n");
}

int main() {
	LiStack* stack=NULL, * p;
	int switch_num;
	char x, y;
	scanf("%d", &switch_num);
	switch (switch_num) {
	case 1:
		InitStack(&stack);
		Push(stack, '1');
		Push(stack, '2');
		Push(stack, '3');
		PrintStack(stack);
		GetTop(stack, &x);
		printf("%c\n", x);
		Pop(stack, &x);
		Pop(stack, &x);
		PrintStack(stack);
		Push(stack, 'a');
		Push(stack, 'b');
		Push(stack, 'c');
		Pop(stack, &x);
		Push(stack, 'd');
		PrintStack(stack);
		break;
	case 2: {
		InitStack(&stack);
		int flag = 1;//���ȼ��������ƽ��� 
		getchar();
		while ((x = getchar()) != '@') {//������Ŵ��ԡ�@�����Ž��� 

			switch (x)
			{
			case'(':case'[':case'{':Push(stack, x); break;//2.2.1���Ϊ�������,����ջ��
			case ')': case ']': case '}':      //2.2.2���Ϊ�Ҳ�����,ִ�����²���
			{
				if (!StackEmpty(stack))                //�ж�ջ�Ƿ�Ϊ��
				{
					GetTop(stack, &y);         //2.2.2.2��ȡջ��Ԫ��                
					if (x == ')' && y == '(' || x == ']' && y == '[' || x == '}' && y == '{') {      //2.2.2.2.1�ж��Ƿ���Ŷ�Ӧ
						Pop(stack, &y);          //2.2.2.2.1��ջ
					}
					else          //2.2.2.2.2 ���Ų���Ӧ,��flagΪ0,�����ж�flag
					{
						flag = 0;
					}
				}
				else
				{
					flag = 0;
				}
			}break;
			default:break;          //2.1��Ϊ������,��Ĭ�ϲ�����,����switch,����ѭ����x
			}
			if (flag == 0)         //��2.2.2.1��2.2.2.2.2,flagΪ0�������,ֱ��failure��
			{
				break;
			}

			//��4������д���д���
		}
		if (!StackEmpty(stack)) flag = 0;
		if (flag)printf("Success\n");
		else printf("Failure\n");
		break;
	}
	}
	DestroyStack(stack);
	return 0;
}
/* ������������
1
3 2 1
3
1
d b a 1

2
[(3-1)/5-4]-[(2-2)*(2-2)-1]@
Success

2
[5-4-(3*3))-1]@
Failure
 */