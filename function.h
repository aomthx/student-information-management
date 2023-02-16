#pragma once
#define C 0
#define M 1
#define E 2
#define TOL 3
struct stu
{
	int id;
	char name[10];
	char major[10];
	char sex[5];
	int score[4];
	char address[20];
	struct stu* next;
};
struct stu* creat();
void PutoutALL(struct stu* p);
void MajorSreach(struct stu* p);
void Sreach(struct stu* p);
void RangeSreach(struct stu* p, int i);
void SexSreach(struct stu* p, int i);
void Add(struct stu* q);
struct stu* Delete(struct stu* h);
void Change(struct stu* p);
void DownRank(struct stu* h, int a);
void UpRank(struct stu* h, int a);