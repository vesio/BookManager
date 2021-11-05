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
        char number[bianhao_size];//���
        char author[author_size];//������
        char name[name_size];//����
        int quantity;//����
        struct Book *pre;
        struct Book *next;
    }Book;


Book *CreateBookHead();//�����սڵ�
void addNode(Book *head,Book* book);//���鱾��������
void CreatNewBook(Book *head);//������
void getInformation( Book *head);//��ȡ�ı��ļ�����
void showBooks(Book *head);//��ʾ������
void delBook(Book *head);//ɾ���鱾
void editBook(Book *head);//�޸��鱾
int findBook(Book *head);//������
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
    printf("��������:");
    gets(p->number);
    printf("�޸ĳɹ�");
}

void editName(Book *p)
{
    fflush(stdin);
    printf("����������:");
    gets(p->name);
    showThebook(p);
    printf("�޸ĳɹ�");
}

void editAuthor(Book *p)
{
    fflush(stdin);
    printf("��������������:");


    gets(p->author);
    printf("�޸ĳɹ�");
}

void editQuantity(Book *p)
{
    fflush(stdin);
    printf("��������:");
    scanf("%d",p->quantity);
    printf("�޸ĳɹ�");
}


void editBook(Book *head)
{
    Book *p =CreateBookHead();
    char in;
    showBooks(head);
    p=findNumber(head);

    puts(p->name);
    fflush(stdin);
    printf("---------------ͼ���޸�------------\n");
    printf("            1.�޸�ͼ����\n");
    printf("            2.�޸�ͼ������\n");
    printf("            3.�޸�ͼ������\n");
    printf("            4.�޸�ͼ������\n");
    printf("----------------------------------------------\n");

    in=getchar();
    while(in>'4'||in<'1')
    {
        printf("��������");
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
        printf("*********************\nɾ���ɹ�\n");
        printf("�Ƿ����±��?\n");
        printf("1.��\t2.��\n");
        fflush(stdin);
        in=getchar();
        while(in!='1'&&in!='2')
        {
            printf("��������");
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
    fp=fopen("D:\\�ҵ��ĵ�\\����\\�γ����\\C���Գ������\\BookManage\\sql.txt","w");

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
    printf("****����ɹ�****\n");

}



void back(Book *head)
{
    fflush(stdin);
    char in;
    printf("\n-----------------------\n");
    printf("1.����������\n");
    printf("0.�˳�����\n");
    in=getchar();
    while(in!='1'&&in!='0')
    {
        printf("��������\n");
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
    printf("��������");
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
            printf("δ�ҵ�");
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
    printf("������ͼ������:\n");
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
            printf("δ�ҵ�");
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
    temp=head;//ͷ�ڵ㲻������Ϣ
    while(1)
    {
        temp=temp->next;
        if(temp->next==NULL) break;
    }
    strcpy(book->number,temp->number);
    a=atoi(book->number);
    a++;
    itoa(a,book->number,10);//��int aת���ַ�������10����
    book->pre=temp;
    temp->next=book;
}

void CreatNewBook(Book *head)
{

    int a=0;
    Book* temp=CreateBookHead();
    printf("����������:");
    gets(temp->name);
    printf("������������:");
    gets(temp->author);
    printf("����������:");
    scanf("%d",&a);
    temp->quantity=a;
    addNode(head,temp);
    printf("***��ӳɹ�***");
}
void getInformation( Book *head)//������Ϣ����
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
        fgets(&Text,100,fp);//��ȡһ�е�����
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
    char a[bianhao_size]="���";
    char b[name_size]="����";
    char c[author_size]="����";


    printf("\n�����鵥����:\n");
    printf("%-16s",&a);
    printf("%-16s",&b);
    printf("%-16s����\t\n----------------------------------------------\n",&c);

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
    printf("�Ƿ񱣴�\n1.��\t2.��\n");
    fflush(stdin);
    in=getchar();
    while(in!='1'&&in!='2'&&in!='\n')
    {
        printf("��������");
        in=getchar();
    }
    if(in=='1'||in=='\n')
    {
        save(head);
    }
    system("cls");
    printf("\n\n-----------------------\n");
    printf("\tллʹ��!");
    printf("\n-----------------------\n");
    exit(0);
}

void menu(Book *head)
{

    char in;
    system("cls");
    printf("----------��ӭʹ�ø���ͼ�����ϵͳ------------\n");
    printf("            1.������ͼ��\n");
    printf("            2.����ͼ��\n");
    printf("            3.ɾ��ͼ��\n");
    printf("            4.�޸�ͼ��\n");
    printf("            5.��ʾ����ͼ��\n");
    printf("            0.�˳�����\n");
    printf("----------------------------------------------\n");

    fflush(stdin);
    in=getchar();
    while(in>'9'||in<'0')
    {
        printf("��������");
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
    //��ȡ�ı���ͼ�������Ϣ

    int i =0;
    Book *head  = CreateBookHead();
    getInformation(head);
    menu(head);


    return 0;
}

