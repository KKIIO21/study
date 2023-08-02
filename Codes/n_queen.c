#include <stdio.h>

int getnum, count = 0;
int temp[16]={0, };

void nqueen(int col);

int main(void) {
    scanf("%d", &getnum);
	
    for(int i = 0;i < getnum; i++) {
        temp[0] = i;
        nqueen(1);
    }

    printf("%d\n", count);
    return 0;
}

void nqueen(int col) {
    if(col == getnum) {
        count += 1;
        return;
    }
	
    for(int i = 0; i < getnum; i++) {
        int check = 1;
        for(int j = 0; j < col; j++) {
            temp[col]=i;
            if(temp[j] == temp[col] || ((j - col) == (temp[j] - temp[col])) || ((j - col) == (temp[col] - temp[j]))) {
                check = 0;
                break;
            }
        }
		
        if(check) {
            nqueen(col + 1);
        }
    }
}
