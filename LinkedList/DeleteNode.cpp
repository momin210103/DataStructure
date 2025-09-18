#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};
Node* Input(){
    Node* head = nullptr;
    Node* tail = nullptr;
    int data;
    cin>>data;
    while(data!=-1){
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = nullptr;
        if(head==nullptr){
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next  = newNode;
            tail = newNode;
        }
        cin>>data;
    }
    return head;

}
Node* DeleteHead(Node* head){
    if(head == nullptr){
        return head;
    }
    Node* tmp = head;
    head = head->next;
    delete tmp;
    return head;
}
Node* Print(Node* head){
    while(head){
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<"NULL"<<endl;
}
int main(){
    Node* head = Input();
    head = DeleteHead(head);
    Print(head);
    return 0;
}