#include<bits/stdc++.h>
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

void insertAtFront(Node* &head, int d){
    Node* temp = new Node(d);

    temp-> next = head;
    head-> next = temp;
    head = temp;
}

void insertAtBack(Node* &tail, int d){
    Node* temp = new Node(d);

    temp-> next = tail-> next;
    tail-> next = temp;
    tail = temp;
}

void insertAtMiddle(Node* head, int pos, int d){
    Node* curr = head;
    int cnt = 1;

    while(cnt < pos - 1){
        curr = curr-> next;
        cnt++;
    }

    Node* temp = new Node(d);
    
    temp-> next = curr-> next;
    curr-> next = temp;
}

void print(Node* head){
    Node* temp = head;
    cout << temp-> data << " ";
    temp = temp-> next;

    while(temp != head){
        cout << temp-> data << " ";
        temp = temp-> next;
    }
    cout << endl;
}

int main(){
    Node* n1 = new Node(3);
    Node* head = n1;
    Node* tail = n1;

    insertAtFront(head, 1);
    print(head);

    insertAtBack(tail, 4);
    print(head);
    
    insertAtMiddle(head, 2, 2);
    print(head);

    return 0;
}