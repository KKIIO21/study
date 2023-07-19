#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define randsize 10

void insert(int getrandom[10]) {
    int num = 0, temp = 0;
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            if(getrandom[j] > getrandom[j+1]) {
                temp = getrandom[j];
                getrandom[j] = getrandom[j+1];
                getrandom[j+1] = temp;
            }
        }
    }
    
    printf("Insert Sorting을 시작합니다. \n[");
    for(int k = 0; k < 10; k++) {
        printf("%d", getrandom[k]);
        if(k != 9) {
            printf(", ");
        }
    }
    printf("]\n\n");
}

void selecte(int getrandom[10]) {
    int num = 0, ptr = 0;
    for(int i = 0; i < 9; i++) {
        num = getrandom[i];
        ptr = i;
        for(int j = i; j < 9; j++) {
            if(num > getrandom[j]) {
                num = getrandom[j];
                ptr = j;
            } 
        }
        getrandom[ptr] = getrandom[i];
        getrandom[i] = num;
    }
    
    printf("Selection Sorting을 시작합니다. \n[");
    for(int k = 0; k < 10; k++) {
        printf("%d", getrandom[k]);
        if(k != 9) {
            printf(", ");
        }
    }
    printf("]\n\n");
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int array[], int low, int high) {
    int pivot = array[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (array[j] < pivot) {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i+1], &array[high]);
    return i + 1;
}

void quicksort(int array[], int low, int high) {
    if (low < high) {
        int pivot_index = partition(array, low, high);
        quicksort(array, low, pivot_index - 1);
        quicksort(array, pivot_index + 1, high);
    }
}

void quick(int getrandom[10]) {
    quicksort(getrandom, 0, 9);

    printf("Quick Sorting을 시작합니다. \n[");
    for(int k = 0; k < 10; k++) {
        printf("%d", getrandom[k]);
        if(k != 9) {
            printf(", ");
        }
    }
    printf("]\n\n");
}

void mergeArray(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2]; 

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        mergeArray(arr, l, m, r);
    }
}

void merge(int getrandom[10]) {
    mergeSort(getrandom, 0, 9);

    printf("Merge Sorting을 시작합니다. \n[");
    for(int k = 0; k < 10; k++) {
        printf("%d", getrandom[k]);
        if(k != 9) {
            printf(", ");
        }
    }
    printf("]\n\n");
}

void heap(int getrandom[10]) {
    int count = 0;
    for(int j = 0; j < 10; j++) {
        if(count != 1) {
            for(int i = count; i > 1; i /=2) {
                if(getrandom[i/2] < getrandom[i]) {
                    int temp;
                    temp = getrandom[i/2];
                    getrandom[i/2] = getrandom[i];
                    getrandom[i] = temp;
                }
            }
        }
    }
    printf("Heap Sorting을 시작합니다. \n[");
    for(int k = 0; k < 10; k++) {
        printf("%d", getrandom[k]);
        if(k != 9) {
            printf(", ");
        }
    }
    printf("]\n\n");
}

void bubble(int getrandom[10]) {
    int counter = 0, temp = 0;
    for(int i = 0; i < 9; i++) {
        counter = 0;
        for(int j = 0; j < 9; j++) {
            if(getrandom[counter] > getrandom[counter+1]) {
                temp = getrandom[counter];
                getrandom[counter] = getrandom[counter+1];
                getrandom[counter+1] = temp;
                counter++;
            } else {
                counter++;
            }
        }
    }
    printf("Bubble Sorting을 시작합니다. \n[");
    for(int k = 0; k < 10; k++) {
        printf("%d", getrandom[k]);
        if(k != 9) {
            printf(", ");
        }
    }
    printf("]\n\n");
}

int main() {
 
	int random[randsize];
	int i,j;
 
	srand((unsigned)time(NULL));
 
	for (i = 0; i < randsize; i++) {
		random[i] = (rand() % 10) + 1;
		for (j = 0; j < i; j++) {
			if (random[i] == random[j]) i--;
		}
	}
 
	printf("난수를 배열에 입력합니다.\n");
    printf("[");
	for (i = 0; i < randsize; i++) {
		printf("%d",random[i]);
        if(i+1 != randsize) {
            printf(", ");
        }
	}
    printf("]\n\n");

    insert(random);
    selecte(random);
    quick(random);
    merge(random);
    heap(random);
    bubble(random);	
}
