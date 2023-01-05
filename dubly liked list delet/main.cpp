#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node* prev;
    node* next;

    node(int data){
     this->data = data;
     this->prev = NULL;
     this->next = NULL;
    }
    ~node(){
      int val = this->data;
      if(this->next != NULL){
        delete next;
        next = NULL;
      }
      cout<<"Memory free for "<<val<<endl;
    }
};

void InsrtAthead(node* &head, int val){
   node* temp = new node(val);
   if(head == NULL){
    head = temp;
     return;
   }
   temp->next = head;
   head->prev = temp;
   head = temp;
}

void InsrtAtTell(node* &head, int val){
    node* n = new node(val);
    node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
}
void InsrtAtMiddle(node* &head, int position, int val){
      if(position == 1){
        InsrtAthead(head,val);
            return;
      }
      node* temp = head;
      int cunt = 1;
      while(cunt < position-1);{
        temp = temp->next;
      }
      if(temp->next == NULL){
        InsrtAtTell(head,val);
      }
      node* n = new node(val);
      n->next = temp->next;
      temp->next->prev = n;
      temp->next = n;
      n->prev = temp;
}

void Delet(node* &head, int position){

  if(position == 1){
    node* temp = head;
    head = head->next;
    temp->next->prev = NULL;
    temp->next = NULL;
    delete temp;
       return;
  }
 else{
    node* curr = head;
    node* previous = NULL;
    int cunt = 1;
    while(cunt < position){
        previous = curr;
        curr = curr->next;
        cunt++;
    }
      curr->prev = NULL;
      previous->next = curr->next;
      curr->next = NULL;
      delete curr;
         return;
 }
}

void print(node* head){

   node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<"-> ";
        temp = temp->next;
    }
    cout<<endl;
}


int main()
{
    node* head = NULL;
    InsrtAthead(head,10);
    InsrtAthead(head,20);
    print(head);
    InsrtAtTell(head,30);
    print(head);
    InsrtAtMiddle(head,2,100);
    Delet(head,4);

    print(head);
    return 0;
}
