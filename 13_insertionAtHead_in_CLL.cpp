#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int data){
            this-> data = data;
            this-> next = NULL;
        }
};

void insertAtHead(Node* &head, int d){
    Node* temp = new Node(d);
    temp-> next = head;
    head-> next = temp;
    head = temp;
}

void print(Node* head){
    Node* temp = head;
    cout << temp-> data;
    temp = temp-> next;
    while(temp != head){
        cout << temp-> data;
        temp = temp-> next;
    }
}

int main()
{
    Node* n1 = new Node(4);
    Node* head = n1;
    // print(head);

    insertAtHead(head, 3);
    print(head);
    // cout << head-> data;

    return 0;
}