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

        void print(Node* head);
};

void Node :: print(Node* head){
    cout << data << endl;
}

void insertAtFront(Node* &head, int d){
    Node* temp = new Node(d);

    temp-> next = head;
    head-> next = temp;
    head = temp;
}

void insertAtPosition(Node* &head, int pos, int d){
    if(pos == 1){
        insertAtFront(head, d);
        return ;
    }

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
    Node* n1 = new Node(2);
    Node* head = n1;
    n1-> print(head);

    insertAtPosition(head, 1, 1);
    print(head);

    insertAtPosition(head, 3, 3);
    print(head);
    
    insertAtPosition(head, 4, 4);
    print(head);

    return 0;
}