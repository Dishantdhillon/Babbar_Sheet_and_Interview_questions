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

Node* sort012(Node* head) {
    int count[3] = {0};
    Node* current = head;
    while(current != NULL) {
        count[current -> data]++;
        current = current -> next;
    }
    Node* newHead = NULL;
    Node* temp;
    for(int i=0; i<3; i++) {
        for(int j=0; j<count[i]; j++) {
            if(newHead == NULL) {
                newHead = new Node(i);
                temp = newHead;
            }
            else {
                temp -> next = new Node(i);
                temp = temp -> next;
            }
        }
    }
    return newHead;
}

int main() {
    int n;
    cin >> n;
    Node* head = NULL;
    Node* temp = NULL;
    for(int i=0; i<n; i++) {
        int value;
        cin >> value;
        if(head == NULL) {
            head = new Node(value);
            temp = head;
        }
        else {
            temp -> next = new Node(value);
            temp = temp -> next;
        }
    }
    printList(sort012(head));
    return 0;
}
