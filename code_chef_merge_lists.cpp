#include<bits/stdc++.h>
using namespace std;

class Node{
	public:
	    int data;
	    Node* next;
	    Node(int x) {
	        data = x;
	        next = NULL;
	    }
};

void print_list(Node* head) {
    Node* curr = head;
    while(curr != NULL) {
        cout << curr -> data << endl;
        curr = curr -> next;
    }
}

Node* merge_common(Node* head1, Node* head2) {
    Node* result = NULL;
    Node* temp;
    Node* temp1 = head1;
    Node* temp2 = head2;
    while(temp1 != NULL && temp2 != NULL) {
        if(temp1 -> data < temp2 -> data) {
            temp1 = temp1 -> next;
        }
        else if(temp1 -> data > temp2 -> data) {
            temp2 = temp2 -> next;
        }
        else {
            if(result == NULL) {
                result = new Node(temp1 -> data);
                temp = result;
            }
            else {
                temp -> next = new Node(temp1 -> data);
                temp = temp -> next;
            }
            temp1 = temp1 -> next;
            temp2 = temp2 -> next;
        }
    }
    return result;
}

Node* merge(Node* head1, Node* head2) {
    Node* result = NULL;
    Node* temp;
    Node* temp1 = head1;
    Node* temp2 = head2;
    while(temp1 != NULL && temp2 != NULL) {
        if(temp1 -> data < temp2 -> data) {
            if(result == NULL) {
                result = new Node(temp1 -> data);
                temp = result;
            }
            else {
                temp -> next = new Node(temp1 -> data);
                temp = temp -> next;
            }
            temp1 = temp1 -> next;
        }
        else if(temp1 -> data > temp2 -> data) {
            if(result == NULL) {
                result = new Node(temp2 -> data);
                temp = result;
            }
            else {
                temp -> next = new Node(temp2 -> data);
                temp = temp -> next;
            }
            temp2 = temp2 -> next;
        }
        else {
            if(result == NULL) {
                result = new Node(temp1 -> data);
                temp = result;
            }
            else {
                temp -> next = new Node(temp1 -> data);
                temp = temp -> next;
            }
            temp1 = temp1 -> next;
            temp2 = temp2 -> next;
        }
    }
    while(temp1 != NULL) {
        if(result == NULL) {
            result = new Node(temp1 -> data);
            temp = result;
        }
        else {
            temp -> next = new Node(temp1 -> data);
            temp = temp -> next;
        }
        temp1 = temp1 -> next;
    }
    while(temp2 != NULL) {
        if(result == NULL) {
            result = new Node(temp1 -> data);
            temp = result;
        }
        else {
            temp -> next = new Node(temp1 -> data);
            temp = temp -> next;
        }
        temp2 = temp2 -> next;
    }
    return result;
}

int  list_size(Node* head) {
    int n = 0;
    Node* curr = head;
    while(curr != NULL) {
        n++;
        curr = curr -> next;
    }
    return n;
}


int main() {
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    Node* head1 = NULL;
    Node* temp1;
    for(int i=0; i<n1; i++) {
        int x;
        cin >> x;
        if(head1 == NULL) {
            head1 = new Node(x);
            temp1 = head1;
        }
        else {
            temp1 -> next = new Node(x);
            temp1 = temp1 -> next;
        }
    }
    Node* head2 = NULL;
    Node* temp2;
    for(int i=0; i<n2; i++) {
        int x;
        cin >> x;
        if(head2 == NULL) {
            head2 = new Node(x);
            temp2 = head2;
        }
        else {
            temp2 -> next = new Node(x);
            temp2 = temp2 -> next;
        }
    }
    Node* head3 = NULL;
    Node* temp3;
    for(int i=0; i<n3; i++) {
        int x;
        cin >> x;
        if(head3 == NULL) {
            head3 = new Node(x);
            temp3 = head3;
        }
        else {
            temp3 -> next = new Node(x);
            temp3 = temp3 -> next;
        }
    }
    Node* result1 = merge_common(head1, head2);
    Node* result2 = merge_common(head2, head3);
    Node* result3 = merge_common(head1, head3);
    delete(head1);
    delete(head2);
    delete(head3);
    Node* result4 = merge(result1, result2);
    delete(result1);
    delete(result2);
    Node* result = merge(result4, result3);
    delete(result3);
    delete(result4);
    cout << list_size(result) << endl;
    print_list(result);
    return 0;
}
