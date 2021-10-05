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

class Linked_list {
    public:
        Node* head;
        Linked_list() {
            head = NULL;
        }

        void push(int data) {
            Node* temp;
            if(head == NULL) {
                head = new Node(data);
                temp = head;
            }
            else {
            	temp -> next = new Node(data);
            	temp = temp -> next;
			}
        }

        void reverse() {
            Node* current = head;
            Node* next = NULL, *prev = NULL;
            while(current != NULL) {
                next = current -> next;
                current -> next = prev;
                prev = current;
                current = next; 
            }
            head = prev;
        }
        
        Node* reverse_recursive(Node* head) {
        	if(head == NULL || head -> next == NULL) {
                return head;
            }
            Node* rest = reverse_recursive(head -> next);
            head -> next -> next = head;
            head -> next = NULL;
            return rest;
		}

        void print() {
            Node* temp = head;
            while(temp != NULL) {
                cout << temp -> data << " ";
                temp = temp -> next; 
            }
        }
};

int main() {
    Linked_list ll;
    ll.push(1);
    ll.push(2);
    ll.push(3);
    ll.print();
    cout << "\nReversed Linked List\n";
    ll.reverse(); 
    ll.print();
    cout << "\nReversed Linked List\n";
    ll.head = ll.reverse_recursive(ll.head);
    ll.print();
    return 0;
}
