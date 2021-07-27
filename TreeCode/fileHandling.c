#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char *arr;
    struct node *left;
    struct node *right;
    int freq;
};
struct node *create_node(char *arr)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    int length = strlen(arr);
    temp->arr = (char *)malloc(sizeof(char) * length);
    strcpy(temp->arr, arr);
    temp->left = temp->right = NULL;
    temp->freq = 1;
    return temp;
}

struct node *Insert(struct node *root, char *arr)
{
    if (!root)
    {
        root = create_node(arr);
        return root;
    }
    else
    {
        int k = strcmp(root->arr, arr);
        if (k == 0)
        {
            root->freq += 1;
            return root;
        }
        else if (k < 0)
            root->right = Insert(root->right, arr);

        else
            root->left = Insert(root->left, arr);
    }
    return root;
}
struct node *search(struct node *root, char *arr)
{
    if (!root)
        return NULL;
    int k = strcmp(root->arr, arr);
    if (k == 0)
        return root;
    else if (k < 0)
        return search(root->right, arr);
    else
        return search(root->left, arr);
}

struct node *Create_Token(FILE *f1, FILE *f2, struct node *root)
{
    char r, word[100]; // maximum length of each word
    while (1)
    {
        r = (char)fgetc(f1);
        if (r == '"' || r == '[')
            r = (char)fgetc(f1);
        int k = 0;
        while ((r != ' ' && r != ',' && r != '.') && !feof(f1))
        {
            word[k++] = r;
            r = (char)fgetc(f1);
            if (r == '[' || r == ']')
                r = (char)fgetc(f1);
            // printf("%c  ", r);
        }
        if (word[k - 1] == '"' || word[k - 1] == ']')
            word[k - 1] = '\0';
        else
            word[k] = '\0';
        fprintf(f2, "%s\n", word);
        root = Insert(root, word);
        // if (root->left)
        //     printf("%s ", root->left->arr);
        if (feof(f1))
            break;
    }
    return root;
}
void UniqueWords(FILE *f2, FILE *f3, struct node *root)
{
    int key = 0;
    char *word = (char *)malloc(sizeof(char) * 100);
    // char word[100];
    rewind(f2);
    struct node *temp = NULL;
    int i = 0;
    while (1)
    {
        key = 0;
        fscanf(f2, "%s", word);
        temp = search(root, word);
        // printf("%s  %s", word, root->arr);
        // empty word to be managed
        if (temp == NULL)
            printf("Not found  %s ", word);
        else
        {
            if (temp->freq == 1)
                fprintf(f3, "%s\n", word);
        }
        if (feof(f2))
            break;
        i++;
    }
}

int main(int argc, char const *argv[])
{
    struct node *root = NULL;
    FILE *file1, *file2, *file3;
    file1 = fopen("football.txt", "r");
    file2 = fopen("File2.txt", "w+");
    file3 = fopen("File3.txt", "w");
    if (file1 == NULL)
        printf("Error, File does not exitst at the location");
    else
    {
        // printf("File is found");
        root = Create_Token(file1, file2, root);
        // if (root)
        //     printf("%s ", root->arr);
        UniqueWords(file2, file3, root);
    }

    fclose(file1);
    fclose(file2);
    fclose(file3);
    return 0;
}
