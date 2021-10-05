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

Node* rotate_n_nodes(Node* head, int n) {
    if(head == NULL || head -> next == NULL || n == 0) {
        return head;
    }
    Node* current = head;
    Node* end = head;
    while(n > 1) {
        current = current -> next;
        n--;
    }
    while(end -> next != NULL) {
        end = end -> next;
    }
    end -> next = head;
    head -> prev = end;
    head = current -> next;
    head -> prev = NULL;
    current -> next = NULL;
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
    int k;
    cin >> k;
    printList(rotate_n_nodes(head, k));
    return 0;
}
