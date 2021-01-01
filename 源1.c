//N�ʺ�����
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int row = 0, temp = 1, n;

typedef struct Queen {
	int Line;
	int Column;
}Queen;

void Q_Create(Queen* a);			//�����ʼ��
int Q_Judge(Queen* a, int b);		//�жϷ�ֹ��λ���Ƿ���ϱ�׼
void Q_Print(Queen* a);				//�������
void Q_Solution(Queen* a);			//DFS����

int main()
{
	printf("������N:");
	scanf("%d", &n);
	Queen* a = malloc(n * sizeof(Queen));
	if (!a)
	{
		//������ռ�ʧ�ܣ����˳�
		printf("ERROR!\n");
		exit(1);
	}
	Q_Create(a);
	Q_Solution(a);
	printf("�ϼƹ���%d�ַ���\n", temp - 1);
	//Q_Print(a);
	return 0;
}

void Q_Create(Queen* a)
{
	//���к�����Ϊ�����±���ͬ�����Բ��ÿ����кŵ����⣬���͸��Ӷ�
	int i;
	for (i = 0; i < n; i++)
	{
		a[i].Line = i;
		a[i].Column = -1;
	}
}											//��ʼ��

int Q_Judge(Queen* a, int b)
{
	//�ź�λ�ú��ж��Ƿ��������
	int i = b - 1;
	bool temp;
	for (; i >= 0; i--)
	{
		temp = a[i].Column == a[b].Column || a[i].Line + a[i].Column == a[b].Line + a[b].Column || a[b].Line - a[i].Line == a[b].Column - a[i].Column;
		if (temp)
		{
			return 0;
		}
	}
	return 1;
}

void Q_Print(Queen* a)
{
	//���N�ʺ�����Ľ��
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (a[i].Column == j)
			{
				printf("*  ");
			}
			else
			{
				printf("0  ");
			}
		}
		printf("\n");
	}
	printf("\n\n");
}

void Q_Solution(Queen* a)
{
	int i;
	for (i = 0; i < n; i++)
	{
		a[row].Column = i;
		if (Q_Judge(a, row))
		{
			//�������������������һ��
			if (row == n - 1)
			{
				//����Ϊ���һ�㣬��������
				printf("��%d�ַ���\n", temp);
				Q_Print(a);
				temp++;
			}
			row++;
			Q_Solution(a);
		}
	}
	//����������λ�ö������㣬����ݵ���һ��
	row--;
	return;
}											//DFS���ݣ����õݹ������
