//SHIVAM YADAV
// Roll No.-20UEC121
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct node
{
    char *arr;
    struct node *next;
};
struct list
{
    struct node *curr, *first;
};
int search(struct list *hash_array, char *word) //to search the word in array
{
    int flag = 0;
    for (int i = 1; i < 20; i++)
    {
        struct node *temp = hash_array[i].first, *prev = NULL;

        while (temp != NULL)
        {
            if (strcmp(temp->arr, word) == 0)
            {
                if (prev != NULL)
                    prev->next = temp->next;

                else
                    hash_array[i].first = hash_array[i].first->next;
                temp->next = NULL;
                if (hash_array[i + 1].first == NULL)
                {
                    hash_array[i + 1].first = temp;
                    hash_array[i + 1].curr = temp;
                }
                else
                {
                    hash_array[i + 1].curr->next = temp;
                    hash_array[i + 1].curr = temp;
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
void insert(struct list *hash_array, char *word) //to insert the word in the array
{
    int found = search(hash_array, word);
    // if the word is not found keep it in freq 1 section
    if (!found)
    {
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp->arr = (char *)malloc(sizeof(char) * strlen(word));
        strcpy(temp->arr, word);
        temp->next = NULL;
        if (hash_array[1].first == NULL)
        {
            hash_array[1].first = temp;
            hash_array[1].curr = temp;
        }
        else
        {
            hash_array[1].curr->next = temp;
            hash_array[1].curr = temp;
        }
    }
}
void Frequent(struct list *hash_array) //to count the frequency of word
{
    int count = 0;
    struct node *temp = NULL;
    for (int i = 20; i >= 0 && count < 10; i--)
    {

        if (hash_array[i].first != NULL)
            temp = hash_array[i].first;
        while (temp && count < 10)
        {
            printf("%s \n", temp->arr);
            temp = temp->next;
            count++;
        }
    }
}
void tenLowestFreqWord(struct list *hash_array) //to count the lowest frequent word
{
    int count = 0;

    for (int i = 0; i < 20; i++)
    {
        struct node *temp = hash_array[i].first;
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

void Create_Token(struct list *hash_array, char *arr) //separating words from the array
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
                insert(hash_array, word);
                // printf("%s\n", word);
            }
            j = 0;
            word[0] = '\0';
        }
    }
}
int menu() //menu option
{
    int choice;
    printf("enter 1 for displaying 10 most frequent\n ");
    printf("Enter 2 for displaying 10 most rare words\n");
    printf("Enter 3 for searching any element\n");
    printf("Enter 4 for quit\n");
    scanf("%d", &choice);
    return choice;
}
int main(int argc, char const *argv[]) // main function
{
    char arr[600] = "Farmers protesting against the three contentious agri laws passed by the central government launched an agitation on Thursday at the Jantar Mantar near Parliament in New Delhi. A series of demonstrations against the farm laws are being held by the Samyukta Kisan Morcha (SKM), an umbrella body of protesting farm unions.The farmers' movement was granted permission for the Jantar Mantar demonstration by Delhi lieutenant-governor Anil Baijal on the condition that only a maximum of 200 protestors will be allowed till August 9 ";

    char word[20];
    struct list hash_array[21];
    for (int i = 0; i < 21; i++)
    {
        hash_array[i].curr = NULL;
        hash_array[i].first = NULL;
    }

    Create_Token(hash_array, arr);

    int k = menu();
    printf("%d", k);
    switch (k)
    {
    case 1:
        Frequent(hash_array);
        break;
    case 2:
        tenLowestFreqWord(hash_array);
        break;
    case 3:
        printf("Enter the word");
        scanf("%s", word);
        search(hash_array, word);
        break;
    case 4:
        exit(1);
    default:
        break;
    }
    return 0;
}
