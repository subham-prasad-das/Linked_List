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

void sort012(Node* &head){
    Node* temp = head;
    int zeroCnt = 0;
    int oneCnt = 0;
    int twoCnt = 0;

    while(temp != NULL){
        if(temp-> data == 0) zeroCnt++;
        else if(temp-> data == 1) oneCnt++;
        else if(temp-> data == 2) twoCnt++;

        temp = temp-> next;
    }

    Node* iter = head;

    while(iter != NULL){
        if(zeroCnt != 0){
            iter-> data = 0;
            zeroCnt--;
        }
        else if(oneCnt != 0){
            iter-> data = 1;
            oneCnt--;
        }
        else if(twoCnt != 0){
            iter-> data = 2;
            twoCnt--;
        }
        iter = iter-> next;
    }
/*
    while(zeroCnt > 0){
        iter-> data = 0;
        iter = iter-> next;
        zeroCnt--;
    }

    while(oneCnt > 0){
        iter-> data = 1;
        iter = iter-> next;
        oneCnt--;
    }

    while(twoCnt > 0){
        iter-> data = 2;
        iter = iter-> next;
        twoCnt--;
    }
*/
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
    Node* node1 = new Node(1);
    Node* head = node1;
    Node* tail = node1;

    insertAtHead(head, 2);
    insertAtTail(tail, 1);
    insertAtTail(tail, 2);
    insertAtTail(tail, 1);
    insertAtTail(tail, 0);
    insertAtTail(tail, 2);
    insertAtMiddle(head, 1, 0);
    print(head);
    
    sort012(head);
    print(head);

    return 0;
}