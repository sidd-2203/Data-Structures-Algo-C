#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *next;
};
struct list
{
    struct node *head;
    struct node *curr;
};
void create_block(struct list *free)
{
    int n;
    printf("Enter value of n");
    scanf("%d", &n);
    struct node *temp;
    for (int i = 0; i < n; i++)
    {
        temp = (struct node *)malloc(1024);
        temp->next = NULL;
        if (!free->head)
        {
            free->head = temp;
            free->curr = temp;
        }
        else
        {
            free->curr->next = temp;
            free->curr = free->curr->next;
        }
    }
}
void allocate_k(struct list *free, struct list *occupied)
{
    int k;
    printf("Enter value of k");
    scanf("%d", &k);
    int t = 1;
    if (!occupied->head)
    {
        occupied->head = free->head;
    }
    else
    {
        occupied->curr->next = free->head;
    }
    while (t < k && free->head != NULL)
    {
        free->head = free->head->next;
        t++;
    }
    occupied->curr = free->head;
    free->head = free->head->next;
    occupied->curr->next = NULL;
}
void free_k(struct list *free, struct list *occupied)
{
    int k;
    printf("Enter value of s");
    scanf("%d", &k);
    int t = 1;
    if (!free->head)
    {
        free->head = occupied->head;
    }
    else
    {
        free->head->next = occupied->head;
    }
    while (t < k && occupied->head != NULL)
    {
        occupied->head = occupied->head->next;
        t++;
    }
    free->curr = occupied->head;
    occupied->head = occupied->head->next;
    free->curr->next = NULL;
}
void display_free(struct list *free)
{
    struct node *temp = free->head;
    while (temp)
    {
        printf("%x ", temp);
        temp = temp->next;
    }
}
void display_occupied(struct list *occupied)
{
    struct node *temp = occupied->head;
    while (temp)
    {
        printf("%x  ", temp);
        temp = temp->next;
    }
}
void instructions()
{
    printf("Menu:\n");
    printf("1:Create blocks\n");
    printf("2:Allocate memory\n");
    printf("3:Free memory block\n");
    printf("4:Display free list\n");
    printf("5:Display occupied list\n");
    printf("6:Quit\n");
}

int main()
{
    struct list free_list, occupied_list;
    free_list.curr = NULL;
    occupied_list.curr = NULL;
    free_list.head = NULL;
    occupied_list.head = NULL;

    int choice;
    while (1)
    {
        instructions();
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            create_block(&free_list);
            break;
        case 2:
            allocate_k(&free_list, &occupied_list);
            break;
        case 3:
            free_k(&free_list, &occupied_list);
            break;
        case 4:
            display_free(&free_list);
            break;
        case 5:
            display_occupied(&occupied_list);
            break;
        case 6:
            exit(1);
        }
    }
}