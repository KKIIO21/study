#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_QUEUE_SIZE 10

typedef int element;
typedef struct {
    element queue[MAX_QUEUE_SIZE];
    int front, rear;
}Queue;

void error(char *message){
    fprintf(stderr, "%s" ,message);
    exit(1);
}

void init_q(Queue *q) {
    q->front = q->rear = 0;
}

int empty(Queue *q) {
    return (q->front == q->rear);
}

int full(Queue *q) {
    return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void enqueue(Queue *q, element item) {
    if(full(q)) {
        error("Overflow");
    }
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->queue[q->rear] = item;
}

element dequeue(Queue *q) {
    if(empty(q)) {
        error("Underflow");
    }
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->queue[q->front];
}

#define MAX_VERTICES 50

typedef struct graph{
    int n;
    int adj[MAX_VERTICES][MAX_VERTICES];
}graph;

int visited[MAX_VERTICES];

void init(graph* x) {
    int r, c;
    x->n = 0;
    for(r = 0; r < MAX_VERTICES; r++) {
        for(c = 0; c < MAX_VERTICES; c++) {
            x->adj[r][c] = 0;
        }
    }
}

void insert_v(graph* x, int v) {
    if(((x->n)+1) > MAX_VERTICES) {
        fprintf(stderr, "Overflow");
        return;
    }
    x->n++;
}

void insert_e(graph* x, int start, int end) {
    if(start >= x->n || end >= x->n) {
        fprintf(stderr, "vertex key error");
        return;
    }
    x->adj[start][end] = 1;
    x->adj[end][start] = 1;
}

void bfs(graph* x, int y) {
    int z;
    Queue q;

    init_q(&q);
    visited[y] = TRUE;
    printf("visit %d -> ", y);
    enqueue(&q, y);
    while(!empty(&q)) {
        y = dequeue(&q);
        for(z = 0; z < x->n; z++) {
            if(x -> adj[y][z] && !visited[z]) {
                visited[z] = TRUE;
                printf("visited %d->", z);
                enqueue(&q, z);
            }
        }
    }
}

int main(void) {
    graph *x;
    x = (graph *)malloc(sizeof(graph));
    init(x);
    for(int i = 0; i < 7; i++) {
        insert_v(x, i);
    }
    insert_e(x, 0, 1);
    insert_e(x, 0, 2);
    insert_e(x, 1, 3);
    insert_e(x, 1, 4);
    insert_e(x, 2, 5);
    insert_e(x, 2, 6);

    printf("BFS\n");
    bfs(x, 0);
    printf("\n");
    free(x);
    return 0;
}
