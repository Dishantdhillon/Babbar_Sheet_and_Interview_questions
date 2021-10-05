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

Node* Reverse(Node* head, int k) {
    stack<Node*> my_stack;
    Node* current = head;
    Node* prev = NULL;
    while(current != NULL) {
        int count = 0;
        while(current != NULL && count < k) {
            my_stack.push(current);
            current = current -> next;
            count++;
        }
        while(my_stack.size() > 0) {
            if(prev = NULL) {
                prev = my_stack.top();
                head = prev;
                my_stack.pop();
            }
            else {
                prev -> next = my_stack.top();
                prev = prev -> next;
                my_stack.pop();
            }
        }
    }
    prev -> next = NULL;
    return head;
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
    int k;
    cin >> k;
    head = Reverse(head, k);
    printList(head);
}
