#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}Node;


void createLinkedList(Node *head){
	// printf("=================================================================\n");
	// scanf("Creating the linkedlist, Adding first node of the list.");
	head->data = 0;
	head->next = NULL;
}

void printList(Node *head){
	// printf("\n\n=================================================================\n");
	// printf("Now Printing the updated list.\n");
	while(head){
		printf("%d ", head->data);
		head = head->next;
	}
}

Node *addNodeInBeginning(Node *head){
	// printf("\n\n=================================================================\n");
	// printf("Adding new Node in the Beginning.\n");

	Node *newNode = (Node *)malloc(sizeof(Node));
	printf("Enter data for new node which is being inserted in the Beginning: ");
	scanf("%d", &(newNode->data));

	newNode->next = head;
	head = newNode;

	// printf("Finished Adding the new Node in the start of list.\n");
	// printf("=================================================================\n");
}

void *addNodeAtEndOfList(Node *head){
	// printf("\n\n=================================================================\n");
	// printf("Adding new Node at the end of list.\n");

	Node *newNode = (Node *)malloc(sizeof(Node));
	printf("Enter value for new node which is being inserted at the end: ");
	scanf("%d", &newNode->data);
	newNode->next = NULL;
	while(head->next){
		head = head->next;
	}
	head->next = newNode;
	// printf("Finished Adding the new Node at the end of list.\n");
	// printf("=================================================================\n");
}


int main(int argc, char const *argv[])
{
	Node *head = (Node *)malloc(sizeof(Node));
	createLinkedList(head);
	printList(head);

	head = addNodeInBeginning(head);
	printList(head);

	addNodeAtEndOfList(head);
	printList(head);

	addNodeAtEndOfList(head);
	printList(head);

	addNodeAtEndOfList(head);
	printList(head);

	addNodeAtEndOfList(head);
	printList(head);
	return 0;
}