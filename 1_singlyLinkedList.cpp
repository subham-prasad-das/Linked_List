#include<bits/stdc++.h>
using namespace std;

class Link{
    public:
        int data; // the data is stored in the head of the linkedlist
        Link* next; // next stores the address of the data of the next node of that particular linked list

        Link(int data){
            this->data = data; 
            this->next=NULL;
        }

        void show(){
            cout << data << endl;
            cout << next << endl;
        }
};

int main(){
    Link *node1 = new Link(10); // made linked list dynamically
    node1-> show(); // called the function using arrow operator
    return 0;
}