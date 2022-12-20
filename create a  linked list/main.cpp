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

void InsrtAtHead(node* &head, int value){

   node* temp = new node(value);   temp->next = head;
   head = temp;
}

void print(node* head){
   node* temp = head;

   while(temp->next != NULL){
      cout<<"-> "<<temp->data;
      temp = temp->next;
   }

}
int main()
{
    node* ob = new node(5);
    node* head = ob;

    //InsrtAtHead(head,10);
   /// InsrtAtHead(head,20);
   // InsrtAtHead(head,30);
    print(head);
    return 0;
}
