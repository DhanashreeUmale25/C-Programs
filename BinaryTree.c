#include<stdio.h>  
#include<stdlib.h>  
struct node  
{  
    int data;  
    struct node *left;   
    struct node *right;   
};  
  struct node *root = NULL;
void main ()  
{  
    
    int choice =0;  
            printf("\n\t\t\t=========================================================================");
            printf("\n\t\t\t\t\t\t\tBinary Tree Opretions");  
            printf("\n\t\t\t=========================================================================\n");
           // root=insert();
        while(choice != 5)   
        {  
            printf("\nChoose one option from the following list ...\n");  
            printf("\n1.Insert Node\n2.Inorder\n3.Preorder\n4.Postorder\n5.Exit\n");  
            printf("\nEnter your choice?\n");         
            scanf("\n%d",&choice);  
            switch(choice)  
            {  
                case 1:  
                insert(); 
                break;  
                case 2:  
                printf("\nThe inorder traversal of tree is: ");
                inorder(root);
                break;  
                case 3:
                printf("\nThe preorder traversal of tree is: ");
                preorder(root);
                break;  
                case 4:  
                printf("\nThe postorder traversal of tree is: ");
                postorder(root);
                break;  
                case 5:  
                exit(0);  
                break;  
                default:  
                printf("Please enter valid choice..");  
            }  
        }  
}  
void insert()  
{  
    struct node *ptr, *parentptr , *nodeptr;  
    ptr = (struct node *) malloc(sizeof (struct node));  
    int item;
    if(ptr == NULL)  
    {  
        printf("can't insert");  
    }  
    else   
    { 
    printf("\nEnter the item which you want to insert?\n");  
    scanf("%d",&item); 
    ptr -> data = item;  
    ptr -> left = NULL;  
    ptr -> right = NULL;   
    if(root == NULL)  
    {  
        root = ptr;  
        root -> left = NULL;  
        root -> right = NULL;  
    }  
    else   
    {  
        parentptr = NULL;  
        nodeptr = root;   
        while(nodeptr != NULL)  
        {  
            parentptr = nodeptr;   
            if(item < nodeptr->data)  
            {  
                nodeptr = nodeptr -> left;   
            }   
            else   
            {  
                nodeptr = nodeptr -> right;  
            }  
        }  
        if(item < parentptr -> data)  
        {  
            parentptr -> left = ptr;   
        }  
        else   
        {  
            parentptr -> right = ptr;   
        }  
    }  
    printf("Node Inserted");  
    }  
}
void preorder(struct node *ptr)
{
  if(ptr!=NULL)
  {
    printf("  %d",ptr->data);
    preorder(ptr->left);
    preorder(ptr->right);
  }
}
void inorder(struct node *ptr)
{
  if(ptr!=NULL)
  {
    inorder(ptr->left);
    printf("  %d",ptr->data);
    inorder(ptr->right);
  }
}
void postorder(struct node *ptr)
{
  if(ptr!=NULL)
  {
    postorder(ptr->left);
    postorder(ptr->right);
    printf("  %d",ptr->data);
  }
}