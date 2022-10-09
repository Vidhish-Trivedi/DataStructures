#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct LinkedList{
    struct Node* head;
};


void printLinkedList(struct LinkedList* l){
    if(l->head == NULL){
        printf("Null LinkedList\n");
        return;
    }
    struct Node* temp = l->head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    return;
}

int getSize(struct LinkedList* l){
    if(l->head == NULL){
        return(0);
    }
    int c = 0;
    struct Node* temp = l->head;
    while(temp != NULL){
        c++;
        temp = temp->next;
    }
    return(c);
}

void addToEnd(struct LinkedList* l, struct Node* n){
    if(l->head == NULL){
        l->head = n;
        return;
    }
    struct Node* temp = l->head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;
    return;
}

void addToBeginning(struct LinkedList* l, struct Node* n){
    struct Node* temp = l->head;
    n->next = temp;
    l->head = n;
    return;
}

int searchLL(struct LinkedList* l, int val){
    if(l->head == NULL){
        return(-1);  // Not Found.
    }
    struct Node* temp = l->head;
    while(temp != NULL){
        if(temp->data == val){
            return(0);  // Found.
        }
        temp = temp->next;
    }
    return(-1);  // Not Found.
}

// Delete first occurrence.
void delete(struct LinkedList* l, int val){
    if(searchLL(l, val) == 0){  // value is in the linked list.
        struct Node* temp1 = l->head;
        struct Node* temp2 = NULL;
        if(temp1->data == val){  // delete head;
            l->head = l->head->next;
            return;
        }
        while(temp1->data != val){  // search and then delete;
            temp2 = temp1;
            temp1 = temp1->next;
        }
        temp2->next = temp1->next;
        temp1->next = NULL;
        return;
    }
    else{  // value is not in linked list.
        printf("Value not in Linked list.\n");
        return;
    }
}

int main(){
    struct LinkedList* l1 = NULL;
    
    // Allocate memory for Linked List.
    l1 = (struct LinkedList*)malloc(sizeof(struct LinkedList));

    l1->head = NULL;

    int i;

    // Add to end of Linked List.
    for(i = 1; i <= 30; i++){
        struct Node* e = NULL;
        e = (struct Node*)malloc(sizeof(struct Node));
        e->data = i*i;
        e->next = NULL;
        addToEnd(l1, e);
    }

    // Add to Beginning of Linked List.
    for(i = -1; i >= -30; i--){
        struct Node* e = NULL;
        e = (struct Node*)malloc(sizeof(struct Node));
        e->data = i;
        e->next = NULL;
        addToBeginning(l1, e);
    }

    // printLinkedList(l1);
    // printf("%d\n", getSize(l1));
    // printf("%d\n", searchLL(l1, 1));

    delete(l1, 841);
    delete(l1, 900);
    printLinkedList(l1);
    printf("%d\n", getSize(l1));
    delete(l1, -30);
    printLinkedList(l1);
    printf("%d\n", getSize(l1));
    delete(l1, -3);
    printLinkedList(l1);
    printf("%d\n", getSize(l1));

    return(0);
}