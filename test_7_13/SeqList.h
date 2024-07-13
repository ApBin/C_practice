#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int SLDateType;
typedef struct SeqList
{
	SLDateType* a;
	int size;//有效数据个数
	int capacity;//空间大小
}SL;

//对数据的管理:增删查改 
//初始化
void SLInit(SL* ps);
//销毁
void SLDestroy(SL* ps);
//打印  
void SLPrint(SL* ps);
//尾插
void SLPushBack(SL* ps, SLDateType x);
//头插
void SLPushFront(SL* ps, SLDateType x);
//尾删
void SLPopFront(SL* ps);
//头删
void SLPopBack(SL* ps);