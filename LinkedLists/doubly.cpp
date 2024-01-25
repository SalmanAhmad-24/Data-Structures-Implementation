#include<iostream>
using namespace std;
class node{
 int data;
 node *next;
 node *previous;
 public:
 node(int val){
   data=val;
   next=NULL;
   previous=NULL;
 }
 int getdata(){
    return data;
 }
 void setnext(node * nxt){
    next=nxt;
 }
 void setprevious(node *pre){
    previous=pre;
 }
 node *getnext(){
    return next;
 }
 node *getprevious(){
    return previous;
 }


};
class linked_list{
    node *head=NULL;
    public:
    void insertAThead(int val){
        node *n=new node(val);
        if(head==NULL){
            head=n;
            return;
        }
        n->setnext(head);
        head->setprevious(n);
        head=n;
    }
    void insertattail( int val){
        node *n=new node(val);
        node *temp=head;
        if (head==NULL){
            insertAThead(val);

        }
        while(temp->getnext()!=NULL){

            temp=temp->getnext();

        }
        temp->setnext(n);
        n->setprevious(temp);
    }
    void insertatval(int val){
        node *n=new node(val);
        node *temp=head;
        int after;
        cout<<"Enter the data after which you want to enter "<<endl;
        cin>>after;
     
        while(temp->getdata()!=after){
            temp=temp->getnext();


        }
        if(temp->getnext()==NULL){
            temp->setnext(n);
            n->setprevious(temp);
            n->setnext(NULL);
            return;

        }
        temp->getnext()->setprevious(n);
        n->setnext(temp->getnext());
        temp->setnext(n);
        n->setprevious(temp);


    }
    void deletes(int val){
        node *temp=head;
        if(head->getdata()==val){
            head=head->getnext();
            return;
        }
        while(temp->getnext()->getdata()!=val){
            temp=temp->getnext();

        }
        if(temp->getnext()->getnext()==NULL){
            temp->setnext(NULL);
            return;
        }
        node *tempnextnext=temp->getnext()->getnext();
        temp->setnext(tempnextnext);
        tempnextnext->setprevious(temp);



    }
 
   void display(){
    node *temp=head;
    while(temp!=NULL){
        cout<<temp->getdata()<<"->";
        temp=temp->getnext();
    }
    cout<<"NULL"<<endl;

   }
};
int main()
{
linked_list l;
l.insertAThead(5);
l.insertattail(7);
l.insertattail(4);
l.insertattail(3);
l.insertAThead(8);
l.display();
l.insertatval(10);
l.display();
cout<<"Which number to delete "<<endl;
int del;
cin>>del;
l.deletes(del);
l.display();
}