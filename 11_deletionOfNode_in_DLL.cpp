#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* prev;
        Node* next;

        Node(int d){
            data = d;
            prev = NULL;
            next = NULL;
        }
};

void insertAtFront(Node* &head, int d){
    Node* temp = new Node(d);

    temp-> next = head;
    head-> prev = temp;
    head = temp;
}

void insertAtTail(Node* &tail, int d){
    Node* temp = new Node(d);

    temp-> prev = tail;
    tail-> next = temp;
    tail = temp;
}

void insertAtMiddle(Node* &head, int pos, int d){
    Node* curr = head;
    Node* past = NULL;
    int cnt = 1;

    while(cnt < pos){
        past = curr;
        curr = curr-> next;
        cnt++;
    }

    Node* temp = new Node(d);
    
    temp-> next = curr; // will work for past-> next as well so we can check for all kinda possibilities as well
    curr-> prev = temp;
    temp-> prev = past;
    past-> next = temp;
}

void deleteNode(Node* &head, int pos){
    int cnt = 1; // for traversal 
    Node* past = NULL; 
    Node* curr = head;

    while(cnt < pos){
        past = curr;
        curr = curr-> next;
        cnt++;
    }

    Node* temp = curr-> next;
    past-> next = temp;
    temp-> prev = past-> prev;

    curr-> next = NULL;
    curr-> prev = NULL;

    delete (curr);
}

void print(Node* &head){
    Node* temp = head;

    while(temp != NULL){
        cout << temp-> data << " ";
        temp = temp-> next;
    }
    cout << endl;
}

int main(){
    Node* n1 = new Node(3);
    Node* head = n1;
    Node* tail = n1;

    insertAtFront(head, 2);
    insertAtTail(tail, 5);
    insertAtMiddle(head, 3, 4);
    print(head);

    deleteNode(head, 3);
    print(head);

    return 0;
}

// the above code is perfect when the pos is != 1. if it is == 1, we need to add a CHECKER to check if the pos came to the function is 1 or not. If it is 1, then move the head to the next of current head and make the prev and next of the current head point to NULL.