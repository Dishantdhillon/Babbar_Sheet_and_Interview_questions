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

class Solution
{
    public:
    Node* addTwoLists(Node* first, Node* second) {
        stack<int> stack1;
        stack<int> stack2;
        while(first != NULL) {
            stack1.push(first -> data);
            first = first -> next;
        }
        while(second != NULL) {
            stack2.push(second -> data);
            second = second -> next;
        }
        Node* result = NULL;
        Node* temp = NULL;
        int carry = 0;
        while(stack1.empty() == false || stack2.empty() == false) {
            int a = 0, b = 0;
            if(stack1.empty() == false) {
                a = stack1.top();
                stack1.pop();
            }
            if(stack2.empty() == false) {
                b = stack2.top();
                stack2.pop();
            }
            int total = a + b + carry;
            carry = total/10;
            if(result == NULL) {
                result = temp = new Node(total % 10);
            }
            else {
                temp -> next = new Node(total % 10);
                temp = temp -> next;
            }
        }
        if(carry != 0) {
            temp -> next = new Node(carry);
            temp = temp -> next;
        }
        temp -> next = NULL;
        stack<int> stack3;
        Node* temp2 = result;
        while(temp2 != NULL) {
            stack3.push(temp2 -> data);
            temp2 = temp2 -> next;
        }
        Node* result1 = NULL; 
        Node* temp3 = NULL;
        result1 = temp3 = new Node(stack3.top());
        stack3.pop();
        while(stack3.size() > 0) {
            temp3 -> next = new Node(stack3.top());
            temp3 = temp3 -> next;
            stack3.pop();
        }
        return result1;
    }
};

void printList(Node* head) {
    Node* temp = head;
    if(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
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
            temp = second;
        }
        else {
            temp -> next = new Node(value);
            temp = temp -> next;
        }
    }
    Solution obj;
    Node* result = obj.addTwoLists(first, second);
    printList(result);
    return 0;
}
