#include "SeqList.h"

/*typedef int SLDateType;
typedef struct SeqList
{
	SLDateType* arr;
    int size;//有效数据个数
	int capacity;//空间大小
}SL;*/

void SLPrint(SL*ps)
{
    for(int i= 0;i<ps->size;i++)
    {
        printf("%d ",ps->arr[i]);
    }
    printf("\n");
}

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

void SLPushBack(SL* ps, SLDateType x)//尾插
{
    if(ps==NULL)
    {
        return;
    }
    SLCheckCapacity(ps);
    ps->arr[ps->size++] = x;
}

void SLPushFront(SL* ps, SLDateType x)// 头插
{
    if(ps==NULL)
    {
        return;
    }
    SLCheckCapacity(ps);
    for(int i= ps->size; i>0; i--)
    {
        ps->arr[i] = ps->arr[i-1];
    }
    ps->arr[0] = x;
    ps->size++;
}

void SLPopBack(SL* ps)//尾删
{
    assert(ps);
    assert(ps->size);
    ps->size--;
}

void SLPopFront(SL* ps)//头删
{
    assert(ps);
    assert(ps->size);

    for(int i= 0; i< ps->size-1; i++)
    {
        ps->arr[i] = ps->arr[i+1];
    }
    ps->size--;
}

void SLInsert(SL* ps, SLDateType x, int pos)//指定插入
{
    assert(ps);
    assert(pos >= 0 && pos <= ps->size);
    SLCheckCapacity(ps);
    //pos之后的数据整体向右移动
    for(int i= ps->size; i>pos; i--)
    {
        ps->arr[i] = ps->arr[i-1];
    }
    ps->arr[pos] = x;
    ps->size++;
}

void SLErase(SL* ps, int pos)//指定删除
{
    assert(ps);
    assert(ps->size);
    assert(pos >= 0 && pos < ps->size);
    //pos之后的数据整体向左移动
    for(int i= pos; i<ps->size-1; i++)
    {
        ps->arr[i] = ps->arr[i+1];
    }
    ps->size--;
}

int SLfind(SL* ps, SLDateType x)//查找数据
{
    assert(ps);
    for(int i= 0; i< ps->size; i++)
    {
        if(ps->arr[i] ==  x)
        {
            return i;
        }
    }
    return -1;
}

void SLFind(SL* ps, SLDateType x)//下标返回
{
    int find= SLfind(ps,  x);
    if(find == -1)
        printf("没有找到\n");
    else
        printf("下标为 %d\n", find);
}