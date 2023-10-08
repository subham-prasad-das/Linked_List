
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
    insertAtBack(tail, 4);
    insertAtMiddle(head, 2, 2);

    checkCLL(head, head-> next);

    return 0;
}