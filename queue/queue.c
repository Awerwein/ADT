#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


typedef struct {
  int n;
  int front;
  int rear;
  int *array;
  int isFull;
  int isEmpty;
}Queue;

Queue* initQ(int size){
  Queue* queue = malloc(sizeof(Queue));
  queue->n = size;
  queue->front = 0;
  queue->rear = 0;
  queue->array = malloc(size*sizeof(int));
  queue->isFull= 0;
  queue->isEmpty = 1;
  // printf("initialized queue\n");
  return queue;
}

void enque(Queue *q, int i){
  if (!q->isFull) {
    // printf("%d\n", q->rear);
    q->array[q->rear] = i;
    printf("enqued %d at Queue[%d]\n", i, q->rear);
    if (q->rear == q->n - 1) {
      q->rear = 0;
    }
    else {
      q->rear = q->rear + 1;
    }
    if (q->rear == q->front) {
      q->isFull = 1;
    }
    q->isEmpty = 0;
    return;
  } else {
    printf("queue is full\n");
  }
}


int dequeue(Queue *q){
  if (!q->isEmpty) {
    int out = q->array[q->front];
    if (q->front == q->n -1) {
      q->front = 0;
    } else {
      q->front = q->front +1;
    }
    printf("dequed %d\n", out);
    if (q->rear == q->front) {
      q->isEmpty = 1;
    }
    q->isFull = 0;
    return out;
  }
  else {
    printf("Queue is empty\n");
  }
}



int main(int argc, char const *argv[]) {

  printf("init\n");
  Queue* Q = initQ(2);
  // printf("enqued\n");
  dequeue(Q);
  enque(Q, 1);
  enque(Q, 24);
  dequeue(Q);
  dequeue(Q);

  // printf("dequed %d\n", dequeue(Q));
  return 0;
}
