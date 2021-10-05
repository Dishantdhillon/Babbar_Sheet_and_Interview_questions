#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
        Node(int data) {
            this -> data = data;
            next = NULL;
        }
};

void printList(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next; 
    }
}

Node* reverse(Node* head) {
    if(head == NULL || head -> next == NULL) {
        return head;
    }
    Node* rest = reverse(head -> next);
    head -> next -> next = head;
    head -> next = NULL;
    return rest;
}
    
Node *compute(Node *head) {
    Node* current = reverse(head);
    Node* newhead = current;
    while(current -> next != NULL) {
        if(current -> data > current -> next -> data) {
            current -> next = current -> next -> next;
        }
        else {
            current = current -> next;
        }
    }
    head = reverse(newhead);
    return head;
}

int main() {
    int n;
    cin >> n;
    Node* head = NULL;
    Node* temp = NULL;
    for(int i=0; i<n; i++) {
        int value;
        cin >> value;
        if(i == 0) {
            head = new Node(value);
            temp = head;
        }
        else {
            temp -> next = new Node(value);
            temp = temp -> next;
        }
    }
    head = compute(head);
    printList(head);
    return 0;
}