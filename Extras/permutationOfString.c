#include <stdio.h>
#include <stdlib.h>

void permute(char arr[], int k)
{
    static char res[10];
    static int flag[10] = {0};

    int i;
    if (arr[k] == '\0')
    {
        res[k] = '\0';
        printf("%s\n", res);
    }
    else
    {
        for (i = 0; arr[i] != '\0'; i++)
        {
            if (flag[i] == 0)
            {
                res[k] = arr[i];
                flag[i] = 1;
                permute(arr, k + 1);
                flag[i] = 0;
            }
        }
    }
}

int main()
{
    // int i = 0;
    char arr[] = "124";
    permute(arr, 0);
}