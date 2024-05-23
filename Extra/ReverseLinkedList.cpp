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
    cout<<endl;
}

void deleteatfirst(Node*& head){
    Node* deleteNode = head;
    head = head->next;
    free(deleteNode);
}

void addatfirst(Node*& head){
    Node* newNode = new Node();
    newNode->val = 91;
    newNode->next = head;
    head = newNode;
}

void reverselinkedlist(Node*& head){
    Node* current = head;
    Node* prev=nullptr;
    Node* n;
    while(current!=nullptr){
        n = current->next;
        current->next = prev;
        prev = current;
        current = n;
    }
    head = prev;
}

int main(){
    Node* head = CreateNode();
    printNode(head);
    deleteatfirst(head);
    printNode(head);
    addatfirst(head);
    printNode(head);
    reverselinkedlist(head);
    printNode(head);
    return 0;
}