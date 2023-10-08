#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int data){
            this-> data = data;
            this-> next = NULL;
        }

        void print(){
            cout << data;
        }
};

int main()
{
    Node* n1 = new Node(4);
    n1-> print();

    return 0;
}