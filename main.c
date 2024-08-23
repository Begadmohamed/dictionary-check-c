#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

typedef struct
{
    char *data;
    struct node *left,*right;
} node;

node*newnode(char *val)
{
    node*n=malloc(sizeof(node));
    n->data=malloc(strlen(val)+1);
    strcpy(n->data,val);
    n->left=NULL;
    n->right=NULL;
    return n;
}
node* insert(node* root,char *key)
{
    if(root==NULL)
        root=newnode(key);
    else if(strcasecmp(root->data,key)>0)
        root->left=insert(root->left,key);
    else if(strcasecmp(root->data,key)<0)
        root->right=insert(root->right,key);
    return root;
}
node* load(char *filename,node *root)
{
    FILE *f=fopen(filename,"r");
    if(f==NULL)
    {
        printf("\nCant't open file \n");
        exit(1);
    }
    root=NULL;
    char word[25];
    while(fgets(word,sizeof(word),f)!=NULL)
    {
        word[strcspn(word,"\n")]='\0';
        root=insert(root,word);
    }
    fclose(f);
    printf("\nDictionary loaded succesfully..!\n");
    return root;
}
int count(node*root)
{
    if(root==NULL)
        return 0;
    return 1+count(root->right)+count(root->left);
}
int max(int a,int b)
{
    return a>b?a:b;
}
int height(node* root)
{
    if(root==NULL)
        return -1;
    return 1+max(height(root->left),height(root->right));
}
int search(node* root,char* key)
{
    if(root==NULL)
        return 0;
    else if(strcasecmp(root->data,key)==0)
        return 1;
    else if(strcasecmp(root->data,key)>0)
        return search(root->left,key);
    else if(strcasecmp(root->data,key)<0)
        return search(root->right,key);

}
node* findMin(node* root)
{
    if(root==NULL)
        return NULL;
    else if(root->left!=NULL)
        return findMin(root->left);
    else
        return root;
}
node* findMax(node* root)
{
    if(root==NULL)
        return NULL;
    else if(root->right!=NULL)
        return findMax(root->right);
    else
        return root;
}
node* LastNode(node*root,char* word,node*lastnode)
{
    if(root==NULL)
        return lastnode;
    else if(strcasecmp(root->data,word)>0)
    {
        lastnode=root;
        return LastNode(root->left,word,lastnode);
    }
    else if(strcasecmp(root->data,word)<0)
    {
        node*lastnode=root;
        return LastNode(root->right,word,lastnode);
    }

}
node* inOrder_Successor (node* root,node* lastnode)
{
    node* successor = NULL;
    while (root != NULL)
    {
        if (strcasecmp(lastnode->data, root->data) < 0)
        {
            successor = root;
            root = root->left;
        }
        else
            root = root->right;

    }
    return successor;
}
node* inOrder_predecessor (node* root,node* lastnode)
{
    node*predecessor=NULL;
    while(root!=NULL)
    {
        if (strcasecmp(lastnode->data, root->data) > 0)
        {
            predecessor=root;
            root=root->right;
        }
        else
            root=root->left;
    }
    return predecessor;
}
void DicCheck(node* root,char *sentence)
{
    char sentenceCopy[200];
    strcpy(sentenceCopy, sentence);
    char *token=strtok(sentenceCopy, " ");
    while(token !=NULL)
    {
        if(search(root,token)==1)
            printf("\n%s - CORRECT\n",token);
        else
        {
            node* lastnode = NULL;
            lastnode = LastNode(root, token, lastnode);
            if (lastnode != NULL)
            {
                node* predecessor = inOrder_predecessor(root,lastnode);
                node* successor = inOrder_Successor(root,lastnode);
                printf("\n%s - Incorrect, suggestions: %s %s %s\n", token, lastnode->data,
successor ? successor->data : "None",predecessor ? predecessor->data : "None");
            }
            else
            {
                printf("\n%s - Incorrect, no suggestions found\n", token);
            }
        }
        token=strtok(NULL, " ");
    }


}

int main()
{
    node*root=load("Dictionary.txt",root);
    printf("\n--------------------------------------------------------\n");
    printf("\nSize = %d\n\nHeight = %d\n\n",count(root),height(root));
    printf("--------------------------------------------------------\n");
        char Sentence[200];
    do
    {
        printf("\nEnter a sentence to check : \n\n");
        fgets(Sentence,200,stdin);
        Sentence[strcspn(Sentence,"\n")]='\0';
        if (Sentence[0] == '\0')
            printf("You entered an empty string. Please try again.\n\n");

    }
    while(Sentence[0] == '\0');
    DicCheck(root,Sentence);

    return 0;
}
