#include "SeqList.h"

typedef int SLDateType;
typedef struct SeqList
{
	SLDateType* arr;
    int size;//有效数据个数
	int capacity;//空间大小
}SL;

void SLInit(SL* ps)//初始化
{
    ps->arr = NULL;
    ps->size = ps->capacity = 0;
}

void SLDestroy(SL* ps)//销毁
{
    if(ps->arr)
    {
        free(ps->arr);
    }
    ps->arr = NULL;
    ps->size = ps->capacity = 0;
}

void SLCheckCapacity(SL*ps)//判断空间充足与否
{
    if(ps->size == ps->capacity)
    {
        int newcapacity = ps->capacity == 0 ? 4 : 2*ps->capacity;
        SLDateType*tmp = (SLDateType*)realloc(ps->arr, newcapacity*sizeof(SLDateType)); 
        if(tmp == NULL)
        {
            perror("realloc fail!");
            exit(1);
        }
        ps->arr = tmp;
        ps->capacity = newcapacity;
    }
}

void SLPushBack(SL* ps, SLDateType x)
{
    if(ps==NULL)
    {
        return 1;
    }
    SLCheckCapacity(ps);
    ps->arr[ps->size++] = x;
}