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

void insert(Node* &head, int position, int d){
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

void reverse(Node* &head, int k){

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

    insert(head, 1, 5);
    insert(head, 3, 20);
    insert(head, 4, 30);
    insert(head, 5, 50);

    print(head);

    return 0;
}