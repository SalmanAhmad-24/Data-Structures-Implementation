#include <iostream>
using namespace std;
// the program will reverse an array using stack;
class node
{
public:
    int data;
    node *next;
    node(int val)
    {
        data = val;
        next = NULL;
    }
};
class stack
{
public:
    node *top = NULL;

    void push(int val)
    {
        node *n = new node(val);
        if (top == NULL)
        {
            top = n;
            return;
        }
        n->next = top;
        top = n;
    }
    int pop()
    {
        return top->data;
    }
    void top_update()
    {
        top = top->next;
    }
    void display()
    {
        node *temp = top;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    stack s;
    stack s2;
    int size;
    cout << "Enter szie of  array :";
    cin >> size;
    int *arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter element of array :";
        cin >> arr[i];
    }
    int mid = size / 2;
    for (int i = 0; i < mid; i++)
    {
        s.push(arr[i]);
    }
    for (int i = mid; i < size; i++)
    {
        s2.push(arr[i]);
    }
    cout<<"First array :"<<endl;
    s.display();
    cout<<"Second array :"<<endl;
    s2.display();

}