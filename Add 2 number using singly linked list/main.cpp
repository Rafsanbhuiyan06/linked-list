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
     node* first = head;
     node* slow = head;
     while(first != NULL && first->next != NULL){
        first = first->next->next;
        slow = slow->next;
     }
     return slow;
}
node* Reverse(node* head){
     node* curr = head;
     node* prev = NULL;
     node* forwrd = NULL;

     while(curr != NULL){
        forwrd = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forwrd;
     }
     return prev;
}
void  InsrtAddTail(node* &head, node* &tail, int val){
     node* n = new node(val);
     if(head == NULL){
        head = n;
        tail = n;
        return;
     }
     else{
        tail->next = n;
        tail = n;
     }
}
node* add(node* &first, node* &second){
     int carry = 0;

     node* ansHead = NULL;
     node* ansTail = NULL;

     while(first != NULL || second != NULL || carry != 0){
            int val1 = 0;
            if(first != NULL){
                val1 = first->data;
            }
            int val2 = 0;
            if(second != NULL){
                val2 = second->data;
            }

        int sum = carry + val1 + val2;
        int digit = sum%10;
        InsrtAddTail(ansHead,ansTail,digit);
        carry = sum/10;

        if(first != NULL)
             first = first->next;
        if(second != NULL)
             second = second->next;
     }
     return ansHead;
}

node* AddTwoList(node* &first, node* &second){
      first = Reverse(first);
      second = Reverse(second);

      node* ans = add(first,second);
      ans = Reverse(ans);
      return ans;
}
void Display(node* &head){
  node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<"-> ";
        temp = temp->next;
    }
    cout<<endl;
}
int main()
{
    node* head1 = NULL;
    InsrtAtHead(head1,5);
    InsrtAtTell(head1,8);
    InsrtAtTell(head1,10);
    InsrtAtTell(head1,15);
    InsrtAtTell(head1,50);
    Display(head1);

    node* head2 = NULL;
    InsrtAtHead(head2,50);
    InsrtAtTell(head2,5);
    InsrtAtTell(head2,10);
    InsrtAtTell(head2,15);
    Display(head2);
    cout<<endl<<endl;

   node* n = AddTwoList(head1,head2);
   Display(n);

    return 0;
}
