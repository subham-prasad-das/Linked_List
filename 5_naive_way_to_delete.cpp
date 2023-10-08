// naive way to delete the required position of the given linkedlist

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

void insertAtTail(Node* &tail, int d){
    Node* temp = new Node(d);
    
    tail-> next = temp;
    tail = temp;    
}

void deleteAtPosition(Node* &head, int pos){
    Node* temp1 = head;
    Node* temp2 = head;
    int cnt1 = 1;
    int cnt2 = 1;

    while(cnt1 < pos){
        temp1 = temp1-> next;
        cnt1++;
    }

    while(cnt2 < pos-1){
        temp2 = temp2-> next;
        cnt2++;
    }

    temp2-> next = temp1-> next;
    temp1-> next = NULL;
}

void print(Node* &head){
    Node* temp = head;

    while(temp != NULL){
        cout << temp-> data << "  ";
        temp = temp-> next;
    }
}

int main(){
    Node* n1 = new Node(1);
    Node* tail = n1;
    Node* head = n1;

    int d;

    cout << "Enter the values you want to keep in the linkedlist: ";

    for(int i = 0; i < 4; i++){
        cin >> d;
        insertAtTail(tail, d);
    }

    print(head);
    deleteAtPosition(head,3);
    cout << endl;
    print(head);

    return 0;
}