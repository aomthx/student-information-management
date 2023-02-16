#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"function.h"

/*如需测试代码请将大作业中 f.txt 文件放置在D盘目录下*/

int main()
{
	int a ,b, end=1;
	char j;
	struct stu* hp = creat();
	
	do {
		system("cls");
		printf("-------------------------学生信息管理系统------------------------\n\n");
		printf("系统功能：1.总览   2.检索   3.成绩修改    4.学生增减    5.退出系统\n");
		printf("请输入功能项:");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			PutoutALL(hp);
			printf("点击任意键以继续.....");
			getchar();
			system("cls");
			break;
		case 2:
			printf("\t1.查询个人信息 \n");
			printf("\t2.分数区间筛选\n");
			printf("\t3.按性别筛选\n");
			printf("\t4.分数按序排列\n");
			printf("\t5.按专业筛选\n");
			printf("请输入：");
			scanf("%d", &a);
			switch (a)
			{
			case 1:
				do {
					Sreach(hp);
					printf("是否继续执行(Y / N):");
					scanf("%c", &j);
					system("cls");
				} while (j == 'Y');
				break;
			case 2:
				do {
					printf("1. 语文 2. 数学 3.英语 4.总分 :");
					scanf("%d", &a);
					RangeSreach(hp, a);
					printf("是否继续执行(Y / N):");
					scanf("%c", &j);
					system("cls");
				} while (j == 'Y');
				break;
			case 3:
				do {
					printf("请输入要筛选的性别(1.男  2.女):");
					scanf("%d", &a);
					SexSreach(hp, a);
					printf("是否继续执行(Y / N):");
					scanf("%c", &j);
					system("cls");
				} while (j == 'Y');
				break;
			case 4:
				do {
					printf("1. 语文 2. 数学 3.英语 4.总分 :");
					scanf("%d", &a);
					printf("1.升序 2.降序 : ");
					scanf("%d", &b);
					switch (b)
					{
					case 1:
						UpRank(hp, a);
						break;
					case 2:
						DownRank(hp, a);
						break;
					}
					printf("是否继续执行(Y / N):");
					scanf("%c", &j);
					system("cls");
				} while (j == 'Y');
				break;
			case 5:
				do {
					MajorSreach(hp);
					printf("是否继续执行(Y / N):");
					scanf("%c", &j);
					system("cls");
				} while (j == 'Y');
				break;
			}
			break;
		case 3:
			do {
				Change(hp);
				printf("是否继续执行(Y / N):");
				scanf("%c", &j);
				system("cls");
			} while (j == 'Y');
			break;
		case 4:
			do {
				printf("1.删除  2.添加 :  ");
				scanf("%d",&a);
				switch (a)
				{
				case 1:
					hp=Delete(hp);
					break;
				case 2:
					Add(hp);
					break;
				}
				printf("是否继续执行(Y / N):");
				scanf("%c", &j);
				system("cls");
			} while (j == 'Y');
			break;
		case 5:
			end = 0;
			break;
		}
	} while (end == 1);
	
	return 0;
}