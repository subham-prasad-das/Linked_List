/*

approach--> 2
checking the linked list if it is pallindrome or not by reversing the part right to the middle of the linked list, then comparing the head with the next of the middle of the linked list till the pointer at the next of the linked list goes on to have NULL as its value. If every comparision goes right then the linked list is pallindrome or else its not. 
After all the operation gets over, re-do the reverse part 

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

Node* reverse(Node* head){
    Node* curr = head;
    Node* prev = NULL;
    while(curr != NULL){
        Node* forward = curr-> next;
        curr-> next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

bool checkPal(Node* &head){
    // step 1 --> find the middle of the linked list
    Node* mid = head;
    Node* mNxt = head-> next;
    while(mNxt-> next != NULL){
        mid = mid-> next;
        mNxt = mNxt-> next-> next;
    }
    
    // step 2 --> reverse the linkedlist from middle to last of the linked list and join it to the next of tee middle
    Node* temp = mid-> next;
    mid-> next = reverse(temp);

    // step 3 --> compare {first node till middle} with {middle-> next till end}
    Node* i = head;
    Node* j = mid-> next;
    while(j-> next != NULL){
        if(i-> data != j-> data){
            temp = mid-> next;
            mid-> next = reverse(temp); // after the operation got finished, re-do the reverse as if nothing has happened to our original linked list🤣🤣🤣🤣
            return false;
        }
        else{
            i = i-> next;
            j = j-> next;
        }
    }
    temp = mid-> next;
    mid-> next = reverse(temp); // after the operation got finished, re-do the reverse as if nothing has happened to our original linked list🤣🤣🤣🤣
    return true;
}

int main(){
    Node* node1 = new Node(3);
    Node* head = node1;
    Node* tail = node1;

    insertAtHead(head, 2);
    insertAtTail(tail, 3);
    insertAtTail(tail, 2);
    insertAtTail(tail, 1);
    insertAtMiddle(head, 1, 1);
    print(head);

    if(checkPal(head)) cout << "The linked list is pallindrome";
    else cout << "The linked list is not pallindrome";
    
    return 0;
}
