#include <bits/stdc++.h>
using namespace std;

struct node
{
    struct node *left, *right;
    int data;
};
struct node *create_tree(int arr[])
{
    static int a = 0;
    struct node *temp;
    int x;
    temp = (struct node *)malloc(sizeof(struct node));
    x = arr[a++];
    if (x == -1)
        return NULL;
    temp->data = x;
    temp->left = create_tree(arr);
    temp->right = create_tree(arr);
    return temp;
}
void levelOrder(struct node *root)
{
    if (!root)
        return;
    queue<struct node *> q;
    cout << root->data << endl;
    struct node *temp1 = NULL, *temp2 = NULL;

    if (root->left)
    {
        q.push(root->left);
        q.push(root->right);
    }
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size / 2; i++)
        {
            temp1 = q.front();
            q.pop();
            cout << temp1->data << " ";
            temp2 = q.front();
            q.pop();
            cout << temp2->data << endl;
            if (temp1->left)
            {
                q.push(temp1->left);
                q.push(temp2->right);
                q.push(temp1->right);
                q.push(temp2->left);
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    struct node *root = NULL;
    int arr[] = {1, 2, 4, 8, 16, -1, -1, 17, -1, -1, 9, 18, -1, -1, 19, -1, -1, 5, 10, 20, -1, -1, 21,
                 -1, -1, 11, 22, -1, -1, 23, -1, -1, 3, 6, 12, 24, -1, -1, 25, -1, -1,
                 13, 26, -1, -1, 27, -1, -1, 7, 14, 28, -1, -1, 29, -1, -1, 15, 30, -1, -1, 31, -1, -1};

    root = create_tree(arr);

    levelOrder(root);

    return 0;
}
