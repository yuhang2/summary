#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;

#define MAXSIZE 10000 /* 排序数组个数最大值 */
typedef struct
{
    int r[MAXSIZE + 1];
    int length;
} SqList;

void swap(SqList *L, int i, int j)
{
    int temp = L->r[i];
    L->r[i] = L->r[j];
    L->r[j] = temp;
}

void print(SqList L)
{
    int i;
    for (i=1; i<L.length; i++)
        printf("%d,", L.r[i]);
    printf("%d", L.r[i]);
    printf("\n");
}

void BubbleSort2(SqList *L)
{
    int i, j;
    Status flag = TRUE;
    for (i=1; i<L->length; i++)
    {
        flag = FALSE;
        for (j=L->length-1; j>=i; j--)
        {
            if (L->r[j] > L->r[j + 1])
            {
                swap(L, j, j + 1);
                flag = TRUE;
            }
        }
    }
}

void SelectSort(SqList *L)
{
    int i, j, min;
    for (i=1; i < L->length; i++)
    {
        min = i;
        for (j = i + 1; j <= L->length; j++)
        {
            if (L->r[min] > L->r[j])
            {
                min = j;
            }
        }
        if (i != min)
        {
            swap(L, i, min);
        }
    }
}

void InsertSort(SqList *L)
{
    int i,j;
    for (i=2;i<=L->length;i++)
    {
        if (L->r[i] < L->r[i-1])
        {
            L->r[0] = L->r[i];
            for (j = i - 1; L->r[j] > L->r[0]; j --)
                L->r[j + 1] = L->r[j];
            L->r[j + 1] = L->r[0];
        }
    }
}

void ShellSort(SqList *L)
{
    int i, j, k=0;
    int increment=L->length;
    do
    {
        increment = increment/3 + 1;
        for (i = increment + 1; i <= L->length; i ++)
        {
            if (L->r[i] < L->r[i-increment])
            {
                L->r[0] = L->r[i];
                for (j = i - increment; j > 0 && L->r[0] < L->r[j]; j -= increment)
                    L->r[j+increment] = L->r[j];
                L->r[j+increment] = L->r[0];
            }
            printf("    第%d趟排序结果:", ++k);
            print(*L);
        }
    }
    while (increment > 1);
}

/* 堆排序 */

void HeapAdjust(SqList *L, int s, int m)
{
    int temp, j;
    temp = L->r[s];
    for (j = 2*s; j <= m; j*=2)
    {
        if (j < m && L->r[j] < L->r[j+1])
        {
            ++j;
        }
        if (temp >= L->r[j])
        {
            break;
        }
        L->r[s] = L->r[j];
        s = j;
    }
    L->r[s] = temp;
}

void HeapSort(SqList *L)
{
    int i;
    for (i = L->length/2; i > 0; i --)
        HeapAdjust(L, i, L->length);

    for (i=L->length; i > 1; i--)
    {
        swap(L, 1, i);
        HeapAdjust(L, 1, i-1);
    }
}

/* 快速排序 */

int Partition(SqList *L, int low, int high)
{
    int pivotkey;

    pivotkey = L->r[low];
    while (low < high)
    {
        while (low < high && L->r[high] >= pivotkey)
            high --;
        swap(L, low, high);
        while (low < high && L->r[low] <= pivotkey)
            low ++;
        swap(L, low, high);
    }
    return low;
}

void QSort(SqList *L, int low, int high)
{
    int pivot;
    if (low < high)
    {
        pivot = Partition(L, low, high);
        QSort(L, low, pivot - 1);
        QSort(L, pivot + 1, high);
    }
}

void QuickSort(SqList *L)
{
    QSort(L, 1, L->length);
}

/* ********************************** */
#define N 9
int main()
{
    int i;

    /*int d[N] = {9,1,5,8,3,7,4,6,2};*/
    int d[N]={50,10,90,30,70,40,80,60,20};

    SqList l0, l1, l2, l3, l4, l5;
    
    for (i=0;i<N;i++)
        l0.r[i + 1] = d[i];
    l0.length = N;
    l5 = l4 = l3 = l2 = l1 = l0;

    printf("排序前:\n");
    print(l0);
    printf("改进冒泡排序:\n");
    BubbleSort2(&l0);
    print(l0);

    printf("选择排序:\n");
    SelectSort(&l1);
    print(l1);

    printf("直接插入排序:\n");
    InsertSort(&l2);
    print(l2);

    printf("希尔排序:\n");
    ShellSort(&l3);
    print(l3);

    printf("堆排序:\n");
    HeapSort(&l4);
    print(l4);

    printf("快速排序:\n");
    QuickSort(&l5);
    print(l5);

    return 0;
}
