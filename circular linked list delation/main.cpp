#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node* next;

    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void InsrtNode(node* &head, int element, int val)
{
    node* temp = head;
    node* NewNode = new node(val);
    if(head == NULL)
    {
        head = NewNode;
        NewNode->next = NewNode;
        return;
    }
    else{
        node* temp = head;
        while(temp->data != element)
        {
            temp = temp->next;
        }
        NewNode->next = temp->next;
        temp->next = NewNode;
    }
}

void Delete(node* &head, int kye)
{
    if(head == NULL)
    {
        cout<<"List is empty ";
        return;
    }
    node* prev = head;
    node* curr = prev->next;
    while(curr->data != kye){
        prev = curr;
        curr = curr->next;
    }
    prev->next = curr->next;
    if(curr == prev){
        head = NULL;
    }
    else if(head == curr){
        head = prev;
    }
    curr->next = NULL;
    delete curr;



}

void print(node* head)
{
    node* temp = head;
    do
    {
        cout<<"-> "<<temp->data;
        temp = temp->next;
    }while(temp != head);
    cout<<endl;
}
int main()
{
    node* head = NULL;
    InsrtNode(head,1,10);
    InsrtNode(head,10,20);
    InsrtNode(head,20,30);
    print(head);
    Delete(head,10);
    print(head);
    return 0;
}
