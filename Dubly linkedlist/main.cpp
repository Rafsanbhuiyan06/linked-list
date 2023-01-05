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

void print(node* head){
  node* temp = head;
  while(temp != NULL){
      cout<<"-> "<<temp->data<<endl;
      temp = temp->next;
  }
}

int main()
{
    node* node1 = new node(10);
    print(node1);
    return 0;
}
