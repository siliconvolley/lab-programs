# include<stdio.h>
# include<stdlib.h>
#include<string.h>
//BST

struct node
{
    char name[25],phno[15];
    struct node* leftChild, *rightChild;
};

typedef struct node *NODE;
int delflag;

NODE createnode()
{
    NODE temp;
    temp = (NODE)malloc(sizeof(struct node));
    printf("Enter the name: ");
    scanf("%s",temp->name);
    printf("Enter the phone number: ");
    scanf("%s",temp->phno);
    temp->leftChild = NULL;
    temp->rightChild = NULL;
    return temp;
}
void insertBST(NODE root, NODE newNode)
{
    if(strcmp(newNode->name,root->name)==0)
    {
        printf("Key already exists\n");
        return;
    }
    else if (strcmp(newNode->name,root->name)<0)
    {
        if (root->leftChild == NULL)
            root->leftChild = newNode;
        else
            insertBST(root->leftChild, newNode);
    }
    else
    {
        if (root->rightChild == NULL)
            root->rightChild = newNode;
        else
            insertBST(root->rightChild, newNode);
    }
}


int search(NODE root, char keyname[])
{
    if(!root)
        return -1;
    if(strcmp(keyname,root->name)==0)
        return 1;
    else if(strcmp(keyname,root->name)<0)
        return search(root->leftChild, keyname);
    else
        return search(root->rightChild,keyname);
}

NODE getRightMin(NODE root)
{
    NODE temp = root;
    while(temp->leftChild != NULL)
    {
        temp = temp->leftChild;
    }

    return temp;
}

NODE deleteBST(NODE root, char keyname[])
{
    if(!root)
    {
        delflag=-1;
        return NULL;
    }
    if(strcmp(keyname,root->name)<0)
        root->leftChild=deleteBST(root->leftChild, keyname);
    else if(strcmp(keyname,root->name)>0)
        root->rightChild=deleteBST(root->rightChild,keyname);
    else
    {
        if(root->leftChild==NULL && root->rightChild==NULL)
        {
            free(root);
            return NULL;
        }
        else if(root->leftChild == NULL)
        {
            NODE temp = root->rightChild;
            free(root);
            return temp;
        }
        else if(root->rightChild == NULL)
        {
            NODE temp = root->leftChild;
            free(root);
            return temp;
        }   
        else
        {
            NODE rightMin = getRightMin(root->rightChild);
            strcpy(root->name,rightMin->name);
            strcpy(root->phno,rightMin->phno);
            root->rightChild = deleteBST(root->rightChild,rightMin->name);
        }
    }
    return root;
}


void inorder(NODE temp)
{
    if (temp != NULL)
    {
        inorder(temp->leftChild);
        printf("|%s|%s|\t", temp->name,temp->phno);
        inorder(temp->rightChild);
    }
}

void preorder(NODE temp)
{
    if (temp != NULL)
    {
        printf("|%s|%s|\t", temp->name,temp->phno);
        preorder(temp->leftChild);
        preorder(temp->rightChild);
    }
}

void postorder(NODE temp)
{
    if (temp != NULL)
    {
        postorder(temp->leftChild);
        postorder(temp->rightChild);
        printf("|%s|%s|\t", temp->name,temp->phno);
    }
}

void main()
{
    int choice,n,i,keyFound = 0;
    char keyname[25];
    NODE root=NULL,newNode;
    printf("------------------Creating a BST------------------\n\n");
    printf("Enter the number of records in the BST: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        newNode = createnode();
        if(root == NULL)
            root = newNode;
        else
            insertBST(root,newNode);
    }
    while(1)
    {
        choice=0;
        printf("\n-----------------MENU----------------------\n");
        printf("1. Search a list for a specified name\n");
        printf("2. Insert a new name\n");
        printf("3. Deleting existing name\n");
        printf("4. Traverse the phone list\n");
        printf("5. Exit\n");
        printf("-------------------------------------------\n");
        printf("Enter choice : ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: printf("Enter the name to be searched:");
                    scanf("%s",keyname);
                    keyFound = search(root,keyname);
                    if(keyFound == 1)
                        printf("\nName: %s is found in the BST",keyname);
                    else
                        printf("\nName: %s is not found in the BST",keyname);
                    break;
            
            case 2: newNode = createnode();
                    if(root == NULL)
                        root = newNode;
                    else
                        insertBST(root,newNode);
                    break;
            
            case 3: if(root == NULL)
                        printf("Tree is empty\n");
                    else
                    {
                        delflag=0;
                        printf("Enter the name to be deleted:");
                        scanf("%s",keyname);
                        root=deleteBST(root,keyname);
                        if(delflag==-1)
                            printf("\nName: %s is not found in the BST\n",keyname);
                        else
                            printf("\nName: %s is deleted from the BST\n",keyname);
                    }
                    break;

            case 4: if (root == NULL)
                        printf("Tree is empty\n");
                    else
                    {
                        printf("\nBST Preorder traversal\n");
                        preorder(root);
                        printf("\nBST Inorder traversal\n");
                        inorder(root);
                        printf("\nBST Postorder traversal\n");
                        postorder(root);
                    }
                    break;
            
            case 5: return;
            
            default:printf("Wrong choice\n");
                    return;

        }
    }
}