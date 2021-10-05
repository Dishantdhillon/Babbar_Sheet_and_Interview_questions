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
    if(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
}

void split_list(Node* head, Node** head1, Node** head2) {
    Node* slow = head;
    Node* fast = head;
    while(fast -> next != head  && fast->next -> next != head) {
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    if(fast -> next -> next == head) {
        fast = fast -> next;
    }
    *head1 = head;
    if(head -> next != head) {
        *head2 = slow -> next;
    }
    fast -> next = slow -> next;
    slow -> next = head;
}

int main() {
    int n, m;
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
    Node* head1 = NULL;
    Node* head2 = NULL;
    split_list(head, &head1, &head2);
    printList(head1);
    cout << "\n";
    printList(head2);
    return 0;
}
