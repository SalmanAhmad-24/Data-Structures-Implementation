#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node* left;
    node* right;
    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
class bst
{

public:
    node* root = nullptr;
    void insert(node* root, int val) {
        node* n = new node(val);
        if (this->root == nullptr) {
            this->root = n;
            return;
        }
        if ( root->data < n->data) {
            if (root->right == nullptr) {
                root->right = n;
            }
            else {
                insert(root->right, val);
            }
        }
        else {
            if (root->left == nullptr) {
                root->left = n;
            }
            else {
                insert(root->left, val);
            }
        }

    }
    void inorder(node* root)
    {
        if (root == nullptr)
        {
            return;
        }
        else {
            inorder(root->left);
            cout << root->data << " ";
            inorder(root->right);
        }
       
    }
    void search(node* root, int val) {
        int found = 0;
        if (root == NULL)
        {
            return;
        }


        if (root->data == val) {
            cout << "\nElement found ";
            found++;
        }
        search(root->left, val);

        search(root->right, val);


    }
    node* getroot() {
        return root;
    }
};

int main()
{
    bst b;
    b.insert(b.getroot(), 50);
    b.insert(b.getroot(), 30);
    b.insert(b.getroot(), 20);
    b.insert(b.getroot(), 40);
    b.insert(b.getroot(), 70);
    b.insert(b.getroot(), 60);
    b.insert(b.getroot(), 80);
    b.inorder(b.getroot());
    b.search(b.getroot(), 40);
}