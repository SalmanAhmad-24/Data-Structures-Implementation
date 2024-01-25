#include <iostream>
using namespace std;
#define SPACE 10
int counter = 0;
class Node
{
private:
    int key;
    Node* left;
    Node* right;
public:
    Node() {
        key = 0;
        left = NULL;
        right = NULL;
    }
    Node(int val)
    {
        key = val;
        left = nullptr;
        right = nullptr;
    }
    void setKey(int val) { key = val; }
    int getKey() { return key; }

    void setLeft(Node* temp) { left = temp; }
    Node* getLeft() { return left; }

    void setRight(Node* temp) { right = temp; }
    Node* getRight() { return right; }
};

class BST
{
private:
    Node* root = nullptr;
public:
    void insertNode(Node* rootNode, int data)
    {
        Node* newNode = new Node(data);
        if (rootNode == nullptr)
        {   
            root = newNode;
            return;
        }
        if (rootNode->getKey() > newNode->getKey())
        {
            if (rootNode->getLeft() == nullptr)
            {
                rootNode->setLeft(newNode);
            }
            else
            {
                insertNode(rootNode->getLeft(), data);
            }
        }
        else
        {
            if (rootNode->getRight() == nullptr)
            {
                rootNode->setRight(newNode);
            }
            else
            {
                insertNode(rootNode->getRight(), data);
            }
        }
    }
    void inOrder(Node* node)
    {
        if (node == nullptr)
        {
            return;
        }
        else
        {
            inOrder(node->getLeft());
            cout << node->getKey() << "  ";
            inOrder(node->getRight());
        }
    }
    void preOrder(Node* node)
    {
        if (node == nullptr)
        {
            return;
        }
        else
        {
            cout << node->getKey() << "  ";
            preOrder(node->getLeft());
            preOrder(node->getRight());
        }
    }
    void postOrder(Node* node)
    {
        if (node == nullptr)
        {
            return;
        }
        else
        {
            postOrder(node->getLeft());
            postOrder(node->getRight());
            cout << node->getKey() << "  ";
        }
    }
    Node* searchNode(Node* node, int data)
    {
        counter++;
        if (node == nullptr || node->getKey() == data)
        {
            return node;
        }
        else if (node->getKey() > data) 
        {
            return searchNode(node->getLeft(), data);
        }
        else
        {
            return searchNode(node->getRight(), data);
        }
    }
    Node* min(Node* node)
    {
        if (node == nullptr || node->getLeft() == nullptr)
        {
            return node;
        }
        else
        {
            return min(node->getLeft());
        }
    }
    Node* deleteNode(Node* root, int key) {
        // Return if the tree is empty
        if (root == NULL) return root;

        // Find the node to be deleted
        if (key < root->getKey())
            root->setLeft(deleteNode(root->getLeft(), key));
        else if (key > root->getKey())
            root->setRight(deleteNode(root->getRight(), key));
        else {
            // If the node is with only one child or no child
            if (root->getLeft() == NULL) {
                if (getRoot() == root)
                {
                    this->root = root->getRight();
                    return nullptr;
                }
                else
                {
                    Node* temp = root->getRight();
                    free(root);
                    return temp;
                }
            }
            else if (root->getRight() == NULL) {
                if (getRoot() == root)
                {
                    this->root = root->getLeft();
                    return nullptr;
                }
                else
                {
                    Node* temp = root->getLeft();
                    free(root);
                    return temp;
                }
            }

            // If the node has two children
            Node* temp = min(root->getRight());

            // Place the inorder successor in position of the node to be deleted
            root->setKey(temp->getKey());

            // Delete the inorder successor
            root->setRight(deleteNode(root->getRight(), temp->getKey()));
        }
        return root;
    }
    Node* getRoot() { return root; }
};


class AVLTree {
public:
    Node* root;
    AVLTree() {
        root = nullptr;
    }
    bool isTreeEmpty() {
        if (root == NULL) {
            return true;
        }
        else {
            return false;
        }
    }
    // Get Height  
    int height(Node* r) {
        if (r == NULL)
            return -1;
        else {
            /* compute the height of each subtree */
            int lheight = height(r->getLeft());
            int rheight = height(r->getRight());

            /* use the larger one */
            if (lheight > rheight)
                return (lheight + 1);
            else return (rheight + 1);
        }
    }

    // Get Balance factor of node N  
    int getBalanceFactor(Node* n) {
        if (n == NULL)
            return -1;
        return height(n->getLeft()) - height(n->getRight());
    }

    Node* rightRotate(Node* y) {
        Node* x = y->getLeft();
        Node* T2 = x->getRight();

        // Perform rotation  
        x->setRight(y);
        y->setLeft(T2);

        return x;
    }

    Node* leftRotate(Node* x) {
        Node* y = x->getRight();
        Node* T2 = y->getLeft();

        // Perform rotation  
        y->setLeft(x);
        x->setRight(T2);

        return y;
    }

    Node* insert(Node* r, int data) {
        Node* new_node = new Node(data);
        if (r == nullptr) {
            r = new_node;
            return r;
        }

        if (new_node->getKey() < r->getKey()) {
            r->setLeft(insert(r->getLeft(), data));
        }
        else if (new_node->getKey() >= r->getKey()) {
            r->setRight(insert(r->getRight(), data));
        }
        else {
            cout << "No duplicate values allowed!" << endl;
            return r;
        }

        int bf = getBalanceFactor(r);
        // Left Left Case  
        if (bf > 1 && new_node->getKey() < r->getLeft()->getKey())
            return rightRotate(r);

        // Right Right Case  
        if (bf < -1 && new_node->getKey() > r->getRight()->getKey())
            return leftRotate(r);

        // Left Right Case  
        if (bf > 1 && new_node->getKey() > r->getLeft()->getKey()) {
            r->setLeft(leftRotate(r->getLeft()));
            return rightRotate(r);
        }

        // Right Left Case  
        if (bf < -1 && new_node->getKey() < r->getRight()->getKey()) {
            r->setRight(rightRotate(r->getRight()));
            return leftRotate(r);
        }

        /* return the (unchanged) node pointer */
        return r;

    }
    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current->getLeft() != NULL) {
            current = current->getLeft();
        }
        return current;
    }
    Node* deleteNode(Node* r, int v) {
        // base case 
        if (r == NULL) {
            return NULL;
        }
        // If the key to be deleted is smaller than the root's key, 
        // then it lies in left subtree 
        else if (v < r->getKey()) {
            r->setLeft(deleteNode(r->getLeft(), v));
        }
        // If the key to be deleted is greater than the root's key, 
        // then it lies in right subtree 
        else if (v > r->getKey()) {
            r->setRight(deleteNode(r->getRight(), v));
        }
        // if key is same as root's key, then This is the node to be deleted 
        else {
            // node with only one child or no child 
            if (r->getLeft() == NULL) {
                Node* temp = r->getRight();
                delete r;
                return temp;
            }
            else if (r->getRight() == NULL) {
                Node* temp = r->getLeft();
                delete r;
                return temp;
            }
            else {
                // node with two children: Get the inorder successor (smallest 
                // in the right subtree) 
                Node* temp = minValueNode(r->getRight());
                // Copy the inorder successor's content to this node 
                r->setKey(temp->getKey());
                // Delete the inorder successor 
                r->setRight(deleteNode(r->getRight(), temp->getKey()));
                //deleteNode(r->right, temp->value); 
            }
        }

        int bf = getBalanceFactor(r);
        // Left Left Imbalance/Case or Right rotation 
        if (bf == 2 && getBalanceFactor(r->getLeft()) >= 0)
            return rightRotate(r);
        // Left Right Imbalance/Case or LR rotation 
        else if (bf == 2 && getBalanceFactor(r->getLeft()) == -1) {
            r->setLeft(leftRotate(r->getLeft()));
            return rightRotate(r);
        }
        // Right Right Imbalance/Case or Left rotation	
        else if (bf == -2 && getBalanceFactor(r->getRight()) <=0)
            return leftRotate(r);
        // Right Left Imbalance/Case or RL rotation 
        else if (bf == -2 && getBalanceFactor(r->getRight()) == 1) {
            r->setRight(rightRotate(r->getRight()));
            return leftRotate(r);
        }

        return r;
    }
    void print2D(Node* r, int space) {
        if (r == NULL) // Base case  1
            return;
        space += SPACE; // Increase distance between levels   2
        print2D(r->getRight(), space); // Process right child first 3 
        cout << endl;
        for (int i = SPACE; i < space; i++) // 5 
            cout << " "; // 5.1  
        cout << r->getKey() << "\n"; // 6
        print2D(r->getLeft(), space); // Process left child  7
    }
    void printPreorder(Node* r) //(current node, Left, Right) 
    {
        if (r == NULL)
            return;
        cout << r->getKey() << " ";
        printPreorder(r->getLeft());
        printPreorder(r->getRight());
    }
    void printInorder(Node* r) 
    {
        if (r == NULL)
            return;
        printInorder(r->getLeft());
        cout << r->getKey() << " ";
        printInorder(r->getRight());
    }
    void printPostorder(Node* r) 
    {
        if (r == NULL)
            return; 
        printPostorder(r->getLeft());
        printPostorder(r->getRight());
        cout << r->getKey() << " ";
    }
    Node* recursiveSearch(Node* r, int val) {
        counter++;
        if (r == NULL || r->getKey() == val)
            return r;

        else if (val < r->getKey())
            return recursiveSearch(r->getLeft(), val);

        else
            return recursiveSearch(r->getRight(), val);
    }
     Node*getroot(){
            return root; 
     }
};



int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

// A function to do counting sort of arr[] according to
// the digit represented by exp.
void countSort(int arr[], int n, int exp)
{
    int *output = new int[n]; // output array
    int i, count[10] = { 0 };

    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

// The main function to that sorts arr[] of size n using
// Radix Sort
void radixsort(int arr[], int n)
{
    // Find the maximum number to know number of digits
    int m = getMax(arr, n);

    // Do counting sort for every digit. Note that instead
    // of passing digit number, exp is passed. exp is 10^i
    // where i is current digit number
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}
// Print an array
void printArray(int array[], int size) {
    int i;
    for (i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}


int main() 
{

    
}