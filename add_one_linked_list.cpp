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

Node *add_one(Node* head) {
    Node* current = head;
    Node* prev = NULL;
    while(current -> next != NULL) {
        if(current -> data != 9) {
            prev = current;
        }
        current = current -> next;
    }
    if(current -> data != 9) {
        current -> data++;
        return head;
    }
    if(prev == NULL) {
        prev = new Node(0);
        prev -> next = head;
        head = prev;
    }
    prev -> data++;
    prev = prev -> next;
    while(prev != NULL) {
        prev -> data = 0;
        prev = prev -> data;
    }
    return head;
}

void printList(Node* head) {
    Node* temp = head;
    if(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
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
    Node* result = add_one(head);
    printList(result);
    return 0;
}