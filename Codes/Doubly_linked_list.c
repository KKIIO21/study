#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prevNode;
    struct Node* nextNode;
} Node;

Node* CreateNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prevNode = NULL;
    newNode->nextNode = NULL;
    return newNode;
}

void AppendNode(Node** head, Node* newNode) {
    if(*head == NULL) *head = newNode;
    else {
        Node* tail = *head;
        while(tail->nextNode != NULL) tail = tail->nextNode;
        tail->nextNode = newNode;
        newNode->prevNode = tail;
    }
}

Node* SearchNode(Node* current, int data) {
    if(current == NULL) return NULL;
    while(current != NULL) {
        if(current->data == data) return current;
        current = current->nextNode;
    }
    return NULL;
}

Node* RemoveNode(Node** head, int data) {
    Node* target = SearchNode(*head, data);
    if(target != NULL) {
	if(*head == target) {
	    *head = target->nextNode;
	    if(*head != NULL) (*head)->prevNode = NULL;
	}
        else {
	    if(target->nextNode != NULL) target->nextNode->prevNode = target->prevNode;
	    target->prevNode->nextNode = target->nextNode;	
	}
	target->prevNode = NULL;
	target->nextNode = NULL;
    }
    return target;
}

void DestroyNode(Node* node) {
    free(node);
}

void PrintList(Node* current) {
    if(current == NULL) printf("빈 리스트\n");
    else {
        while(current != NULL) {
            printf("[%p] %p %d %p\n", current, current->prevNode, current->data, current->nextNode);
            current = current->nextNode;
        }
    }
}

void DestroyList(Node* current) {
    Node* remove = current;
    while(remove != NULL) {
        current = current->nextNode;
        free(remove);
        remove = current;
    }
}

int main(void)
{
    Node* head = NULL;
    Node* newNode = NULL;

    newNode = CreateNode(10);
    AppendNode(&head, newNode);
    newNode = CreateNode(20);
    AppendNode(&head, newNode);
    newNode = CreateNode(30);
    AppendNode(&head, newNode);
    PrintList(head);

    DestroyNode(RemoveNode(&head, 30));
    PrintList(head);
    DestroyNode(RemoveNode(&head, 10));
    PrintList(head);
    DestroyNode(RemoveNode(&head, 20));
    PrintList(head);

    newNode = CreateNode(30);
    AppendNode(&head, newNode);
    DestroyNode(head);
    return 0;
}
