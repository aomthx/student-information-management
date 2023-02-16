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
	printf("ѧ��\t����\tרҵ\t����\t��ѧ\tӢ��\t�ܷ�\n");
	while (p) {
		printf("%d\t%s\t%s\t%d\t%d\t%d\t%d\n", p->id, p->name, p->major, p->score[C], p->score[M], p->score[E], p->score[TOL]);
		p = p->next;
	}
	getchar();
}

void MajorSreach(struct stu* p)
{
	char major[][10] = { "�ƿ�","����" };
	int i;
	printf("�������ѯרҵ(1.�ƿ� 2.���� ): ");
	scanf("%d", &i);
	i -= 1;
	printf("ѧ��\t����\tרҵ\t����\t��ѧ\tӢ��\t�ܷ�\n");
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
	printf("������Ҫ��ѯ��Ϣ��ѧ��ѧ�ţ�");
	scanf("%d", &a);
	while (1)
	{
		if (p == NULL)
		{
			printf("ѧ��������\n");
			break;
		}
		else {
			if (p->id == a)
			{
				printf("ѧ��:%d\n����:%s\n�Ա�:%s\nרҵ:%s\n��ͥסַ:%s\n���ĳɼ�:%d\n��ѧ�ɼ�:%d\nӢ��ɼ�:%d\n�ܷ�:%d\n", p->id, p->name, p->sex, p->major, p->address, p->score[C], p->score[M], p->score[E], p->score[TOL]);
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
	printf("������������䣨��������60 80����");
	scanf("%d %d", &a, &b);
	printf("ѧ��\t����\t����\n");
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
		printf("��\n");
	}
	getchar();
}

void SexSreach(struct stu* p, int i)
{
	printf("ѧ��\t����\t�Ա�\t����\t��ѧ\tӢ��\t�ܷ�\n");
	while (p)
	{
		switch (i)
		{
		case 1:
			if (strcmp(p->sex, "��") == 0)
			{
				printf("%d\t%s\t%s\t%d\t%d\t%d\t%d\n", p->id, p->name, p->sex, p->score[C], p->score[M], p->score[E], p->score[TOL]);
			}
			break;
		case 2:
			if (strcmp(p->sex, "Ů") == 0)
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
	printf("������ѧ����Ϣ��\n");
	printf("ѧ�ţ�");
	scanf("%d", &p->id);
	printf("������");
	scanf("%s", p->name);
	printf("�Ա�");
	scanf("%s", p->sex);
	printf("��ͥסַ��");
	scanf("%s", p->address);
	printf("���ĳɼ���");
	scanf("%d", &p->score[C]);
	printf("��ѧ�ɼ���");
	scanf("%d", &p->score[M]);
	printf("Ӣ��ɼ���");
	scanf("%d", &p->score[E]);
	p->score[TOL] = p->score[C] + p->score[M] + p->score[E];
	q->next = p;
	p->next = NULL;
	printf("��ӳɹ�\n");
	getchar();
}

struct stu* Delete(struct stu* h)
{
	int a;
	struct stu* p1, * p2;
	p1 = p2 = h;
	printf("������Ҫɾ��������ѧ��ѧ�ţ�");
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
	printf("�ɹ�ɾ��\n");
	getchar();
	return h;
}

void Change(struct stu* p)
{
	int a, i, j;
	printf("������Ҫ�޸���Ϣ��ѧ��ѧ�ţ�");
	scanf("%d", &a);
	while (1)
	{
		if (p == NULL)
		{
			printf("ѧ��������\n");
		}
		else {
			if (p->id == a)
			{
				printf("�޸�ѡ�1.���� 2.�Ա� 3.��ͥסַ 4.���Ƴɼ� : ");
				scanf("%d", &i);
				switch (i)
				{
				case 1:
					printf("���ģ�");
					scanf("%s", p->name);
					break;
				case 2:
					printf("���ģ�");
					scanf("%s", p->sex);
					break;
				case 3:
					printf("���ģ�");
					scanf("%s", p->address);
					break;
				case 4:
					printf("�γ̣�1.���� 2.��ѧ 3.Ӣ���");
					scanf("%d", &j);
					switch (j)
					{
					case 1:
						printf("���ģ�");
						scanf("%d", &p->score[C]);
						break;
					case 2:
						printf("���ģ�");
						scanf("%d", &p->score[M]);
						break;
					case 3:
						printf("���ģ�");
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
	printf("ѧ��\t����\t����\t��ѧ\tӢ��\t�ܷ�\n");
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
	printf("ѧ��\t����\t����\t��ѧ\tӢ��\t�ܷ�\n");
	while (p != NULL) {
		printf("%d\t%s\t%d\t%d\t%d\t%d\n", p->id, p->name, p->score[C], p->score[M], p->score[E], p->score[TOL]);
		p = p->next;
	}
	getchar();
}