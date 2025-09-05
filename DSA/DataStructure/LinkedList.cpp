#include <iostream>

    // the first element is known as the "head"
    // each element store a value and a pointer to the next element
    // has dynamic size but no random element access

class Node {
    public:  
        int value;
        Node* next;
};

void printList(Node* head){
    while (head != NULL){
        std::cout << head->value << '\n';
        head = head->next;
    }
};

void insertHead(Node** head, int insert){
    // prepare a newNode
    Node* newHead = new Node();
    newHead->value = insert;
    // put it in front of the current head
    newHead->next = *head;
    // move head of the list to point to the newNode
    *head = newHead;
};

void insertTail(Node** head, int insert){
    // prepare a newNode
    Node* newTail = new Node();
    newTail->value = insert;
    newTail->next = NULL;
    // if the linked list is empty, newNode will be a head node
    if (*head == NULL){
        *head = newTail;
        return;
    }
    // Find the last node
    Node* last = *head; // new Node pointer 
    while (last->next != NULL){
        last = last->next;
    }
    // insert newNode after last node 
    last->next = newTail;
};

void insertAfter(Node* previous, int insert){
    // check if previous node is NULL
    if (previous == NULL){
        std::cout << "previous can not be NULL";
        return;
    }
    // prepare a newNOde
    Node* newNode = new Node();
    newNode->value = insert;
    // insert newNode after previous
    newNode->next = previous->next;
    previous->next = newNode;
};

/*void reverseList(Node* n){
    Node temp = n->next;
    n->next = NULL;
    while (n != NULL){
        n = temp->next;
        temp->next = n->next;
    }

}; */

int main (){

    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();

    head->value = 1;
    head->next = second;
    second->value = 2;
    second->next = third;
    third->value = 3;
    third->next = NULL;

    insertHead(&head,0);
    insertHead(&head,-1);
    insertTail(&head,4);
    insertAfter(second,69);
    printList(head);

    std::cout << "The value of the head is: " << head->value;

    return 0;
}