#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node*right;
    struct Node*left;
};
struct Node*createNode(int data){
    struct Node*ptr = (struct Node*) malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->right = NULL;
    ptr->left = NULL;
    return ptr;
}
void createTree(struct Node** root, int data){
    if(*root == NULL){
        *root = createNode(data);
    }else{
        struct Node*prev = NULL;
        struct Node*ptr = createNode(data);
        struct Node*p = *root;
        while(p!=NULL){
            prev = p;
            if(p->data == data){
                printf("Duplicate Entry:\nCannot be Inserted:\n");
                return;
            }else if(p->data > data){
               p = p->left;
            }else if(p->data < data){
                p = p->right;
            }
        }
        if(prev->data > data){
            prev->left = ptr;
        }else{
            prev->right = ptr;
        }
    }
}
void inorderTraversal(struct Node*root){
    struct Node*p = root;
    if(p!=NULL){
        inorderTraversal(p->left);
        printf("%d\t",p->data);
        inorderTraversal(p->right);
    }
}
struct Node*SecondMaxElement(struct Node*root,int k){
    struct Node*p = root;
    int i = 0;
    while(i!=k-1){
        p = p->right;
        i++;
    }
    return p;
}
int main(){
    struct Node*root = NULL;
    int data;
    for(int i = 0; i<7; i++){
        printf("Enter the Data:\n");
        scanf("%d",&data);
        createTree(&root, data);
    }
    
    printf("IN-ORDER traversal:\n");
    inorderTraversal(root);
    struct Node* s =SecondMaxElement(root,2);
    printf("\nMaximum Element = %d\n",s->data);

}