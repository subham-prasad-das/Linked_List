#include<bits/stdc++.h>
using namespace std;

class Link{
    public:
        int data;
        Link* next; // as this is a pointer 

    Link(int data){ // it will create the first node which will have a data and will be pointing to NULL
        this-> data = data;
        this-> next = NULL;
    }
};

void insert(Link* &head, int d){
    Link* temp = new Link(d); // whenever the function is called, we make a new LL dynamically
    temp-> next = head; // the 'next' of the newly created LL should point to the head of the prec=vious LL so as it will come before it.
    head = temp; // as now we have a LL before our preveously created LL, so now our head should point to the newly created LL 
    // here we used temp and head instead of head->data and temp->data because they both are of same type so can get recognized by their value.
}

void print(Link* &head){
    Link* temp = head; // the newly created LL should hold its data in head
    while(temp != NULL){ //as we know that the last data will be NULL so the loop will go till the last of the LL
        cout << temp-> data << " "; // the data in the temp will be printed
        temp = temp-> next; // after printing the 'data' in the 'temp', the 'temp' will be incremented to its 'next' which hold the 'address of the data' of the next data holding LL.
    }
    cout << endl;
}

int main(){
    Link* node1 = new Link(10);
    Link* head = node1;
    // print(head); // for printing the head first
    int num;
    cout << "Enter the number of list you want to create?" << endl;
    cin >> num;
    /*
    insert(head, 12);
    print(head);
    
    insert(head, 15);
    print(head);
    */

   /*Tried to insert the datas throug a loop*/
   for(int i = 0; i < num; i++){
        int n;
        cout << "Enter the node: " << endl;
        cin >> n;
        insert(head, n);
   }
    print(head); // to print the whole node
    return 0;
}

// we have taken <&head> throughout the program because we doont want to create any copy of our LL, but make changes in the orignal LL.