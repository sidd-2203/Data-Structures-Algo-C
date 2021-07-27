#include <stdio.h>
#include <stdlib.h>
#define mm 10

struct heap
{
    int *arr;
    int capacity;
    int currentCount;
};
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
// parent at i then children are
// left child   (2*i)
// right child (2*i+1)

int parent(int i)
{
    return (i - 1) / 2;
}
int lchild(int i)
{
    return 2 * i + 1;
}
int rchild(int i)
{
    return 2 * i + 2;
}

void Heapify_deletion(struct heap *mHeap, int i)
{
    int max = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < mHeap->currentCount && mHeap->arr[l] > mHeap->arr[max])
        max = l;
    if (r < mHeap->currentCount && mHeap->arr[r] > mHeap->arr[max])
        max = r;

    if (max != i)
    {
        swap(&mHeap->arr[max], &mHeap->arr[i]);
        Heapify(mHeap, max);
    }
}
void insertInHeap(struct heap *mHeap)
{
    int n;
    printf("enter the total Number of elements : ");
    scanf("%d", &n);
    if (n > mHeap->capacity)
    {
        mHeap->arr = (int *)realloc(mHeap->arr, sizeof(int) * n);
        mHeap->capacity = n;
    }
    printf("enter %d students ", n);
    for (int i = mHeap->currentCount; i < n; i++)
    {
        scanf("%d", &mHeap->arr[i]);
        mHeap->currentCount++;
    }
    Heapify(mHeap, 0);
}
void Delete(struct heap *mHeap)
{
    int first = mHeap->arr[0];
    int last = mHeap->arr[mHeap->currentCount - 1];
    mHeap->arr[0] = last;
    // mHeap->arr[mHeap->currentCount - 1] = first; // just for heap sort
    mHeap->currentCount--;
    Heapify(mHeap, 0);
}
void Print(struct heap *mHeap)
{
    for (int i = 0; i < mHeap->currentCount; i++)
    {
        printf("%d  ", mHeap->arr[i]);
    }
}
int main(int argc, char const *argv[])
{
    struct heap mHeap;
    mHeap.arr = (int *)malloc(sizeof(int) * mm);
    mHeap.capacity = mm;
    mHeap.currentCount = 0;

    insertInHeap(&mHeap);
    Print(&mHeap);
    printf("\n");
    Delete(&mHeap);
    Print(&mHeap);
    return 0;
}
