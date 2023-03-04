/*A和B是两个单链表（带表头结点），其中元素递增有序，设计一个算法，将A和B归并成一个按元素值非递减有序的链表C，
 * C有A和B中的结点组成。*/
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int data;//目前结点的值
    struct LNOde* next;//指向下一个结点
}LNOde;//单链表结点

LNOde creat_newlist_head(LNOde* C, int a[], int n)
{
    LNOde* s;//指向新的结点
    LNOde* r;//指向终端结点
    C = (LNOde*)malloc(sizeof(LNOde));
    C->next = NULL;
    r = C;
    int i;//创建新结点的循环变量
    for (i = 0; i < n; i++)
    {
        s = (LNOde*)malloc(sizeof(LNOde));
        s->data = a[i];
        r->next = s;
        r = r->next;
    }
    r->next = NULL;
    return *C;
}//头插法

LNOde creat_newlist_tail(LNOde* C, int a[], int n)
{
    LNOde* s;
    C = (LNOde*)malloc(sizeof(LNOde));
    C->next = NULL;
    int i;//创建新结点的循环变量
    for (i = 0; i < n; i++)
    {
        s = (LNOde*)malloc(sizeof(LNOde));
        s->next = NULL;
        C->next = s;
    }
    return *C;
}//尾插法

void merge(LNOde A, LNOde B, LNOde* C)
{
    LNOde* q = A.next;//q指向A的最小结点
    LNOde* p = B.next;//p指向B的最小结点
    LNOde* r;
    *C = A;
    C->next = NULL;
    r = C;
    while (p != NULL && q != NULL)
    {
        if (q->data <= p->data)
        {
            r->next = q;
            q = q->next;
            r = r->next;
        }
        else
        {
            r->next = p;
            p = p->next;
            r = r->next;
        }
    }
    r->next = NULL;
    if (p != NULL)
    {
        r->next = p;
    }
    if (q != NULL)
    {
        r->next = q;
    }
}
void ShowList(LNOde* C)					//打印整个链表
{
    LNOde *p;
    p = C->next;
    if (p == NULL)
    {
        printf("这是一个空链表！\n");
    }
    while (p)
    {
        printf("  %d", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    LNOde A;
    LNOde* Aa;
    Aa = &A;
    int a[3] = { 1,2,3 };
    int nub = 3;
    A = creat_newlist_head(Aa, a, nub);
    LNOde B;
    LNOde* Bb;
    Bb = &B;
    int b[3] = { 4,5,6 };
    B = creat_newlist_head(Bb, b, nub);
    LNOde C;
    LNOde* Cc;
    Cc = &C;
    merge(A, B, Cc);
    ShowList(Cc);
    return 0;
}