#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node* next;

    node(int data){
     this->data = data;
     this->next = NULL;
    }

    ~node(){
     int value = this->data;
       if(this->next != NULL){
           delete next;
     this->next = NULL;
      }
      cout<<"The memery is free for "<<value<<endl;
    }
};
void InsrtAtHead(node* &head, int dat){

     node* n = new node(dat);
     n->next = head;
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
}
void InsrtAtPosition(node* &head, int position, int data){
     if(position == 1){
        InsrtAtHead(head,data);
           return;
     }
     node* temp = head;
     int cunt = 1;

     while(cunt < position-1){
        temp = temp->next;
        cunt++;
     }
     if(temp->next == NULL){
        InsrtAtTell(head,data);
        return;
     }
     node* n = new node(data);
     n->next = temp->next;
     temp->next = n;

}
void Seach(node* &head,int kye){
    node* temp = head;
    while(temp != NULL){
            if(temp->data == kye){
                cout<<"The item is found "<<kye<<endl;
                return;
            }
        temp = temp->next;
    }
    cout<<"The item id not found "<<endl;
}
void DeleteNode(node* &head, int position){

   if(position == 1){ /// Delet first node.
    node* temp = head;
    head = head->next;
    temp->next = NULL;
    delete temp;
   }
   else{
    node* current = head;
    node* previous = NULL;

    int cunt = 1;
    while(cunt < position){
        previous = current;
        current = current->next;
        cunt++;
    }
    previous->next = current->next;
    current->next = NULL;
    delete current;
  }
}

void Display(node* head){
   node* temp = head;

   while(temp != NULL){
    cout<<"-> "<<temp->data;
    temp = temp->next;
   }
   cout<<endl;
}
int main()
{
    node* head = NULL;
    InsrtAtHead(head,10);
    InsrtAtHead(head,5);
    InsrtAtTell(head,20);
    InsrtAtTell(head,25);
    InsrtAtPosition(head,3,30);

    Display(head);
    DeleteNode(head,1);
    Display(head);

    return 0;
}
