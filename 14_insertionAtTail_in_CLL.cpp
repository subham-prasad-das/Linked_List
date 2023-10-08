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

void insertAtTail(Node* tail, int d){
    Node* temp = new Node(d);

    tail-> next = temp;
    temp-> next = tail;
    tail = temp;
}

void print(Node* head){
    Node* temp = head;
    cout << temp-> data << " ";
    temp = temp-> next;

    while(temp != head){
        cout << temp-> data << " ";
        temp = temp-> next;
    }
}

int main(){
    Node* n1 =  new Node(3);
    Node* tail = n1;
    Node* head = n1;

    insertAtTail(tail, 4);
    print(head);

    return 0;
}