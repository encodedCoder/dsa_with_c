#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node * next;
}Node;

Node * front = NULL;
Node * rear = NULL;
int nodeCount = 0;

void enqueue(int data);
int dequeue(void);
void printQueue(void);

int main(int argc, char const *argv[])
{
    enqueue(10);
    printQueue();
   
    enqueue(12);
    printQueue();

    enqueue(51);
    printQueue();

    enqueue(47);
    printQueue();

    enqueue(42);
    printQueue();

    printf("\t\t\n%d is removed from the queue.\n\n", dequeue());
    printf("\t\t\n%d is removed from the queue.\n\n", dequeue());
    printf("\t\t\n%d is removed from the queue.\n\n", dequeue());
    
    printQueue();

    return 0;
}

void enqueue(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if(nodeCount == 0)
    {
        front = newNode;
        rear = newNode;
        nodeCount++;
    }else
    {
        rear->next = newNode;
        rear = newNode;
        nodeCount++;
    }
    
}

int dequeue(void)
{
    if(nodeCount == 0)
    {
        printf("Queue Underflow.\n");
        return -9999;
    }else
    {
        int data = front->data;
        Node * t = front;
        front = front->next;
        free(t);
        nodeCount--;
        return data;
    }
    
}

void printQueue(void)
{
    Node * head = front;
    printf("\n\n[");
    while(head != NULL){
        printf("%-3d", head->data);
        head = head->next;
    }
    printf("]\n\n");
}