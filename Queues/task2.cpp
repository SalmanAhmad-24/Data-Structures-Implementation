#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
};

class queue
{
private:
    node* head = NULL;
    node* tail = NULL;

public:
    

    void enqueue(int val)
    {
        node* temp = new node;
        temp->data = val;
        temp->next = NULL;

        if(head == NULL){
            head = temp;
            tail = temp;
        }
        tail->next = temp;
        tail = tail->next;

    }

    int dequeue()
    {
        if(head == NULL){
            cout<<"the queue is empty"<<endl;
            return 0;
        }
        int val = head->data;
        head = head->next;
        return val;
    }

    int peak()
    {
        if (head == NULL)
        {
            cout << "the queue is empty" << endl;
            return 0;
        }
        int val = head->data;
        return val;
    }

        void display()
        {
            if(head == NULL){
                cout<<"the queue is empty"<<endl;
                return;
            }
            node* temp = head;
            cout<<"Queue: "<<endl;
            while(temp != NULL){
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            cout<<endl;

    }
};

int main()
{

    queue q;
    int a = 1;
    while (a)
    {

        int choice;
        cout << "enter what operation you want to perform: " << endl
             << "1. Enqueue" << endl
             << "2. Dequeue" << endl
             << "3. Peak" << endl
             << "4. Dispay" << endl
             << "5.Exit" << endl;

        cin >> choice;

        switch (choice)
        {
        case 1:
            int val;
            cout << "enter the value you want to enqueue: " << endl;
            cin >> val;
            q.enqueue(val);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.peak();
            break;
        case 4:
            q.display();
            break;
        case 5:
            a = 0;
            break;

        default:
            cout << "Enter correct option" << endl;
            break;
        }
    }
    return 0;
}