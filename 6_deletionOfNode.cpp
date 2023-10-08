// now i will be practising  the whole thing i have learnt while exploring linked list

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
    head = temp;
}

void insertAtMiddle(Node* &head, int pos, int d){
    Node* init = head;
    int cnt = 1;

    while(cnt < pos - 1){
        init = init-> next;
        cnt++;
    }

    Node* temp = new Node(d);
    temp-> next = init-> next;
    init-> next = temp;
}

void insertAtTail(Node* &tail, int d){
    Node* temp = new Node(d);

    tail-> next = temp;
    tail = temp;
}

/*
*/
void dlt(Node* &head, int pos){
    // here if we want to delete the 1st node, there would be an unexpected error.
    // so here we need to check the pos if it is greater than 1 or not , if it is greater than 1, then the below code will work fine like old wine..
    // if the pos will be 1, then we will need to perform the following operations -->
    //          -> create a temp of Node type and assign the value of head to temp
    //          -> make head = head-> next;
    //          -> make temp-> next = NULL;
    Node* prev = NULL;
    Node* curr = head;
    int cnt = 1;

    while(cnt < pos){
        prev = curr;
        curr = curr-> next;
        cnt++;
    }

    prev-> next = curr-> next;
    // delete(curr);
    curr-> next = NULL;
}

void print(Node* &head){
    Node* temp = head;

    while(temp != NULL){
        cout << temp-> data << " ";
        temp = temp-> next;
    }
}

int main(){
    Node* n1 = new Node(3);
    Node* head = n1;
    Node* tail = n1;

    insertAtFront(head, 2);
    insertAtFront(head, 1);

    insertAtTail(tail, 5);
    insertAtTail(tail, 6);

    insertAtMiddle(head, 4, 4);

    print(head);
    cout << endl;
    dlt(head, 6);
    print(head);
    return 0;
}