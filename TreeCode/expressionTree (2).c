#include <stdio.h>
#include <stdlib.h>

struct node
{
	char data;
	struct node *right;
	struct node *left;
};

void postorder(struct node *root)
{
	if (root == NULL)
		return;
	else
	{
		postorder(root->left);
		postorder(root->right);
		printf("%c ", root->data);
	}
}

int precedence(char sign)
{
	if (sign == '+' || sign == '-')
		return 0;
	else
		return 1;
}

struct node *create_tree(char arr[], int start, int end)
{

	if (start == end)
	{
		struct node *temp = (struct node *)malloc(sizeof(struct node));
		temp->data = arr[start];
		temp->left = NULL;
		temp->right = NULL;
		return temp;
	}
	int rank, i, in_index, min = 2;
	for (i = start; i <= end; i++)
	{
		if (arr[i] == '+' || arr[i] == '-' || arr[i] == '*' || arr[i] == '/')
		{
			rank = precedence(arr[i]);
			if (rank <= min)
			{
				min = rank;
				in_index = i;
			}
		}
	}
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = arr[in_index];
	temp->left = create_tree(arr, start, in_index - 1);
	temp->right = create_tree(arr, in_index + 1, end);
	return temp;
}

int main()
{
	char arr[] = "3*5+7/3-4";
	int len = sizeof(arr) / sizeof(arr[0]);
	struct node *root = create_tree(arr, 0, 8);
	postorder(root);
}
