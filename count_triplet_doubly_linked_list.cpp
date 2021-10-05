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

int doublet(Node* start, Node* end, int sum) {
    int count = 0;
    Node* start1 = start;
    while(start1 != end && start1 -> next != end) {
        if(start1 -> data + end -> data > sum) {
            end = end -> prev;
        }
        else if(start1 -> data + end -> data < sum) {
            start1 = start1 -> next;
        }
        else {
            count++;
            start1 = start1 -> next;
            end = end -> prev;
        }
    }
    if(start1 -> next == end) {
        if(start1 -> data + end -> data == sum) {
            count++;
        }
    }
    return count;
}

int count_triplet(Node* head, int sum) {
    int count = 0;
    Node* current = head;
    Node* end = head;
    while(end -> next != NULL) {
    	end = end -> next;
	}
    while(current -> next -> next != NULL) {
        count = count + doublet(current -> next, end, sum - current -> data);
    }
    return count;
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
    cout << count_triplet(head, sum);
    return 0;
}
