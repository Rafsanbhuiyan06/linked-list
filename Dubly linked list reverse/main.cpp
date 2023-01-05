#include <iostream>
using namespace std;


class node
{
public:
    int data;
    node* next;
    node* prev;

    node(int data){
    this->data = data;
    this->next = NULL;
    this->prev = NULL;
    }
};
void InsrtAtHead(node* &head, int val){
    node* n = new node(val);
    if(head == NULL){
        head = n;
         return;
    }
    n->next = head;
    head->prev = n;
    head = n;
}
void Reverse(node* &head){

    if(head == NULL){
        cout<< "List is Empty ";
          return;
    }
    node* currNod = head;
    node* nextNod = NULL;
    while(currNod != NULL){
        nextNod = currNod->next;
        currNod->next = currNod->prev;
        currNod->prev = nextNod;
        currNod = nextNod;
            cout<<" "<<currNod->data;
    }
    head = currNod;

    node* temp = head;
    while(temp->prev != NULL){
    cout<<"-> "<<temp->data;
    temp = temp->next;
   }
   cout<<endl;
}

void Print(node* head){
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
    InsrtAtHead(head, 40);
    InsrtAtHead(head, 30);
    InsrtAtHead(head, 20);
    InsrtAtHead(head, 10);

    Print(head);
    Reverse(head);
    //Print(head);
    return 0;
}
