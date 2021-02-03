#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    
    // It's better to have a constructor otherwise you'll have to do this manually
    Node(int x){
        data = x;
        next = nullptr;
    }
};

// data field can store data
// next field can store address of other Node (remember it is custom data type defined using struct which stores data and address of other Node)

// We need to store the address of first node in some variable (otherwise how will you access that linked list?)

// use nullptr instead of NULL because it is sometimes better, say when we have two same
// -name functions with int and int* as parameter, NULL will be calling int one because it is
// type int but nullptr will be calling the int* one

void printList(Node* head);

int main(){
    int n;
    cin>>n;
    
    // we have to declare first node separately out of the loop because we want to give it's
    // address to head node.
    
    int x; // for taking integer input
    cin>>x;
    
    Node* head = nullptr;
    
    // new creates an instance of struct Node and returns address to it (pointer to it)(address of Node);
    Node* firstNode = new Node(x);
    
    head = firstNode; // address of firstNode is stored in head
    Node* tail = head;
    
    
   /* We can use Arrow Operator (->) to access class members instead of using combination of two operators 
   Asterisk (*) and Dot (.) operator, Arrow operator in also known as “Class Member Access Operator” in C++
   programming language.
    */
    
    // (*firstNode).data :: first we got the structure variable using dereferencing(*), then we access its data item
    // firstNode -> data :: firstNode is pointer, if we want to access the data members of Node pointed by it
    // (Node whose address is stored by pointer firstNode) we can use this. Cool, Isn't it ??

    
    for(int i=1;i<=n-1;i++){ // loop runs n-1 times
    cin>>x;
    
    // this will create a new node with value x and return its address
    tail->next = new Node(x); // at this time our new Node is pointing to nullptr
    // tail var me jis node ka address hai (us node ke next field me agle node ka address daalna hai)
    // tail pointing to first node
    
    // (ab hm tail var me agle node ka address dalege)
    tail = tail->next;
    // tail pointing to second node (Ist iteration)
    }
    
    printList(head); // passing address to this first element of list
    
    return 0;
}

void printList(Node *head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
}
