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

Node* reverse_in_given_size(Node* head, int k) {
    Node* current = head;
    Node* temp = NULL;
    Node* temp1 = NULL;
    while(current != NULL) {
        int count = 0;
        stack<Node*> myStack;
        while(current != NULL && count < k) {
            count++;
            myStack.push(current);
            current = current -> next;
        }
        while(myStack.size() > 0) {
            if(temp == NULL) {
                temp = myStack.top();
                head = temp;
                temp1 = temp;
                myStack.pop();
            }
            else {
                temp -> next = myStack.top();
                temp = temp -> next;
                temp -> prev = temp1;
                temp1 = myStack.top();
                myStack.pop();  
            }
        }
    }
    temp -> next = NULL;
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
    printList(reverse_in_given_size(head, k));
    return 0;
}
