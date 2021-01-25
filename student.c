#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "student.h"
#include <time.h>

struct StudentInfo * students[100];
int stu_index=0;

struct node_StudentInfo * head = 0;
//把一个节点存到文件中 
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
	FILE *fp = 0;//指针是0也可以NULL
	fp=fopen("abc.txt","r");//打开文件  打开方式是读取
	if(fp==0)//判断
	{
		printf("                                        未查询到本地存档！\n\n");
		return;
	}
	//定义变量
	int id;
	char name[20];
	char gender[2];
	int age;
	char roomname[20];
	int latetime;
	while(1==1)
	{
		if(feof(fp)) break;//判断文件是否读取结束
		//读取文件  读取格式要一样
		fscanf(fp, "%d %s %s %d %s %d\n",&id,name,gender,&age,roomname,&latetime);
		struct StudentInfo * stuInfo = malloc( sizeof(struct StudentInfo));
		stuInfo->id = id;
		strcpy( stuInfo->name,name );//字符串用strcpy
		stuInfo->age = age;
		strcpy(stuInfo->gender,gender);
		strcpy( stuInfo->roomName, roomname);
		stuInfo->lateTime = latetime;
		struct node_StudentInfo *node = add_node(stuInfo);//创建节点
		if(head==0)	
			head = node;//如果节点没有 就把节点设置为头节点
		else
		{
			struct node_StudentInfo *tmpNode = head;
			while(tmpNode->next != 0)
			{//循环找到最后一个节点 
				tmpNode = tmpNode->next;
			}
			tmpNode->next = node;//把新建立的节点放置到链表的最后 
		}
	}
	//printf("%d;%s;%s;%d;%s",id,name,gender,age,roomname);	
	fclose(fp);
	printf("                                        成功查询到本地存档！\n\n");
}

void save_all()
{
	if(head==0) return;//判断
	FILE *fp = 0;//文档类型
	fp=fopen("abc.txt","w");//打开文档
	if(fp==0)//判断返回的是否可能是空指针
	{
		printf("文件打开失败\n");
		return;
	}
	struct node_StudentInfo * tmpNode = head;
	while( tmpNode != 0)//判断下一个地址是否为null
	{
		save_node(tmpNode, fp);//执行函数，把下一节点存放文档
		tmpNode = tmpNode -> next;//下一个地址赋给当前指针
	}
	fclose(fp);//关闭文件
	printf("数据信息都已存放到文件中了！\n"); 
}
//建立节点 
struct node_StduentInfo * add_node(struct StudentInfo *data)//声明创建节点函数
{   //为指针node申请内存空间
	struct node_StudentInfo * node = (struct node_StudentInfo*)malloc( sizeof(struct node_StudentInfo) );
	node->data = data;//给node的数据域赋值
	node->next = 0;//新添加的节点位于表尾，所以它的指针域为NULL
	return node;//返回head的地址
}
//释放节点 
void free_node (struct node_StudentInfo * p)
{
	if(p==0) return;//找不到或者节点为空，则直接返回
	if(p->data!=0)
	{
		printf("成功释放学号为%d的学生信息的节点！\n",p->data->id);
		free(p->data);//tip:free()只能释放堆内存，也就是malloc()创建的空间
		p->data=0;
	}
	p->next=0;
	free(p);//释放下一个节点的内存空间
	p=0;
}
//释放所有节点 
void free_all()
{
	if(head==0) return;
	struct node_StudentInfo * tmpNode = head;//在node_StudentInfo中新建声明临时节点函数
	while(tmpNode!=0)
	{
		struct node_StudentInfo *tmpNode2 = tmpNode;//将需要释放的节点存到tmpNode2中
		tmpNode=tmpNode->next;//tmpNode继续指向下一个节点
		free_node(tmpNode2);//释放tmpNode2
	}
	head=0;
}

void printStudentInfo(struct StudentInfo *p)
{
	printf("\n");
	printf("                              ———————————————————\n");
	printf("                              \t\t学生的学号为：%d\n", p->id);
	printf("                              \t\t学生的姓名为：%s\n", p->name);
	printf("                              \t\t学生的性别为：%s\n", p->gender);
	printf("                              \t\t学生的年龄为：%d\n", p->age);
	printf("                              \t\t学生的宿舍号为：%s\n", p->roomName);
	printf("                              \t\t学生的迟到次数为：%d\n", p->lateTime);
	printf("                              ———————————————————\n");
}

void printAll()
{
	//int i=0;
	//for(i=0;i<stu_index;i++)
	//{
	//	printStudentInfo( students[i] );
	//}数组需要
	struct node_StudentInfo * tmpNode = head;
	while(tmpNode != 0)
	{
		printStudentInfo( tmpNode->data );
		tmpNode = tmpNode->next;
	} 
}
struct StudentInfo * add()
{
	printf("\n添加学生信息\n\n");
	//struct StudentInfo si;
	struct StudentInfo *si;//定义一个指针，将输入的数据保存到指定的结构体变量中
	//为指针申请一段空间，数据类型是结构体中的结构类型
	si = (struct StudentInfo *)malloc( sizeof(struct StudentInfo) );
	
	printf("请输入学生的学号：");
	int id = 0;
	scanf("%d",&id);
	//保存到结构体变量id中，两个id不是一个东西，一个是结构体中的id，另一个是你输入的id，
	//输入的id赋值给指针，指针指向结构体，下面同理
	si->id = id;
	
	printf("请输入学生的姓名：");
	char name[20];
	scanf("%s", name);
	strcpy(si->name,name);//保存到结构体变量name中，char类型要使用strcpy函数
	
	printf("请输入学生的年龄：");
	int age = 0;
	scanf("%d",&age);
	si->age = age;
	
	printf("请输入学生的性别：");
	char sex[2];
	scanf("%s",sex);
	strcpy(si->gender,sex);
	
	printf("请输入学生的宿舍号：");
	char roomname[20];
	scanf("%s",roomname);
	strcpy(si->roomName,roomname);
	
	printf("请输入学生先前的迟到次数：");
	int latetime = 0;
	scanf("%d", &latetime);
	si->lateTime = latetime;
	
	//printStudentInfo(si);
	printf("成功创建该学生信息！\n\n");
	return si;
}

void del()
{
	printf("\n删除学生信息\n\n");
	printf("请输入删除学生学号：");
	int stuNo;
	scanf("%d", &stuNo);
	struct node_StudentInfo * tmpNode1=0;
	struct node_StudentInfo * tmpNode2=0;
	struct node_StudentInfo * tmpNode3=0;
	tmpNode1 = head;
	if(tmpNode1 == 0) 
	{
		printf("未查到该学号信息！\n");
	    return;}
	//链表中只有一个节点，且要删除他，所以置为0 
	if(tmpNode1->next==0) 
	{
		if(tmpNode1->data->id==stuNo)
		{
			free_node(head);//释放头节点
			head = 0;//将头节点赋值为0，即为删除。
			printf("成功删除该学生信息！\n\n");
		}
		return;
	}
	if(tmpNode1 != 0)//有多节点时的情况
	{
		tmpNode2 = tmpNode1->next;
	}
	//链表中有多个节点，要删除头节点，把头节点指向第二节点 
	if(tmpNode1->data->id==stuNo && tmpNode1==head && tmpNode2!=0)//多节点，删除的节点为头节点时
	{
		free_node(head);//释放头节点
		head = tmpNode2;//将head节点赋值
		printf("成功删除该学生信息！\n\n");
		return;
	}
	while(tmpNode1 != 0 && tmpNode2 != 0)//多节点，删除的节点为中间节点时
	{
		if(tmpNode2->data->id==stuNo)//找到中间该删除的节点
		{
			tmpNode1->next = tmpNode2->next;
			free_node(tmpNode2);
			tmpNode2=0;
			printf("成功删除该学生信息！\n\n"); 
			break; 
		}else//找不到时通过指向下一个来继续查找
		{
			tmpNode1 = tmpNode1->next;
			tmpNode2 = tmpNode2->next;
			printf("查无此学生信息！\n\n");
		}
	}
}

void lookup()
{
	printf("\n查询学生信息\n\n");
	printf("请输入学生的学号：");
	int stuNo=0;
	scanf("%d",&stuNo);//scanf语句输入学生的学号
	struct node_StudentInfo * tmpNode = head;
	int found=0;//定义一个变量
	while(tmpNode!=0)	//不为0获得数据做循环访问所有的节点查找数据
	{
		if(tmpNode->data->id==stuNo)/*data就是前面struct StudentInfo（数据）的指针因为是用学号查找所以指向id==我们定义的stuNo就找到了*/
		{
			printStudentInfo(tmpNode->data);//找到了之后打印学生信息
			found=1;//找到了
			break;//跳出循环
		}
		tmpNode=tmpNode->next;
	} 
	if(found==0)//没有找到
	{
		printf("查无此学生信息！\n\n");
	}
	
}

void modify()
{
	printf("\n修改学生信息\n\n");
	printf("请输入需要修改的学生学号：");
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
		printf("查无此学生信息！\n");
		return;
	}
	while(1==1)
	{
		
		printf("\n"); 
	printf("***************************************************************************************************\n");
	printf("￥                                          欢迎使用             *                               ￥\n");
	printf("￥  *           *                      **学生信息修改系统**                                      ￥\n");
	printf("￥                                    **********************                     *               ￥\n"); 
	printf("￥   *                   *                   OWO                                         *       ￥\n");
	printf("￥                        *             [1]修改学生学号               *                          ￥\n");
	printf("￥   *                                  [2]修改学生姓名                                          ￥\n");
	printf("￥                                      [3]修改学生性别                                          ￥\n");
	printf("￥                                      [4]修改学生年龄                              *           ￥\n");
	printf("￥                                      [5]修改学生宿舍号                                        ￥\n");
	printf("￥                                      [0]退出信息修改系统                 *                    ￥\n"); 
	printf("￥   *                   *                                                               *       ￥\n"); 
	printf("***************************************************************************************************\n\n"); 
	printf("                                            选择命令：");

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
				printf("修改学生学号\n\n");
				printf("请输入学生的学号：");
				scanf("%d",&No);
				tmpNode->data->id=No;
				printf("\n成功修改学生学号！\n\n");
				break;
			case 2:
				printf("修改学生姓名\n\n");
				printf("请输入学生的姓名：");
				scanf("%s",Name);
				strcpy(tmpNode->data->name,Name);
				printf("\n成功修改学生姓名！\n\n");
				break;
			case 3:
				printf("修改学生性别\n\n");
				printf("请输入学生的性别：");
				scanf("%s",Gender);
				strcpy(tmpNode->data->gender,Gender);
				printf("\n成功修改学生性别！\n\n");
				break;
			case 4:
				printf("修改学生年龄\n\n");
				printf("请输入学生的年龄：");
				scanf("%d",&Age);
				tmpNode->data->age=Age;
				printf("\n成功修改学生年龄！\n\n");
				break;
			case 5:
				printf("修改学生宿舍号\n\n");
			    printf("请输入学生的宿舍号：");
				scanf("%s",Roomname);
				strcpy(tmpNode->data->roomName,Roomname);
				printf("\n成功修改学生宿舍号！\n\n");
				break;	
			default:
				printf("该命令不存在！");
				break;		
		}
	}
	
}

//学生签到信息管理
void lateTime()
{
	printf("\n归宿学生签到管理\n\n");
	
	printf("请输入需要进行签到管理的学生学号：");//查询学号对学号对应的学生进行签到信息管理
	int stuNo = -1;
	scanf("%d", &stuNo);
	struct node_StudentInfo *tmpNode = head;
	int found = 0;
	while (tmpNode != 0)
	{
		if (tmpNode->data->id == stuNo)
		{
			printStudentInfo(tmpNode->data);
			found = 1;//找到该学号对应的学生之后设置标记=1
			break;
		}
		else
		{
			tmpNode = tmpNode->next;
		}
	}
	if (found == 0) //若found为0则表示未找到学生信息
	{
		printf("查无此学生信息！\n\n");
		return;
	}
	while (1 == 1)
	{
		
			printf("\n"); 
	printf("***************************************************************************************************\n");
	printf("￥                                          欢迎使用             *                               ￥\n");
	printf("￥  *           *                      **学生签到信息系统**                                      ￥\n");
	printf("￥                                    **********************                     *               ￥\n"); 
	printf("￥   *                   *                    OUO                                        *       ￥\n");
	printf("￥                        *             [1]为该学生进行签到          *                           ￥\n");
	printf("￥   *                                  [2]查看该学生迟到次数                                    ￥\n");
	printf("￥                                      [3]修改学生迟到次数                                      ￥\n");
	printf("￥                                      [0]退出签到信息系统                          *           ￥\n");
	printf("￥                                                                   *                           ￥\n"); 
	printf("￥   *                   *                                                               *       ￥\n"); 
	printf("***************************************************************************************************\n\n"); 
	printf("                                            选择命令：");
		int cmd = -1;
		int Latetime = -1;//对设置的参数初始化避免读取出其他数值
		
		scanf("%d", &cmd);

		if (cmd == 0)
			break;
		switch (cmd)
		{
		case 1:
		    
			printf("正在签到中……\n\n");
			caltime();//签到功能
			break;
		case 2:

			printf("\n该学生的迟到次数为：%d\n\n",tmpNode->data->lateTime);
			break;
		case 3:
            printf("\n修改迟到次数\n\n");
			printf("请输入学生的迟到次数：");
			scanf("%d", &Latetime);
			tmpNode->data->lateTime = Latetime;//通过指针重新输入并且覆盖先前保存的数值
			printf("\n修改迟到次数成功！\n\n");
			break;	

		default:
			printf("\n该命令不存在！\n\n");
			break;
		}
	}

}

//签到功能
void caltime()
{
    time_t t;
	/*其中time_t为time.h定义的结构体，一般为长整型。这个函数会获取当前时间，并返回。 
    如果参数__timer非空，会存储相同值到__timer指向的内存中。 */
    struct tm * lt;
	int Latetime = 0;
	int Latetime2 = 0;
	struct node_StudentInfo *tmpNode = head;//通过指针来链接先前储存的数据

    time (&t);//获取Unix时间戳。即从1970年1月1日（UTC/GMT的午夜）开始所经过的秒数，不考虑闰秒。由于是秒作为单位的，所以这并不是习惯上的时间，要转为习惯上的年月日时间形式就需要另外一个函数了。
    lt = localtime (&t);//转为时间结构。
	//localtime函数形式为struct tm *localtime (const time_t *__timer)；其中tm为一个结构体，包含了年月日时分秒等信息。
	//struct tm中的tm_year 值为实际年减去1900， 所以输出的时候要是lt->tm_year+1900。同理 lt->tm_mon+1。
    printf ( "现在是%d/%d/%d %d:%d:%d\n",lt->tm_year+1900, lt->tm_mon+1, lt->tm_mday, lt->tm_hour, lt->tm_min, lt->tm_sec);//输出结果
    if(lt->tm_hour >=23 && lt->tm_min >10)//意为23:10之后进行签到即为迟到
    {
        printf("\n同学本次迟到，下次注意不能再迟到了哟~（￣へ￣）！\n\n");

		Latetime= tmpNode->data->lateTime;       //通过中间数值对lateTime中的参数数值进行+1的操作，意为迟到次数+1
		Latetime2=Latetime+1;
		tmpNode->data->lateTime = Latetime2;
		
    }
	else if(lt->tm_hour <=5 && lt->tm_min <30)//意为5:30之前进行签到即为迟到
    {
        printf("\n同学本次迟到，下次注意不能再迟到了哟~（￣へ￣）！\n\n");

		Latetime= tmpNode->data->lateTime;
		Latetime2=Latetime+1;
		tmpNode->data->lateTime = Latetime2;
		
    }
    else
    {
        printf("\n同学本次未迟到，要继续努力保持良好的生活习惯哦~b(￣▽￣)d！\n\n");
    }

    
    return;
}
