#include<iostream>
using namespace std;
// program will ask user how many nodes he want to make
// does he want to add another node and after which node does he want to add 
// will be able to delete a node 
// display fo the list
// get the first element of the list
// size of the list 
// update node of list
class node {
    private:
    int data;
    node *next;
    public:
    int getdata(){
        return data;
    }
    node *getnext(){
        return next;
    }
    void setnext(node *x){
        next=x;
    }
    void setdata(int val){
        data=val;
    }
    node(int val){
        data=val;
        next=NULL;
    }
};
class linked_list{
private:
node *head=NULL;
public:
void insert(int val){
    node*n=new node(val);
    if(head==NULL){
        head=n;
        return;
    }
    node *temp=head;
    while(temp->getnext()!=NULL){
        temp=temp->getnext();
    }
    temp->setnext(n);
    
    
   

   
}
void insertval_atpos(){
    int val;
    cout<<"Enter the value which you want to add :";
    cin>>val;
    int pos;
    cout<<"Enter the data of the node after which you want to add :";
    cin>>pos;
    node *n=new node(val);
    if(head==NULL){
       head=n;
       return;
    }
    node*temp=head;
    while(temp->getdata()!=pos){
        temp=temp->getnext();
    }
    n->setnext(temp->getnext());
    temp->setnext(n);
   
}
void creation_nodes(){
    int n;
    int val; 
    cout<<"How many nodes do you want to have in your list.Please enter a number "<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Enter data :";
        cin>>val;
        insert(val);
    }
    
    

 }
void deletes(){
int del;
cout<<"Enter node which you want to delete "<<endl;
cin>>del;
node *temp=head;
if(head->getdata()==del){
  
    node*todelete=head;
     head=temp->getnext();
    delete todelete;
    return;

}
while(temp->getnext()->getdata()!=del){
    temp=temp->getnext();
}
node* todelete=temp->getnext();
temp->setnext(temp->getnext()->getnext());
delete todelete;

}
void update(){
int update;
int to_be_updated;
cout<<"Enter data of the node which you want to update "<<endl;
cin>>to_be_updated;
cout<<"Enter the number which you want in place of the previous "<<endl;
cin>>update;
node *temp=head;
int found=0;
while(temp != NULL){
    
    if(temp->getdata()==to_be_updated){
     temp->setdata(update);
     found++;
    }
    temp=temp->getnext();
}

if(found!=1){
    cout<<"No matching value found "<<endl;

}


}
void getfirst(){
    cout<<"First element :"<<head->getdata()<<endl;
}
void getsize(){
    int count=0;
    node *temp=head;
    while(temp->getnext()!=NULL){
        count++;
        temp=temp->getnext();
    }
    cout<<"Size of list :"<<count<<endl;
}
void isEmpty(){
    if (head==NULL){
        cout<<"The list is empty "<<endl;
    }
    else{
        cout<<"List is not empty "<<endl;
    }
}
void display(){
    if(head==NULL){
        cout<<"List is empty "<<endl;
    }
    node *temp=head;
    while(temp!=NULL){
        cout<<temp->getdata()<<"->";
        temp=temp->getnext();
    }
    cout<<"NULL"<<endl;

}
};
int main(){
    linked_list l1;
    int n;
    int val; 
    cout<<"How many nodes do you want to have in your list.Please enter a number "<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Enter data :";
        cin>>val;
        l1.insert(val);
    }
    l1.display();
    l1.insertval_atpos();
    l1.display();
    l1.deletes();
    l1.display();
    l1.update();
    l1.display();
    l1.getfirst();
    l1.getsize();
    l1.isEmpty();

}