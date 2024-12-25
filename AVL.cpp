#include "BST.hpp"

void balance(node*&);
node* LL(node*&);
node* RR(node*&);
node* LR(node*&);
node* RL(node*&);
void AVL_insert(node*&,node*&);
void AVL_balance(node*&);
void AVL_list(node*,int,int);
void AVL_deleteMin(node*&);
void AVL_deleteMax(node*&);
void AVL_delete(node*&,int);

int main()
{
   node* root = NULL;
   int choice;
   do
   {
      cout<<endl<<"MAIN MENU"<<endl;
      cout<<"Enter 1 to insert element in AVL Tree"<<endl;
      cout<<"Enter 2 for inorder traversal"<<endl;
      cout<<"Enter 3 for preorder traversal"<<endl;
      cout<<"Enter 4 for postorder traversal"<<endl;
      cout<<"Enter 5 for level-order traversal"<<endl;
      cout<<"Enter 6 to find the height of the AVL Tree"<<endl;
      cout<<"Enter 7 to find the minimum element"<<endl;
      cout<<"Enter 8 to find the maximum element"<<endl;
      cout<<"Enter 9 to search an element in AVL Tree"<<endl;
      cout<<"Enter 10 to find the left and right child of a node"<<endl;
      cout<<"Enter 11 to delete the node with minimum value"<<endl;
      cout<<"Enter 12 to delete the node with maximum value"<<endl;
      cout<<"Enter 13 to find the number of leaf nodes in AVL Tree"<<endl;
      cout<<"Enter 14 to find all key values in the range [a,b]"<<endl;
      cout<<"Enter 15 to delete the root node"<<endl;
      cout<<"Enter 16 to delete a node from AVL Tree"<<endl;
      cout<<"Enter 0 to exit"<<endl;
      cout<<"Enter your choice: ";
      cin>>choice;
      switch(choice)
      {
         case 1:
         {
            int data;
            cout<<"Enter the value to be inserted: ";
            cin>>data;
            node* key = new node;
            key->data = data;
            AVL_insert(root,key);
            cout<<"Element inserted in AVL Tree"<<endl;
            break;
         }
         case 2:
         {
            if(root != NULL)
            {
               cout<<"Inorder traversal"<<endl;
               inorder(root);
            }
            else
               cout<<"AVL Tree is empty"<<endl;
            break;
         }
         case 3:
         {
            if(root != NULL)
            {
               cout<<"Preorder traversal"<<endl;
               preorder(root);
            }
            else
               cout<<"AVL Tree is empty"<<endl;
            break;
         }
         case 4:
         {
            if(root != NULL)
            {
               cout<<"Postorder traversal"<<endl;
               postorder(root);
            }
            else
               cout<<"AVL Tree is empty"<<endl;
            break;
         }
         case 5:
         {
            if(root != NULL)
            {
               cout<<"Level-order traversal"<<endl;
               levelorder(root);
            }
            else
               cout<<"AVL Tree is empty"<<endl;
            break;
         }
         case 6:
         {
            cout<<"Height of AVL Tree: "<<height(root)<<endl;
            break;
         }
         case 7:
         {
            if(root == NULL)
            {
               cout<<"AVL Tree is empty"<<endl;
               break;
            }
            int min = minimum(root);
            cout<<"Minimum element: "<<min<<endl;
            break;
         }
         case 8:
         {
            if(root == NULL)
            {
               cout<<"AVL Tree is empty"<<endl;
               break;
            }
            int max = maximum(root);
            cout<<"Maximum element: "<<max<<endl;
            break;
         }
         case 9:
         {
            int data;
            cout<<"Enter the value to be searched: ";
            cin>>data;
            search = 0;
            node* ptr = find(root,data);
            if(ptr != NULL)
            {
               cout<<"Element found"<<endl;
               cout<<"Address of element: "<<ptr<<endl;
               cout<<"Number of searches taken to find the element: "<<search<<endl;
            }
            else
            {
               cout<<"Element not found"<<endl;
            }
            break;
         }
         case 10:
         {
            int data;
            cout<<"Enter the value of the node: ";
            cin>>data;
            node* ptr = find(root,data);
            if(ptr != NULL)
            {
               cout<<"Left child: ";
               if(ptr->left != NULL)
                  cout<< ptr->left->data <<endl;
               else
                  cout<<"NULL"<<endl;
               cout<<"Right child: ";
               if(ptr->right != NULL)
                  cout<< ptr->right->data <<endl;
               else
                  cout<<"NULL"<<endl;
            }
            else
            {
               cout<<"Element not found"<<endl;
            }
            break;
         }
         case 11:
         {
            if(root != NULL)
            {
               AVL_deleteMin(root);
               cout<<"Node with the minimum value is deleted"<<endl;
            }
            else
            {
               cout<<"AVL Tree is empty"<<endl;
            }
            break;
         }
         case 12:
         {
            if(root != NULL)
            {
               AVL_deleteMax(root);
               cout<<"Node with the maximum value is deleted"<<endl;
            }
            else
            {
               cout<<"AVL Tree is empty"<<endl;
            }
            break;
         }
         case 13:
         {
            cout<<"Number of leaf nodes in the AVL Tree: "<<leaf(root)<<endl;
            break;
         }
         case 14:
         {
            int a,b;
            cout<<"Enter the values of a and b"<<endl;
            cin>>a>>b;
            cout<<"List of key values in the range ["<<a<<","<<b<<"]"<<endl;
            AVL_list(root,a,b);
            break;
         }
         case 15:
         {
            if(root != NULL)
            {
               AVL_delete(root,root->data);
               cout<<"Root node is deleted"<<endl;
            }
            else
            {
               cout<<"AVL Tree is empty"<<endl;
            }
            break;
         }
         case 16:
         {
            if(root != NULL)
            {
               int key;
               cout<<"Enter the key value to be deleted: ";
               cin>>key;
               AVL_delete(root,key);
            }
            else
            {
               cout<<"AVL Tree is empty"<<endl;
            }
            break;
         }
         case 0:
         {
            break;
         }
         default:
         {
            cout<<"Invalid choice"<<endl;
         }
      }
   }
   while(choice!=0);

   return 0;
}

void balance(node*& root)
{
   int hl = height(root->left);
   int hr = height(root->right);
   if(hl-hr > 1)
   {
      int hll = height(root->left->left);
      int hlr = height(root->left->right);
      if(hll > hlr)
         root = LL(root);
      else
         root = LR(root);
   }
   if(hl-hr < -1)
   {
      int hrl = height(root->right->left);
      int hrr = height(root->right->right);
      if(hrr > hrl)
         root = RR(root);
      else
         root = RL(root);
   }
}

node* LL(node*& A)
{
   node* k = A->left;
   A->left = k->right;
   k->right = A;
   return k;
}

node* RR(node*& A)
{
   node* k = A->right;
   A->right = k->left;
   k->left = A;
   return k;
}

node* LR(node*& A)
{
   A->left = RR(A->left);
   node* m = LL(A);
   return m;
}

node* RL(node*& A)
{
   A->right = LL(A->right);
   node* m = RR(A);
   return m;
}

void AVL_insert(node*& root,node*& key)
{
   if(root != NULL)
   {
      if(key->data > root->data)
         AVL_insert(root->right,key);
      else if(key->data < root->data)
         AVL_insert(root->left,key);
   }
   else
   {
      key->left = key->right = NULL;
      root = key;
   }
   balance(root);
}

void AVL_balance(node*& root)
{
   if(root == NULL)
   {
      return;
   }
   if(root->left != NULL || root->right != NULL)
   {
      AVL_balance(root->left);
      AVL_balance(root->right);
   }
   balance(root);
}

void AVL_list(node* root,int lb,int ub)
{
   if(root != NULL)
   {
      AVL_list(root->left,lb,ub);
      if(root->data >= lb && root->data <= ub)
         cout<< root->data <<endl;
      AVL_list(root->right,lb,ub);
   }
}

void AVL_deleteMin(node*& root)
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
      AVL_deleteMin(root->left);
   }
   balance(root);
}

void AVL_deleteMax(node*& root)
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
      AVL_deleteMax(root->right);
   }
   balance(root);
}

void AVL_delete(node*& root,int key)
{
   if(root == NULL)
   {
      cout<<"Key element not found"<<endl;
      return;
   }
   if(key == root->data && root->left == NULL && root->right == NULL)
   {
      node* k = root;
      root = NULL;
      cout<<"Key element is deleted"<<endl;
      delete k;
      return;
   }
   if(key == root->data)
   {
      if(root->left != NULL)
      {
         root->data = maximum(root->left);
         AVL_deleteMax(root->left);
         cout<<"Key element is deleted"<<endl;
      }
      else
      {
         root->data = minimum(root->right);
         AVL_deleteMin(root->right);
         cout<<"Key element is deleted"<<endl;
      }
      balance(root);
      return;
   }
   if(key < root->data)
   {
      AVL_delete(root->left,key);
   }
   else if(key > root->data)
   {
      AVL_delete(root->right,key);
   }
   balance(root);
}
