#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node* link;

    node(int data){
       this->data = data;
       this->link = NULL;
    }

    ~node(){
    int value = this->data;
       if(this->link != NULL){
          delete link; /// Memory free.
             link = NULL;
       }
       cout<<"Memory is free for "<<value<<endl;
    }
};

void DeleteNode(node* &head, int positon){

      if(positon == 1){ /// Delet first node.
        node* temp = head;
        head = head->link;
        temp->link = NULL;
        delete temp;
      }
      else{
        node* current = head;
        node* previous = NULL;

        int cunt = 1;
        while(cunt <  positon){
            previous = current;
            current = current->link;
            cunt++;
        }
         if(current->link == NULL){
            cout<<current->data<<endl;
         }
        previous->link = current->link;
        current->link = NULL;
        delete current;
    }

}
void InsrtAtHead(node* &head, int data){
   node* temp = new node(data);
   temp->link = head;
   head = temp;
}

void InsrtAtTell(node* &head, int value){
     node* n = new node(value);

     if(head == NULL){
        head = n;
        return;
     }
     node* temp = head;

     while(temp->link != NULL){
        temp = temp->link;
     }
     temp->link = n;
}

void InsrtAtMiddle(node* &head, int position, int value){

     if(position == 1){
        InsrtAtHead(head,value);
        return;
     }
     node* temp = head;

     int cunt = 1;
     while(cunt < position-1){
        temp = temp->link;
        cunt++;
     }

     if(temp->link == NULL){
        InsrtAtTell(head,value);
        return;
     }
     node* InsrtValue = new node(value);
     InsrtValue->link = temp->link;
     temp->link = InsrtValue;
}

void Display(node* head){
   node* temp = head;
   while(temp != NULL){
    cout<<"-> "<<temp->data;
    temp = temp->link;
   }
}

int main()
{
    node* head = NULL;
    InsrtAtHead(head,10);
    InsrtAtHead(head,5);
    InsrtAtMiddle(head,3,20);

    InsrtAtTell(head,30);
    InsrtAtTell(head,40);
    InsrtAtTell(head,70);
    InsrtAtMiddle(head,4,80);
    Display(head);
    cout<<endl;

    DeleteNode(head,6);
    Display(head);
    return 0;
}
