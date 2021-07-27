#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 300

struct node
{
    char *arr;
    int freq;
};

void Heapify(struct node *word_token_maxHeap[], int count, int k)
{
    int child = k;
    int parent = (child - 1) / 2;
    struct node *nodetemp = word_token_maxHeap[child];

    while (child >= 0 && word_token_maxHeap[child]->freq > word_token_maxHeap[parent]->freq)
    {
        nodetemp = word_token_maxHeap[child];
        word_token_maxHeap[child] = word_token_maxHeap[parent];
        word_token_maxHeap[parent] = nodetemp;
        child = parent;
        parent = (child - 1) / 2;
    }
}

int Find_Articles_words(struct node *word_Token_maxHeap[], char *word, int *count, int needed)
{

    for (int i = 0; i < *count; i++)
    {
        if (strcmp(word_Token_maxHeap[i]->arr, word) == 0)
        {
            if (needed)
                printf("Word Found");
            return i;
        }
    }
    if (needed)
        printf("Not found");
    return -1;
}
void insert(struct node *word_Token_maxHeap[], char *word, int *count)
{
    int k = Find_Articles_words(word_Token_maxHeap, word, count, 0);
    int count2 = *count;
    int length = strlen(word);
    //  printf("%d %d",*count,length);
    if (k == -1)
    {
        word_Token_maxHeap[*count]->arr = (char *)malloc(sizeof(char) * length);

        strcpy(word_Token_maxHeap[*count]->arr, word);
        word_Token_maxHeap[*count]->freq = 1;
        *count += 1;
    }
    else
    {
        word_Token_maxHeap[k]->freq += 1;
        Heapify(word_Token_maxHeap, *count, k);
    }
}

void Remove_Numerals(struct node *word_token_maxHeap[], int count)
{
    char word[20] = "\0";
    for (int i = 0; i < count; i++)
    {
        int k = 0;
        struct node *temp = word_token_maxHeap[i];
        int length = strlen(word_token_maxHeap[i]->arr);
        // printf("%s\n", word_token_maxHeap[i]->arr);
        for (int j = 0; j < length; j++)
        {

            if (isalpha(word_token_maxHeap[i]->arr[j]))
            {
                word[k++] = temp->arr[j];
            }
        }
        word[k] = '\0';
        k = 0;
        strcpy(word_token_maxHeap[i]->arr, word);
    }
}

void Find_Frequnecy(struct node *word_token_maxheap[], int count)
{
    for (int i = 0; i < count; i++)
    {
        printf("%s  %d\n", word_token_maxheap[i]->arr, word_token_maxheap[i]->freq);
    }
}
void Display_Most_Rare_words(struct node *word_token_maxheap[], int count)
{
    int number = 0;
    for (int i = count; i >= 0 && number < 10; i--)
    {
        printf("%s \n", word_token_maxheap[i]->arr);
        number++;
    }
}
void Display_Most_freq_words(struct node *word_token_maxheap[], int count)
{
    int number = 0;
    for (int i = 0; i < count && number < 10; i++)
    {
        printf("%s \n", word_token_maxheap[i]->arr);
        number++;
    }
}

void Create_Token(struct node *word_token_maxheap[], char *para, int *count)
{
    int length = strlen(para);

    char word[20] = "\0";
    for (int i = 0, k = 0; i < length; i++)
    {
        if (para[i] == '.' || para[i] == ',' || para[i] == ':' || para[i] == '-' || para[i] == ' ')
        {
            if (k != 0)
            {
                word[k] = '\0';
                insert(word_token_maxheap, word, count);
                k = 0;
            }
        }
        else
            word[k++] = para[i];
    }
}

int Menu()
{
    int choice;
    printf("Enter 1 for Find_Frequnecy \n");
    printf("Enter 2 for finding a word \n");
    printf("Enter 3 for Displaying most frequent words \n");
    printf("Enter 4 for Displaying most rare words\n");
    printf("Enter 5 to QUIT\n");
    scanf("%d", &choice);
    return choice;
}

int main(int argc, char const *argv[])
{

    struct node *Word_token[MAX];
    for (int i = 0; i < MAX; i++)
    {
        Word_token[i] = (struct node *)malloc(sizeof(struct node));
    }

    int count = 0;
    char para1[1000] = "India and the world changed dramatically at the beginning of the 1990s. Communist Soviet Union collapsed. The Cold War ended. And India embarked on a bold new path of economic reforms. Thirty years later, the global order is changing fundamentally yet again.";
    char para2[500] = "The speed, scale and substance of this change are unprecedented, even unpredictable. Yet, one thing is absolutely predictable: India’s time has come. Destiny and Drive are making the 21st century’s favourite nation ready for a great leap forward.";
    char para3[500] = "India stands at the doorstep of prosperity that is both significant and inclusive, and of delivering all-round human development through the democratic route. With faith in our potential, confidence in our collective capabilities, and unity in action, we can exceed the world’s expectations.";
    char para4[500] = "My source of optimism is our recent past. In 1991, India showed foresight and courage in changing both the direction and determinants of its economy. The government placed the private sector also at the commanding heights of the national economy, which the public sector had occupied for the previous four decades.";
    char para5[500] = "It ended the license-quota raj, liberalised trade and industrial policies, and freed up capital markets and the financial sector. These reforms liberated India’s entrepreneurial energy.";

    Create_Token(Word_token, para1, &count);
    Create_Token(Word_token, para2, &count);
    Create_Token(Word_token, para3, &count);
    Create_Token(Word_token, para4, &count);
    Create_Token(Word_token, para5, &count);
    Remove_Numerals(Word_token, count);
    // Menu();
    while (1)
    {
        char word[20];
        int k = Menu();
        switch (k)
        {
        case 1:
            Find_Frequnecy(Word_token, count);
            break;
        case 2:
            printf("Enter the word");
            scanf("%s", word);
            Find_Articles_words(Word_token, word, &count, 1);
            break;
        case 3:
            Display_Most_freq_words(Word_token, count);
            break;
        case 4:
            Display_Most_Rare_words(Word_token, count);
            break;
        case 5:
            exit(1);
            break;
        default:
            break;
        }
    }
    return 0;
}
