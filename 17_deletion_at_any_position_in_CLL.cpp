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
    Node* prev = head;
    int cnt = 1;

    while(cnt < pos-1){
        prev = prev-> next;
        cnt++;
    }

    Node* temp = new Node(d);

    temp-> next = prev-> next;
    prev-> next = temp;
}  

void deleteAtPosition(Node* &head, Node* &tail, int pos){
    if(pos == 1){
        Node* temp = head;
        tail-> next = temp-> next;
        temp-> next = NULL;
        head = tail-> next;
        delete temp;
    }

    else{
        /*
        // if it is required to remove the tail then eventually we need to replace the tail too...
        // so we need to count the no of nodes of the particular linked list and then we need to code if the given pos == tail's index, then update tail...
        Node* temp = head;
        int count = 1;
        do{
            temp = temp-> next;
            count++;
        }while(temp-> next != head);
        */

        Node* curr = tail-> next;
        Node* prev = NULL;
        int cnt = 1;

        while(cnt < pos){
            prev = curr;
            curr = curr-> next;
            cnt++;
        }

        prev-> next = curr-> next;
        curr-> next = NULL;
        delete curr;

        /*
        if(pos == count){
            Node* init = head;

            do{
                adhuri sii ye code haii....
            }while(init != head);
        }
        */
    }
}

void print(Node* &head){
    Node* temp = head;

    do{
        cout << temp-> data << " ";
        temp = temp-> next;
    }while(temp != head);
    cout << endl;
}


int main(){
    Node* n1 = new Node(3);
    Node* head = n1;
    Node* tail = n1;

    insertAtFront(head, 1);
    print(head);

    insertAtBack(tail, 5);
    print(head);

    insertAtMiddle(head, 3, 4);
    print(head);

    deleteAtPosition(head, tail, 4);
    print(head);

    cout << "New tail is: " << tail-> data;
    return 0;
}