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

    int k;
    cout << "Enter how many elements you want to reverse: " << endl;
    cin >> k;
    int* arr = new int[size];
    for (int i = k - 1; i >= 0; i--)
    {
        arr[i] = q.dequeue();
    }

    for (int i = k; i < size; i++)
    {
        arr[i] = q.dequeue();
    }
    queue q1;
    for (int i = 0; i < size; i++)
    {
        q1.enqueue(arr[i]);
    }
    cout << "The reversed queue is: " << endl;
    q1.display();
}