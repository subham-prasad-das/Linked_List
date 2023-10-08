/*

approach 1 --> 
    making a vector to store all the elements of the linkedlist and then applying the same logic that we used in case of an array or string to find if it is pallindrome or not.

*/

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

void print(Node* &head){
    Node* temp = head;

    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout << endl;
}

bool checkPal(Node* &head){
    Node* temp = head;
    vector<int> v;

    while(temp != NULL){
        v.push_back(temp-> data);
        temp = temp-> next;
    }

    for(int i = 0, j = v.size()-1; i < j; i++, j--){
        if(v[i] != v[j]) return false;
    }
    return true;
}

int main(){
    Node* node1 = new Node(3);
    Node* head = node1;
    Node* tail = node1;

    insertAtHead(head, 2);
    insertAtTail(tail, 2);
    insertAtTail(tail, 1);
    insertAtMiddle(head, 1, 1);
    print(head);

    if(checkPal(head)) cout << "The linked list is pallindrome";
    else cout << "The linked list is not pallindrome";
    
    return 0;
}