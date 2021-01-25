# StudentDormitoryManagementSystem
学生寝室管理系统.c

系统详情介绍在CSDN，链接在此：https://blog.csdn.net/qq_38677092/article/details/113114475

项目包含文件：

1、main.c（执行该文件即可运行系统）

2、student.c（包含几乎所有要执行的系统功能的函数）

3、student.h（项目需要的头文件，相当于提前声明了一下student.c中的函数）

4、图片直接看模糊的话点击一下可以查看大图哦~

5、开发文档（许多地方可以改得好玩点哈哈哈）

6、程序流程图

喜欢的话可以点个小星星哦~✧(≖ ◡ ≖✿)

**一、系统介绍**

1.学生寝室管理系统介绍：
可以录入、修改、删除、查询学生的详细信息，也可以进行学生归寝签到、记录，方便寝室阿姨进行学生寝室的管理

2.系统功能描述：
1. 录入宿舍学生信息
录入宿舍的学生的姓名、学号、电话、宿舍号、床位信息；
2. 浏览宿舍学生信息
浏览数据库中所有学生信息；
3. 修改宿舍学生信息
根据学号查询对应学生信息条进行修改；
4. 删除宿舍学生信息
根据学号查询对应学生信息条进行删除；
5. 查询宿舍学生信息
根据学号查询对应学生信息条进行显示；
6. 保存数据到文件中
保存录入的数据到本地文件以便随时访问
7. 归宿学生签到管理
根据学号查询对应学生信息进行签到信息管理

**二、系统功能实现流程图**

![系统结构图](https://img-blog.csdnimg.cn/20210125151054969.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzM4Njc3MDky,size_16,color_FFFFFF,t_70#pic_center)

超清流程图在线浏览链接：https://www.processon.com/view/link/5ee6cdd807912929cb423912

密码：1703

[点击前往](https://www.processon.com/view/link/5ee6cdd807912929cb423912)

**三、使用工具**

1.DevCpp-5.4.0

2.VSCode

3.建议用Dev，一体的IDE，不用很麻烦去配置，但是vscode在编辑的时候使用体验更佳，有能力的hxd自己去百度“VSCode环境配置”吧

这边给个推荐的文章：
[步平凡-Visual Studio Code (vscode) 配置 C / C++ 环境](https://www.cnblogs.com/bpf-1024/p/11597000.html)

**四、界面展示**

1.开始界面

![开始界面](https://img-blog.csdnimg.cn/20210125154911874.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzM4Njc3MDky,size_16,color_FFFFFF,t_70#pic_center)

2.添加学生信息

![添加学生信息](https://img-blog.csdnimg.cn/20210125154934791.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzM4Njc3MDky,size_16,color_FFFFFF,t_70#pic_center)

3.查询学生信息

![查询学生信息](https://img-blog.csdnimg.cn/20210125155002580.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzM4Njc3MDky,size_16,color_FFFFFF,t_70#pic_center)

4.保存数据到文件中

![保存数据到文件中](https://img-blog.csdnimg.cn/20210125155109892.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzM4Njc3MDky,size_16,color_FFFFFF,t_70#pic_center)

5.启动时自检是否有本地数据，有则读取，查询操作跟之前一样

![成功查询到本地存档](https://img-blog.csdnimg.cn/20210125155211251.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzM4Njc3MDky,size_16,color_FFFFFF,t_70#pic_center)

6.退出时释放节点（链式存储）

![在这里插入图片描述](https://img-blog.csdnimg.cn/20210125155422927.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzM4Njc3MDky,size_16,color_FFFFFF,t_70#pic_center)

