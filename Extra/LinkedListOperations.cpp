// LinkedListOperations

#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
};

Node* createNode() {
    Node* first = new Node();
    Node* second = new Node();
    Node* third = new Node();
    Node* four = new Node();
    
    first->val = 1;
    second->val = 2;
    third->val = 3;
    four->val = 4;
    
    first->next = second;
    second->next = third;
    third->next = four;
    four->next = nullptr;
    
    return first;
}

void printNode(Node* head) {
    Node* current = head;
    while (current != NULL) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

void addNodeAtEnd(Node* head) {
    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    Node* five = new Node();
    five->val = 81;
    current->next = five;
    five->next = NULL;
}

void addNodeAtStart(Node*& head) {
    Node* newNode = new Node();
    newNode->val = 91;
    newNode->next = head;
    head = newNode;
}

// Remove Nth Node From Last

void removeNthNode(Node*& head) {
    int length = 1;
    int k;
    cin >> k;
    Node* current = head;
    
    // Calculate the length of the list
    while (current->next != NULL) {
        current = current->next;
        length++;
    }
    
    if (k > length || k < 1) {
        cout << "Out of bound. Value Must be between 1 and " << length << endl;
        return;
    }
    
    // Special case: if the node to be removed is the head node
    if (k == length) {
        Node* deleteNode = head;
        head = head->next;
        cout << deleteNode->val << " got deleted" << endl;
        delete deleteNode;
        return;
    }
    
    // Find the (length - k)th node
    int n = length - k;
    current = head;
    for (int i = 1; i < n; i++) {
        current = current->next;
    }
    
    Node* deleteNode = current->next;
    current->next = current->next->next;
    cout << deleteNode->val << " got deleted" << endl;
    delete deleteNode;
}

int main() {
    Node* head = createNode();
    printNode(head);
    addNodeAtEnd(head);
    printNode(head);
    addNodeAtStart(head);
    printNode(head);
    removeNthNode(head);
    printNode(head);
    return 0;
}