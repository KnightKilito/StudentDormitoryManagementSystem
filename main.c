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
	        printf("                                 �t(*�㨌��*)�s==��ӭ�´�ʹ�ã�==�t(*�㨌��*)�s                              \n\n");
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
			//students[stu_index++]=p;//������Ҫ�� 
			node = add_node(p);
			if(head==0)	
				head = node;
			else
			{
				struct node_StudentInfo *tmpNode = head;
				while(tmpNode->next != 0)
				{//ѭ���ҵ����һ���ڵ� 
					tmpNode = tmpNode->next;
				}
				tmpNode->next = node;//���½����Ľڵ���õ��������� 
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
			printf("������0~7��\n");
			break;			
	}
}

void menu()
{

	printf("\n"); 
	printf("***************************************************************************************************\n");
	printf("��                                          ��ӭʹ��             *                               ��\n");
	printf("��  *           *                      **ѧ���������ϵͳ**                                      ��\n");
	printf("��                                    **********************                     *               ��\n"); 
	printf("��                                            �� �y  ��                                           ��\n"); 
	printf("��                                           ( ��ޡ�  )                                         ��   \n"); 
	printf("��                        *             [1]�������ѧ����Ϣ           *                          ��\n");
	printf("��   *                                  [2]ɾ������ѧ����Ϣ                                      ��\n");
	printf("��                                      [3]��ѯ����ѧ����Ϣ                                      ��\n");
	printf("��                                      [4]�޸�����ѧ����Ϣ                          *           ��\n");
	printf("��                                      [5]�鿴��������ѧ����Ϣ                                  ��\n");
	printf("��            *                         [6]�������ݵ��ļ���                                      ��\n");
	printf("��                                      [7]����ѧ��ǩ������                                      ��\n");
	printf("��                                      [0]�˳�ϵͳ                                              ��\n");
	printf("��                                                                   *                           ��\n"); 
	printf("��   *                   *                                                               *       ��\n"); 
	printf("��                         *     �˳�ϵͳǰ����ؼ���Ƿ񱣴���Ҫ�����ݣ�                        ��\n");
	printf("***************************************************************************************************\n\n"); 
	printf("                                            ѡ�����");

}

int getCmd()
{
	int cmd;
	scanf("%d",&cmd);
	return cmd;
}

