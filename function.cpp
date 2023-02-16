#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"function.h"

struct stu* creat()
{
	struct stu* p1, * p2 = NULL, * h = NULL;

	FILE* fp = fopen("d:\\f.txt", "r");
	while (feof(fp) == 0)
	{
		p1 = (struct stu*)malloc(sizeof(struct stu));
		fscanf(fp, "%d %s %s %s %d %d %d %s", &p1->id, p1->name, p1->major, p1->sex, &p1->score[C], &p1->score[M], &p1->score[E], p1->address);
		p1->score[TOL] = p1->score[C] + p1->score[M] + p1->score[E];
		if (h == NULL) {
			h = p2 = p1;
		}
		else {
			p2->next = p1;
			p2 = p1;
		}
	}
	p2->next = NULL;
	fclose(fp);
	return h;
}

void PutoutALL(struct stu* p)
{
	printf("学号\t姓名\t专业\t语文\t数学\t英语\t总分\n");
	while (p) {
		printf("%d\t%s\t%s\t%d\t%d\t%d\t%d\n", p->id, p->name, p->major, p->score[C], p->score[M], p->score[E], p->score[TOL]);
		p = p->next;
	}
	getchar();
}

void MajorSreach(struct stu* p)
{
	char major[][10] = { "计科","虚拟" };
	int i;
	printf("请输入查询专业(1.计科 2.虚拟 ): ");
	scanf("%d", &i);
	i -= 1;
	printf("学号\t姓名\t专业\t语文\t数学\t英语\t总分\n");
	while (p) {
		if (strcmp(p->major, major[i]) == 0) {
			printf("%d\t%s\t%s\t%d\t%d\t%d\t%d\n", p->id, p->name, p->major, p->score[C], p->score[M], p->score[E], p->score[TOL]);
		}
		p = p->next;
	}
	getchar();
}

void Sreach(struct stu* p)
{
	int a;
	printf("请输入要查询信息的学生学号：");
	scanf("%d", &a);
	while (1)
	{
		if (p == NULL)
		{
			printf("学生不存在\n");
			break;
		}
		else {
			if (p->id == a)
			{
				printf("学号:%d\n姓名:%s\n性别:%s\n专业:%s\n家庭住址:%s\n语文成绩:%d\n数学成绩:%d\n英语成绩:%d\n总分:%d\n", p->id, p->name, p->sex, p->major, p->address, p->score[C], p->score[M], p->score[E], p->score[TOL]);
				break;
			}
		}
		p = p->next;
	}
	getchar();
}

void RangeSreach(struct stu* p, int i)
{
	int a, b;
	int judge = 1;
	printf("请输入分数区间（例：输入60 80）：");
	scanf("%d %d", &a, &b);
	printf("学号\t姓名\t分数\n");
	while (p)
	{
		switch (i)
		{
		case 1:

			if (p->score[C] >= a && p->score[C] <= b)
			{
				printf("%d\t%s\t%d\n", p->id, p->name, p->score[C]);
				judge = 0;
			}
			break;
		case 2:

			if (p->score[M] >= a && p->score[M] <= b)
			{
				printf("%d\t%s\t%d\n", p->id, p->name, p->score[M]);
				judge = 0;
			}
			break;
		case 3:

			if (p->score[E] >= a && p->score[E] <= b)
			{
				printf("%d\t%s\t%d\n", p->id, p->name, p->score[E]);
				judge = 0;
			}
			break;
		case 4:

			if (p->score[TOL] >= a && p->score[TOL] <= b)
			{
				printf("%d\t%s\t%d\n", p->id, p->name, p->score[TOL]);
				judge = 0;
			}
			break;
		}
		p = p->next;
	}
	if (judge) {
		printf("无\n");
	}
	getchar();
}

void SexSreach(struct stu* p, int i)
{
	printf("学号\t姓名\t性别\t语文\t数学\t英语\t总分\n");
	while (p)
	{
		switch (i)
		{
		case 1:
			if (strcmp(p->sex, "男") == 0)
			{
				printf("%d\t%s\t%s\t%d\t%d\t%d\t%d\n", p->id, p->name, p->sex, p->score[C], p->score[M], p->score[E], p->score[TOL]);
			}
			break;
		case 2:
			if (strcmp(p->sex, "女") == 0)
			{
				printf("%d\t%s\t%s\t%d\t%d\t%d\t%d\n", p->id, p->name, p->sex, p->score[C], p->score[M], p->score[E], p->score[TOL]);
			}
			break;
		}
		p = p->next;
	}
	getchar();
}

void Add(struct stu* q)
{
	struct stu* p;
	p = (struct stu*)malloc(sizeof(struct stu));
	while (q->next) {
		q = q->next;
	}
	printf("请输入学生信息：\n");
	printf("学号：");
	scanf("%d", &p->id);
	printf("姓名：");
	scanf("%s", p->name);
	printf("性别：");
	scanf("%s", p->sex);
	printf("家庭住址：");
	scanf("%s", p->address);
	printf("语文成绩：");
	scanf("%d", &p->score[C]);
	printf("数学成绩：");
	scanf("%d", &p->score[M]);
	printf("英语成绩：");
	scanf("%d", &p->score[E]);
	p->score[TOL] = p->score[C] + p->score[M] + p->score[E];
	q->next = p;
	p->next = NULL;
	printf("添加成功\n");
	getchar();
}

struct stu* Delete(struct stu* h)
{
	int a;
	struct stu* p1, * p2;
	p1 = p2 = h;
	printf("请输入要删除档案的学生学号：");
	scanf("%d", &a);
	while (p1 != NULL)
	{
		if (a == p1->id) {
			if (p1 == h)
			{
				h = p1->next;
				p1->next = NULL;
			}
			else {
				p2->next = p1->next;
				p1->next = NULL;
			}
			free(p1);
			break;
		}
		p2 = p1;
		p1 = p1->next;
	}
	printf("成功删除\n");
	getchar();
	return h;
}

void Change(struct stu* p)
{
	int a, i, j;
	printf("请输入要修改信息的学生学号：");
	scanf("%d", &a);
	while (1)
	{
		if (p == NULL)
		{
			printf("学生不存在\n");
		}
		else {
			if (p->id == a)
			{
				printf("修改选项：1.姓名 2.性别 3.家庭住址 4.各科成绩 : ");
				scanf("%d", &i);
				switch (i)
				{
				case 1:
					printf("更改：");
					scanf("%s", p->name);
					break;
				case 2:
					printf("更改：");
					scanf("%s", p->sex);
					break;
				case 3:
					printf("更改：");
					scanf("%s", p->address);
					break;
				case 4:
					printf("课程（1.语文 2.数学 3.英语）：");
					scanf("%d", &j);
					switch (j)
					{
					case 1:
						printf("更改：");
						scanf("%d", &p->score[C]);
						break;
					case 2:
						printf("更改：");
						scanf("%d", &p->score[M]);
						break;
					case 3:
						printf("更改：");
						scanf("%d", &p->score[E]);
						break;
					}
					p->score[TOL] = p->score[C] + p->score[M] + p->score[E];
					break;
				}
				break;
			}
		}
		p = p->next;
	}
	getchar();
}

void DownRank(struct stu* h, int a)
{
	int count = 0;
	int i, j;
	struct stu* o, * hp, * p, * p1, * p2, * p3;
	hp = (struct stu*)malloc(sizeof(struct stu));
	hp->next = h;
	o = h;
	while (o) {
		count++;
		o = o->next;
	}
	switch (a)
	{
	case 1:
		for (i = 0; i < count; i++) {
			p1 = hp;
			p2 = hp->next;
			p3 = p2->next;
			for (j = i; j < count - 1; j++) {
				if (p2->score[C] > p3->score[C]) {
					p2->next = p3->next;
					p1->next = p3;
					p3->next = p2;
				}
				p1 = p1->next;
				p2 = p1->next;
				p3 = p2->next;
			}
		}
		break;
	case 2:
		for (i = 0; i < count; i++) {
			p1 = hp;
			p2 = hp->next;
			p3 = p2->next;
			for (j = i; j < count - 1; j++) {
				if (p2->score[M] > p3->score[M]) {
					p2->next = p3->next;
					p1->next = p3;
					p3->next = p2;
				}
				p1 = p1->next;
				p2 = p1->next;
				p3 = p2->next;
			}
		}
		break;
	case 3:
		for (i = 0; i < count; i++) {
			p1 = hp;
			p2 = hp->next;
			p3 = p2->next;
			for (j = i; j < count - 1; j++) {
				if (p2->score[E] > p3->score[E]) {
					p2->next = p3->next;
					p1->next = p3;
					p3->next = p2;
				}
				p1 = p1->next;
				p2 = p1->next;
				p3 = p2->next;
			}
		}
		break;
	case 4:
		for (i = 0; i < count; i++) {
			p1 = hp;
			p2 = hp->next;
			p3 = p2->next;
			for (j = i; j < count - 1; j++) {
				if (p2->score[TOL] > p3->score[TOL]) {
					p2->next = p3->next;
					p1->next = p3;
					p3->next = p2;
				}
				p1 = p1->next;
				p2 = p1->next;
				p3 = p2->next;
			}
		}
		break;
	}
	h = hp->next;
	p = hp->next;
	free(hp);
	printf("学号\t姓名\t语文\t数学\t英语\t总分\n");
	while (p != NULL) {
		printf("%d\t%s\t%d\t%d\t%d\t%d\n", p->id, p->name, p->score[C], p->score[M], p->score[E], p->score[TOL]);
		p = p->next;
	}
	getchar();
}

void UpRank(struct stu* h, int a)
{
	int count = 0;
	int i, j;
	struct stu* o, * hp, * p, * p1, * p2, * p3;
	hp = (struct stu*)malloc(sizeof(struct stu));
	hp->next = h;
	o = h;
	while (o) {
		count++;
		o = o->next;
	}
	switch (a)
	{
	case 1:
		for (i = 0; i < count; i++) {
			p1 = hp;
			p2 = hp->next;
			p3 = p2->next;
			for (j = i; j < count - 1; j++) {
				if (p2->score[C] < p3->score[C]) {
					p2->next = p3->next;
					p1->next = p3;
					p3->next = p2;
				}
				p1 = p1->next;
				p2 = p1->next;
				p3 = p2->next;
			}
		}
		break;
	case 2:
		for (i = 0; i < count; i++) {
			p1 = hp;
			p2 = hp->next;
			p3 = p2->next;
			for (j = i; j < count - 1; j++) {
				if (p2->score[M] < p3->score[M]) {
					p2->next = p3->next;
					p1->next = p3;
					p3->next = p2;
				}
				p1 = p1->next;
				p2 = p1->next;
				p3 = p2->next;
			}
		}
		break;
	case 3:
		for (i = 0; i < count; i++) {
			p1 = hp;
			p2 = hp->next;
			p3 = p2->next;
			for (j = i; j < count - 1; j++) {
				if (p2->score[E] < p3->score[E]) {
					p2->next = p3->next;
					p1->next = p3;
					p3->next = p2;
				}
				p1 = p1->next;
				p2 = p1->next;
				p3 = p2->next;
			}
		}
		break;
	case 4:
		for (i = 0; i < count; i++) {
			p1 = hp;
			p2 = hp->next;
			p3 = p2->next;
			for (j = i; j < count - 1; j++) {
				if (p2->score[TOL] < p3->score[TOL]) {
					p2->next = p3->next;
					p1->next = p3;
					p3->next = p2;
				}
				p1 = p1->next;
				p2 = p1->next;
				p3 = p2->next;
			}
		}
		break;
	}
	h = hp->next;
	p = hp->next;
	free(hp);
	printf("学号\t姓名\t语文\t数学\t英语\t总分\n");
	while (p != NULL) {
		printf("%d\t%s\t%d\t%d\t%d\t%d\n", p->id, p->name, p->score[C], p->score[M], p->score[E], p->score[TOL]);
		p = p->next;
	}
	getchar();
}