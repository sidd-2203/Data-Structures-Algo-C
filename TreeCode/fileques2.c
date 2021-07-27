#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// It is a waste code as its time complexity is O(n^2)

struct node
{
    char *arr;
    struct node *next;
};
struct list
{
    struct node *curr, *first;
};
int search(struct list *hashtable, char *word)
{
    int flag = 0;
    for (int i = 1; i < 20; i++)
    {
        struct node *temp = hashtable[i].first, *prev = NULL;

        while (temp != NULL)
        {
            if (strcmp(temp->arr, word) == 0)
            {
                if (prev != NULL)
                    prev->next = temp->next;

                else
                    hashtable[i].first = hashtable[i].first->next;
                temp->next = NULL;
                if (hashtable[i + 1].first == NULL)
                {
                    hashtable[i + 1].first = temp;
                    hashtable[i + 1].curr = temp;
                }
                else
                {
                    hashtable[i + 1].curr->next = temp;
                    hashtable[i + 1].curr = temp;
                }
                flag = 1;
            }
            prev = temp;
            temp = temp->next;
            if (flag)
                break;
        }
        if (flag)
            break;
    }
    return flag;
}
void insert(struct list *hashtable, char *word)
{
    int found = search(hashtable, word);
    // if the word is not found keep it in freq 1 section
    if (!found)
    {
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp->arr = (char *)malloc(sizeof(char) * strlen(word));
        strcpy(temp->arr, word);
        temp->next = NULL;
        if (hashtable[1].first == NULL)
        {
            hashtable[1].first = temp;
            hashtable[1].curr = temp;
        }
        else
        {
            hashtable[1].curr->next = temp;
            hashtable[1].curr = temp;
        }
    }
}
void Frequent(struct list *hashtable)
{
    int count = 0;
    struct node *temp = NULL;
    for (int i = 20; i >= 0 && count < 10; i--)
    {

        if (hashtable[i].first != NULL)
            temp = hashtable[i].first;
        while (temp && count < 10)
        {
            printf("%s \n", temp->arr);
            temp = temp->next;
            count++;
        }
    }
}
void tenLowestFreqWord(struct list *hashtable)
{
    int count = 0;

    for (int i = 0; i < 20; i++)
    {
        struct node *temp = hashtable[i].first;
        while (temp)
        {
            printf("%s \n", temp->arr);
            temp = temp->next;
            count++;
            if (count == 10)
                break;
        }
        if (count == 10)
            break;
    }
}

void Create_Token(struct list *hashtable, char *arr)
{
    char word[10] = "\0";
    int j = 0;
    // printf("%d ", strlen(arr));
    for (int i = 0; i < strlen(arr); i++)
    {
        char c = arr[i];
        if (c != ' ' && c != ',' && c != '"' && isalpha(c))
            word[j++] = c;
        else
        {
            word[j] = '\0';
            if (word[0] != '\0')
            {
                insert(hashtable, word);
                // printf("%s\n", word);
            }
            j = 0;
            word[0] = '\0';
        }
    }
}
int menu()
{
    int choice;
    printf("enter 1 for displaying 10 most frequent\n ");
    printf("Enter 2 for displaying 10 most rare words\n");
    printf("Enter 3 for searching any element\n");
    printf("Enter 4 for quit\n");
    scanf("%d", &choice);
    return choice;
}
int main(int argc, char const *argv[])
{
    char arr[500] = "para1:The vaccine was more than 90\% effective in a late - stage US - based clinical trial, according to the company.The government has also ordered 300 million doses of another vaccine from Indian firm Biological E.";

    char word[20];
    struct list hashtable[21];
    for (int i = 0; i < 21; i++)
    {
        hashtable[i].curr = NULL;
        hashtable[i].first = NULL;
    }

    Create_Token(hashtable, arr);

    int k = menu();
    switch (k)
    {
    case 1:
        Frequent(hashtable);
        break;
    case 2:
        tenLowestFreqWord(hashtable);
        break;
    case 3:
        printf("Enter the word");
        scanf("%s", word);
        search(hashtable, word);
        break;
    case 4:
        exit(1);
    default:
        break;
    }
    return 0;
}
