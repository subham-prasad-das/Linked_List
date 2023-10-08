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

        void show(Node* &head){
            cout << this-> data;
        }
};

void insertAtTail(Node* &tail, int d){
    Node* temp = new Node(d); // every time we make a inssertion, we make a new node
    tail-> next = temp; // the prev created node's next should point to the newly created node as the newly created node come before the prev node
    tail = temp; // because now the tail has the address of the newly created data so the new LL will be the tail now
} 

void print(Node* &head){
    Node* temp = head; // made a temp which is assigned to the value of head

    
    while(temp!=NULL){ // will traverse from head till we find the data value as NULL
        cout << temp-> data << " ";
        temp = temp-> next;
    }
}

int main(){
    Node* node1 = new Node(12); // 1st node created
    Node* head = node1; // firstly make a head. It should be immutable as we are gonna traverse and print thriugh the heaad only
    // print(head);

    Node* tail = node1; // tail is also assignesd to the data of nosd1. It will be mutable as we are gonna add LL towards the tail of every node.
    insertAtTail(tail, 15);
    // print(head);

    insertAtTail(tail, 17);
    print(head);            
    
    return 0;
}