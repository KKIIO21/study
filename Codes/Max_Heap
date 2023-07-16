#include <stdio.h>
#include <stdlib.h>

#define size 200000

int arr[size];
int n = 0;


void insert(int x) {
    arr[++n] = x;
    if(n != 1) {
        for(int i = n; i > 1; i /=2) {
            if(arr[i/2] < arr[i]) {
                int temp;
                temp = arr[i/2];
                arr[i/2] = arr[i];
                arr[i] = temp;
            }
        }
    }
}

int delete(int x) {
    if(n == 0) {
        printf("Heap이 비어있습니다.\n");
    } else if(x == 0) {
        printf("힙을 삭제하지 않습니다.\n");
    } else if(x == 1) {
        printf("최대 Heap을 삭제합니다.\n");
    } else {
        printf("올바른 수를 입력하세요.\n");
    }
    if(x == 1) {
        int deleted = arr[1];
        arr[1] = '\0';
        arr[1] = arr[n];
        arr[n] = '\0';
        n--;
        for(int i = x; i * 2 <= n;){
            if(arr[i] > arr[i * 2] && arr[i] > arr[i * 2 + 1]) {
                break;
            } else if(arr[i * 2] > arr[i * 2 + 1]) {
                int temp;
                temp = arr[i * 2];
                arr[i * 2] = arr[i];
                arr[i] = temp;
                i *= 2;
            } else {
                int temp;
                temp = arr[i * 2 + 1];
                arr[i * 2 + 1] = arr[i];
                arr[i] = temp;
                i = i * 2 + 1;
            }
        }
        return deleted;
    }
    return 0;
}

int main() {
    int getnum, numlist;
    scanf("%d", &getnum);
    for(int i = 0; i < getnum; i++) {
        scanf("%d", &numlist);
        insert(numlist);
    }
    for(int j = 1; j <= getnum; j++) {
        printf("%d ", arr[j]);
    }
    printf("\n");

    printf("최대 Heap을 삭제하려면 1을 입력하세요. 아니면 0을 입력하세요.\n");
    scanf("%d", &getnum);
    if(getnum == 1) {
        printf("%d가 삭제되었습니다.\n", delete(getnum));
    } else if (getnum == 0) {
        printf("%d을 입력하여 최대 Heap을 삭제하지 않습니다.\n", delete(getnum));
    }
}
