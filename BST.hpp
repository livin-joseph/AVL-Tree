#include<iostream>
using namespace std;

typedef struct Node
{
   int data;
   Node* left;
   Node* right;
}
node;

void insert(node*&,node*&);
void inorder(node*);
void preorder(node*);
void postorder(node*);
void levelorder(node*);
void printlevel(node*,int);
int height(node*);
node* find(node*,int);
int minimum(node*);
int maximum(node*);
void deleteMin(node*&);
void deleteMax(node*&);
int leaf(node*);

int search = 0;

void insert(node*& root,node*& key)
{
   if(root != NULL)
   {
      if(key->data > root->data)
         insert(root->right,key);
      else if(key->data < root->data)
         insert(root->left,key);
   }
   else
   {
      key->left = key->right = NULL;
      root = key;
   }
}

void inorder(node* root)
{
   if(root != NULL)
   {
      inorder(root->left);
      cout<< root->data <<endl;
      inorder(root->right);
   }
}

void preorder(node* root)
{
   if(root != NULL)
   {
      cout<< root->data <<endl;
      preorder(root->left);
      preorder(root->right);
   }
}

void postorder(node* root)
{
   if(root != NULL)
   {
      postorder(root->left);
      postorder(root->right);
      cout<< root->data <<endl;
   }
}

void printlevel(node* root,int level)
{
   if(root == NULL)
      return;
   if(level == 0)
      cout<< root->data <<endl;
   else if(level > 0)
   {
      printlevel(root->left,level-1);
      printlevel(root->right,level-1);
   }
}

void levelorder(node* root)
{
   int i;
   int h = height(root);
   if(root != NULL)
   {
      for(i=0;i<=h;i++)
      {
         printlevel(root,i);
      }
   }
}

int height(node* root)
{
   int rh=0,lh=0;
   if(root == NULL)
   {
      return -1;
   }
   else
   {
      lh=height(root->left);
      rh=height(root->right);
      return ((lh>rh)?lh+1:rh+1);
   }
}

node* find(node* root,int data)
{
   search++;
   if(root == NULL)
      return NULL;
   if(data == root->data)
   {
      return root;
   }
   if(data < root->data)
   {
      return find(root->left,data);
   }
   else if(data > root->data)
   {
      return find(root->right,data);
   }
   else
      return NULL;
}

int minimum(node* root)
{
   if(root->left == NULL)
      return (root->data);
   else
      return (minimum(root->left));
}

int maximum(node* root)
{
   if(root->right == NULL)
      return (root->data);
   else
      return (maximum(root->right));
}

void deleteMin(node*& root)
{
   if(root->left == NULL)
   {
      node* ptr = root;
      root = root->right;
      delete ptr;
      return;
   }
   else
   {
      deleteMin(root->left);
   }
}

void deleteMax(node*& root)
{
   if(root->right == NULL)
   {
      node* ptr = root;
      root = root->left;
      delete ptr;
      return;
   }
   else
   {
      deleteMax(root->right);
   }
}

int leaf(node* root)
{
   int num = 0;
   if(root == NULL)
      return 0;
   if(root->left == NULL && root->right == NULL)
      num++;
   else
      num = num + leaf(root->left);
      num = num + leaf(root->right);
   return num;
}
