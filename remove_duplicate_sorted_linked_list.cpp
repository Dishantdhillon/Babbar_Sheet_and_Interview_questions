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

Node* remove_duplicate(Node* head) {
    Node* current = head;
    while(current != NULL && current -> next != NULL) {
        if(current -> data == current -> next -> data) {
            current -> next = current -> next -> next;
        }
        else {
            current = current -> next;
        }
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
    Node *result = remove_duplicate(head);
    printList(result);
    return 0;
}
