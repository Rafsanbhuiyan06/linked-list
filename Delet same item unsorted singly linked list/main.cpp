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

void InsrtAtHead(node* &head, int val){
     node* n = new node(val);
     if(head == NULL){
        head = n;
        return;
     }
     n->next = head;
     head = n;
}

void DeletNodeUseLop(node* &head){

      if(head == NULL || head->next == NULL){
        return;
      }
      node* curr = head;
      while(curr->next != NULL){
            node* chack = curr->next;
              while(chack->next != NULL){
                  if(curr->data == curr->next->data){
                       node* last = curr->next->next;
                       curr->next = last;
                       chack->next = NULL;
                       delete chack;
                       chack = last;
                  }
                  else{
              chack = chack->next;
                  }
              }
      curr = curr->next;
      }
}

void DeletNodeUseMap(node* &head){
     node* temp = head;
     map<node*, bool> chack;

     while(temp != NULL){
        if(chack[temp] == true){
            cout<<"Temp data is "<<temp->data<<endl;
        }
           chack[temp] = true;
        temp = temp->next;
     }



}
void Display(node* head){
      node* temp = head;
      while(temp != NULL){
        cout<<temp->data<< "-> ";
        temp = temp->next;
      }
      cout<<endl;
}

int main()
{
   node* head = NULL;
   InsrtAtHead(head,10);
   InsrtAtHead(head,20);
   InsrtAtHead(head,20);
   InsrtAtHead(head,30);
   InsrtAtHead(head,30);
   InsrtAtHead(head,30);
   InsrtAtHead(head,40);
   InsrtAtHead(head,40);
   InsrtAtHead(head,50);
    Display(head);

   DeletNodeUseMap(head);
   //Display(head);
    return 0;
}
