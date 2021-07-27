#include <bits/stdc++.h>
#include <stack>
using namespace std;
// has to use stack and queue

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

void levelOrderSpiral2Level(struct node *root)
{
    if (!root)
        return;
    bool RtoL = false;
    int c = 0;
    stack<struct node *> s;
    queue<struct node *> q;
    q.push(root);
    while (!q.empty())
    {
        struct node *temp;
        c++;
        int size = q.size();
        cout << endl;

        for (int i = 0; i < size; i++)
        {

            temp = q.front();
            q.pop();
            if (RtoL)
                s.push(temp);
            else
                cout << temp->data << "   ";
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
        if (RtoL)
        {
            cout << endl;

            while (!s.empty())
            {
                cout << s.top()->data << "   ";
                s.pop();
            }
        }
        if (c == 2)
        {
            RtoL = !RtoL;
            c = 0;
        }
    }
}
void print(struct node *root)
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
    struct node *root = NULL;
    int arr[] = {1, 2, 4, 8, -1, -1, 9, 16, -1, -1, -1, 5, 3, -1, -1, 1, 17, -1, -1, 18, -1, -1, 3, 6, 4, -1, -1, 2, -1, 19, -1, -1, 7, 7, -1, -1, 2, -1, -1};
    root = create_tree(arr);

    bool LtoR = true;

    // print(root);

    levelOrderSpiral2Level(root);
    return 0;
}
