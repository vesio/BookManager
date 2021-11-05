#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define name_size 20
#define author_size 20
#define charToint(ch) (ch)-'0'
#define bianhao_size 7
#define starNumber 900001


 typedef struct Book
    {
        char number[bianhao_size];//编号
        char author[author_size];//作者名
        char name[name_size];//书名
        int quantity;//数量
        struct Book *pre;
        struct Book *next;
    }Book;


Book *CreateBookHead();//创建空节点
void addNode(Book *head,Book* book);//将书本加入链表
void CreatNewBook(Book *head);//创建书
void getInformation( Book *head);//获取文本文件内容
void showBooks(Book *head);//显示所有书
void delBook(Book *head);//删除书本
void editBook(Book *head);//修改书本
int findBook(Book *head);//查找书
void copyBook(Book *newbook,Book* Source);
void EXIT(Book *head);
void back(Book *head);
void save(Book *head);
Book * findNumber(Book *head);



void updateNumber(Book *head)
{
    Book *p=head->next;
    int temp1,flag=starNumber;

    while(1)
    {
        if(atoi(p->number)!=flag)
        {
            itoa(flag,p->number,10);
        }
        if(p->next==NULL) break;
        p=p->next;
        flag++;

    }
}

void editNumber(Book *p)
{
    fflush(stdin);
    printf("请输入编号:");
    gets(p->number);
    printf("修改成功");
}

void editName(Book *p)
{
    fflush(stdin);
    printf("请输入书名:");
    gets(p->name);
    showThebook(p);
    printf("修改成功");
}

void editAuthor(Book *p)
{
    fflush(stdin);
    printf("请输入作者姓名:");


    gets(p->author);
    printf("修改成功");
}

void editQuantity(Book *p)
{
    fflush(stdin);
    printf("请输入编号:");
    scanf("%d",p->quantity);
    printf("修改成功");
}


void editBook(Book *head)
{
    Book *p =CreateBookHead();
    char in;
    showBooks(head);
    p=findNumber(head);

    puts(p->name);
    fflush(stdin);
    printf("---------------图书修改------------\n");
    printf("            1.修改图书编号\n");
    printf("            2.修改图书名字\n");
    printf("            3.修改图书作者\n");
    printf("            4.修改图书数量\n");
    printf("----------------------------------------------\n");

    in=getchar();
    while(in>'4'||in<'1')
    {
        printf("输入有误");
        in=getchar();
    }
    switch(in)
    {
        case '1': editNumber(p);
                  back(head);

        case '2': editName(p);
                  back(head);

        case '3': editAuthor(p);
                  back(head);

        case '4': editQuantity(p);
                  back(head);

    }
}



void delBook(Book *head)
{
    Book *p=CreateBookHead();
    Book *previous=CreateBookHead();
    char in;
    int flag=0;
    flag=findBook(head);
    if(flag==1)
    {
        p=findNumber(head);
        previous=p->pre;
        previous->next=p->next;
        free(p);
        printf("*********************\n删除成功\n");
        printf("是否重新编号?\n");
        printf("1.是\t2.否\n");
        fflush(stdin);
        in=getchar();
        while(in!='1'&&in!='2')
        {
            printf("输入有误");
            in=getchar();
        }
        if(in=='1')
        {
            updateNumber(head);
        }
    }
}

void save(Book *head)
{
    FILE *fp;
    Book *p=head->next;
    fp=fopen("D:\\我的文档\\档案\\课程设计\\C语言程序设计\\BookManage\\sql.txt","w");

    while(1)
    {
        fputs(p->number,fp);
        fputc('#',fp);
        fputs(p->name,fp);
        fputc('#',fp);
        fputs(p->author,fp);
        fputc('#',fp);
        fprintf(fp,"%d",p->quantity);
        fprintf(fp,"#\n");
        if(p->next==NULL) break;
        p=p->next;
    }
    fclose(fp);
    printf("****保存成功****\n");

}



void back(Book *head)
{
    fflush(stdin);
    char in;
    printf("\n-----------------------\n");
    printf("1.返回主界面\n");
    printf("0.退出程序\n");
    in=getchar();
    while(in!='1'&&in!='0')
    {
        printf("输入有误\n");
        in=getchar();
    }
    switch(in)
    {
        case '1': menu(head);
                  break;
        case '0': EXIT(head);
                  break;

    }
}


Book * findNumber(Book *head)
{
    char book_number[bianhao_size];
    int flag=1;
    fflush(stdin);
    printf("请输入编号");
    gets(book_number);
    Book *p=head->next;
    while(1)
    {
        if(strcmp(p->number,book_number)==0)
        {   flag=1;
            break;
        }
        if(p->next==NULL) {flag=0;break;}
        p=p->next;
    }
    if(flag==1)
    {
        return p;

    }else
        {
            printf("未找到");
            back(head);
        }

        return NULL;
}


int findBook(Book *head)
{

    char book_name[name_size];
    int flag = 1;
    fflush(stdin);
    Book *p=head->next;
    Book *list =CreateBookHead();
    system("cls");
    printf("请输入图书名字:\n");
    gets(book_name);
    while(1)
    {
        Book *listp=CreateBookHead();
        list->next=listp;
        if(strcmp(p->name,book_name)==0)
        {   copyBook(listp,p);
            list->next=listp;
            flag=1;
            break;
        }
        if(p->next==NULL) {flag=0;break;}
        p=p->next;
    }
    if(flag==1)
    {
        showBooks(list);
        return 1;
    }else
        {
            printf("未找到");
        }

}

void copyBook(Book *newbook,Book* Source)
{
    strcpy(newbook->author,Source->author);
    strcpy(newbook->number,Source->number);
    strcpy(newbook->name,Source->name);
    newbook->quantity=Source->quantity;

}

void showThebook(Book *p)
{
    printf("%-16s",p->number);
    printf("%-16s\t",p->name);
    printf("%-16s\n",p->author);

}


void addNode(Book *head,Book* book)
{
    Book* temp;
    int a;
    temp=head;//头节点不储存信息
    while(1)
    {
        temp=temp->next;
        if(temp->next==NULL) break;
    }
    strcpy(book->number,temp->number);
    a=atoi(book->number);
    a++;
    itoa(a,book->number,10);//将int a转成字符串，以10进制
    book->pre=temp;
    temp->next=book;
}

void CreatNewBook(Book *head)
{

    int a=0;
    Book* temp=CreateBookHead();
    printf("请输入书名:");
    gets(temp->name);
    printf("请输入作者名:");
    gets(temp->author);
    printf("请输入数量:");
    scanf("%d",&a);
    temp->quantity=a;
    addNode(head,temp);
    printf("***添加成功***");
}
void getInformation( Book *head)//所有信息都有
{
    Book *itr =head;

    char Text[100];
    char *p;
    FILE *fp;
    char number[bianhao_size];
    char name[name_size];
    char author[author_size];
    int quantity;
    int i=0;

    fp=fopen("sql.txt","r");

    while(1)
    {
        Book *temp=CreateBookHead();
        fgets(&Text,100,fp);//获取一行的内容
        p=Text;
        while(*p!='#')
        {
            number[i++]=*p;
            p++;
        }
        number[i]='\0';
        p++;
        i=0;
        while(*p!='#')
        {
            name[i++]=*p;
            p++;
        }
        name[i]='\0';
        p++;
        i=0;
        while(*p!='#')
        {
            author[i]=*p;
            i++;
            p++;
        }
        author[i]='\0';
        p++;
        i=0;
        quantity=charToint(*p);

        strcpy(temp->number,number);
        strcpy(temp->name,name);
        strcpy(temp->author,author);
        temp->quantity=quantity;


        temp->pre=itr;
        itr->next=temp;
        itr=itr->next;
        if(feof(fp)) break;
        puts(temp->number);
        //showThebook(itr);
    }
    fclose(fp);

}

Book *CreateBookHead()
{

    Book *L;
    L=(Book *)malloc(sizeof(Book));
    L->next=NULL;
    return L;

}

void showBooks(Book *head)
{
    char in;
    Book *p=head->next;
    char a[bianhao_size]="编号";
    char b[name_size]="书名";
    char c[author_size]="作者";


    printf("\n您的书单如下:\n");
    printf("%-16s",&a);
    printf("%-16s",&b);
    printf("%-16s数量\t\n----------------------------------------------\n",&c);

    while(1)
    {
        printf("%-16s",p->number);
        printf("%-16s",p->name);
        printf("%-16s",p->author);
        printf("%-16d\n",p->quantity);
        if(p->next==NULL) break;
        p=p->next;
    }
    printf("---------------------------------------------\n");
}

void EXIT(Book *head)
{
    char in;
    printf("是否保存\n1.是\t2.否\n");
    fflush(stdin);
    in=getchar();
    while(in!='1'&&in!='2'&&in!='\n')
    {
        printf("输入有误");
        in=getchar();
    }
    if(in=='1'||in=='\n')
    {
        save(head);
    }
    system("cls");
    printf("\n\n-----------------------\n");
    printf("\t谢谢使用!");
    printf("\n-----------------------\n");
    exit(0);
}

void menu(Book *head)
{

    char in;
    system("cls");
    printf("----------欢迎使用个人图书管理系统------------\n");
    printf("            1.创建新图书\n");
    printf("            2.查找图书\n");
    printf("            3.删除图书\n");
    printf("            4.修改图书\n");
    printf("            5.显示所有图书\n");
    printf("            0.退出程序\n");
    printf("----------------------------------------------\n");

    fflush(stdin);
    in=getchar();
    while(in>'9'||in<'0')
    {
        printf("输入有误");
        in=getchar();
    }
    switch(in)
    {
        case '1': fflush(stdin);
                  CreatNewBook(head);
                  back(head);


        case '2': fflush(stdin);
                  findBook(head);
                  back(head);

        case '3': fflush(stdin);
                  delBook(head);
                  back(head);

        case '4': fflush(stdin);
                  editBook(head);
                  back(head);

        case '5': fflush(stdin);
                  showBooks(head);
                  back(head);

        case '0':
                  EXIT(head);
        default : fflush(stdin);
                  menu(head);
    }
}


int main()
{
    //读取文本中图书相关信息

    int i =0;
    Book *head  = CreateBookHead();
    getInformation(head);
    menu(head);


    return 0;
}

