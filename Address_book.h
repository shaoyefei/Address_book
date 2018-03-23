#pragma once





#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 1000

//typedef struct Person     
//{  
//    char name[20];    //姓名  
//    char sex[2];      //性别  
//    int age;          //年龄  
//    char tele[15];    //电话  
//    char address[25]; //地址  
//}Person;  
//  
//typedef struct Book  
//{  
//    Person data[MAX_SIZE]; //存储每个人信息的结构体数组  
//    size_t size;           //当前已存储的人数  
//}Book; 

typedef struct Person{
    char name[200];//姓名
    char sex[2];//性别
    int age;//年龄
    char tele[15];//电话
    char address[20];//住址
}Person;

typedef struct Book{
    Person data[MAX_SIZE];//每个人的信息的结构体数组
    int size;
}Book;

void Init(Book* book);
void Insert(Book* book);
void Delete(Book* book);
void PrintfBook(Book* book);
int Find(const Book* book,char* name);
void Serch(Book* book);
void Set(Book* book); 
void RemoveAll(Book* book);
void Sort(Book* book);
void AddrSave(Book* book);
void AddrLode(Book* book);
