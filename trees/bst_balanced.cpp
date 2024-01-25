#include<iostream>
using namespace std;
class node{
  public:
  int data;
  node* left;
  node* right;
  node(int val){
    data=val;
    left=NULL;
    right=NULL;
  }
};
class bst{
  public:
  node *root=NULL;
  void insert(node *root,int data){
    node *n=new node (data);
    if(root==NULL){
      this->root=n;
      return;
    }
    if(n->data>root->data){
      if(root->right==NULL){
        root->right=n;
      }
      else{
        insert(root->right,data);
      }
    
    }
    else{
      if(root->left==NULL){
        root->left=n;
      }
      else{
        insert(root->left,data);
      }
    }
  }
  void inorder(node *root){
    if(root==NULL){
      return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
  }
  node *getroot(){
    return root;
  }
  int height(node *root){
    if(root==NULL){
      return 0;
    }
    int lh,rh;
    lh=height(root->left);
    rh=height(root->right);
    return max(lh,rh)+1;
  }
  bool isbalance(node *root){
    if(root==NULL){
      return true;
    }
    if(isbalance(root->left)==false){
      return false;
    }
     if(isbalance(root->right)==false){
      return false;
    }
    int lh,rh;
    lh=height(root->left);
    rh=height(root->right);
    if(abs(lh-rh)<=1){
      return true;
    }
    else{
       return false;
    }
   
  }
  node*search(node *root,int key){
    if(root==NULL){
      return NULL;
    }
    
    if(root->data==key){
      return root;
    }
    if(root->data >key){
      return search(root->left,key);
    }
    return search(root->right,key);
  }
};

int main()
{


    bst b;
  b.insert(b.getroot(), 1);
    b.insert(b.getroot(), 2);
    b.insert(b.getroot(), 3);
    b.insert(b.getroot(), 4);
    b.insert(b.getroot(), 5);
    b.insert(b.getroot(), 6);
    b.insert(b.getroot(), 7);
    b.inorder(b.getroot());
    
    if(b.isbalance(b.getroot())==true){
     cout<<"\nBalanced "<<endl;
    }
    else{
      cout<<"\nUnbalanced";
    }
    if(b.search(b.getroot(),10)!=NULL){
      cout<<"\nNumber Found "<<endl;
    }
    else{
      cout<<"\nNumber not found "<<endl;
    }
}