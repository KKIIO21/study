#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}node;

void insert_node(node* head, const int index, const int data) {
    int k = index;
    node* pre_node = head;
    node* insert = (node*)malloc(sizeof(node));
    insert->data = data;

    while(k-- && pre_node != NULL){
        pre_node = pre_node->next;
    }

    if(pre_node == NULL) {
        free(insert);
        return;
    }

    insert->next = pre_node->next;
    pre_node->next = insert;
}

void delete_node(node* head, const int index) {
    int k = index;
    node* temp = head;
    node* garbage = NULL;

    while(k-- && temp != NULL) {
        temp = temp->next;
    }

    if(temp == NULL || temp->next == NULL) {
        return;
    }

    garbage = temp->next;
    temp->next = garbage->next;
    free(garbage);

}

int search(node* head, const int val) {
    if(head->next == NULL) {
        return -1;
    }

    int index = 0;
    node* temp = head->next;

    while(temp != NULL) {
        if(temp->data == val) {
            return index;
        }
        ++index;
        temp = temp->next;
    }

    return -1;
}


int get_data(node* head, const int index) {
    if(head->next == NULL) {
        return -1;
    }
    
    int k = index;
    node* temp = head->next;

    while(k--) {
        temp = temp->next;
    }

    return temp->data;
}

int size(node* head) {
    node* temp = head->next;
    int len = 0;
    while(temp != NULL) {
        ++len;
        temp = temp->next;
    }
    return len;
}

void print_ll(node* head) {
    if(head->next == NULL) {
        return;
    }

    node* temp = head->next;
    while(temp != NULL) {
        printf("%d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    node* head = (node* )malloc(sizeof(node));
    head->data = 0;
    head->next = NULL;

    insert_node(head, 0, 123);
    print_ll(head); 

    insert_node(head, 1, 10);
    print_ll(head); 

    insert_node(head, 2, 20);
    print_ll(head); 

    insert_node(head, 1, 11);
    print_ll(head); 
    
    insert_node(head, 5, 19); 
    print_ll(head); 

    printf("%d\n", search(head, 20));
    printf("%d\n", search(head, 11));
    printf("%d\n", size(head));
    printf("%d\n", get_data(head, 3));

    delete_node(head, 0);
    print_ll(head);
    
    delete_node(head, 4);
    print_ll(head); 
}
