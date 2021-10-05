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

void detect_loop(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while(slow != NULL && fast != NULL && fast -> next != NULL) {
        slow = slow -> next;
        fast = fast -> next -> next;
        if(slow == fast) {
            remove_loop_optimized(Node* slow, Node* head);
        }
    }
}

void remove_loop_1st_method(Node* slow, Node* head) {
    Node* fast = head;
    int count = 1;
    while(fast -> next != slow) {
        fast = fast -> next;
        count++;
    }
    slow = head;
    fast = head;
    for(int i=0; i<count; i++) {
        fast = fast -> next;
    }
    while(slow != fast) {
        slow = slow -> next;
        fast = fast -> next;
    }
    while(slow -> next != fast) {
        slow = slow -> next;
    }
    slow -> next = NULL;
}

void remove_loop_optimized(Node* slow, Node* head) {
    Node* fast = slow;
    slow = head;
    if(slow == fast) {
        while(slow -> next != fast) {
            slow = slow -> next;
        }
    }
    else {
        while(slow != fast) {
            slow = slow -> next;
            fast = fast -> next;
        }
        while(slow -> next != fast) {
            slow = slow -> next;
        }
    }
    slow -> next = NULL;
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