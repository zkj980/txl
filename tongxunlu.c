#include <stdio.h>
#include <string.h>
#include <getch.h>
#include <stdlib.h>
char name[51][20]={};
char sex[51][4]={};
char phnu[51][12]={};
int mea=0;
int nuor=-1;

//任意键继续

void anykey_continue(void)
{
	stdin->_IO_read_ptr = stdin->_IO_read_end;
	puts("任意键继续。。。");
	getch();
}
/*
void show_msg(const char* msg,float sec)
{
	printf("%s",msg);
	fflush(stdout);
	usecond_t usec=sec*1000000;
	usllep(usec);
}
*/
//添加联系人
void add(void)
{
		system("clear");
	if(50==mea)
	{
		printf("\n已达到最大存储量！\n");
		return;
	}
	printf("\n姓名：");
	gets(name[mea]);
	printf("性别:");
	gets(sex[mea]);
	printf("电话号码：");
	gets(phnu[mea]);
	printf("添加联系人成功\n");
	mea++;
	
anykey_continue();
}

//删除联系人
void del(void)
{
		system("clear");
	if(-1==nuor)
	{
		return;
	}
	printf("\n已删除联系人\n");
	puts(name[nuor]);
	puts(sex[nuor]);
	puts(phnu[nuor]);
	for(int i=nuor;i<mea;i++)
	{
		strcpy(name[i],name[i+1]);
	
	strcpy(sex[i],sex[i+1]);
		strcpy(phnu[i],phnu[i+1]);
	}
	nuor=-1;
	mea--;
anykey_continue();
}


//修改联系人信息
void alter(void)
{
		system("clear");
	if(-1==nuor)
	{
		return;
	}
	puts(name[nuor]);
	puts(sex[nuor]);
	puts(phnu[nuor]);
	printf("\n请重新输入\n姓名：");
	gets(name[nuor]);
	printf("性别:");
	gets(sex[nuor]);
	printf("电话号码：");
	gets(phnu[nuor]);
	nuor=-1;
anykey_continue();
}

//查找联系人
void sek(void)
{
		system("clear");
	printf("\n查找：");
	char mes[20]={};
	gets(mes);
	int n=strlen(mes);
	int i=0,k=0;
	for(;i<mea;i++)
	{
		if(0==strncmp(mes,name[i],n) || 0==strncmp(mes,phnu[i],n))
		{
			nuor=i;
			printf("%d\n",i+1);
			puts(name[i]);
			puts(sex[i]);
			puts(phnu[i]);
			k++;
		}
	}
	if(0==k)
	{
		puts("未找到该联系人\n");
	}
anykey_continue();
}

//显示所有联系人
void sho(void)
{
		system("clear");
	for(int i=0;i<mea;i++)
	{
		printf("\n%d\n",i+1);
		puts(name[i]);
		puts(sex[i]);
		puts(phnu[i]);
		
anykey_continue();
	}
}
int main()
{
	for(;;)
	{
		system("clear");
		puts("1、添加联系人");
		puts("2、删除联系人");
		puts("3、修改联系人信息");
		puts("4、查找联系人");
		puts("5、显示所有联系人");
		printf("请输入指令：");
		switch(getch())
		{
			case '1':add();break;
			case '2':del();break;
			case '3':alter();break;
			case '4':sek();break;
			case '5':sho();break;
			default: break;
		}
	}
}
