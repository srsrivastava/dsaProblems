#include <iostream>

using namespace std;

struct node {
    int data;
    node *next;
    node *prev;
    
};

node *head = NULL;

void insertAtBeg(int data) {
    node *newNode = (node*) malloc(sizeof(node));
    newNode -> data = data;
    if(head == NULL) {
        newNode -> next = NULL;
        newNode -> prev = NULL;
        head = newNode;
        return;
        
    }
    
    newNode -> next = head;
    newNode -> prev = NULL;
    head -> prev = newNode;
    head = newNode;
}

void insertAtEnd(int data) {
    node *newNode = (node*) malloc(sizeof(node));
    newNode -> data = data;
    if(head == NULL) {
        newNode -> next = NULL;
        newNode -> prev = NULL;
        head = newNode;
        return;
        
    }
    
    node *temp = head;
    
    while(temp -> next != NULL) {
        temp = temp -> next;
    }
    
    newNode -> next = NULL;
    temp -> next = newNode;
    newNode -> prev = temp;
}

void insertInMiddle(int data, int pos) {
    node *newNode = (node*) malloc(sizeof(node));
    newNode -> data = data;
    if(head == NULL) {
        newNode -> next = NULL;
        newNode -> prev = NULL;
        head = newNode;
        return;
        
    }
    
    node *temp = head;
    
    int count = 1;
    while(count < pos -1 && temp -> next != NULL) {
        count++;
        temp = temp -> next;
    }
    
    if(temp -> next == NULL) {
        temp -> next = newNode;
        newNode -> next = NULL;
        newNode -> prev = temp;
        return;
    }
    
    newNode -> next = temp -> next;
    newNode -> next -> prev = newNode;
    temp -> next = newNode;
    
    
}

void display() {
    node *temp = head;
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    int data;
    for(int i = 0; i < n; i++) {
        cin >> data;
        insertAtBeg(data);
    }
    
    cout << "Insert at Beginning: ";
    display();
    head = NULL;
    
    for(int i = 0; i < n; i++) {
        cin >> data;
        insertAtEnd(data);
    }
    
    cout << "Insert at End: ";
    display();
    
    int pos;
    cin >> pos;
    // int data;
    cin >> data;
    cout << "Insert in middle: ";
    insertInMiddle(data, pos);
    display();

    return 0;
}