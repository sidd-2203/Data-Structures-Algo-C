#include<stdio.h>
#include<string.h>

int main(){


    char a[]="finding";
    int h=0,x=0;
    // printf("%d",sizeof(int));
    for (int i = 0;a[i]!='\0'; i++)
    {
        x=1;
        x=x<<(a[i]-97);
        // printf("%d\n",x&h);
        if((x&h) >0 )
            printf("%c is Duplicate \n",a[i]);
         else
            h=x|h;
    }
    


return 0;
}