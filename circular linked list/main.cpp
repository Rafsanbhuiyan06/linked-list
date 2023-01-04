#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node*next;

    node(int data){
     this->data = data;
     this->next = NULL;
    }
    ~node(){
     int val = this->data;
     if(data != NULL){
        delete this->next;
          this->next = NULL;
     }
     cout<< "Memory delet for "<<val;
    }
};

void InsrtNode(node* &tell, int element, int val){
    if(tell == NULL){
        node* newNode = new node(val);
        tell = newNode;
        newNode->next = newNode;
        return;
    }
    node* curr = tell;
    while(curr->data != element){
        curr = curr->next;
    }
    node* temp = new node(val);
    temp->next = curr->next;
    curr->next = temp;
}

void Delete(node* &tell, int val){
  if(tell == NULL){
    cout<<"List is empty "<<endl;
    return;
  }
  else{
    node* prev = tell;
    node* curr = prev->next;

    while(curr->data != val){
        prev = curr;
        curr = curr->next;
    }
    prev->next = curr->next;
    if(curr == prev){
        tell = NULL;
    }
    else if(tell == curr){
        tell == prev;
    }
    curr->next = NULL;
    delete curr;
  }

}

void print(node* tell){
    if(tell == NULL){
        cout<<"List is empty "<<endl;
        return;
    }
    node* temp = tell;
    do{
        cout<<temp->data<< " ->";
        temp = temp->next;
    }while(temp != tell);
    cout<<endl;
}

int main()
{
    node* tell = NULL;
    InsrtNode(tell,5,10);
    print(tell);
    InsrtNode(tell,10,20);
    print(tell);
    InsrtNode(tell,20,30 );
    print(tell);
    Delete(tell,20);
    print(tell);
    return 0;


}
