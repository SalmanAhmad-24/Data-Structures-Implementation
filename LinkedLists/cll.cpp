#include <iostream>
using namespace std;
class node
{
   int data;
   node *next;
   node *previous;

public:
   node(int val)
   {
      data = val;
      next = NULL;
   }
   int getdata()
   {
      return data;
   }
   void setnext(node *nxt)
   {
      next = nxt;
   }

   node *getnext()
   {
      return next;
   }
};
class cll{
    public:
    node *head=NULL;
    void insertathead(int val){
    node *n=new node(val);
        if (head==NULL){
           
            head=n;

            return;
        }
        node *temp=head;
        while(temp->getnext()!=NULL){
          temp=temp->getnext();

        }
        temp->setnext(n);
        n->setnext(head);
        head=n;
    }
    void insertattail(int val){
        node *n=new node(val);
        if(head == NULL){
            head = n;
            return;
        }
        if(head->getnext() == NULL){
            n->setnext(head);
            head->setnext(n);
            return; 
        }
        node *temp=head;
        while(temp->getnext()!=head){
            temp=temp->getnext();
        }
        n->setnext(head);
        temp->setnext(n);
    }
    void display(){
        node*temp=head;
      while(temp->getnext()!=head){
        cout<<temp->getdata()<<"->";
        temp=temp->getnext();

      }
      cout<<temp->getdata()<<"->";
      cout<<"NULL"<<endl;
    }
};
int main()
{
    cll l;
     l.insertathead(5);
    l.insertattail(7);
    l.insertattail(4);
    l.insertattail(2);
    l.display();


}