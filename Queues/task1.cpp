#include <iostream>
using namespace std;

// class node{
//     int data;
//     node* next;
// };

class queue
{
private:
    int *arr;
    int head = 0;
    int size = 0;
    int tail = 0;
    int currentsize = 0;

public:
    queue()
    {

        cout << "Please enter the size of the queue you want: " << endl;
        cin >> size;
        arr = new int[size];
    }

    void enqueue(int val)
    {
        if (tail + 1 <= size)
        {
            arr[tail] = val;
            tail++;
        }

        else
        {
            cout << "The queue has overflowed" << endl;
        }
    }

    int dequeue()
    {
        if (tail != 0)
        {
            int val = arr[0];
            int *temp = new int[size];
            for (int i = 0; i < size - 1; i++)
            {
                temp[i] = arr[i + 1];
            }
            arr = temp;
            tail--;
            return val;
        }
        else
        {
            cout << "The dueue is empty" << endl;
        }
    }

    int peak()
    {
        if (tail != 0)
        {
            int val = arr[0];
            return val;
        }
        else
        {
            cout << "The dueue is empty" << endl;
        }
    }

    void display()
    {
        cout << "Queue: " << endl;
        for (int i = 0; i < tail; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
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
             <<"5.Exit"<<endl;

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
            cout<<"Peak: "<< q.peak()<<endl;
            break;
        case 4:
            q.display();
            break;
        case 5:
            a=0;
            break;

        default:
            cout << "Enter correct option" << endl;
            break;
        }

    }
    return 0;
}