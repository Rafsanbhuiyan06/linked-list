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
     int val = this->data;
     if(this->next != NULL){
        delete this->next;
          next = NULL;
     }
   }
};

void InsrtNode(node* &tail, int element, int val){
     node* NewNode = new node(val);
     if(tail == NULL){
        tail = NewNode;
        NewNode->next = NewNode;
            return;
     }
     node* temp = tail;
     while(temp->data != element){
        temp = temp->next;
     }
     NewNode->next = temp->next;
     temp->next = NewNode;
}
void print(node* &tail){
  node* temp = tail;
  do{
    cout<<temp->data<<"->";
    temp = temp->next;
  }while(temp != tail);

}

int main()
{
    node* tail = NULL;
    InsrtNode(tail,5,10);
    InsrtNode(tail,10,20);
    InsrtNode(tail,20,30);
    print(tail);
    return 0;
}
