#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* prev;
        Node* next;

        Node(int data){
            this-> data = data;
            this-> prev = NULL;
            this-> next = NULL;
        }
};

void insertAtFront(Node* &head, int d){
    Node* temp = new Node(d);

    temp-> next = head;
    head-> prev = temp;
    head = temp;
}

void print(Node* &head){
    Node* temp = head;

    while(temp != NULL){
        cout << temp-> data << " ";
        temp = temp-> next;
    }
    cout << endl;
}

int count(Node* &head){
    Node* temp = head;
    int cnt = 0;

    while(temp != NULL){
        cnt++;
        temp = temp-> next;
    }

    return cnt;
}

int main(){
    Node* n1 = new Node(3);
    Node* head = n1;

    insertAtFront(head, 2);

    print(head);
    cout << "For now we have: " << count(head) << " Nodes in the linked list.";
    
    return 0;
}
