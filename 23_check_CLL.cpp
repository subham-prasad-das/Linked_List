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

void checkCLL(Node* &head, Node* temp){
    // base case 1-> if head came again while traversal, the linked list is circular
    if(temp == head){
        cout << "It is circular";
        return ;
    }

    // base case 2-> if NULL came again while traversal, the linked list is not circular
    else if(temp == NULL){
        cout << "It is not circular";
        return ;
    }

    // the recursive case
    else{
        checkCLL(head, temp-> next);
    }
}

void print(Node* &head){
    Node* temp = head;

    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int main(){
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    insertAtHead(head, 5);
    insertAtTail(tail, 20);
    insertAtTail(tail, 40);
    insertAtMiddle(head, 1, 3);

    checkCLL(head, head-> next);

    return 0;
}