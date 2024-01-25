#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
};

class queue
{
private:
    node *head = NULL;
    node *tail = NULL;

public:
    void enqueue(int val)
    {
        node *temp = new node;
        temp->data = val;
        temp->next = NULL;

        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        tail->next = temp;
        tail = tail->next;
    }

    int dequeue()
    {
        if (head == NULL)
        {
            cout << "the queue is empty" << endl;
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
        if (head == NULL)
        {
            cout << "the queue is empty" << endl;
            return;
        }
        node *temp = head;
        cout << "Queue: " << endl;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    queue q;
    int size;
    int mid;
    cout << "Enter the size of your queue: " << endl;
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        int temp;
        cout << "Enter " << i + 1 << " value of the queue: " << endl;
        cin >> temp;
        q.enqueue(temp);
    }
    cout << "The queue is: " << endl;
    q.display();

    if(size% 2 == 0){
        mid = size/2;
    }
    else{
        mid = size /2 +1;
    }
    queue q1;
    queue q2;
    queue q4;

    for(int i=0; i<mid; i++){
        q1.enqueue(q.dequeue());
    }

    for(int i =mid; i<size ; i++){
        q2.enqueue(q.dequeue());
    }

    for(int i=0 ; i<size; i++){
        if(i%2 == 0){
            q4.enqueue(q1.dequeue());
        }
        else{
            q4.enqueue(q2.dequeue());
        }
    }

    cout<<"queue after interleaving is: ";
    q4.display();

}