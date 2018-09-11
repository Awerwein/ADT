#include <stdlib.h>
#include <stdio.h>


//no exception handling!!!

typedef struct {
  int n;
  int front;
  int rear;
  int *array;
}Queue;

Queue* initQ(int size){
  Queue* queue = malloc(sizeof(Queue));
  queue->n = size;
  queue->front = 0;
  queue->rear = 0;
  queue->array = malloc(size*sizeof(int));
  // printf("initialized queue\n");
  return queue;
}

void enque(Queue *q, int i){
  // printf("%d\n", q->rear);
  q->array[q->rear] = i;
  printf("enqued %d at Queue[%d]\n", i, q->rear);
  if (q->rear == q->n - 1) {
    q->rear = 0;
  }
  else {
    q->rear = q->rear + 1;
  }
  return;
}

int dequeue(Queue *q){
  int out = q->array[q->front];
  if (q->front == q->n -1) {
    q->front = 0;
  } else {
    q->front = q->front +1;
  }
  printf("dequed %d\n", out);
  return out;
}




int main(int argc, char const *argv[]) {

  printf("init\n");
  Queue* Q = initQ(10);
  // printf("enqued\n");
  enque(Q, 1);
  enque(Q, 24);
  dequeue(Q);
  dequeue(Q);

  // printf("dequed %d\n", dequeue(Q));
  return 0;
}
