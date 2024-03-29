#include <stdio.h>
#include <stdlib.h>

typedef struct _bst {
    
    int key;
    struct _bst *left;
    struct _bst *right;
} bst;

bst* search(bst* root, int key) {
    if(root == NULL) {
        printf("Error : 값을 찾을 수 없습니다.\n");
        return root;
    }

    if(key == root->key) {
        return root;
    } else if(key < root->key) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

bst* insert(bst* root, int key) {
    if(root == NULL) {
        root = (bst*) malloc(sizeof(bst));
        root->key = key;
        root->left = root->right = NULL;
    } else if(key < root->key) {
        root->left = insert(root->left, key);
    } else if(key > root->key) {
        root->right = insert(root->right, key);
    } else {
        printf("Error : 중복값은 허용되지 않습니다!\n");
    }
    return root;
}

bst* delete(bst* root, int key) {
    bst* del = NULL;
    bst* parent = NULL;
    bst* successor = NULL;
    bst* predecessor = NULL;
    bst* child = NULL;

    del = root;
    
    while(del != NULL) {    
        if(key == del->key) {
            break;
        }
        parent = del;
        if(key < del->key) {
            del = del->left;
        } else {
            del = del->right;
        }
    }

    if(del == NULL) {
        printf("Error : 존재하지 않는 키\n");
        return root;
    }

    if(del->left == NULL && del->right == NULL) {
        if(parent != NULL) {
            if(parent->left == del) {
                parent->left = NULL;
            } else {
                parent->right = NULL;
            }
        } else {
            root = NULL;
        }
    } else if(del->left != NULL  && del->right != NULL) {
        predecessor = del;
        successor = del->left;

        while(successor->right != NULL) {
            predecessor = successor;
            successor = successor->right;
        }

        if(predecessor->left == successor) {
            predecessor->left = successor->left;
        } else {
            predecessor->right = successor->left;
        }

        del->key = successor->key;
        del = successor;
    } else {
        if(del->left != NULL) {
            child =del->left;
        } else {
            child = del->right;
        }

        if(parent != NULL) {
            if(parent->left == del) {
                parent->left = child;
            } else {
                parent->right = child;
            }
        } else {
            root = child;
        }
    }

    free(del);
    return root;
}

void print_bst(bst* root) {
    if(root != NULL) {
        print_bst(root->left);
        printf("%d ", root->key);
        print_bst(root->right);
    }
}

int getnum, searchkey, wantdel;
int num[100];
int main() {
    bst* root = NULL;
    
    printf("노드의 개수를 입력하세요.\n");
    scanf("%d", &getnum);
    printf("------------------------\n");
    printf("노드를 입력하세요.\n");
    for(int i = 0; i < getnum; i++) {
        scanf("%d", &num[i]);
        root = insert(root, num[i]);
    }
    printf("------------------------\n");

    printf("오름차순으로 정렬하면 : ");
    print_bst(root);
    printf("입니다.\n");

    printf("------------------------\n");
    printf("검색할 노드 번호를 입력하세요.\n");
    scanf("%d", &searchkey);

    bst* search_result = NULL;

    search_result = search(root, searchkey);

    printf("------------------------\n");
    if(search_result == NULL) {
        printf("Error : 찾는 값이 없습니다.");
    } else {
        printf("찾으신 값은 존재합니다.\n");
    }
    printf("------------------------\n");
    printf("삭제하려는 값을 입력하세요.\n");
    scanf("%d", &wantdel);

    bst* del_result = NULL;

    del_result = delete(root, wantdel);
    root = del_result;

    printf("%d이(가) 삭제되었습니다.\n", wantdel);
    printf("남은 노드는 : ");
    print_bst(root);
    printf("입니다.\n");

    return 0;
}
