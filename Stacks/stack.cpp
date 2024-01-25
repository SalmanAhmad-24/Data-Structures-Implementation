#include <iostream>
using namespace std;
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

    void push()
    {

        int val;
        cout << "Enter value :" << endl;
        cin >> val;
        node *n = new node(val);
        if (top == NULL)
        {
            top = n;
            return;
        }
        n->next = top;
        top = n;
    }
    void pop()
    {
        if (top == NULL)
        {
            cout << "List is empty no value can be popped " << endl;
            return;
        }
        cout << "The value popped is " << top->data << endl;
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
    void topelemnt()
    {
        if (top == NULL)
        {
            cout << "Top element : NULL" << endl;
            return;
        }
        cout << "Top element :" << top->data << endl;
    }
    void is_empty()
    {
        if (top == NULL)
        {
            cout << "Stack is empty " << endl;
        }
        else
        {
            cout << "List is not empty " << endl;
        }
    }
};

int main()
{
    stack s;
    int choice;
    while (1)
    {
        cout << "Please choose an option: " << endl;
        cout << "1. Push" << endl
             << "2. Pop" << endl
             << "3. Display" << endl
             << "4. Top" << endl
             << "5. Empty" << endl;

        cin >> choice;

        switch (choice)
        {
        case 1:
            s.push();
            break;
        case 2:
            s.pop();
            break;
        case 3:
            s.display();
            break;
        case 4:
            s.topelemnt();
            break;
        case 5:
            s.is_empty();
            break;

        default:
            cout << "enter correct option" << endl;
            break;
        }
    }

    return 0;
}