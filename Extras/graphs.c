#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct linkedlist{
    int linkedData;
    struct linkedlist* nestedNext;
};

struct node{
    int data;
    struct linkedlist* nested;
    struct node* next;
};

struct linkedlist* insertNestedNode(struct linkedlist* root, int y){
    if(root == NULL){
        struct linkedlist* temp = (struct linkedlist*)malloc(1*sizeof(struct linkedlist));
        temp->linkedData = y;
        temp->nestedNext = NULL;
        root = temp;
    }

    struct linkedlist* temp = root;
    while(temp->nestedNext != NULL){
        temp = temp->nestedNext;
    }
    temp->linkedData = y;
    temp->nestedNext = NULL;
    return root;
}

struct node* insert(struct node* root, int x, int y){
    struct node* temp = root;
    while(temp->data != x){
        temp = temp->next;
    }
    insertNestedNode(temp->nested, y);

    temp = root;
    while(temp->data != y){
        temp = temp->next;
    }
    insertNestedNode(temp->nested, x);
    return root;
}

struct node* createBase(struct node* root, int n){
    printf("here ");
    struct node* temp = (struct node*)malloc(1*sizeof(struct node));
    temp->data = 1;
    temp->nested->nestedNext = NULL;
    temp->next = NULL;
    root = temp;
    struct node* temp1 = root;
    printf("%d ",temp1->data);
    // temp1 = temp1->next;
    for(int i=2; i<=n; i++){
        printf("h ");
        struct node* temp2 = (struct node*)malloc(1*sizeof(struct node));
        temp2->data = i;
        temp2->next = NULL;
        temp2->nested->nestedNext = NULL;
        temp1->next = temp2;
        temp1 = temp2;
    }
    return root;
}

void displayll(struct linkedlist* root){
    struct linkedlist* temp = root;
    while(temp->nestedNext != NULL){
        printf("%d ", temp->linkedData);
        temp = temp->nestedNext;
    }
    printf("\n");
    return;
}

void display(struct node* root){
    if(root==NULL){
        return;
    }
    struct node* temp = root;
    while(temp != NULL){
        printf("%d -> ", temp->data);
        displayll(temp->nested);
        temp = temp->next;
    }
}

int main(){
    int n;
    printf("Number of elements: ");
    scanf("%d",&n);
    int arr[n+1][n+1];
    int m;
    printf("Number of edges: ");
    scanf("%d",&m);

    // for adjacency matrix
    // for(int i=0; i<=n; i++){
    //     for(int j=0; j<=n; j++){
    //         arr[i][j]=0;
    //     }
    // }

    // for(int i=0; i<m; i++){
    //     int x,y;
    //     printf("Enter nodes: ");
    //     scanf("%d %d",&x,&y);
    //     arr[x][y] = arr[y][x] = 1;
    // }

    // for(int i=1; i<=n; i++){
    //     for(int j=1; j<=n; j++){
    //         printf("%d ",arr[i][j]);
    //     }
    //     printf("\n");
    // }

    // for adjacency list
    struct node* root = NULL;
    root = createBase(root, n);
    printf("%d",root->data);
    for(int i=0; i<n; i++){
        int x,y;
        printf("Enter nodes: ");
        scanf("%d %d",&x,&y);
        insert(root, x, y);
    }

    display(root);
    return 0;
}