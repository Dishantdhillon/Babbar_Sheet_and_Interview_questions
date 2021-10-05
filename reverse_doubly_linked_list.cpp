#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
        Node* prev;
        Node(int data) {
            this -> data = data;
            next = NULL;
            prev = NULL;
        }
};

void printList(Node* head) {
    Node* temp = head;
    if(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
}

Node* reverseDLL(Node * head) {
    if(head == NULL && head -> next == NULL) {
        return head;
    }
    Node* current = head;
    Node* temp = NULL;
    while(current != NULL) {
        temp = current -> prev;
        current -> prev = current -> next;
        current -> next = temp;
        current = current -> prev;
    }
    if(temp != NULL)
        head = temp -> prev;
    return head;
}

int main() {
    int n;
    cin >> n;
    Node* head = NULL;
    Node* tail = head;
    for(int i=0; i<n; i++) {
        int value;
        cin >> value;
        if(i == 0) {
            head = new Node(value);
            tail = head;
        }
        else {
            Node* temp = new Node(value);
            tail -> next = temp;
            temp -> prev = tail;
            tail = temp;
        }
    }
    printList(reverseDLL(head));
    return 0;
}
