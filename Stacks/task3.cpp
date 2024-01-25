#include<iostream>
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
    void top_update(){
       top = top->next;
       }
};

int main()
{
    stack s;
    int size;
    cout<<"Enter szie of  array "<<endl;
    cin>>size;
    int *arr=new int [size];
    for(int i=0;i<size;i++){
    cout<<"Enter element of array :";
     cin>>arr[i];
    }
    for(int i=0;i<size;i++){
        s.push(arr[i]);
    }
    for(int i=0;i<size;i++){
        arr[i]=s.pop();
        s.top_update();
    }
    cout<<"Reversed array :"<<endl;
    for(int i=0;i<size;i++){
     cout<<arr[i]<<" ";
    }



}