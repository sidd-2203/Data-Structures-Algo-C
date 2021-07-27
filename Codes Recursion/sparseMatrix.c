#include<stdio.h>
#include<stdlib.h>

struct element{
int i;
int j;
int x;
};

struct sparseMatrix
{
    int m;
    int n;
    int num;
    struct element *ele;
}; 

void create(struct sparseMatrix *s){
    int i;
    printf("Enter the dimensions m and n : ");
    scanf("%d%d",&s->m,&s->n);
    printf("Enter the number of non zero values :");
    scanf("%d",&s->num);
    s->ele=(struct element *)malloc((s->num)*sizeof(struct element));
    printf("Enter all the elements : ");
    for ( i = 0; i < s->num; i++)
    {
        scanf("%d%d%d",&s->ele[i].i,&s->ele[i].j,&s->ele[i].x);
    }

}

void display(struct sparseMatrix s){
    int i,j,k=0;
    for (i = 0; i < s.m; i++)
    {
        for ( j = 0; j < s.n; j++)
        {
            if(i==s.ele[k].i && j==s.ele[k].j)
            printf("%d",s.ele[k++].x);
            else
            printf("0");

        }
        printf("\n");
        
    }
    
}

int main(){
  struct sparseMatrix s;
  create(&s);
  display(s);
}