/*
Shivam Yadav
20UEC121
7TH jUNE
*/
/*
Running commands ---->
gcc 20uec121.c -o 20uec121
./20uec121 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Defining structure for each student for roll number and gpa
struct each
{
    int rollno;
    int gpa;
};
// Defining structure for each student
struct node
{
    char *data;
    struct each info;
    struct node *next;
};
// Struct which will keep students list first pointers
struct pointers
{

    struct node *first;
    struct node *curr;
};

// Function to create linked list for the qualification
void create(struct pointers *head)
{
    int a = 0;
    do
    {
        // Variables defining
        a = 0;
        char arr[50];
        int roll, gpa;
        // Inputting variables values
        printf("Enter qualification: ");
        scanf("%s", arr);
        printf("Enter roll no: ");
        scanf("%d", &roll);
        printf("Enter gpa: ");
        scanf("%d", &gpa);
        // Giving memory eacch node
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp->data = (char *)malloc(sizeof(strlen(arr) + 1));
        strcpy(temp->data, arr);
        temp->info.gpa = gpa;
        temp->info.rollno = roll;
        temp->next = NULL;
        // checking if list is empty
        if (head->first == NULL)
        {
            head->first = temp;
            head->curr = temp;
        }
        else
        {
            // if list is not empty then adding to next
            head->curr->next = temp;
            head->curr = head->curr->next;
        }
        while (getchar() != '\n')
            ;

        // checking for more qualifications
        printf("Want to add more value ? Enter 1: ");
        scanf("%d", &a);
    } while (a == 1);
}

// Function to reverse the provided list
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
// Display function
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
}

// Main function to call members accordingly
int main()
{
    int n;
    printf("Enter number of students : ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) // for number of students
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