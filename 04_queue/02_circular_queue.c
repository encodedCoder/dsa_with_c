#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

typedef struct Queue{
	int item[SIZE];
	int rear, front;
}Queue;

void Enqueue(Queue *qp, int value){
	if((qp->rear+1)%SIZE == qp->front){
		printf("Queue overflow.\n");
		return;
	}
	qp->rear = (qp->rear + 1) % SIZE;
	qp->item[qp->rear] = value;
}

int Dequeue(Queue *qp){
	if(qp->front == qp->rear){
		printf("Queue underflow.\n");
		return -9999;
	}
	qp->front = (qp->front + 1) % SIZE;
	return qp->item[qp->front]; 
}

void main(){
	Queue queue1;
	queue1.rear = SIZE-1;
	queue1.front = SIZE-1;

	Enqueue(&queue1, 8);
	Enqueue(&queue1, 9);
	Enqueue(&queue1, 4);
	Enqueue(&queue1, 5);
	Enqueue(&queue1, 7);
	Enqueue(&queue1, 2);

	printf("%d\n", Dequeue(&queue1));
	printf("%d\n", Dequeue(&queue1));
	printf("%d\n", Dequeue(&queue1));
	printf("%d\n", Dequeue(&queue1));
	printf("%d\n", Dequeue(&queue1));
	printf("%d\n", Dequeue(&queue1));
	printf("%d\n", Dequeue(&queue1));
	printf("%d\n", Dequeue(&queue1));
	printf("%d\n", Dequeue(&queue1));
	printf("%d\n", Dequeue(&queue1));
	printf("%d\n", Dequeue(&queue1));

	Enqueue(&queue1, 50);
	printf("%d\n", Dequeue(&queue1));
	printf("%d\n", Dequeue(&queue1));

}