#include "SeqList.h"

void SLtest01()
{
    SL s;
    SLInit(&s);

    SLPushBack(&s,1);
    SLPushBack(&s,2);
    SLPushBack(&s,3);
    SLPushBack(&s,4);
    //SLPushBack(NULL,5);
    SLPushFront(&s,6);
    SLPrint(&s);

    SLPopBack(&s);
    SLPrint(&s);
    SLPopFront(&s);
    SLPrint(&s);

    SLInsert(&s,6,0);
    SLPrint(&s);
    SLInsert(&s,66,2);
    SLPrint(&s);
    SLInsert(&s,666,s.size);
    SLPrint(&s);

    SLErase(&s, 3);
    SLPrint(&s);

    SLErase(&s, 4);
    SLPrint(&s);

    SLFind(&s, 2);
    SLFind(&s, 3);
    SLFind(&s, 66);

    SLDestroy(&s);
}

int main()
{
    SLtest01();
    return 0;
}