#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int SLDateType;
typedef struct SeqList
{
	SLDateType* arr;
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
//插入数据
void SLPushBack(SL* ps, SLDateType x);
void SLPushFront(SL* ps, SLDateType x);
//删除数据
void SLPopBack(SL* ps);
void SLPopFront(SL* ps);
//指定位置插入删除
void SLInsert(SL* ps, SLDateType x, int pos);
void SLErase(SL* ps, int pos);
//查找数据
void SLFind(SL* ps, SLDateType x);