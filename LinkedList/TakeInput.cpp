#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;

};
Node* Input(){
    Node* head = nullptr;
    Node* tail = nullptr;
    int val;
    cout<<"Enter value"<<endl;
    cin>>val;
    while(val!=-1){
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = nullptr;
        if(head==nullptr){
            head = newNode;
            tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
        cin>>val;

    }
    return head;
}
Node* reversed(Node* head){
    Node* cur = head;
    Node* pre = nullptr;
    Node* next;
    while(cur){
        next = cur->next;
        cur->next = pre;
        pre=cur;
        cur = next;

    }
    return pre;
}
void PrintList(Node* head){
    while(head){
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    Node* head = Input();
    PrintList(head);
    head = reversed(head);
    PrintList(head);
}
