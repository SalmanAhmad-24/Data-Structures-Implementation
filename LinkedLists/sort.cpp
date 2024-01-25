#include<iostream>
using namespace std;

template <typename T> class node
{
  public:
  T data;
  node* next = NULL;
  //node* prev = NULL;
};

template <typename U> class list
{
  private:
  node<U>* head = NULL;
  public:
  void insertnode(U val)
  {
    if(head == NULL)
    {
      node<U>* newnode = new node<U>;
      head = newnode;
      head->data = val;
      return;
    }
    node<U>* temp = head;
    while(temp->next != NULL)
    {
      temp = temp->next;
    }
    temp->next = new node<U>;
    temp->next->data = val;
  }

  void sort()
  {
    if(head == NULL)
    {
      cout << "The list is empty" << endl;

    }

    node<U>* tempouterloop = head;
    node<U>* tempinnerloop;

    while(tempouterloop != NULL)
    {
      tempinnerloop = head;
      while(tempinnerloop != NULL)
      {
        if(tempinnerloop->next != NULL && tempinnerloop->data > tempinnerloop->next->data)
        {
          int temp = tempinnerloop->next->data;
          tempinnerloop->next->data = tempinnerloop->data;
          tempinnerloop->data = temp;
        }
        tempinnerloop = tempinnerloop->next;
      }
      tempouterloop = tempouterloop->next;
    }
  }

  void display()
  {
    if(head == NULL)
    {
      cout << "The list is empty" << endl;
      return;
    }
    node<U>*temp = head;

    while(temp!=NULL)
    {
      cout << temp->data << "-->";
      temp = temp->next;
    }
    cout << "NULL" << endl;
  }
};


int main()
{
  list<char> a;
  list<int> b;
  a.insertnode('g');
  a.insertnode('z');
  a.insertnode('c');
  b.insertnode(8323);
  b.insertnode(1232);
  b.insertnode(232);

  a.display();
  a.sort();
  a.display();

  cout << endl << endl;
  b.display();
  b.sort();
  b.display();
  return 0;
}