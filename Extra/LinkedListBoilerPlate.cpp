#include<iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
};

Node* CreateNode() {
    Node* first = new Node();
    Node* second = new Node();
    Node* third = new Node();
    
    first->val = 1;
    second->val = 2;
    third->val = 3;
    
    first->next = second;
    second->next = third;
    third->next = nullptr;
    
    return first;
}

void printNode(Node* head){
    Node* current = head;
    while(current!=nullptr){
        cout << current->val;
        current = current->next;
        if(current !=nullptr){
            cout<<"->";
        }
    }
}



int main(){
    Node* head = CreateNode();
    printNode(head);
    return 0;
}