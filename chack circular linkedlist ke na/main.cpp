#include <iostream>
#include <map>
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

void InsrtAtTail(node* &head,int kye,int val){
    node* n = new node(val);
    if(head == NULL){
        head = n;
        head->next = head;
         return;
    }
    node* temp = head;
    while(temp->data != kye){
        temp = temp->next;
    }
    n->next = temp->next;
    temp->next = n;
}

bool ChackNode(node* &head){
    if(head == NULL){
         return NULL;
    }
    node* temp = head->next;
    while(temp != NULL && temp != head){
        temp = temp->next;
    }
    if(temp == head){
        return true;
    }
    return false;
}

bool DecectLoop(node* &head){
     if(head == NULL){
        return false;
     }
     map<node*, bool> visited;
     node* temp = head;
     while(temp != NULL){
        if(visited[temp] == true)
           return true;
        }
        visited[temp] = true;
        temp = temp->next;
     }
     return false;
}

void Print(node* head){
   node* temp = head;
   do{
      cout<<"-> "<<temp->data;
      temp = temp->next;
   }while(temp != head);

   cout<<endl;
}
int main()
{
    node* head = NULL;
    InsrtAtTail(head,5, 10);
    InsrtAtTail(head,10, 20);
    InsrtAtTail(head,20, 30);
    InsrtAtTail(head,30, 40);
    InsrtAtTail(head,40, 50);
    Print(head);

    int n = DecectLoop(head);
    cout<<" 1 Yes 0 No  : "<<n<<endl;
    return 0;
}
