#include "Address_book.h"
#include <string.h>
#include <stddef.h>

void Init(Book *book){
    FILE* fp = fopen("book.txt","r");
    char ch;
    int count = 0;
    while(!feof(fp))
    {
        ch = fgetc(fp);
        if(ch == '\n')
        {
            ++count;
        }
    }
    book->size = count;
    //memset(book->data,0,sizeof(book->data));
}

void Insert(Book *book){
    if(book->size >= MAX_SIZE){
        //通讯录已满
        printf("通讯录已满\n");
        return;
    }
    printf("请输入姓名\n");
    scanf("%s",book->data[book->size].name);
    printf("请输入性别\n");
    scanf("%s",book->data[book->size].sex);
    printf("请输入年龄\n");
    scanf("%d",&book->data[book->size].age);
    printf("请输入电话\n");
    scanf("%s",book->data[book->size].tele);
    printf("请输入住址\n");
    scanf("%s",book->data[book->size].address);

    ++book->size;
}

void Delete(Book *book){
    char name[20];
    printf("请输入要删除的姓名:>\n");
    scanf("%s",name);
    int ret = Find(book,name);
    if(ret == -1){
        printf("对不起，没有找到\n");
    }else{
        book->data[ret] = book->data[book->size-1];
        --book->size;
    }
}


int Find(const Book *book,char* name){
    int i = 0;
//    printf("%s\n",name);
    for(;i<book->size;++i){
    if(strcmp(name,book->data[i].name) == 0)
        return i;
//       printf("找到了联系人\n");
     }
    return -1;
    }

void Serch(Book *book){  
    char name[20];
    printf("请输入查找的姓名:>\n");
    scanf("%s",name);
    int ret = Find(book,name);
    if(ret == -1){
        printf("没找到\n");
    }else{
    printf("姓名\t性别\t年龄\t电话\t\t住址\n");
    printf("%s\t%s\t%d\t%s\t%s\n",book->data[ret].name,book->data[ret].sex,book->data[ret].age\
           ,book->data[ret].tele,book->data[ret].address);
       }
}

void PrintfBook(Book *book){
    int i = 0;
    printf("\n------------------------------------------\n");
    printf("|||||||||||||||||通讯录|||||||||||||||||||\n");
    printf("------------------------------------------\n");
    printf("姓名\t性别\t年龄\t电话\t\t住址\n");
    for(i=0;i<book->size;++i){
    printf("%s\t%s\t%d\t%s\t%s\n",book->data[i].name,book->data[i].sex,book->data[i].age\
           ,book->data[i].tele,book->data[i].address);
    }
}

void Set(Book *book){
    char name[20];
    printf("请输入要修改人的姓名:>\n");
    scanf("%s",name);
    int ret = Find(book,name);
    if(ret == -1){
        printf(">用户不存在<\n");
    }else{
        int chose;
        printf("请选择要修改的信息>:\n");
        printf("**1.姓名*******2.年龄*******\n");
        printf("**3.性别*******4.电话*******\n");
        printf("**5.住址*******0.退出*******\n");
        printf("请输入:>");
        scanf("%d",&chose);
        switch(chose){
        case 1:
            {           
                char name[20];
                printf("请输入要修改的姓名>:\n");
                scanf("%s",name);
                strcpy(book->data[ret].name,name);
                printf(">姓名修改成功<\n");
                break;
            }
        case 2:
            {     int age;
            printf("请输入要修改的年龄>:\n");
            scanf("%d",&age);
            book->data[ret].age = age;
            printf(">年龄修改成功<\n");
            break;
            }
        case 3:
            {     char sex[4];
            printf("请输入要修改的性别>:\n");
            scanf("%s",sex);
            strcpy(book->data[ret].sex,sex);
            printf(">性别修改成功<\n");
            break;
            }
        case 4:
            {     char tel[20];
            printf("请输入要修改的电话>:\n");
            scanf("%s",tel);
            strcpy(book->data[ret].tele,tel);
            printf(">电话修改成功<\n");
            break;
            }
        case 5:
            {     char address[20];
            printf("请输入要修改的地址>:\n");
            scanf("%s",address);
            strcpy(book->data[ret].address,address);
            printf(">地址修改成功<\n");
            break;
            }
        default :
            {         printf(">无任何修改，退出<\n");
            break;
            }
        }
    }
} 
//
//
void RemoveAll(Book* book){
    if(book == NULL){
        //非法输入
        return;
    }
    book->size = 0;
    printf(">所有名单已删除<\n");
}

void Swap(Person* a,Person* b)
{
    Person tmp = *a;
    *a = *b;
    *b = tmp;
}

void Sort( Book* book){
    int i = 0;
    for(;i<book->size;++i){
        int j = 0; 
        for(;j<book->size-i-1;++j){
            if(strcmp(book->data[j].name,book->data[j+1].name)>0){
               Swap(&(book->data[j]),&(book->data[j+1]));
//                Person tmp;
////                book->data[j] = book->data[j+1];
////                book->data[j+1] = tmp;
//                strcpy(tmp.name,book->data[i].name);
//                strcpy(tmp.sex,book->data[i].sex);
//                tmp.age = book->data[i].age;
//                strcpy(tmp.tele,book->data[i].tele);
//                strcpy(tmp.address,book->data[i].address);
//
//                strcpy(book->data[i].name,book->data[i+1].name);
//                strcpy(book->data[i].sex,book->data[i+1].sex);
//                book->data[i].age = book->data[i+1].age;
//                strcpy(book->data[i].tele,book->data[i+1].tele);
//                strcpy(book->data[i].address,book->data[i+1].address);
//
//                strcpy(book->data[i+1].name,tmp.name);
//                strcpy(book->data[i+1].sex,tmp.sex);
//                book->data[i+1].age = tmp.age;
//                strcpy(book->data[i+1].tele,tmp.tele);
//                strcpy(book->data[i+1].address,tmp.address);
            }
    }

}
        printf(">排序完成<\n");
}


void AddrSave(Book* book){
    if(book == NULL){
        return;
    }
    FILE* fp = fopen("book.txt","w");
    if(fp == NULL){
        printf("打开失败\n");
        return;
    }
    int i = 0;
    for(;i<book->size;++i){
        fprintf(fp,"%s\t%s\t%d\t%s\t\t%s\n",book->data[i].name,book->data[i].sex,book->data[i].age,book->data[i].tele,\
                                                  book->data[i].address);
    }
    fclose(fp);
}
void AddrLode(Book* book){
    if(book == NULL){
        return;
    }
    FILE* fp = fopen("book.txt","r");
    if(fp == NULL){
        printf("打开文件失败\n");
        return;
    }
    int i = 0;
    while(!feof(fp))
    {
        fscanf(fp,"%s\t%s\t%d\t%s\t\t%s\n",book->data[i].name,book->data[i].sex,&book->data[i].age,book->data[i].tele,\
                                                  book->data[i].address);
        ++i;
    }
}

///////////////////////////////////////////////////////////
///以下为测试代码
///////////////////////////////////////////////////////////
#if 1

#include <stdio.h>

#define TEST_HEAD printf("\n--------------------%s---------------------\n",__FUNCTION__);

//void testInsert(){
//    Book book;
//    Init(&book);
//    Insert(&book);
//    PrintfBook(&book);
//}
//
//void testFind(){
//    Book book;
//    Init(&book);
//    Insert(&book);
//    Insert(&book);
//    Insert(&book);
//    Insert(&book);
//    PrintfBook(&book);
//    Serch(&book);
//}
//
void Test(){
    TEST_HEAD;
    Book book;
    Init(&book);
    Insert(&book);
    Insert(&book);
    Insert(&book);
    Insert(&book);
    PrintfBook(&book);
    Set(&book);
    Serch(&book);
    Delete(&book);
    PrintfBook(&book);
    RemoveAll(&book);
    PrintfBook(&book);
//    RemoveAll(&book);
    Sort(&book);
    PrintfBook(&book);
}

void menu(){
    printf("\n********************************\n");
    printf("********1.添加    2.删除********\n");
    printf("********3.查找    4.修改********\n");
    printf("********5.清除    6.排序********\n");
    printf("********7.打印    0.退出********\n");
    printf("********************************\n");

}

int main(){
    Book book;
    Init(&book);
    AddrLode(&book);
    do{
        menu();
        int i;
        printf("请选择:>");
        scanf("%d",&i);
        switch(i){
        case 1:
            Insert(&book);
                AddrSave(&book);
            break;
        case 2:
            Delete(&book);
                AddrSave(&book);
            break;
        case 3:
            Serch(&book);
            break;
        case 4:
            Set(&book);
                AddrSave(&book);
            break;
        case 5:
            RemoveAll(&book);
            break;
        case 6:
            Sort(&book);
            break;
        case 7:
            {
                PrintfBook(&book);
//                AddrSave(&book);
//                AddrLode(&book);
                break;
            }
        case 0:
            return 0;
            break;
        default :
            printf("请重新选择\n");
        }

    }while(1);
   // testInsert();
   // testFind();
    return 0;
}


#endif
