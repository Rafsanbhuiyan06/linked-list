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
node* solve(node* &first, node* &second){
    if(first->next == NULL){
        first->next = second;
        return first;
    }
    node* curr1 = first;
    node* Next1 = curr1->next;
    node* curr2 = second;
    node* Next2 = curr2->next;

    while(Next1 != NULL && curr2 != NULL){
        if(curr2->data >= curr1->data &&
           curr2->data <= Next1->data){

            curr1->next = curr2;
            Next2 = curr2->next;
            curr2->next = Next1;
            curr1 = curr2;
            curr2 = Next2;
           }
           else{
            curr1 = Next1;
            Next1 = Next1->next;
            if(Next1->next == NULL){
                curr1->next = curr2;
                return first;
            }
        }
    }
    return first;
}
node* SortTwoList(node* first, node* second){
         if(first == NULL){
            return second;
         }
         if(second == NULL){
            return first;
         }
    if(first->data <= second->data){
       return solve(first,second);
    }
    else{
       return solve(first,second);
    }
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
    node* head1 = NULL;
    InsrtAtHead(head1,10);
    InsrtAtTell(head1,20);
    InsrtAtTell(head1,30);
    InsrtAtTell(head1,40);
    Display(head1);

    node* head2 = NULL;
    InsrtAtHead(head2,12);
    InsrtAtTell(head2,15);
    InsrtAtTell(head2,25);
    InsrtAtTell(head2,35);
    Display(head2);

    node* n = SortTwoList(head1,head2);
    Display(n);

    return 0;
}
