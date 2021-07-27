#include <stdio.h>
#include <stdlib.h>

struct heap
{
    int med_ID;
    char *med_name;
    int price;
    int quantity;
    int count;
};

void Heapify(struct heap *h, int count, int index)
{
    struct heap node;
    int lchild = index * 2;
    int rchild = index * 2 + 1;

    int max = index;
    if (h[lchild].med_ID > h[max].med_ID)
        max = lchild;

    if (h[rchild].med_ID > h[max].med_ID)
        max = rchild;
    if (max != index)
    {
        node = h[index];
        h[index] = h[max];
        h[max] = node;
        Heapify(h, count, max);
    }
}

void Sort(struct heap *h, int *count)
{
    struct heap node;
    for (int i = (*count) / 2 - 1; i >= 0; i--)
        Heapify(h, count, i);
    for (int i = count - 1; i > 0; i--)
    {
        node = h[0];
        h[0] = h[i];
        h[i] = node;
        Heapify(h, count, 0);
    }
}

void search(struct heap *h, int medical_ID, int count)
{
    int i;
    for (i = 0; i < count; ++i)
    {
        if (h[i].med_ID == medical_ID)
            printf("Medicine is found\n");
    }
    if (i == count)
        printf("Medicine is not found\n");
}

void display_quantity(struct heap *h, int medical_ID, int count)
{
    int i;
    for (i = 0; i < count; i++)
    {
        if (h[i].med_ID == medical_ID)
            printf("Quantity of searched medicine is: %d\n", h[i].quantity);
    }
    if (i == count)
        printf("Medicine is not found\n");
}

int take_order(struct heap *h, int medical_ID, int order_quantity, int count)
{
    int i;
    for (i = 0; i < count; i++)
    {
        if (h[i].med_ID == medical_ID)
        {
            if (h[i].quantity >= order_quantity)
            {
                printf("Order placed\n");
                return 1;
                //h->quantity[i] = h->quantity[i] - order_quantity;
            }
            else
            {
                printf("Ordered quantity is more than available quantity , order can't be placed\n");
                return 0;
            }
        }
    }
    if (i == count)
    {
        printf("Medicine is not found\n");
        return 0;
    }
}

void total_cost(struct heap *h, int medical_ID, int order_quantity, int count)
{
    int i;
    for (i = 0; i < count; i++)
    {
        if (h[i].med_ID == medical_ID)
        {
            int amount = order_quantity * h[i].price;
            printf("Total cost of ordered medicine is: %d", amount);
        }
    }
    if (i == count)
        printf("Medicine is not found\n");
}

void update(struct heap *h, int medical_ID, int order_quantity, int count)
{
    int i;
    for (i = 0; i < count; i++)
    {
        if (h[i].med_ID == medical_ID)
        {
            if (h[i].quantity >= order_quantity)
            {
                h[i].quantity = h[i].quantity - order_quantity;
                printf("Quantity Updated \n");
            }
            else
                printf("Ordered quantity is more than available quantity , order can't be placed\n");
        }
    }
    if (i == count)
        printf("Medicine is not found\n");
}
void AddMedicine(struct heap *med_arr, int *count)
{

    int x, price, quantity;
    char name[50];

    printf("\nEnter medical ID:");
    scanf("%d", &x);
    printf("\nEnter medicine name:");
    scanf("%s", name);
    printf("\nEnter price of medicine");
    scanf("%d", &price);
    printf("\n Enter the quantity of medice");
    scanf("%d", &quantity);

    med_arr[*count].quantity = quantity;
    med_arr[*count].med_ID = x;
    med_arr[*count].med_name = (char *)malloc(sizeof(char) * strlen(name));
    strcpy(med_arr[*count].med_name, name);
    med_arr[*count].price = price;
    *count++;
}
void menu()
{
}
int main()
{
    struct heap med_arr[100];
    int count = 0;
    AddMedicine(med_arr, &count);

    search(med_arr, 10, count);
}