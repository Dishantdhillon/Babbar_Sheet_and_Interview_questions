#include<bits/stdc++.h>
using namespace std;

class Node {
	public:
	    int data;
	    Node* next;
	    Node(int x) {
	        data = x;
	        next = NULL;
	    }
};

void take_delete(Node** head, int x) {
	if(*head == NULL) {
		return;
	}
    Node* curr = *head;
	if(x == 1) {
        cout << curr -> data << endl;
        curr = curr -> next;
        *head = curr;
        return;
    }
    for(int i=0; i<x-2; i++) {
        curr = curr -> next;
    }
    cout << curr -> next -> data << endl;
    curr -> next = curr -> next -> next;
}

void print_list(Node* head) {
	Node* curr = head;
	while(curr != NULL) {
		cout << curr -> data << " ";
		curr = curr -> next;
	}
}

int main() {
    int m;
    cin >> m;
    Node* head = NULL;
    Node* temp;
    for(int i=0; i<m; i++) {
        int book;
        cin >> book;
        if(head == NULL) {
            head = new Node(book);
            temp = head;
        }
        else {
            temp -> next = new Node(book);
            temp = temp -> next;
        }
    }
    int n;
    cin >> n;
    while(n--) {
        int x;
        cin >> x;
        take_delete(&head, x);
    }
    return 0;
}
