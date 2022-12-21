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

int main()
{
    node* a = new node(10);
    node* b = new node(15);
    node* c = new node(20);

    a->next = b;
    b->next = c;
    c->next = NULL;

    while(a != NULL){
        cout<<a->data<<"-> ";
        a = a->next;
    }
    return 0;
}
