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
Node* DeleteTail(Node* head){
    if(head == nullptr || head->next == nullptr){
        return nullptr;
    }
    Node* tmp = head;
    while(tmp->next->next != nullptr){
        tmp = tmp->next;
    }
    delete tmp->next;
    tmp->next = nullptr;
    return head;
}
Node* DeletePosition(Node* head,int pos){
    if(head == NULL){
        return head;
    }
    if(pos==1){
        Node* tmp = head;
        head = head->next;
        delete tmp;
        return head;
    }
    Node* tmp = head;
    int cnt =0;
    Node* prev = NULL;
    while(tmp!=NULL){
        cnt++;
        if(cnt == pos){
            prev->next = prev->next->next;
            delete tmp;
            break;
        }
        prev = tmp;
        tmp = tmp->next;
    }
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
    head = DeleteTail(head);
    Print(head);
    head = DeletePosition(head,3);
    Print(head);
    return 0;
}