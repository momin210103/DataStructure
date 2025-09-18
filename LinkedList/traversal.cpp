#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;
public:
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};
Node* ConvertArryToLL(vector<int> &ar){
    Node* head = new Node(ar[0]);
    Node* mover = head;
    for(int i=1; i<ar.size(); i++){
        Node* tmp = new Node(ar[i]);
        mover->next = tmp;
        mover = tmp;
    }
    return head;
}
int length(Node* head){
    int cnt =0;
    while(head){
        cnt++;
        head= head->next;
    }
    return cnt;
}
int main(){
    vector<int> ar = {19,2,3,5,6,7};
    Node* head = ConvertArryToLL(ar);
    Node* tmp = head;
    cout<<head->data<<" ";
    while(tmp){
        tmp = tmp->next;
        cout<<tmp->data<<" ";

    }
    cout<<length(head);

}
