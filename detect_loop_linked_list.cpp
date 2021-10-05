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

bool detect_loop(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while(slow != NULL && fast != NULL && fast -> next != NULL) {
        slow = slow -> next;
        fast = fast -> next -> next;
        if(slow == fast) {
            return true;
        }
    }
    return false;
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
    cout << detect_loop(head);
    return 0;
}