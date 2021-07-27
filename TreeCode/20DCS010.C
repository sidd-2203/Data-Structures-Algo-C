/*
Name: Siddharth Chaudhary
Roll No: 20DCS010
Date: 3rd June
Batch : P2
*/

/* Running command  -->
gcc 20DCS010.C -o 20dcs010
./20dcs010
*/

#include <stdlib.h> // Library for printf and scanf
#include <stdio.h>  // Library for malloc

// defining a node for containing coeff and power
struct node
{
    int coeff;
    int power;
    struct node *next;
};

// list struct for containg pointers of current list
struct list
{
    struct node *first;
    struct node *curr;
};

// Function for initialising pointers
void initialize(struct list *ptr)
{
    ptr->first = NULL;
    ptr->curr = NULL;
}
// function to crete lists --->
void create(struct list *ll)
{
    // Defining varaibles
    int ans = 0, c, p;
    do
    {
        ans = 0;
        // taking input from user
        printf("Enter the coeff and power: ");
        scanf("%d %d", &c, &p);
        // Dynamic memory allocation for each node
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp->coeff = c;
        temp->power = p;
        temp->next = NULL;
        // if list is empty
        if (ll->first == NULL)
        {
            ll->first = temp;
            ll->curr = temp;
        }
        else // If list is not empty
        {
            ll->curr->next = temp;
            ll->curr = ll->curr->next;
        }
        printf("Enter 1 if you want to add more terms ");
        scanf("%d", &ans);
    } while (ans == 1);
}

// Function for merging two list and returning the resultant
struct list *merge(struct list *l1, struct list *l2)
{
    struct list *l3;
    struct node *free_var;
    // allocating dynamic memory for list3 head and current pointers
    l3 = (struct list *)malloc(sizeof(struct list));
    initialize(l3);
    // For setting first node of list 3
    if (l1->first->power > l2->first->power) // if power of first list greater than second
    {
        l3->first = l1->first;
        l3->curr = l1->first;
        l1->first = l1->first->next;
    }
    else if (l1->first->power < l2->first->power) // if power of first is less than second
    {
        l3->first = l2->first;
        l3->curr = l2->first;
        l2->first = l2->first->next;
    }
    else // if power is same we can store its sum of coefficients in list one coeffient and then adding it to list 3
    {
        l1->first->coeff = l1->first->coeff + l2->first->coeff;
        l1->first->power = l1->first->power + l2->first->power;
        l3->first = l1->first;
        l3->curr = l1->first;
        free_var = l2->first;
        l1->first = l1->first->next;
        l2->first = l2->first->next;
        free(free_var); // freeing space consumed by l2 node
    }

    // for adding next nodes
    while (l1->first != NULL && l2->first != NULL) // till any one of them are null
    {
        if (l1->first->power > l2->first->power)
        {
            l3->curr->next = l1->first;
            l3->curr = l3->curr->next;
            l1->first = l1->first->next;
        }
        else if (l1->first->power < l2->first->power)
        {
            l3->curr->next = l2->first;
            l3->curr = l3->curr->next;
            l2->first = l2->first->next;
        }
        else
        { // if power is same we can store its sum of coefficients in list one coeffient and then adding it to list 3
            l1->first->coeff += l2->first->coeff;
            l3->curr->next = l1->first;
            l3->curr = l3->curr->next;
            free_var = l2->first;
            l1->first = l1->first->next;
            l2->first = l2->first->next;
            free(free_var); // Freeing the other variable
        }
    }
    // Adding the left list to the 3rd list
    if (l1->first != NULL) // if list 1 is not empty
    {
        l3->curr->next = l1->first;
    }
    else if (l2->first != NULL) // if list 2 is not empty
    {
        l3->curr->next = l2->first;
    }
    return l3;
}
// Display function for passed list
void display(struct list *head)
{ // priting till one less than last
    while (head->first->next != NULL)
    {
        if (head->first->coeff != 0)
            printf(" %dX^%d +", head->first->coeff, head->first->power);
        head->first = head->first->next;
    }
    // printing the last element
    printf("%dX^%d", head->first->coeff, head->first->power);
}

int main()
{
    int s;
    struct list first, second; // Creating two list first and second
    initialize(&first);
    initialize(&second);
    printf("\n\n<----------------------Data for 1st Expression ---------------->\n\n");
    create(&first); // Creating the first list
    printf("\n\n");
    printf("\n\n<----------------------Data for 2nd Expression ---------------->\n\n");
    create(&second); // Creating the second list
    printf("\n\n");

    // Calling the merge function to get the list and then passing it to display
    struct list *l3 = merge(&first, &second);
    display(l3);
}