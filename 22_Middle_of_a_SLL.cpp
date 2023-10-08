// doing it recurssively

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

void insertAtHead(Node* &head, int d){
    Node* temp = new Node(d);

    temp-> next = head;
    head = temp;
}

void insertAtTail(Node* &tail, int d){
    Node* temp = new Node(d);

    tail-> next = temp;
    tail = temp;
}

void insertAtMiddle(Node* &head, int position, int d){
    if(position == 1) insertAtHead(head, d);

    else{
        Node* temp = head;
        int count = 1;

        while(count<position-1){
            temp = temp-> next;
            count++;
        }

        Node* nodeToInsert = new Node(d);
        nodeToInsert-> next = temp-> next;
        temp-> next = nodeToInsert;
    }

}

int middle(Node* &head){
    // for finding out the length of the linked list
    Node* temp = head;
    int len = 0;

    while(temp != NULL){
        len++;
        temp = temp-> next;
    }

    // for finding out the middle of the linked list
    int midl = len/2;
    Node* mid = head;
    int cnt = 0;

    while(cnt < midl){
        mid = mid-> next;
        cnt++;
    }

    return mid-> data;

}

void print(Node* &head){
    Node* temp = head;

    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout << endl;
}

int main(){
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    insertAtHead(head, 5);
    insertAtTail(tail, 20);
    insertAtTail(tail, 40);
    insertAtMiddle(head, 1, 3);
    print(head);

    cout << "The middle of the linked list is: " << middle(head);

    return 0;
}