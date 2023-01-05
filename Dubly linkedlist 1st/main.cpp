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

};

void InsrtAtHead(node* &head, int value){
     node* n = new node(value);
     if(head == NULL){
        head = n;
         return;
     }
      n->next = head;
      head->prev = n;
      head = n;
}

void InsrtAtTell(node* &head, int val){
     node* n = new node(val);
     if(head == NULL){
        head = n;
         return;
     }
     node* temp = head;

     while(temp->next != NULL){
        temp = temp->next;
     }
     temp->next = n;
     n->prev = temp;
}


void InsrtAtPosition(node* &head, int position, int val){
    node* InsrNode = new node(val);

    if(position == 1){
        InsrtAtHead(head,val);
    }
    node* temp = head;
    int cunt = 1;
    while(cunt < position){
        temp = temp->next;
        cunt++;
    }
    if(temp->next == NULL){
        InsrtAtTell(head,val);
    }
    InsrNode->next = temp->next;
    temp->next->prev = InsrNode;
    temp->next = InsrNode;
    InsrNode->prev = temp;

}

void print(node* head){
  node* temp = head;

  while(temp != NULL){
    cout<<"-> "<<temp->data;
    temp = temp->next;
  }
}

int Length(node* &head){
    node* temp = head;
    int cunt = 0;
    while(temp != NULL){
        cunt++;
        temp = temp->next;
    }
    return cunt;
}

int main()
{
    /*node* node1 = new node(10);
    node* head = node1;*/

    node* head = NULL;
    InsrtAtHead(head,10);
    InsrtAtHead(head,5);
    print(head);
    cout<<endl;

    InsrtAtTell(head,15);
    InsrtAtTell(head,20);
    print(head);
    cout<<endl;

    InsrtAtPosition(head,2,50);
    print(head);
    return 0;
}
