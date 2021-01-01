//N皇后问题
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int row = 0, temp = 1, n;

typedef struct Queen {
	int Line;
	int Column;
}Queen;

void Q_Create(Queen* a);			//将其初始化
int Q_Judge(Queen* a, int b);		//判断防止该位置是否符合标准
void Q_Print(Queen* a);				//输出棋盘
void Q_Solution(Queen* a);			//DFS回溯

int main()
{
	printf("请输入N:");
	scanf("%d", &n);
	Queen* a = malloc(n * sizeof(Queen));
	if (!a)
	{
		//若申请空间失败，则退出
		printf("ERROR!\n");
		exit(1);
	}
	Q_Create(a);
	Q_Solution(a);
	printf("合计共有%d种方案\n", temp - 1);
	//Q_Print(a);
	return 0;
}

void Q_Create(Queen* a)
{
	//将行号设置为和其下标相同，可以不用考虑行号的问题，降低复杂度
	int i;
	for (i = 0; i < n; i++)
	{
		a[i].Line = i;
		a[i].Column = -1;
	}
}											//初始化

int Q_Judge(Queen* a, int b)
{
	//放好位置后判断是否满足规则
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
	//输出N皇后问题的结果
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
			//若满足条件，则进入下一层
			if (row == n - 1)
			{
				//若已为最后一层，则输出结果
				printf("第%d种方案\n", temp);
				Q_Print(a);
				temp++;
			}
			row++;
			Q_Solution(a);
		}
	}
	//若该行所有位置都不满足，则回溯到上一层
	row--;
	return;
}											//DFS回溯，利用递归来解决
