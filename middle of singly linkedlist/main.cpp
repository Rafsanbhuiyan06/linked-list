#include <iostream>
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
int Length(node* head);
void Print(node* head);
void InsrtAtTail(node* &head, int val);
void InsrtAtHead(node* &head, int val);
node* Middle(node* head);

int main()
{

    node* head = NULL;
    InsrtAtHead(head ,10);
    InsrtAtTail(head,20);
    InsrtAtTail(head,30);
    InsrtAtTail(head,40);

    node* newNode = Middle(head);
    cout<<newNode->data<<endl;
    //Print(head);
    //node* newHead = RecursivRev(head);
    //Print(newHead);
    return 0;
}

node* Middle(node* head){
      int len = Length(head);
      int mid = (len/2);
      int cnt = 0;
      node* temp = head;
      while(cnt <  mid){
        temp = temp->next;
        cnt++;
      }
      return temp;
}


int Length(node* head){
   node* temp = head;
   int cnt = 0;
   while(temp->next != NULL){
      cnt++;
      temp = temp->next;
   }
   return cnt;
}

void Print(node* head){
  node* temp = head;

  while(temp != NULL){
    cout<<temp->data<<"-> ";
    temp = temp->next;
  }
  cout<<endl;
}

void InsrtAtTail(node* &head, int val){
    if(head == NULL){
        InsrtAtHead(head, val);
    }
  node* n = new node(val);
  node* temp = head;
  while(temp ->next != NULL){
    temp = temp->next;
  }
  temp->next = n;
}
void InsrtAtHead(node* &head, int val){
   node* n = new node(val);
   if(head == NULL){
     head = n;
      return;
   }
   n->next = head;
   head = n;
}



