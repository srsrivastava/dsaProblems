
#include <iostream>

using namespace std;

class DllNode {
    public:
        int data;
        DllNode * next;
        DllNode * prev;
        DllNode(int data) {
            this -> data = data;
            this -> next = NULL;
            this -> prev = NULL;
        }
        
};

class DLL {
    public: 
        DllNode *head;
        DLL() {
            this -> head = NULL;
        }
        
        void insertAtBeg(int);
        void deleteAtBeg();
        void deleteAtEnd();
        void deleteInMid(int);
};

void DLL:: insertAtBeg(int data) {
    DllNode * node = new DllNode(data);
    if(head == NULL) {
        head = node;
    } else {
        node -> next = head;
        head -> prev = node;
        head = node;
        
    }
}

void DLL:: deleteAtBeg() {
    DllNode * temp = head;
    if(temp == NULL) {
        cout << "Linked list is empty: \n";
        return;
    }
    
    if(temp -> next == NULL) {
        head = NULL;
        delete temp;
        return;
    }
    
    head = head -> next;
    head -> prev = NULL;
    temp -> next = NULL;
    delete temp;
}

void DLL:: deleteAtEnd() {
    DllNode * temp = head;
    if(temp == NULL) {
        cout << "Linked list is empty: \n";
        return;
    }
    
    if(temp -> next == NULL) {
        head = NULL;
        delete temp;
        return;
    }
    
    while(temp -> next -> next != NULL) {
        temp = temp -> next;
    }
    
    DllNode *temp1 = temp -> next;
    temp -> next = NULL;
    temp1 -> prev = NULL;
    delete temp1;
}

void DLL:: deleteInMid(int pos) {
    DllNode * temp = head;
    if(temp == NULL) {
        cout << "Linked list is empty: \n";
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
    
    DllNode *temp1 = temp -> next;
    temp -> next = temp1 -> next;
    temp1 -> next -> prev = temp;
    temp1 -> next = NULL;
    temp1 -> prev = NULL;
    delete temp1;
    
}

void display(DllNode * head) {
    DllNode * temp = head;
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int main()
{
    DLL * llist = new DLL();
    int n;
    cin  >> n;
    for(int i = 0; i < n; i++) {
        int data;
        cin >> data;
        llist -> insertAtBeg(data);
    }
    
    cout << "insert at beginning: ";
    display(llist -> head);
    
    cout << "After delete at beginning: ";
    llist -> deleteAtBeg();
    display(llist->head);
    
    cout << "After delete at end: ";
    llist -> deleteAtEnd();
    display(llist -> head);
    
    int pos;
    cin >> pos;
    
    llist -> deleteInMid(pos);
    display(llist -> head);
    return 0;
}