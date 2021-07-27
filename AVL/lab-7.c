#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *left, *right;
    int cust_id;
    char gender;
    int ht;
};

struct node *newNode(int c_id, char gender)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->left = temp->right = NULL;
    temp->cust_id = c_id;
    temp->gender = gender;
    temp->ht = 0;
    return temp;
}

int balance_factor(struct node *root)
{
    if (!root || root->ht == 0)
        return 0;
    else
    {
        if (!root->left)
            return -root->right->ht;
        else if (!root->right)
            return root->left->ht;
        else
            return root->left->ht - root->right->ht;
    }
}

int height(struct node *root)
{
    int lh = 0, rh = 0;
    if (!root)
        return 0;
    else
    {
        if (root->left)
            lh = 1 + root->left->ht;
        if (root->right)
            rh = 1 + root->right->ht;
        return lh > rh ? lh : rh;
    }
}

struct node *rotateright(struct node *x)
{
    struct node *temp;
    temp = x->left;
    x->left = temp->right;
    temp->right = x;
    x->ht = height(x);
    temp->ht = height(temp);
    return temp;
}

struct node *rotateleft(struct node *x)
{
    struct node *temp;
    temp = x->right;
    x->right = temp->left;
    temp->left = x;
    x->ht = height(x);
    temp->ht = height(temp);

    return temp;
}

// Single rotation due to left-to-left case
struct node *LL(struct node *root)
{
    root = rotateright(root);

    return root;
}

// Double  rotation due to left-to-right case
struct node *LR(struct node *root)
{
    root->left = rotateleft(root->left);
    root = rotateright(root);

    return root;
}

// Single rotation due to right-to-right case
struct node *RR(struct node *root)
{
    root = rotateleft(root);
    return root;
}

// double rotation due to right-to-left case
struct node *RL(struct node *root)
{
    root->right = rotateright(root->right);
    root = rotateleft(root);
    return root;
}

struct node *insert(struct node *root, int c_id, char gender)
{
    if (!root)
        root = newNode(c_id, gender);
    else if (root->cust_id < c_id)
    {
        root->right = insert(root->right, c_id, gender);
        root->ht = height(root);
        if (balance_factor(root) == -2)
        {
            if (c_id > root->right->cust_id)
                root = RR(root);
            else
                root = RL(root);
        }
    }
    else if (root->cust_id > c_id)
    {
        root->left = insert(root->left, c_id, gender);
        root->ht = height(root);
        if (balance_factor(root) == 2)
        {
            if (c_id < root->left->cust_id)
                root = LL(root);
            else
                root = LR(root);
        }
    }
    return root;
}

// finding difference between male and female  for cust_id<cid
int find_diff(struct node *root, int cid)
{
    int x = 0, y = 0;
    if (!root)
        return 0;
    if (!root->right && !root->left)
    {
        if (root->gender == 'M')
            return 1;
        else
            return -1;
    }
    else
    {
        if (root->cust_id < cid)
        {
            x = find_diff(root->left, cid);
            y = find_diff(root->right, cid);
        }
        else
        {
            x = find_diff(root->left, cid);
            y = 0;
        }
        if (root->gender == 'M')
            return x + y + 1;
        else
            return x + y - 1;
    }
}

// find the node of the given and changing its gender
struct node *update(struct node *root, int cid)
{
    if (!root)
        return root;
    if (root->cust_id == cid)
    {
        root->gender = 'M';
    }
    else if (root->cust_id < cid)
        root->left = update(root->right, cid);
    else
        root->right = update(root->right, cid);
    return root;
}

// function for finding number with Height H
int find_number_withHeight(struct node *root, int ht)
{
    if (!root)
        return 0;
    if (root->ht == ht)
        return 1;
    else
    {
        int x = find_number_withHeight(root->left, ht);
        int y = find_number_withHeight(root->right, ht);
        return x + y;
    }
}

int main(int argc, char const *argv[])
{

    return 0;
}
