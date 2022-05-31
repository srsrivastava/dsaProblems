#include <iostream>
#include <cstdlib>


using namespace std;

struct node {
    int data;
    struct node* next;
};

struct node* createList(struct node* head) {
    struct node* newnode, *temp;
    
    for(int i = 1; i <= 5; i++) {
        newnode = (struct node*) malloc(sizeof(struct node*));
        
        if(newnode == NULL) {
            return head;
        }
        newnode -> data = i;
        newnode -> next = NULL;
        
        if(head == NULL) {
            head = newnode;
            temp = head;
        }
        
        temp -> next = newnode;
        temp = newnode;
    }
    
    return head;
    
}

void printList(struct node* head) {
    while(head != NULL) {
        cout << head -> data << " ";
        head = head -> next;
    }
    cout << endl;
}

int main()
{
    // cout<<"Hello World";
    struct node* head = NULL;
    head = createList(head);
    printList(head);
    
    // cout << head -> data;

    return 0;
}