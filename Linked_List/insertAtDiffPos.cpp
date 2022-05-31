#include <iostream>
#include <cstdlib>


using namespace std;

typedef struct node {
    int data ;
    struct node* next;
}Node;


Node *head = NULL;
void insertAtBeg(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode -> data = data;
    newNode -> next = head;
    head = newNode;
    
    
    
}

void insertAtEnd(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode -> data = data;
    newNode -> next = NULL;
    Node *temp = head;
    if(temp == NULL) {
        head = newNode;
        return;
    }
    
    
    while(temp -> next != NULL) {
        temp = temp -> next;
    }
    
    temp -> next = newNode;
        
}

void insertAtMiddle(int data, int pos) {
    Node * temp = head;
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode -> data = data;
    newNode -> next = NULL;
    if(temp == NULL){
        head = newNode;
        return;
    }
    
    int count = 1;
    while(count < pos && temp -> next != NULL) {
        count++;
        temp = temp -> next;
    }
    
    if(temp -> next == NULL) {
        temp -> next = newNode;
        return;
    }
    
    newNode -> next = temp -> next;
    temp -> next = newNode;
}

void printList() {
    Node* temp = head;
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
    printList();
    head = NULL;
    cout << endl;
    
    cout << "AT end\n";
    // int n;
    // cin >> n;
    for(int i = 0; i   < n; i++) {
        // int data;
        cin >> data;
        insertAtEnd(data);
    }
    
    printList();
    cout << endl;
    
    cout << "Insert at middle \n";
    int pos;
    cin >> pos;
    insertAtMiddle(data, pos);
    printList();
    cout << endl;
    

    return 0;
}