#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node* next;
    node* rendom;

    node(int data){
     this->data = data;
     this->next = NULL;
     this->rendom = NULL;
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
void InsrtTell(node* &head,node* &tail,int val){
     node* NewNode = new node(val);
     if(head == NULL){
        head = NewNode;
        tail  = NewNode;
        return;
     }
     tail->next = NewNode;
     tail = NewNode;
}
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
node* CloneList(node* &head){
   node* CloneHead = NULL;
   node* CloneTell = NULL;
   node* temp = head;

   while(temp != NULL){
    InsrtTell(CloneHead,CloneTell,temp->data)
    temp = temp->next;
   }
   unordered_map<node*,node*> oldToNew;
   node* OrginalNode = head;
   node* CloneNode = CloneHead;

   while(OrginalNode != NULL && CloneNode != NULL){
        oldToNew[OrginalNode] = CloneNode;

    OrginalNode = OrginalNode->next;
    CloneNode = CloneNode->next;
   }
   OrginalNode = head;
   CloneNode = CloneHead;

   while(OrginalNode != NULL){
    CloneNode->rendom = oldToNew[OrginalNode->rendom];
    OrginalNode = OrginalNode->next;
    CloneNode = CloneNode->next;
   }

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

    return 0;
}
