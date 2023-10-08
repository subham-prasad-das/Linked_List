// Removing duplicates from a linked list with sorted data set

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

/*
void removeDuplicates(Node* &head, Node* curr, Node* forward){
    if(forward == NULL){ // base case
        head = curr;
        print(head);
        return ; 
    }

    if(curr != forward){ // if two nodes are not same then move the curr as well as the forward forward
        removeDuplicates(head, forward, forward-> next);
    }

    if(curr == forward){ // if it seems to get some duplicate pair
        curr-> next = forward-> next; // point curr to next of forward
        forward-> next = NULL; // make the next of the forward to be NULL
        delete forward; // and finally delete forward
        removeDuplicates(head, curr, curr-> next); // and thus move on
    }
}
*/

void removeDuplicates(Node* &head){

    if(head == NULL) return ; // if the LL we were given is empty

    Node* curr = head;
    while(curr != NULL){ // full traversal
        if((curr -> next != NULL) && /*here must not be just one element in the linked list*/
           (curr-> data == curr-> next-> data)) { /*if curr-> data is equal to the data of curr-> next i.e. its forward's data*/ 
                Node* next_next = curr-> next-> next; // next_next is the next of curr's forward 
                Node* nodeToDelete = curr-> next; // nodeToDelete is curr's forward
                delete(nodeToDelete); // deleted curr's forward
                curr-> next = next_next; // made curr's next same as its forward's next
        }

        else{ // if curr's data is not equal to its forward's data, then just move the curr forward
            curr = curr-> next;
        }
    }
}

int main(){
    Node* node1 = new Node(2);
    Node* head = node1;
    Node* tail = node1;

    insertAtHead(head, 2);
    insertAtTail(tail, 2);
    insertAtTail(tail, 3);
    insertAtTail(tail, 3);
    insertAtMiddle(head, 1, 1);
    print(head);

    //removeDuplicates(head, head, head-> next); tried for doing this in a recurssive way

    removeDuplicates(head);
    print(head);

    return 0;
}

/*
    Need to work on the recurssive approach ASAP. What I think, I might need to include the "-> data" appropriately
*/