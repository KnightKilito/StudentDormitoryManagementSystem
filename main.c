#include<stdio.h>
#include"student.h"
#include<stdlib.h>
#include "student.c"

void menu();
int getCmd();
void executeCmd(int cmd);

int main()
{	
	read_all();
	int cmd;
	while(1==1)
	{
		menu();
		cmd = getCmd();
		if(cmd==0)
		{
			//save_all();
			free_all();
			printf("\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
	        printf("                                 ╰(*°▽°*)╯==欢迎下次使用！==╰(*°▽°*)╯                              \n\n");
	        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			system("pause");
			return 0;
		} 
		executeCmd(cmd);
	}
	system("pause");
	return 0;
} 

void executeCmd(int cmd)
{
	struct StudentInfo * p;
	struct node_StudentInfo *node;
	switch(cmd)
	{
		case 1:
			p = add();
			//printStudentInfo(p);
			//students[stu_index++]=p;//数组需要的 
			node = add_node(p);
			if(head==0)	
				head = node;
			else
			{
				struct node_StudentInfo *tmpNode = head;
				while(tmpNode->next != 0)
				{//循环找到最后一个节点 
					tmpNode = tmpNode->next;
				}
				tmpNode->next = node;//把新建立的节点放置到链表的最后 
			}
			break;
		case 2:
			del();
			break;
		case 3:
			lookup();
			break;
		case 4:
			modify();
			break;
		case 5:
			printAll();
			break;
		case 6:
			save_all();
			break;
		case 7:
			lateTime();
			break;			
		default:
			printf("请输入0~7！\n");
			break;			
	}
}

void menu()
{

	printf("\n"); 
	printf("***************************************************************************************************\n");
	printf("￥                                          欢迎使用             *                               ￥\n");
	printf("￥  *           *                      **学生宿舍管理系统**                                      ￥\n");
	printf("￥                                    **********************                     *               ￥\n"); 
	printf("￥                                            ∩ ▂  ∩                                           ￥\n"); 
	printf("￥                                           ( ●＾●  )                                         ￥   \n"); 
	printf("￥                        *             [1]添加宿舍学生信息           *                          ￥\n");
	printf("￥   *                                  [2]删除宿舍学生信息                                      ￥\n");
	printf("￥                                      [3]查询宿舍学生信息                                      ￥\n");
	printf("￥                                      [4]修改宿舍学生信息                          *           ￥\n");
	printf("￥                                      [5]查看宿舍所有学生信息                                  ￥\n");
	printf("￥            *                         [6]保存数据到文件中                                      ￥\n");
	printf("￥                                      [7]归宿学生签到管理                                      ￥\n");
	printf("￥                                      [0]退出系统                                              ￥\n");
	printf("￥                                                                   *                           ￥\n"); 
	printf("￥   *                   *                                                               *       ￥\n"); 
	printf("￥                         *     退出系统前请务必检查是否保存需要的数据！                        ￥\n");
	printf("***************************************************************************************************\n\n"); 
	printf("                                            选择命令：");

}

int getCmd()
{
	int cmd;
	scanf("%d",&cmd);
	return cmd;
}

