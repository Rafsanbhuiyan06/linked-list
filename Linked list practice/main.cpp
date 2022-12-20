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
};

void InsrtAtTell(node* &head, int value){
    node* n = new node(value);
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
void InsrtAtHead(node* &head, int value){
    node* n = new node(value);
    n->next = head;
    head = n;
}
void InsrtAtPosition(node* &head, int position, int data){

    if(position == 1){ /// Insrting at first position
        InsrtAtHead(head,data);
          return;
    }
    int cunt = 1;
    node* temp =  head;
    while(cunt < position-1){
        temp = temp->next;
        cunt++;
    }
    if(temp->next == NULL){ /// Insrting at last position
        InsrtAtTell(head,data);
          return;
    }
    node* InsrtNode = new node(data);
    InsrtNode->next = temp->next;
    temp->next = InsrtNode;
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
    InsrtAtTell(head,10);
    InsrtAtTell(head,15);
    InsrtAtTell(head,18);
    Display(head);
    InsrtAtHead(head,5);
    Display(head);
    InsrtAtPosition(head,3,100);
    Display(head);

    return 0;
}
