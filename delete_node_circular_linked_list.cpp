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
    if(temp -> next != head) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
}

Node* delete_node(Node* head, int key) {
    Node* current = head;
    Node* prev = NULL;
    if(current -> data == key && current -> next == current) {
        head = NULL;
        return head;
    }
    if(current -> data == key) {
        while(current -> next != head) {
            current = current -> next;
        }
        current -> next = head -> next;
        head = current -> next;
        return head;
    }
    if(current -> next -> data != key && current -> next != head) {
        current -> next = current -> next -> next;
        return head;
    }
    else {
        return head;
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
    temp -> next = head;
    int key;
    cin >> key;
    printList(delete_node(head, key));
}
