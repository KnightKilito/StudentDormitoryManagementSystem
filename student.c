#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "student.h"
#include <time.h>

struct StudentInfo * students[100];
int stu_index=0;

struct node_StudentInfo * head = 0;
//��һ���ڵ�浽�ļ��� 
void save_node(struct node_StudentInfo *node ,FILE *fp)
{
	fprintf(fp, "%d ", node->data->id);
	fprintf(fp, "%s ", node->data->name);
	fprintf(fp, "%s ", node->data->gender);
	fprintf(fp, "%d ", node->data->age);
	fprintf(fp, "%s ", node->data->roomName);
	fprintf(fp, "%d\n", node->data->lateTime);

}

void read_all()
{
	//if(head==0) return;
	FILE *fp = 0;//ָ����0Ҳ����NULL
	fp=fopen("abc.txt","r");//���ļ�  �򿪷�ʽ�Ƕ�ȡ
	if(fp==0)//�ж�
	{
		printf("                                        δ��ѯ�����ش浵��\n\n");
		return;
	}
	//�������
	int id;
	char name[20];
	char gender[2];
	int age;
	char roomname[20];
	int latetime;
	while(1==1)
	{
		if(feof(fp)) break;//�ж��ļ��Ƿ��ȡ����
		//��ȡ�ļ�  ��ȡ��ʽҪһ��
		fscanf(fp, "%d %s %s %d %s %d\n",&id,name,gender,&age,roomname,&latetime);
		struct StudentInfo * stuInfo = malloc( sizeof(struct StudentInfo));
		stuInfo->id = id;
		strcpy( stuInfo->name,name );//�ַ�����strcpy
		stuInfo->age = age;
		strcpy(stuInfo->gender,gender);
		strcpy( stuInfo->roomName, roomname);
		stuInfo->lateTime = latetime;
		struct node_StudentInfo *node = add_node(stuInfo);//�����ڵ�
		if(head==0)	
			head = node;//����ڵ�û�� �Ͱѽڵ�����Ϊͷ�ڵ�
		else
		{
			struct node_StudentInfo *tmpNode = head;
			while(tmpNode->next != 0)
			{//ѭ���ҵ����һ���ڵ� 
				tmpNode = tmpNode->next;
			}
			tmpNode->next = node;//���½����Ľڵ���õ��������� 
		}
	}
	//printf("%d;%s;%s;%d;%s",id,name,gender,age,roomname);	
	fclose(fp);
	printf("                                        �ɹ���ѯ�����ش浵��\n\n");
}

void save_all()
{
	if(head==0) return;//�ж�
	FILE *fp = 0;//�ĵ�����
	fp=fopen("abc.txt","w");//���ĵ�
	if(fp==0)//�жϷ��ص��Ƿ�����ǿ�ָ��
	{
		printf("�ļ���ʧ��\n");
		return;
	}
	struct node_StudentInfo * tmpNode = head;
	while( tmpNode != 0)//�ж���һ����ַ�Ƿ�Ϊnull
	{
		save_node(tmpNode, fp);//ִ�к���������һ�ڵ����ĵ�
		tmpNode = tmpNode -> next;//��һ����ַ������ǰָ��
	}
	fclose(fp);//�ر��ļ�
	printf("������Ϣ���Ѵ�ŵ��ļ����ˣ�\n"); 
}
//�����ڵ� 
struct node_StduentInfo * add_node(struct StudentInfo *data)//���������ڵ㺯��
{   //Ϊָ��node�����ڴ�ռ�
	struct node_StudentInfo * node = (struct node_StudentInfo*)malloc( sizeof(struct node_StudentInfo) );
	node->data = data;//��node��������ֵ
	node->next = 0;//����ӵĽڵ�λ�ڱ�β����������ָ����ΪNULL
	return node;//����head�ĵ�ַ
}
//�ͷŽڵ� 
void free_node (struct node_StudentInfo * p)
{
	if(p==0) return;//�Ҳ������߽ڵ�Ϊ�գ���ֱ�ӷ���
	if(p->data!=0)
	{
		printf("�ɹ��ͷ�ѧ��Ϊ%d��ѧ����Ϣ�Ľڵ㣡\n",p->data->id);
		free(p->data);//tip:free()ֻ���ͷŶ��ڴ棬Ҳ����malloc()�����Ŀռ�
		p->data=0;
	}
	p->next=0;
	free(p);//�ͷ���һ���ڵ���ڴ�ռ�
	p=0;
}
//�ͷ����нڵ� 
void free_all()
{
	if(head==0) return;
	struct node_StudentInfo * tmpNode = head;//��node_StudentInfo���½�������ʱ�ڵ㺯��
	while(tmpNode!=0)
	{
		struct node_StudentInfo *tmpNode2 = tmpNode;//����Ҫ�ͷŵĽڵ�浽tmpNode2��
		tmpNode=tmpNode->next;//tmpNode����ָ����һ���ڵ�
		free_node(tmpNode2);//�ͷ�tmpNode2
	}
	head=0;
}

void printStudentInfo(struct StudentInfo *p)
{
	printf("\n");
	printf("                              ��������������������������������������\n");
	printf("                              \t\tѧ����ѧ��Ϊ��%d\n", p->id);
	printf("                              \t\tѧ��������Ϊ��%s\n", p->name);
	printf("                              \t\tѧ�����Ա�Ϊ��%s\n", p->gender);
	printf("                              \t\tѧ��������Ϊ��%d\n", p->age);
	printf("                              \t\tѧ���������Ϊ��%s\n", p->roomName);
	printf("                              \t\tѧ���ĳٵ�����Ϊ��%d\n", p->lateTime);
	printf("                              ��������������������������������������\n");
}

void printAll()
{
	//int i=0;
	//for(i=0;i<stu_index;i++)
	//{
	//	printStudentInfo( students[i] );
	//}������Ҫ
	struct node_StudentInfo * tmpNode = head;
	while(tmpNode != 0)
	{
		printStudentInfo( tmpNode->data );
		tmpNode = tmpNode->next;
	} 
}
struct StudentInfo * add()
{
	printf("\n���ѧ����Ϣ\n\n");
	//struct StudentInfo si;
	struct StudentInfo *si;//����һ��ָ�룬����������ݱ��浽ָ���Ľṹ�������
	//Ϊָ������һ�οռ䣬���������ǽṹ���еĽṹ����
	si = (struct StudentInfo *)malloc( sizeof(struct StudentInfo) );
	
	printf("������ѧ����ѧ�ţ�");
	int id = 0;
	scanf("%d",&id);
	//���浽�ṹ�����id�У�����id����һ��������һ���ǽṹ���е�id����һ�����������id��
	//�����id��ֵ��ָ�룬ָ��ָ��ṹ�壬����ͬ��
	si->id = id;
	
	printf("������ѧ����������");
	char name[20];
	scanf("%s", name);
	strcpy(si->name,name);//���浽�ṹ�����name�У�char����Ҫʹ��strcpy����
	
	printf("������ѧ�������䣺");
	int age = 0;
	scanf("%d",&age);
	si->age = age;
	
	printf("������ѧ�����Ա�");
	char sex[2];
	scanf("%s",sex);
	strcpy(si->gender,sex);
	
	printf("������ѧ��������ţ�");
	char roomname[20];
	scanf("%s",roomname);
	strcpy(si->roomName,roomname);
	
	printf("������ѧ����ǰ�ĳٵ�������");
	int latetime = 0;
	scanf("%d", &latetime);
	si->lateTime = latetime;
	
	//printStudentInfo(si);
	printf("�ɹ�������ѧ����Ϣ��\n\n");
	return si;
}

void del()
{
	printf("\nɾ��ѧ����Ϣ\n\n");
	printf("������ɾ��ѧ��ѧ�ţ�");
	int stuNo;
	scanf("%d", &stuNo);
	struct node_StudentInfo * tmpNode1=0;
	struct node_StudentInfo * tmpNode2=0;
	struct node_StudentInfo * tmpNode3=0;
	tmpNode1 = head;
	if(tmpNode1 == 0) 
	{
		printf("δ�鵽��ѧ����Ϣ��\n");
	    return;}
	//������ֻ��һ���ڵ㣬��Ҫɾ������������Ϊ0 
	if(tmpNode1->next==0) 
	{
		if(tmpNode1->data->id==stuNo)
		{
			free_node(head);//�ͷ�ͷ�ڵ�
			head = 0;//��ͷ�ڵ㸳ֵΪ0����Ϊɾ����
			printf("�ɹ�ɾ����ѧ����Ϣ��\n\n");
		}
		return;
	}
	if(tmpNode1 != 0)//�ж�ڵ�ʱ�����
	{
		tmpNode2 = tmpNode1->next;
	}
	//�������ж���ڵ㣬Ҫɾ��ͷ�ڵ㣬��ͷ�ڵ�ָ��ڶ��ڵ� 
	if(tmpNode1->data->id==stuNo && tmpNode1==head && tmpNode2!=0)//��ڵ㣬ɾ���Ľڵ�Ϊͷ�ڵ�ʱ
	{
		free_node(head);//�ͷ�ͷ�ڵ�
		head = tmpNode2;//��head�ڵ㸳ֵ
		printf("�ɹ�ɾ����ѧ����Ϣ��\n\n");
		return;
	}
	while(tmpNode1 != 0 && tmpNode2 != 0)//��ڵ㣬ɾ���Ľڵ�Ϊ�м�ڵ�ʱ
	{
		if(tmpNode2->data->id==stuNo)//�ҵ��м��ɾ���Ľڵ�
		{
			tmpNode1->next = tmpNode2->next;
			free_node(tmpNode2);
			tmpNode2=0;
			printf("�ɹ�ɾ����ѧ����Ϣ��\n\n"); 
			break; 
		}else//�Ҳ���ʱͨ��ָ����һ������������
		{
			tmpNode1 = tmpNode1->next;
			tmpNode2 = tmpNode2->next;
			printf("���޴�ѧ����Ϣ��\n\n");
		}
	}
}

void lookup()
{
	printf("\n��ѯѧ����Ϣ\n\n");
	printf("������ѧ����ѧ�ţ�");
	int stuNo=0;
	scanf("%d",&stuNo);//scanf�������ѧ����ѧ��
	struct node_StudentInfo * tmpNode = head;
	int found=0;//����һ������
	while(tmpNode!=0)	//��Ϊ0���������ѭ���������еĽڵ��������
	{
		if(tmpNode->data->id==stuNo)/*data����ǰ��struct StudentInfo�����ݣ���ָ����Ϊ����ѧ�Ų�������ָ��id==���Ƕ����stuNo���ҵ���*/
		{
			printStudentInfo(tmpNode->data);//�ҵ���֮���ӡѧ����Ϣ
			found=1;//�ҵ���
			break;//����ѭ��
		}
		tmpNode=tmpNode->next;
	} 
	if(found==0)//û���ҵ�
	{
		printf("���޴�ѧ����Ϣ��\n\n");
	}
	
}

void modify()
{
	printf("\n�޸�ѧ����Ϣ\n\n");
	printf("��������Ҫ�޸ĵ�ѧ��ѧ�ţ�");
	int id=-1;
	scanf("%d",&id);
	struct node_StudentInfo * tmpNode = head;
	int found=0;
	while(tmpNode!=0)	
	{
		if(tmpNode->data->id==id)
		{
			printStudentInfo(tmpNode->data);
			found=1;
			break;
		}else
			tmpNode=tmpNode->next;
	} 
	if(found==0)
	{
		printf("���޴�ѧ����Ϣ��\n");
		return;
	}
	while(1==1)
	{
		
		printf("\n"); 
	printf("***************************************************************************************************\n");
	printf("��                                          ��ӭʹ��             *                               ��\n");
	printf("��  *           *                      **ѧ����Ϣ�޸�ϵͳ**                                      ��\n");
	printf("��                                    **********************                     *               ��\n"); 
	printf("��   *                   *                   OWO                                         *       ��\n");
	printf("��                        *             [1]�޸�ѧ��ѧ��               *                          ��\n");
	printf("��   *                                  [2]�޸�ѧ������                                          ��\n");
	printf("��                                      [3]�޸�ѧ���Ա�                                          ��\n");
	printf("��                                      [4]�޸�ѧ������                              *           ��\n");
	printf("��                                      [5]�޸�ѧ�������                                        ��\n");
	printf("��                                      [0]�˳���Ϣ�޸�ϵͳ                 *                    ��\n"); 
	printf("��   *                   *                                                               *       ��\n"); 
	printf("***************************************************************************************************\n\n"); 
	printf("                                            ѡ�����");

		int cmd = -1;
		int No = -1;
		char Name[20];
		char Gender[2];
		int Age = -1;
		char Roomname[20];
		scanf("%d",&cmd);
		if(cmd==0)
		{
			break;
		}
		switch(cmd)
		{
			case 1:
				printf("�޸�ѧ��ѧ��\n\n");
				printf("������ѧ����ѧ�ţ�");
				scanf("%d",&No);
				tmpNode->data->id=No;
				printf("\n�ɹ��޸�ѧ��ѧ�ţ�\n\n");
				break;
			case 2:
				printf("�޸�ѧ������\n\n");
				printf("������ѧ����������");
				scanf("%s",Name);
				strcpy(tmpNode->data->name,Name);
				printf("\n�ɹ��޸�ѧ��������\n\n");
				break;
			case 3:
				printf("�޸�ѧ���Ա�\n\n");
				printf("������ѧ�����Ա�");
				scanf("%s",Gender);
				strcpy(tmpNode->data->gender,Gender);
				printf("\n�ɹ��޸�ѧ���Ա�\n\n");
				break;
			case 4:
				printf("�޸�ѧ������\n\n");
				printf("������ѧ�������䣺");
				scanf("%d",&Age);
				tmpNode->data->age=Age;
				printf("\n�ɹ��޸�ѧ�����䣡\n\n");
				break;
			case 5:
				printf("�޸�ѧ�������\n\n");
			    printf("������ѧ��������ţ�");
				scanf("%s",Roomname);
				strcpy(tmpNode->data->roomName,Roomname);
				printf("\n�ɹ��޸�ѧ������ţ�\n\n");
				break;	
			default:
				printf("��������ڣ�");
				break;		
		}
	}
	
}

//ѧ��ǩ����Ϣ����
void lateTime()
{
	printf("\n����ѧ��ǩ������\n\n");
	
	printf("��������Ҫ����ǩ�������ѧ��ѧ�ţ�");//��ѯѧ�Ŷ�ѧ�Ŷ�Ӧ��ѧ������ǩ����Ϣ����
	int stuNo = -1;
	scanf("%d", &stuNo);
	struct node_StudentInfo *tmpNode = head;
	int found = 0;
	while (tmpNode != 0)
	{
		if (tmpNode->data->id == stuNo)
		{
			printStudentInfo(tmpNode->data);
			found = 1;//�ҵ���ѧ�Ŷ�Ӧ��ѧ��֮�����ñ��=1
			break;
		}
		else
		{
			tmpNode = tmpNode->next;
		}
	}
	if (found == 0) //��foundΪ0���ʾδ�ҵ�ѧ����Ϣ
	{
		printf("���޴�ѧ����Ϣ��\n\n");
		return;
	}
	while (1 == 1)
	{
		
			printf("\n"); 
	printf("***************************************************************************************************\n");
	printf("��                                          ��ӭʹ��             *                               ��\n");
	printf("��  *           *                      **ѧ��ǩ����Ϣϵͳ**                                      ��\n");
	printf("��                                    **********************                     *               ��\n"); 
	printf("��   *                   *                    OUO                                        *       ��\n");
	printf("��                        *             [1]Ϊ��ѧ������ǩ��          *                           ��\n");
	printf("��   *                                  [2]�鿴��ѧ���ٵ�����                                    ��\n");
	printf("��                                      [3]�޸�ѧ���ٵ�����                                      ��\n");
	printf("��                                      [0]�˳�ǩ����Ϣϵͳ                          *           ��\n");
	printf("��                                                                   *                           ��\n"); 
	printf("��   *                   *                                                               *       ��\n"); 
	printf("***************************************************************************************************\n\n"); 
	printf("                                            ѡ�����");
		int cmd = -1;
		int Latetime = -1;//�����õĲ�����ʼ�������ȡ��������ֵ
		
		scanf("%d", &cmd);

		if (cmd == 0)
			break;
		switch (cmd)
		{
		case 1:
		    
			printf("����ǩ���С���\n\n");
			caltime();//ǩ������
			break;
		case 2:

			printf("\n��ѧ���ĳٵ�����Ϊ��%d\n\n",tmpNode->data->lateTime);
			break;
		case 3:
            printf("\n�޸ĳٵ�����\n\n");
			printf("������ѧ���ĳٵ�������");
			scanf("%d", &Latetime);
			tmpNode->data->lateTime = Latetime;//ͨ��ָ���������벢�Ҹ�����ǰ�������ֵ
			printf("\n�޸ĳٵ������ɹ���\n\n");
			break;	

		default:
			printf("\n��������ڣ�\n\n");
			break;
		}
	}

}

//ǩ������
void caltime()
{
    time_t t;
	/*����time_tΪtime.h����Ľṹ�壬һ��Ϊ�����͡�����������ȡ��ǰʱ�䣬�����ء� 
    �������__timer�ǿգ���洢��ֵͬ��__timerָ����ڴ��С� */
    struct tm * lt;
	int Latetime = 0;
	int Latetime2 = 0;
	struct node_StudentInfo *tmpNode = head;//ͨ��ָ����������ǰ���������

    time (&t);//��ȡUnixʱ���������1970��1��1�գ�UTC/GMT����ҹ����ʼ�����������������������롣����������Ϊ��λ�ģ������Ⲣ����ϰ���ϵ�ʱ�䣬ҪתΪϰ���ϵ�������ʱ����ʽ����Ҫ����һ�������ˡ�
    lt = localtime (&t);//תΪʱ��ṹ��
	//localtime������ʽΪstruct tm *localtime (const time_t *__timer)������tmΪһ���ṹ�壬������������ʱ�������Ϣ��
	//struct tm�е�tm_year ֵΪʵ�����ȥ1900�� ���������ʱ��Ҫ��lt->tm_year+1900��ͬ�� lt->tm_mon+1��
    printf ( "������%d/%d/%d %d:%d:%d\n",lt->tm_year+1900, lt->tm_mon+1, lt->tm_mday, lt->tm_hour, lt->tm_min, lt->tm_sec);//������
    if(lt->tm_hour >=23 && lt->tm_min >10)//��Ϊ23:10֮�����ǩ����Ϊ�ٵ�
    {
        printf("\nͬѧ���γٵ����´�ע�ⲻ���ٳٵ���Ӵ~�����أ�����\n\n");

		Latetime= tmpNode->data->lateTime;       //ͨ���м���ֵ��lateTime�еĲ�����ֵ����+1�Ĳ�������Ϊ�ٵ�����+1
		Latetime2=Latetime+1;
		tmpNode->data->lateTime = Latetime2;
		
    }
	else if(lt->tm_hour <=5 && lt->tm_min <30)//��Ϊ5:30֮ǰ����ǩ����Ϊ�ٵ�
    {
        printf("\nͬѧ���γٵ����´�ע�ⲻ���ٳٵ���Ӵ~�����أ�����\n\n");

		Latetime= tmpNode->data->lateTime;
		Latetime2=Latetime+1;
		tmpNode->data->lateTime = Latetime2;
		
    }
    else
    {
        printf("\nͬѧ����δ�ٵ���Ҫ����Ŭ���������õ�����ϰ��Ŷ~b(������)d��\n\n");
    }

    
    return;
}
