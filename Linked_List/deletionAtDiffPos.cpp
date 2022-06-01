#include <iostream>
using namespace std;

struct Node {
    int data;
    Node * next = NULL;
};

Node *head = NULL;
void insertAtBeg(int data)
{
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode -> data = data;
    newNode -> next = head;
    head = newNode;
}

void deleteAtBeg() {
    Node *temp = head;
    if(temp == NULL) {
        cout << "LL is Empty\n";
        return;
    }
    
    head = head -> next;
    delete temp;
    
}

void deleteAtEnd() {
    Node *temp = head;
    if(temp == NULL) {
        cout << "LL is Empty\n";
        return;
    }
    
    if(temp -> next == NULL) {
        head = NULL;
        delete temp;
        return;
    }
    
    while(temp -> next -> next != NULL)
        temp = temp -> next;
    Node *temp1 = temp -> next;
    temp -> next = NULL;
    delete temp1;
}

void deleteInMid(int pos) {
     Node *temp = head;
    if(temp == NULL) {
        cout << "LL is Empty\n";
        return;
    }
    
    if(temp -> next == NULL) {
        head = NULL;
        delete temp;
        return;
    }
    
    int count = 1;
    while(count < pos-1) {
        count++;
        temp = temp -> next;
    }
    
    Node *temp1 = temp -> next;
    temp -> next = temp1 -> next;
    temp1 -> next = NULL;
    delete temp1;
}

void display() {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}
int main()
{
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int data;
        for(int i = 0; i < n; i++) {
            cin >> data;
            insertAtBeg(data);
        }
    
    
        cout << "Insert at Beginning: ";
        display();
        cout << "After delete at beg: ";
        deleteAtBeg();
        display();
        
        cout << "After delete at end: ";
        deleteAtEnd();
        display();
        
        int pos;
        cin >> pos;
        
        cout << "After delete in middle: ";
        deleteInMid(pos);
        display();
    }

    return 0;
}