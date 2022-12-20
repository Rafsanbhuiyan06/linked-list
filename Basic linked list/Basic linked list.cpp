#include <bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node* next;

    node(int data){
      this->data = data;
      this->next = NULL;
    }
};

void InstrValue(node* &head, int value){
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

void display(node* head){
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

   InstrValue(head, 1);
   InstrValue(head, 2);
   InstrValue(head, 3);

   display(head);
    return 0;
}
