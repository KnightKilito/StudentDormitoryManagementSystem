#ifndef __STUDENT_H__
#define __STUDENT_H__

extern struct StudentInfo * students[100];
extern int stu_index;
extern struct node_StudentInfo * head;


struct StudentInfo
{
	int id;
	char name[20];
	char gender[2];
	int age;
	char roomName[20];
	int lateTime;
};

//����ṹ�壺�洢��������
struct node_StudentInfo
{
	struct StudentInfo *data;//����������
	struct node_StudentInfo *next;//����ָ����
};

//void save_node(struct node_StudentInfo *node ,FILE *fp);

void save_all();

void read_all(); 

struct node_StduentInfo * add_node(struct StudentInfo *data);

struct StudentInfo * add();
void printStudentInfo(struct StudentInfo *p);

void del();

void lookup();

void modify();

void printAll();

void free_all();

void caltime();



#endif
