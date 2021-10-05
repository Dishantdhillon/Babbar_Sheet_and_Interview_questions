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
    if(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
}

Node *last_to_front(Node *head) {
    Node* current = head;
    while(current -> next -> next != NULL) {
        current = current -> next;
    }
    current -> next -> next = head;
    head = current -> next;
    current -> next = NULL;
    return head; 
}

int main() {
    int n;
    cin >> n;
    Node* head = NULL;
    Node* temp = head;
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
    Node* result = last_to_front(head);
    printList(result);
    return 0;
}
