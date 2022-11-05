#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

typedef struct Queue{
	int item[SIZE];
	int rear, front;
}Queue;

void Enqueue(Queue *, int);
int Dequeue(Queue *);

void main(){
	// int items[SIZE];
	Queue queue1;
	queue1.rear = 0;
	queue1.front = 0;

	Enqueue(&queue1, 5);
	Enqueue(&queue1, 2);
	Enqueue(&queue1, 3);

	printf("%d\n", Dequeue(&queue1));
	printf("%d\n", Dequeue(&queue1));
	printf("%d\n", Dequeue(&queue1));
	printf("%d\n", Dequeue(&queue1));
	printf("%d\n", Dequeue(&queue1));
}

void Enqueue(Queue *qp, int value){
	if(qp->item[qp->rear] == SIZE-1){
		printf("Queue overflow\n");
		return;
	}
	qp->item[qp->rear++] = value;
}

int Dequeue(Queue *qp){
	if(qp->item[qp->rear] == qp->item[qp->front]){
		printf("Queue underflow.\n");
		return;
	}
	return qp->item[qp->front++];
}