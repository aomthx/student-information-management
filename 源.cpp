#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"function.h"

/*������Դ����뽫����ҵ�� f.txt �ļ�������D��Ŀ¼��*/

int main()
{
	int a ,b, end=1;
	char j;
	struct stu* hp = creat();
	
	do {
		system("cls");
		printf("-------------------------ѧ����Ϣ����ϵͳ------------------------\n\n");
		printf("ϵͳ���ܣ�1.����   2.����   3.�ɼ��޸�    4.ѧ������    5.�˳�ϵͳ\n");
		printf("�����빦����:");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			PutoutALL(hp);
			printf("���������Լ���.....");
			getchar();
			system("cls");
			break;
		case 2:
			printf("\t1.��ѯ������Ϣ \n");
			printf("\t2.��������ɸѡ\n");
			printf("\t3.���Ա�ɸѡ\n");
			printf("\t4.������������\n");
			printf("\t5.��רҵɸѡ\n");
			printf("�����룺");
			scanf("%d", &a);
			switch (a)
			{
			case 1:
				do {
					Sreach(hp);
					printf("�Ƿ����ִ��(Y / N):");
					scanf("%c", &j);
					system("cls");
				} while (j == 'Y');
				break;
			case 2:
				do {
					printf("1. ���� 2. ��ѧ 3.Ӣ�� 4.�ܷ� :");
					scanf("%d", &a);
					RangeSreach(hp, a);
					printf("�Ƿ����ִ��(Y / N):");
					scanf("%c", &j);
					system("cls");
				} while (j == 'Y');
				break;
			case 3:
				do {
					printf("������Ҫɸѡ���Ա�(1.��  2.Ů):");
					scanf("%d", &a);
					SexSreach(hp, a);
					printf("�Ƿ����ִ��(Y / N):");
					scanf("%c", &j);
					system("cls");
				} while (j == 'Y');
				break;
			case 4:
				do {
					printf("1. ���� 2. ��ѧ 3.Ӣ�� 4.�ܷ� :");
					scanf("%d", &a);
					printf("1.���� 2.���� : ");
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
					printf("�Ƿ����ִ��(Y / N):");
					scanf("%c", &j);
					system("cls");
				} while (j == 'Y');
				break;
			case 5:
				do {
					MajorSreach(hp);
					printf("�Ƿ����ִ��(Y / N):");
					scanf("%c", &j);
					system("cls");
				} while (j == 'Y');
				break;
			}
			break;
		case 3:
			do {
				Change(hp);
				printf("�Ƿ����ִ��(Y / N):");
				scanf("%c", &j);
				system("cls");
			} while (j == 'Y');
			break;
		case 4:
			do {
				printf("1.ɾ��  2.��� :  ");
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
				printf("�Ƿ����ִ��(Y / N):");
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