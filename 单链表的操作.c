/*A��B����������������ͷ��㣩������Ԫ�ص����������һ���㷨����A��B�鲢��һ����Ԫ��ֵ�ǵݼ����������C��
 * C��A��B�еĽ����ɡ�*/
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int data;//Ŀǰ����ֵ
    struct LNOde* next;//ָ����һ�����
}LNOde;//��������

LNOde creat_newlist_head(LNOde* C, int a[], int n)
{
    LNOde* s;//ָ���µĽ��
    LNOde* r;//ָ���ն˽��
    C = (LNOde*)malloc(sizeof(LNOde));
    C->next = NULL;
    r = C;
    int i;//�����½���ѭ������
    for (i = 0; i < n; i++)
    {
        s = (LNOde*)malloc(sizeof(LNOde));
        s->data = a[i];
        r->next = s;
        r = r->next;
    }
    r->next = NULL;
    return *C;
}//ͷ�巨

LNOde creat_newlist_tail(LNOde* C, int a[], int n)
{
    LNOde* s;
    C = (LNOde*)malloc(sizeof(LNOde));
    C->next = NULL;
    int i;//�����½���ѭ������
    for (i = 0; i < n; i++)
    {
        s = (LNOde*)malloc(sizeof(LNOde));
        s->next = NULL;
        C->next = s;
    }
    return *C;
}//β�巨

void merge(LNOde A, LNOde B, LNOde* C)
{
    LNOde* q = A.next;//qָ��A����С���
    LNOde* p = B.next;//pָ��B����С���
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
void ShowList(LNOde* C)					//��ӡ��������
{
    LNOde *p;
    p = C->next;
    if (p == NULL)
    {
        printf("����һ��������\n");
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