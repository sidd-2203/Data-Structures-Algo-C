#include <stdio.h>
#include <stdlib.h>
struct treenode
{
    struct treenode *left, *right;
    int data;
};
struct que_node
{
    struct treenode *data;
    struct que_node *next;
};
struct linked_que
{
    struct que_node *first;
    struct que_node *curr;
};

struct treenode *create_tree(int arr[])
{
    static int a = 0;
    struct treenode *temp;
    int x;
    temp = (struct treenode *)malloc(sizeof(struct treenode));
    x = arr[a++];
    if (x == -1)
        return NULL;
    temp->data = x;
    temp->left = create_tree(arr);
    temp->right = create_tree(arr);
    return temp;
}
struct treenode *deque(struct linked_que *list)
{
    if (!list->first)
        return NULL;
    struct treenode *temp = list->first->data;
    struct que_node *temp1 = list->first;
    list->first = list->first->next;
    free(temp1);
    return temp;
}
void enque(struct linked_que *list, struct treenode *node)
{
    struct que_node *temp = (struct que_node *)malloc(sizeof(struct que_node));
    temp->data = node;
    temp->next = NULL;
    if (!list->first)
    {
        list->first = temp;
        list->curr = temp;
    }
    else
    {
        list->curr->next = temp;
        list->curr = temp; // one forward
    }
}
struct treenode *search_parent(struct linked_que *list, struct treenode *root)
{
    struct treenode *parent = NULL, *temp;
    int flag = 1;
    enque(list, root);
    while (flag)
    {
        temp = deque(list);
        flag = 0;
        if (temp->left)
        {
            enque(list, temp->left);
            flag = 1;
        }
        if (temp->right)
        {
            enque(list, temp->right);
            flag = 1;
        }
        if (flag)
            parent = temp;
    }
    return parent;
}
struct treenode *search(struct treenode *root, int key)
{
    if (!root)
        return NULL;
    if (root->data == key)
        return root;
    struct treenode *temp = search(root->left, key);
    if (!temp)
        return search(root->right, key);
    return temp;
}
void delete_node(struct treenode *root, int data, struct linked_que *list)
{
    struct treenode *temp = search(root, data), *parent = NULL;
    if (!temp)
        printf("given data does not exist in the tree");
    else
    {
        parent = search_parent(list, root);
        if (parent->right)
        {
            temp->data = parent->right->data;
            free(parent->right);
            parent->right = NULL;
        }
        else
        {
            temp->data = parent->left->data;
            free(parent->left);
            parent->left = NULL;
        }
    }
}

void print(struct treenode *root)
{
    if (root)
    {
        printf("%d  ", root->data);
        print(root->left);
        print(root->right);
    }
}
int main(int argc, char const *argv[])
{

    struct treenode *root = NULL;
    int arr[] = {5, 6, 7, -1, -1, 8, -1, -1, 9, 10, -1, -1, -1};
    root = create_tree(arr);
    struct linked_que list;
    list.curr = NULL;
    list.first = NULL;
    printf("Before deleting Tree\n");
    print(root);
    int x;
    printf("\nEnter the data to be deleted \n");
    scanf("%d", &x);
    delete_node(root, x, &list);
    printf("\nAfter deleting node\n");
    print(root);
    return 0;
}