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

int intersectPoint(Node* head1, Node* head2) {
    Node* i = head1;
    Node* j = head2;
    while(i != NULL && j != NULL) {
        if(i == j) {
            return i -> data;
        }
        if(i < j) {
            i = i -> next;
        }
        else {
            j = j -> next;
        }
    }
    return -1;
}

int main() {
    int n, m;
    cin >> n;
    Node* first = NULL;
    Node* temp = first;
    for(int i=0; i<n; i++) {
        int value;
        cin >> value;
        if(i == 0) {
            first = new Node(value);
            temp = first;
        }
        else {
            temp -> next = new Node(value);
            temp = temp -> next;
        }
    }
    cin >> m;
    Node* second = NULL;
    Node* temp2 = second;
    for(int i=0; i<m; i++) {
        int value;
        cin >> value;
        if(i == 0) {
            second = new Node(value);
            temp2 = second;
        }
        else {
            temp2 -> next = new Node(value);
            temp2 = temp2 -> next;
        }
    }
    cout << intersectPoint(first, second);
    return 0;
}