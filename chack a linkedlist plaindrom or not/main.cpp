#include <iostream>
#include <vector>
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
node* getMiddle(node* &head){
     node* slow = head;
     node* first = head;
     while(first != NULL && first->next != NULL){
        first = first->next->next;
        slow = slow->next;
     }
     return slow;
}

bool ChackPlaindrom(node* &head){
   vector<int> arr;
   node* temp = head;

   while(temp != NULL){
    arr.push_back(temp->data);
    temp = temp->next;
   }

   int siz = arr.size();
   int start = 0;
   int ende = siz-1;

   while(start <= ende){
      if(arr[start] != arr[ende]){
        return false;
      }
     start++;
     ende--;
    }
   return true;
}
node* Reverse(node* &head){
   node* curr = head;
   node* forwrd = NULL;
   node* prev = NULL;

   while(curr != NULL){
    forwrd = curr->next;
    curr->next = prev;
    prev = curr;
    curr = forwrd;
   }
   return prev;
}

bool Plaindrom(node* &head){
     if(head->next == NULL){
        return NULL;
     }
    node* middle = getMiddle(head);
    node* temp = middle->next;
    middle->next = Reverse(temp);

    node* head1 = head;
    node* head2 = middle->next;
    while(head2 != NULL){
        if(head1->data != head2->data){
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    return true;
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
    InsrtAtHead(head,50);
    InsrtAtTell(head,5);
    InsrtAtTell(head,10);
    InsrtAtTell(head,15);
    InsrtAtTell(head,50);

   bool n = Plaindrom(head);
    if(n){
        cout<<"This is plindrom"<<endl;
    }
    else{
        cout<< "This is not a plindrom"<<endl;
    }



    return 0;
}
