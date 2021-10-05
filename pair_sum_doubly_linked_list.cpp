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

void pairSum(Node* head, int sum) {
    Node* start = head;
    Node* end = head;
    while(end -> next != NULL) {
        end = end -> next;
    }
    while(start != end && start -> next != end) {
        if(start -> data + end -> data > sum) {
            end = end -> prev;
        }
        else if(start -> data + end -> data < sum) {
            start = start -> next;
        }
        else {
            cout << start -> data << " " << end -> data << endl;
            start = start -> next;
            end = end -> prev;
        }
    }
    if(start -> next == end) {
        if(start -> data + end -> data == sum) {
            cout << start -> data << " " << end -> data << endl;
        }
    }
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
    int sum;
    cin >> sum;
    pairSum(head, sum);
    return 0;
}
