#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

struct node{
  int val;
  struct node *next;
};

struct queue {
  int size;
  struct node *front, *rear;
};
typedef struct node *Node;
typedef struct queue *Queue;
Queue queue_new(void);
Node node_new(int i);

int main(void){
  Queue q = queue_new();
  enqueue(q, 10);
  enqueue(q, 15);
  enqueue(q, 20);
  print_queue(q);
  return 0;
}

Node node_new(int i) {
  Node n = malloc(sizeof(struct node));
  n -> val = i;
  n -> next = NULL;
  return n;
}

Queue queue_new(void) {
  Queue q = malloc(sizeof(struct queue));
  q -> size = 0;
  q -> front = q -> rear = NULL;
  return q;
}

// Put element on rear
void enqueue( Queue q, int i){
  Node n = node_new(i);
  if(is_empty_queue(q)){
    q -> front = q -> rear = n;
    q -> size = 1;
    return;
  }
  q -> size = q -> size+1;
  printf("rear : %d, ", q -> rear -> val);
  q -> rear -> next = n;
  printf("n : %d\n", n -> val);
  q -> rear = n;
}

// Remove and return element from front
int dequeue( Queue q){
  if(is_empty_queue(q))
    return 0;
  Node tmp = q -> front;
  q -> front = q -> front -> next;

  if(q -> front == NULL)
    q -> rear = NULL;

  free(tmp);
  return 1;
}

// Return front element
int frontValue( Queue q){
  if(is_empty_queue(q))
    return 0;
  return q -> front -> val;
}

// Check if queue is empty
int is_empty_queue( Queue q){
  return q -> size==0;
}

// Print queue content
void print_queue( Queue q){
  if(is_empty_queue(q))
    return;
  printf("[ ");
  //Queue tmp = q -> rear;
  while(q -> front){
    printf("%d ", q -> front -> val);
    q -> front = q -> front -> next;
  }
  printf("]\n");
}
