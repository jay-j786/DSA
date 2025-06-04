// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

struct Node {
int data;
struct Node *next;
};

// Display
void traverseLinkedList(struct Node *ptr){
    while(ptr!=NULL){
        printf("Element %d \n", ptr->data);
        ptr=ptr->next;
    }
}

// insertions
struct Node * insertAtStart(struct Node * head, int data){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    
    ptr->data=data;
    ptr->next=head;

     return ptr;
}
struct Node * insertAtIndex(struct Node * head, int index, int data){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node * p = head;
    int i =0;

    while(i != index-1){
        p=p->next;
        i++;
    }

    ptr->data = data;
    ptr->next =p->next;
    p->next=ptr;
   
    return head;
}
struct Node * insertAtEnd(struct Node * head, int data){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node * p = head;
    
    while(p->next!=NULL){
        p = p->next;
    }

    p->next=ptr;
    ptr->data=data;
    ptr->next=NULL;

     return head;
}
void insertAfterNode(struct Node * prevNode, int data){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    
    ptr->next=prevNode->next;
    prevNode->next = ptr;
    
}

// Deletions
struct Node * deleteFirst(struct Node * head){
    struct Node * ptr = head;
    head = head->next;
    free(ptr);
    
    return head;
}

struct Node * deleteAtIndex(struct Node * head, int index){
    struct Node * p = head;
    struct Node * q = head->next;

    
    int i = 0;
    while(i!=index-1){
        p = p->next;
        q = q->next; 
        i++;   
    }
    p->next = q->next;
    free(q);

    return head;
}

struct Node * deleteLastNode(struct Node *head){
    struct Node * p = head;
    struct Node * q=head->next;
    while(q->next!=NULL){
        p=p->next;
        q=q->next;
    }

    p->next = NULL;
    free(q);

    return head;
}

struct Node * deleteByValue(struct Node * head,int value){

    struct Node * p=head;
    struct Node * q=head->next;

    while(q->data != value && q->next != NULL){
        p=p->next;
        q=q->next;
    }
    if(q->data == value){
        p->next = q->next;
        free(q);
    }

    return head;
}

int main() {
    struct Node * head = (struct Node *)malloc(sizeof(struct Node));
    struct Node * second =  (struct Node *)malloc(sizeof(struct Node));
    struct Node * third  =  (struct Node *)malloc(sizeof(struct Node));
    struct Node * fourth  =  (struct Node *)malloc(sizeof(struct Node));
    
    head->data=7, head->next=second;
    second->data=11, second->next=third;
    third->data=13, third->next=fourth;
    fourth->data=66, fourth->next=NULL;

    printf("Before Deletion :\n");
    // traverseLinkedList(head);
     // head = insertAtStart(head, 89);
     // head = insertAtIndex(head, 89);
     // head = insertAtEnd(head, 89);
    // insertAfterNode(third, 89);  
    // head = deleteFirst(head);
    // head = deleteAtIndex(head,2);
    // head= deleteLastNode(head);
    // head= deleteByValue(head,11);
    // printf("\nAfter Deletion :\n");
    // traverseLinkedList(head);

    
    return 0;
}