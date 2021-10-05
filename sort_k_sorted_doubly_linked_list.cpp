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

class compare {
	public:
    	bool operator()(Node* p1, Node* p2) {
        	return p1 -> data > p2 -> data;
    	}
};

Node* sortedDLL(Node* head, int k) {
    if(head == NULL || head -> next == NULL) {
        return head;
    }
    priority_queue<Node*, vector<Node*>, compare> pq;
    Node* newHead = NULL;
    Node* temp;
    for(int i=0; head != NULL && i <= k; i++) {
        pq.push(head);
        head = head -> next;
    }
    while(!pq.empty()) {
        if(newHead == NULL) {
            newHead = pq.top();
            temp = newHead;
        }
        else {
            temp -> next = pq.top();
            pq.top() -> prev = temp;
            temp = pq.top();
        }
        pq.pop();
        if(head != NULL) {
            pq.push(head);
            head = head -> next;
        }
    }
    temp -> next = NULL;
    return newHead;
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
    printList(sortedDLL(head, k));
    return 0;
}
