#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct each
{
    int rollno;
    int gpa;
};

struct node
{
    char *data;
    struct each info;
    struct node *next;
};
struct pointers
{

    struct node *first;
    struct node *curr;
};
void create(struct pointers *head)
{
    int a = 0;
    do
    {
        a = 0;
        char arr[50];
        int roll, gpa;
        printf("Enter qualification: ");
        scanf("%s", arr);
        printf("Enter roll no: ");
        scanf("%d", &roll);
        printf("Enter gpa: ");
        scanf("%d", &gpa);
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp->data = (char *)malloc(sizeof(strlen(arr) + 1));
        strcpy(temp->data, arr);
        temp->info.gpa = gpa;
        temp->info.rollno = roll;
        temp->next = NULL;
        if (head->first == NULL)
        {
            head->first = temp;
            head->curr = temp;
        }
        else
        {
            head->curr->next = temp;
            head->curr = head->curr->next;
        }
        while (getchar() != '\n')
            ;

        printf("Want to add more value ? Enter 1: ");
        scanf("%d", &a);
    } while (a == 1);
}
struct node *reverse(struct pointers *head)
{
    struct node *p = head->first;
    struct node *q = NULL;
    struct node *temp = head->first->next;
    while (p != NULL)
    {
        p->next = q;
        q = p;
        p = temp;
        if (temp != NULL)
            temp = temp->next;
    }
    return q;
}

void display(struct node *head)
{
    while (head != NULL)
    {
        printf("%s \n", head->data);
        printf("Roll no : %d", head->info.rollno);
        printf("GPA : %d", head->info.gpa);
        head = head->next;
        printf("\n");
    }
    // printf("NULL");
}

int main()
{
    int n;
    printf("Enter number of students : ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        printf("For student -> %d\n", i);

        {
            struct pointers head;
            head.first = NULL;
            head.curr = NULL;
            create(&head);
            struct node *new_first;
            if (head.first == NULL)
                printf("NULL");
            new_first = reverse(&head);
            display(new_first);
        }
    }
}