#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    int stack[1000];
    int count = 0;
    char *push = "push";
    char *pop = "pop";
    char *empty = "empty";
    char *front = "front";
    char *back = "back";
    while(1) {
        char temp[100];
        scanf("%s", temp);
        if(strcmp(temp, push) == 0) {
            scanf("%d", &stack[count]);
            count++;
        } else if(strcmp(temp, pop) == 0) {
            if(count >= 1) {
                printf("%d\n", stack[0]);
                for(int i = 1; i < sizeof(stack)/sizeof(int); i++) {
                    stack[i-1] = stack[i];
                }
                count--;
            } else {
                    printf("There is no integer in the stack\n");
            }
        } else if(strcmp(temp, empty) == 0) {
            if(count == 0) {
                printf("There is no integer in the stack\n");
            } else {
                printf("0\n");
            }
        } else if(strcmp(temp, front) == 0) {
            if(count == 0) {
                printf("There is no integer in the stack\n");
            } else {
                printf("%d\n", stack[0]);
            }
        } else if(strcmp(temp, back) == 0) {
            if(count == 0) {
                printf("There is no integer in the stack\n");
            } else {
                printf("%d\n", stack[count-1]);
            }
        }
    }
}
